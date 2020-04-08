/*
 ============================================================================
 Name        : c.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void main(void) {
	int list[5]; //길이가 5인 int형 배열 list 선언
	int *plist[5]; //int형 포인터 배열 5개로 이루어진 plist 선언

	list[0]=10; //list[0]에 10 저장
	list[1]=11; //list[1]에 11저장

	plist[0]=(int*)malloc(sizeof(int)); //malloc을 이용해 int형 크기의 메모리를 할당받고, 할당받은 메모리의 주솟값을 plist[0]에 반환

	printf("list[0]\t=%d\n",list[0]); //list[0]에 저장된 데이터 값 출력
	printf("address of list\t=%p\n",list); //list 배열의 주솟값 출력
	printf("address of list[0]\t=%p\n",&list[0]); //list[0]의 주솟값 출력
	printf("address of list + 0 \t=%p\n",list+0); //(list+0)의 주솟값 출력 /시작주소+0byte
	printf("address of list + 1 \t=%p\n",list+1); //(list+1)의 주솟값 출력 /시작주소+4byte
	printf("address of list + 2 \t=%p\n",list+2); //(list+2)의 주솟값 출력 /시작주소+8byte
	printf("address of list + 3 \t=%p\n",list+3); //(list+3)의 주솟값 출력 /시작주소+12byte
	printf("address of list + 4 \t=%p\n",list+4); //(list+4)의 주솟값 출력 /시작주소+16byte
	printf("address of list[4]\t=%p\n",&list[4]); //list[4]의 주솟값 출력

	free(list[0]); //malloc을 이용해 heap에 할당해두었던 메모리 해제
}
