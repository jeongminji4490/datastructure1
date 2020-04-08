/*
 ============================================================================
 Name        : lab3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void main(void){
	int list[5]; //길이가 5인 int형 배열 선언
	int *plist[5]={NULL,}; //저장된 주솟값 없음

	plist[0]=(int*)malloc(sizeof(int)); //malloc을 이용해 int형 크기의 메모리를 동적으로 할당하고 그 주솟값을 plist[0]에 반환

	list[0]=1; //list[0]에 1 저장
	list[1]=100; //list[1]에 100 저장

	*plist[0]=200; //plist[0]이 가지고 있는 주솟값을 역참조한 값에 200저장

	printf("소프트웨어학과 2018038090 정민지\n");
	printf("value of list[0]       =%d\n",list[0]); //list[0]에 저장된 데이터 값
	printf("address of list[0]     =%p\n",&list[0]); //list[0]의 메모리 주솟값
	printf("value of list          =%p\n",list); //list 배열의 주솟값
	printf("address of list(&list) =%p\n",&list); //list 배열의 주솟값

	printf("--------------------------------------------\n\n");

	printf("value of list[1]       =%d\n",list[1]); //list[1]에 저장된 데이터 값
	printf("address of list[1]     =%p\n",&list[1]); //list[1]의 메모리 주솟값
	printf("value of *(list+1)     =%d\n",*(list+1)); //list+1에 저장된 주소값을 역참조한 값에 저장된 데이터 값
	printf("address of list+1      =%p\n",list+1); //list+1의 주솟값

	printf("--------------------------------------------\n\n");
	printf("value of *plist[0]=%d\n",*plist[0]); //plist[0]을 역참조한 값에 저장되어 있는 데이터 값
	printf("&plist[0]         =%p\n",&plist[0]); //plist[0]의 메모리 주솟값
	printf("&plist            =%p\n",&plist); //plist 배열의 주솟값
	printf("plist             =%p\n",plist); //plist 배열의 주솟값
	printf("plist[0]          =%p\n",plist[0]); //plist[0]의 주솟값
	printf("plist[1]          =%p\n",plist[1]); //plist[1]의 주솟값
	printf("plist[2]          =%p\n",plist[2]); //plist[2]의 주솟값
	printf("plist[3]          =%p\n",plist[3]); //plist[3]의 주솟값
	printf("plist[4]          =%p\n",plist[4]); //plist[4]의 주솟값

	free(plist[0]); //plist[0]에 할당해주었던 메모리 영역 해제
}
