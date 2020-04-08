/*
 ============================================================================
 Name        : p2-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

void print1(int *ptr,int rows); //int형 포인터 변수와 int형 변수를 매개변수로 받는 print1 함수 선언

int main(void) {
	int one[]={0,1,2,3,4}; //길이가 5인  int형 배열 선언

	printf("소프트웨어학과 2018038090 정민지\n");
	printf("one     =%p\n",one); //one 배열의 주솟값 출력
	printf("&one    =%p\n",&one); //one 배열의 주솟값 출력
	printf("&one[0] =%p\n",&one[0]); //one[0]의 주솟값 출력
	printf("\n");

	print1(&one[0],5); //print1함수를 호출하고, one[0]의 주솟값과 정수 5를 print1의 매개변수로 전달

	return 0;
}

void print1(int *ptr,int rows)
{/*print out a one-dimentional array using a pointer*/

	int i; //int형 변수 i 선언
	printf("Address \t Contents\n");
	for(i=0;i<rows;i++) //rows-1번 반복하며 아래의 연산 진행
		printf("%p\t %5d\n",ptr+i,*(ptr+i)); //(ptr+i)의 주솟값과 (ptr+i)을 역참조하여 얻은
	printf("\n");
}
