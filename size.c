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
	int **x; //int�� ���� ������ ���� x����

	printf("����Ʈ�����а� 2018038090 ������\n");
	printf("sizeof(x)=%u\n",sizeof(x)); //���� x�� ũ�⸦ long���� ��ȣ ���� 10���� ������ ���
	printf("sizeof(*x)=%u\n",sizeof(*x)); //*x(���� ������ ���� x���� �� �� �������� ��)�� ũ�⸦  long���� ��ȣ ���� 10���� ������ ���
	printf("sizeof(**x)=%u\n",sizeof(**x)); //**x(���� ������ ���� x���� �� �� �������� ��)�� ũ�⸦  long���� ��ȣ ���� 10���� ������ ���

}
