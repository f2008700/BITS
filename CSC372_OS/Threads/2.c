/*
 * 2.c
 *
 *  Created on: 21-Mar-2014
 *      Author: vikas
 */

#include<stdio.h>
#include<stdlib.h>

int n, m, d, *a, *b, *r, *res;
void *multiply(int n);

int main() {
	int i, j, k, status;
	scanf("%d%d", &n, &m);
	i = n;
	d = 0;
	printf("n:%d m:%d\n", n, m);
	for (; i > 0; d++) {
		i /= 10;
	}
	printf("\nThe number of digits in the number n:%d\n", d);
	a = (int *) malloc(d * sizeof(int));
	b = (int *) malloc(d * sizeof(int));
	r = (int *) malloc(((2 * d) - 1) * sizeof(int));
	res = (int *) malloc(((2 * d) - 1) * sizeof(int));
	for (i = n, j = m, k = d - 1; i > 0; k--) {
		a[k] = i % 10;
		b[k] = j % 10;
		i /= 10;
		j /= 10;
	}
	for (i = 0; i < d; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	for (i = 0; i < d; i++) {
		printf("%d ", b[i]);
	}
	printf("\n");
	printf("\n");

	pthread_t *n_tid = (pthread_t *) malloc(((2 * d) - 1) * sizeof(pthread_t));
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	for (i = 0; i < ((2 * d) - 1); i++) {
		r[i] = 0;
		pthread_create(&n_tid[i], &attr, multiply, i);
	}
	k = 0, j = 0;
	for (i = 0; i < ((2 * d) - 1); i++) {
		pthread_join(n_tid[i], &status);
		printf("status: %d, ", status);
		k = (j + status) % 10;
		printf("k value: %d\n", k);
		res[i] = k;
		j = (j + status) / 10;
	}
	if (j > 0)
		res[i] = j;
	else
		res[i] = 0;
	printf("\nPrinting the final values\n");
	for (i = ((2 * d) - 1), j = 0; i >= 0; i--, j = j * 10) {
		j += res[i];
		//		printf("%d",res[i]);
	}
	j /= 10;
	printf("%d\n", j);
	return 0;
}
void *multiply(int n) {
	printf("\nFor child %d\n", n);
	int i, j, k = n;
	j = d - 1;
	for (i = d - 1 - n; k >= 0; k--, i++, j--) {
		if ((i < 0) || (j < 0) || (i >= d)) {
			continue;
		}
		r[n] = r[n] + (a[i] * b[j]);
		//		printf("a[%d]:%d b[%d]:%d r[%d]:%d\t",n,a[i],n,b[j],n,r[n]);
	}
	printf("r[%d]:%d\n", n, r[n]);
	pthread_exit(r[n]);
}
