/*
 ============================================================================
 Name        : size.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void main(void) {
	int **x; //int형 더블 포인터 변수 x선언

	printf("소프트웨어학과 2018038090 정민지\n");
	printf("sizeof(x)=%u\n",sizeof(x)); //변수 x의 크기를 long형의 부호 없는 10진수 정수로 출력
	printf("sizeof(*x)=%u\n",sizeof(*x)); //*x(더블 포인터 변수 x에서 한 번 역참조한 값)의 크기를  long형의 부호 없는 10진수 정수로 출력
	printf("sizeof(**x)=%u\n",sizeof(**x)); //**x(더블 포인터 변수 x에서 두 번 역참조한 값)의 크기를  long형의 부호 없는 10진수 정수로 출력

}
