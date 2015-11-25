/*
 * 1.c
 *
 *  Created on: 21-Mar-2014
 *      Author: vikas
 */
#include<stdio.h>
#include<stdlib.h>
int n, m, *a1, *a2, *result;
void *create_array(void);
void *run_element(int i);
void *print_array();
int main() {
	int i, j = 1;
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	//	printf("Just before creating child process");
	pthread_create(&tid, &attr, create_array, NULL);
	pthread_join(tid, NULL);
	printf("Child thread finished creating the processes! \n");

	pthread_t *n_tid = (pthread_t *) malloc((n + m) * sizeof(pthread_t));
	for (i = 0; i < n + m; i++) {
		pthread_create(&n_tid[i], &attr, run_element, i);
	}
	printf("Main thread ending..\n");
	for (i = 0; i < n + m; i++) {
		printf("i: %d, n: %d,  m: %d\n", i, n, m);
		pthread_join(n_tid[i], NULL);
	}

	pthread_create(&tid, &attr, print_array, NULL);
	pthread_join(tid, NULL);

	printf("Main thread ending\n");
	return 0;
}
void *print_array() {
	int i;
	printf("The sorted array is as follows!\n\n");
	for (i = 0; i < n + m; i++) {
		printf("%d ", result[i]);
	}
	printf("\n");
}
void *run_element(int i) {
	int index;
	if (i < n) {
		index = binary_search(1, a1[i]);
		//	printf("Index returned: %d for a[%d]: %d\n",index,i,a1[i]);
		//		printf("Index to be put at: %d for a[%d]: %d\n",index+i,i,a1[i]);
		result[index + i] = a1[i];
		//		printf("Index returned: %d for a[%d]: %d\n",index,i,a1[i]);
	} else if ((i >= n) && (i < n + m)) {
		i -= n;
		//		printf("Child 2: i: %d\tvalue: %d\n",i,a2[i]);
		index = binary_search(2, a2[i]);
		//		printf("Index returned: %d for a[%d]: %d\n",index,i,a2[i]);
		result[index + i] = a2[i];
	}

	//	printf("Child %d ending\n",i);
	pthread_exit(0);
}

int binary_search(int c, int t) {
	int beg, end, mid;
	//	printf("Reaching here\n");
	beg = 0;
	if (c == 1) {
		end = m - 1;
		if (t < a2[0])
			return 0;
		else if (t > a2[m - 1])
			return (m);
		else {
			while (1) {
				mid = (beg + end) / 2;
				if ((t > a2[mid]) && (t < a2[mid + 1])) {
					return mid + 1;
				} else if (t > a2[mid]) {
					beg = mid + 1;
				} else if (t < a2[mid]) {
					end = mid - 1;
				}
			}
		}
	}
	if (c == 2) {
		end = n - 1;
		if (t < a1[0])
			return 0;
		else if (t > a1[n - 1])
			return (n);
		else {
			while (1) {
				mid = (beg + end) / 2;
				if ((t > a1[mid]) && (t < a1[mid + 1])) {
					return mid + 1;
				} else if (t > a1[mid]) {
					beg = mid + 1;
				} else if (t < a1[mid]) {
					end = mid - 1;
				}
			}
		}
	}
}
void *create_array(void) {
	int i;
	printf("Child thread id%d\n", pthread_self());
	scanf("%d", &n);
	a1 = (int *) malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &a1[i]);
		printf("%d ", a1[i]);
	}
	printf("\n");
	scanf("%d", &m);
	a2 = (int *) malloc(m * sizeof(int));
	for (i = 0; i < m; i++) {
		scanf("%d", &a2[i]);
		printf("%d ", a2[i]);
	}
	result = (int *) malloc((m + n) * sizeof(int));
	printf("\n");
	pthread_exit(0);
}
