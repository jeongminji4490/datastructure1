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
	int list[5]; //���̰� 5�� int�� �迭 ����
	int *plist[5]={NULL,}; //����� �ּڰ� ����

	plist[0]=(int*)malloc(sizeof(int)); //malloc�� �̿��� int�� ũ���� �޸𸮸� �������� �Ҵ��ϰ� �� �ּڰ��� plist[0]�� ��ȯ

	list[0]=1; //list[0]�� 1 ����
	list[1]=100; //list[1]�� 100 ����

	*plist[0]=200; //plist[0]�� ������ �ִ� �ּڰ��� �������� ���� 200����

	printf("����Ʈ�����а� 2018038090 ������\n");
	printf("value of list[0]       =%d\n",list[0]); //list[0]�� ����� ������ ��
	printf("address of list[0]     =%p\n",&list[0]); //list[0]�� �޸� �ּڰ�
	printf("value of list          =%p\n",list); //list �迭�� �ּڰ�
	printf("address of list(&list) =%p\n",&list); //list �迭�� �ּڰ�

	printf("--------------------------------------------\n\n");

	printf("value of list[1]       =%d\n",list[1]); //list[1]�� ����� ������ ��
	printf("address of list[1]     =%p\n",&list[1]); //list[1]�� �޸� �ּڰ�
	printf("value of *(list+1)     =%d\n",*(list+1)); //list+1�� ����� �ּҰ��� �������� ���� ����� ������ ��
	printf("address of list+1      =%p\n",list+1); //list+1�� �ּڰ�

	printf("--------------------------------------------\n\n");
	printf("value of *plist[0]=%d\n",*plist[0]); //plist[0]�� �������� ���� ����Ǿ� �ִ� ������ ��
	printf("&plist[0]         =%p\n",&plist[0]); //plist[0]�� �޸� �ּڰ�
	printf("&plist            =%p\n",&plist); //plist �迭�� �ּڰ�
	printf("plist             =%p\n",plist); //plist �迭�� �ּڰ�
	printf("plist[0]          =%p\n",plist[0]); //plist[0]�� �ּڰ�
	printf("plist[1]          =%p\n",plist[1]); //plist[1]�� �ּڰ�
	printf("plist[2]          =%p\n",plist[2]); //plist[2]�� �ּڰ�
	printf("plist[3]          =%p\n",plist[3]); //plist[3]�� �ּڰ�
	printf("plist[4]          =%p\n",plist[4]); //plist[4]�� �ּڰ�

	free(plist[0]); //plist[0]�� �Ҵ����־��� �޸� ���� ����
}
