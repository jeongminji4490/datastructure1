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
	struct student pst; //student ����ü ���� pst ����

	printf("size of student = %ld\n",sizeof(struct student)); //student ����ü�� ũ�� ���
	printf("size of int = %ld\n",sizeof(int)); //int �ڷ����� ũ�� ���
	printf("size of short = %ld\n",sizeof(short)); //short �ڷ����� ũ�� ���

	return 0;
}
