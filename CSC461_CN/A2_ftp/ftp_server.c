#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <pthread.h>
#define max 4294967

int main()
{
	int sd,b,cd,bytes_r,connected,sin_size,f_open,m,flag=1,pid,i;
	char fname[50], op[max],recv_data[1024],data1[1024],*op1,*op2,path[1024];
	struct sockaddr_in caddr,saddr;
	FILE *fp;
	socklen_t clen=sizeof(caddr);
	strcpy(data1,"#connected \0");

	sd=socket(AF_INET,SOCK_STREAM,0);
	if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) { // TCP connection
		perror("Socket");
		exit(1);
	}
	saddr.sin_family=AF_INET;
	saddr.sin_port=htons(10204);
	saddr.sin_addr.s_addr=INADDR_ANY;
	bzero(&(saddr.sin_zero),8); 
	b=bind(sd,(struct sockaddr*)&saddr,sizeof(saddr));

	if(b>=0)
		printf("binded successfully \n");
	else
	{	perror("Unable to bind");
        	exit(1);
	}
	listen(sd, 5);
	printf("\nFTPServer Waiting for client on port 10k*\n"); 

        while(flag)
        {	sin_size = sizeof(struct sockaddr_in);
		connected = accept(sd, (struct sockaddr *)&caddr,&sin_size);
		printf("\n I got a connection from (%s , %d)\n",inet_ntoa(caddr.sin_addr),ntohs(caddr.sin_port));
		send(connected, data1,strlen(data1), 0);

		while (1)
		{	bytes_r = recv(connected,recv_data,1024,0);//recvng first cmd
			recv_data[bytes_r] = '\0';
			if (strcmp(recv_data , "quit") == 0)
                	{	printf("\n Connection closed from (%s , %d)\n",inet_ntoa(caddr.sin_addr),ntohs(caddr.sin_port));
				close(connected);
				break;
                	}
			else if((strcmp(recv_data,"put")==0) || (strcmp(recv_data,"PUT")==0))
			{	//cd=accept(sd,(struct sockaddr*)&caddr,&clen);
				recv(connected,fname,sizeof(fname),0);
				//fp=fopen(fname,"w");
		
				if ((fp=fopen(fname,"w"))==NULL)
				{	printf("error in opening in a file");
					exit(0);
				}
				else 
					printf("file opened successfully \n");
		
				recv(connected,op,sizeof(op),0);
				fwrite(op,strlen(op),1,fp);
		        	fclose(fp);
		        	memset(op,'\0',strlen(op));
				printf("the file has been transferred \n");		
				//break;
			}
			else if((strcmp(recv_data,"get")==0) || (strcmp(recv_data,"GET")==0))
			{	recv(connected,fname,sizeof(fname),0);
				fp=fopen(fname,"rb");
				fseek(fp, 0L, SEEK_END);
				m = ftell(fp);
				op2=malloc((sizeof(char))*m);
				fseek(fp, 0, SEEK_SET);
				fread(op2,m,1,fp);
				send(connected,op2,m,0);
				fclose(fp);
				memset(op2,'\0',strlen(op2));
				printf("the file has been transferred \n");
				//break;
			}
			else if(strcmp(recv_data,"mkdir")==0)
			{	recv(connected,fname,sizeof(fname),0);
				mkdir(fname,0);
				strcpy(recv_data,"chmod 777 ");
				strcat(recv_data,fname);
				system(recv_data);				
				printf("Directory '%s' created \n",fname);
							
			}
			else if(strcmp(recv_data,"chdir")==0)
			{	recv(connected,fname,sizeof(fname),0);
					
				if(fname[0]!='/')
				{//	printf("heeasd\n");			
					
					chdir(fname);
					printf("New directory: ");			
					system("pwd");
					system("ls");				
				}
				else if(fname[0]=='/')
				{	chdir("/");
					chdir(fname);
					printf("New directory: ");			
					system("pwd");
					system("ls");
				}
							
			}
			else if(strcmp(recv_data,"remove")==0) 
			{	recv(connected,fname,sizeof(fname),0);
				int x=remove(fname);
				if(x==0)printf("the file has been removed \n");
			}
			else if(strcmp(recv_data,"ls")==0)
			{	pid = fork();
				if (pid < 0) 
				{	fprintf(stderr, "Fork Failed");
					exit(-1);
				}
				else if (pid == 0) 
				{ 	
					FILE *fp;
					//int fp1;
					close(1);	
					fp = fopen("list.txt", "w");
					dup(fp);
					execlp("/bin/ls","ls", NULL);
					close(fp);
				}
				else
				{	wait(NULL);
					FILE *fp;
					i=0;
					fp = fopen("list.txt", "r");
					while((op[i]=fgetc(fp))!=EOF)
					{
						i++;
					}
					op[i]='\0';
					fclose(fp);
					remove("list.txt");
					//printf("%s\n",send_data);
					send(connected,op, strlen(op), 0);
					memset(op,'\0',strlen(op));
				}			
			}	
		}
		printf("Do you want to close server: Yes==0, No==1\n");
		scanf("%d",&flag);		
	}
	return 0;
}
