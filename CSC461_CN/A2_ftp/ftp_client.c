#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#define max 4294967

int main() {
	int sd, c, s, connected, bytes_r, m;
	int count = 0;
	char fname[50], sip[25], *op1, send_data[1024], recv_data[1024], op[max];
	struct sockaddr_in caddr;
	struct hostent *he;
	FILE *fp;
	printf("enter the server ip address \n");
	scanf("%s", sip);
	he = gethostbyname(sip);
	sd = socket(AF_INET, SOCK_STREAM, 0);
	if (sd == -1)  // TCP connection
	{	perror("Socket");
		exit(1);
	}
	caddr.sin_family = AF_INET;
	caddr.sin_port = htons(10204);    // Port to connect to server
	caddr.sin_addr = *((struct in_addr *) he->h_addr);
	bzero(&(caddr.sin_zero), 8);

	connected = connect(sd, (struct sockaddr *) &caddr,sizeof(struct sockaddr));

	if (connected >= 0)
		printf("connected to server \n");
	else {
		printf("connection failed \n");
		exit(1);
	}

	bytes_r = recv(sd, recv_data, 1024, 0);    //receivng initial msg
	recv_data[bytes_r] = '\0';
	printf("#ftp %s", recv_data); //printing intial message that connection is established
	while (1) {
		fflush(stdout);
		printf("\n#ftp: ");
		gets(send_data);
		send(sd, send_data, strlen(send_data), 0);    //sending first cmd

		if (strcmp(send_data, "quit") == 0) {
			close(connected);
			break;
		}

		else if (strcmp(send_data, "put") == 0) {
			printf("#ftp: enter the file name \n");
			scanf("%s", fname);
			//send(sd,fname,sizeof(fname),0);
			send(sd, fname, sizeof(fname), 0);
			fp = fopen(fname, "rb");
			fseek(fp, 0L, SEEK_END);
			m = ftell(fp);
			op1 = malloc((sizeof(char)) * m);
			fseek(fp, 0, SEEK_SET);
			fread(op1, m, 1, fp);
			//op1[m]='/0';
			send(sd, op1, m, 0);
			fclose(fp);
			memset(op1, '\0', strlen(op1)); ///change here
			//break;
		}

		else if ((strcmp(send_data, "get") == 0)
				|| (strcmp(send_data, "GET") == 0)) {
			printf("#ftp: enter the file name \n");
			scanf("%s", fname);
			//send(sd,fname,sizeof(fname),0);
			send(sd, fname, sizeof(fname), 0);
			recv(connected, fname, sizeof(fname), 0);
			if ((fp = fopen(fname, "w")) == NULL ) {
				printf("error in opening in a file");
				exit(0);
			} else
				printf("file opened successfully \n");
//
			recv(sd, op, sizeof(op), 0);
			fwrite(op, strlen(op), 1, fp);
			fclose(fp);
			memset(op, '\0', strlen(op));
			printf("The file has been transferred \n");
		}
		else if (strcmp(send_data, "mkdir") == 0) {
			printf("#ftp: Enter the name of the directory: \n");
			scanf("%s", fname);
			send(sd, fname, sizeof(fname), 0);
		}
		else if (strcmp(send_data, "chdir") == 0) {
			printf("#ftp: Enter the name of the directory: \n");
			scanf("%s", fname);
			send(sd, fname, sizeof(fname), 0);
		}
		else if (strcmp(send_data, "ls") == 0) {
			printf("#ftp: The directory contains: \n");
			recv(sd, op, sizeof(op), 0);
			printf("%s", op);
			memset(op, '\0', strlen(op));
			fflush(stdout);
		}
		else if (strcmp(send_data, "remove") == 0) {
			printf("#ftp: enter the file name \n");
			scanf("%s", fname);
			send(sd, fname, sizeof(fname), 0);
		}
		//count++;
	}
	return 0;
}
