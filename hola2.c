/*
 ============================================================================
 Name        : hola2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i;
		int *ptr;
		int **dptr;

		i=1234;

		printf("[checking values before ptr = &i]\n");
		printf("value of i == %d\n",i); /*변수 i의 값을 출력*/
		printf("address of i == %p\n",&i); /*변수 i의 주소값을 출력*/
		printf("value of ptr == %p\n", ptr); /*싱글 포인터 변수 ptr 메모리의 주소값 출력*/
		printf("address of ptr == %p\n",&ptr); /*싱글 포인터 변수 ptr이 가지고 있는 주소값 출력*/

		ptr = &i; /*싱글 포인터 변수 ptr이 변수 i의 주소값을 가지도록 함*/

		printf("[checking values after ptr = &i]\n");
		printf("value of i == %d\n",i); /*변수 i의 데이터를 출력*/
		printf("address of i == %p\n",&i); /*변수 i의 주소값 출력*/
		printf("value of ptr == %p\n", ptr); /*싱글 포인터 변수 ptr 메모리의 주소값 출력*/
		printf("address of ptr == %p\n",&ptr); /*싱글 포인터 변수 ptr이 가진 주소값 출력*/
		printf("value of *ptr == %d\n",*ptr); /*싱글 포인터 변수 ptr이 가지고 있는 주소값에 들어있는 데이터를 출력*/

		dptr=&ptr;

		printf("\n[checking values after dptr = &ptr]\n"); /*dptr이 ptr의 주소를 값도록 해봅시다.*/
		printf("value of i == %d\n",i); /*변수 i의 데이터 출력*/
		printf("address of i == %p\n", &i); /*변수 i의 주소값 출력*/
		printf("value of ptr == %p\n", ptr); /*싱글 포인터 ptr 메모리의 주소값 출력*/
		printf("address of ptr == %p\n", &ptr); /*싱글 포인터 ptr이 가진 주소값 출력*/
		printf("value of *ptr == %d\n", *ptr); /* 싱글 포인터 ptr이 가지고 있는 주소값에 들어있는 데이터 출력*/
		printf("value of dptr == %p\n", dptr); /*더블 포인터 dptr 메모리의 주소값 출력*/
		printf("address of dptr == %p\n", &dptr); /*더블 포인터 dptr이 가지고 있는 주소값 출력*/
		printf("value of *dptr == %p\n", *dptr); /*더블 포인터 dptr이 가지고 있는 주소값이 가지고 있는 값 출력 */
		printf("value of **dptr == %d\n", **dptr); /*더블 포인터 dptr이 가지고 있는 주소값이 가진 주소값이 가지고 있는 데이터 출력 */

		*ptr = 7777; /* changing the value of *ptr*/

		printf("\n[after *ptr = 7777\n"); /* 싱글 포인터 ptr이 가지고 있는 주소값에 해당하는 메모리에 7777저장 */
		printf("value of i == %d\n", i); /* 변수 i의 값 출력 */
		printf("value of *ptr == %d\n", *ptr); /* 싱글 포인터  ptr이 가지고 있는 주소값에 들어있는 데이터 출력 */
		printf("value of **dptr == %d\n", **dptr);  /*더블 포인터 dptr이 가지고 있는 주소값이 가진 주소값이 가지고 있는 데이터 출력 */

		**dptr = 8888;  /* changing the value of **dptr */

		printf("\n[after **dptr = 8888]\n"); /*더블 포인터 dptr이 가진 주소값이 가진 주소값에 해당하는 메모리에 8888저장 */
		printf("value of i == %d\n",i); /* 변수 i의 데이터 출력 */
		printf("value of *ptr == %d\n", *ptr); /* 싱글 포인터 변수 ptr이 가진 주소값에 들어있는 데이터 출력 */
		printf("value of **dptr == %d\n", **dptr);  /*더블 포인터 변수 dptr이 가지고 있는 주소값이 가진 주소값이 가지고 있는 데이터 출력 */


		return 0;
}
