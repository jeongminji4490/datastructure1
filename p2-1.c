/*
 ============================================================================
 Name        : p2-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

#define MAX_SIZE 100 //매크로 MAX_SIZE 정의

float sum(float[],int); //main 함수 전 sum함수 미리 선언,sum함수는 float배열과 int형 변수를 매개변수로 받고, 반환형이 float인 함수
float input[MAX_SIZE],answer; //float형 전역변수 input배열, answer변수 선언
int i; //int형 전역변수 i 선언

void main(void) {

printf("소프트웨어학과 2018038090 정민지\n");
	for(i=0;i<MAX_SIZE;i++) //0부터 (max_size-1)번까지 아래의 연산을 반복하시오.
		input[i]=i; //반복문이 진행될 때마다 input[i]에 i값 저장

	/*for checking call by reference*/
	printf("address of input=%p\n",input); //input 변수에 저장된 주솟값 출력

	answer=sum(input,MAX_SIZE); //sum함수에 input,MAX_SIZE인자를 전달하여 얻은 결과를 answer변수에 반환
	printf("The sum is:%f\n",answer); //answer 변수의 값 출력
}

float sum(float list[],int n)
{
	printf("value of list=%p\n",list); //list에 저장된 주솟값 출력
	printf("address of list=%p\n\n",&list); //list의 메모리 주솟값 출력

	int i; //전역변수 i와 다름
	float tempsum=0; //float형 변수 tempsum 선언
	for(i=0;i<n;i++) //0에서 n-1번 반복하여 아래의 연산 수행
		tempsum+=list[i]; //반복문이 진행될 때마다 tempsum 변수에 list[i]값 저장

	return tempsum; //tempsum 반환
}
