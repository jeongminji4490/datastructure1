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

#define MAX_SIZE 100 //��ũ�� MAX_SIZE ����

float sum(float[],int); //main �Լ� �� sum�Լ� �̸� ����,sum�Լ��� float�迭�� int�� ������ �Ű������� �ް�, ��ȯ���� float�� �Լ�
float input[MAX_SIZE],answer; //float�� �������� input�迭, answer���� ����
int i; //int�� �������� i ����

void main(void) {

printf("����Ʈ�����а� 2018038090 ������\n");
	for(i=0;i<MAX_SIZE;i++) //0���� (max_size-1)������ �Ʒ��� ������ �ݺ��Ͻÿ�.
		input[i]=i; //�ݺ����� ����� ������ input[i]�� i�� ����

	/*for checking call by reference*/
	printf("address of input=%p\n",input); //input ������ ����� �ּڰ� ���

	answer=sum(input,MAX_SIZE); //sum�Լ��� input,MAX_SIZE���ڸ� �����Ͽ� ���� ����� answer������ ��ȯ
	printf("The sum is:%f\n",answer); //answer ������ �� ���
}

float sum(float list[],int n)
{
	printf("value of list=%p\n",list); //list�� ����� �ּڰ� ���
	printf("address of list=%p\n\n",&list); //list�� �޸� �ּڰ� ���

	int i; //�������� i�� �ٸ�
	float tempsum=0; //float�� ���� tempsum ����
	for(i=0;i<n;i++) //0���� n-1�� �ݺ��Ͽ� �Ʒ��� ���� ����
		tempsum+=list[i]; //�ݺ����� ����� ������ tempsum ������ list[i]�� ����

	return tempsum; //tempsum ��ȯ
}
