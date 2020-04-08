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
	int list[5]; //���̰� 5�� int�� �迭 list ����
	int *plist[5]; //int�� ������ �迭 5���� �̷���� plist ����

	list[0]=10; //list[0]�� 10 ����
	list[1]=11; //list[1]�� 11����

	plist[0]=(int*)malloc(sizeof(int)); //malloc�� �̿��� int�� ũ���� �޸𸮸� �Ҵ�ް�, �Ҵ���� �޸��� �ּڰ��� plist[0]�� ��ȯ

	printf("list[0]\t=%d\n",list[0]); //list[0]�� ����� ������ �� ���
	printf("address of list\t=%p\n",list); //list �迭�� �ּڰ� ���
	printf("address of list[0]\t=%p\n",&list[0]); //list[0]�� �ּڰ� ���
	printf("address of list + 0 \t=%p\n",list+0); //(list+0)�� �ּڰ� ��� /�����ּ�+0byte
	printf("address of list + 1 \t=%p\n",list+1); //(list+1)�� �ּڰ� ��� /�����ּ�+4byte
	printf("address of list + 2 \t=%p\n",list+2); //(list+2)�� �ּڰ� ��� /�����ּ�+8byte
	printf("address of list + 3 \t=%p\n",list+3); //(list+3)�� �ּڰ� ��� /�����ּ�+12byte
	printf("address of list + 4 \t=%p\n",list+4); //(list+4)�� �ּڰ� ��� /�����ּ�+16byte
	printf("address of list[4]\t=%p\n",&list[4]); //list[4]�� �ּڰ� ���

	free(list[0]); //malloc�� �̿��� heap�� �Ҵ��صξ��� �޸� ����
}
