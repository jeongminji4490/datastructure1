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

void print1(int *ptr,int rows); //int�� ������ ������ int�� ������ �Ű������� �޴� print1 �Լ� ����

int main(void) {
	int one[]={0,1,2,3,4}; //���̰� 5��  int�� �迭 ����

	printf("����Ʈ�����а� 2018038090 ������\n");
	printf("one     =%p\n",one); //one �迭�� �ּڰ� ���
	printf("&one    =%p\n",&one); //one �迭�� �ּڰ� ���
	printf("&one[0] =%p\n",&one[0]); //one[0]�� �ּڰ� ���
	printf("\n");

	print1(&one[0],5); //print1�Լ��� ȣ���ϰ�, one[0]�� �ּڰ��� ���� 5�� print1�� �Ű������� ����

	return 0;
}

void print1(int *ptr,int rows)
{/*print out a one-dimentional array using a pointer*/

	int i; //int�� ���� i ����
	printf("Address \t Contents\n");
	for(i=0;i<rows;i++) //rows-1�� �ݺ��ϸ� �Ʒ��� ���� ����
		printf("%p\t %5d\n",ptr+i,*(ptr+i)); //(ptr+i)�� �ּڰ��� (ptr+i)�� �������Ͽ� ����
	printf("\n");
}
