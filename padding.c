/*
 ============================================================================
 Name        : padding.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

struct student{
	char lastName[13]; //13 bytes
	int studentId;     //4 bytes
	short grade;       //2 bytes
};

int main(void) {
	struct student pst; //student 구조체 변수 pst 선언

	printf("size of student = %ld\n",sizeof(struct student)); //student 구조체의 크기 출력
	printf("size of int = %ld\n",sizeof(int)); //int 자료형의 크기 출력
	printf("size of short = %ld\n",sizeof(short)); //short 자료형이 크기 출력

	return 0;
}
