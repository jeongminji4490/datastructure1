
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char charType; //char�� ���� charType
	int integerType; //int�� ���� intType
	float floatType; //float�� ���� floatType
	double doubleType; //double�� ���� doubleType

	printf("[����Ʈ�����а�],[������],[2018038090]\n");
	printf("size of charType: %ld byte \n", sizeof(charType)); //charType�� ũ��
	printf("size of intType: %ld byte \n", sizeof(integerType)); //integerType�� ũ��
	printf("size of floatType: %ld byte \n", sizeof(floatType)); //floatType�� ũ��
	printf("size of doubleType: %ld byte \n", sizeof(doubleType)); //doubleType�� ũ��

	printf("----------------------------------------------\n");

	printf("size of char: %ld byte \n", sizeof(char)); //�ڷ��� char�� ũ��
	printf("size of int: %ld byte \n", sizeof(int)); //�ڷ��� int�� ũ��
	printf("size of float: %ld byte \n", sizeof(float)); //�ڷ��� float�� ũ��
	printf("size of double: %ld byte \n", sizeof(double)); //�ڷ��� double�� ũ��

	printf("----------------------------------------------\n");

	printf("size of char*: %ld byte \n", sizeof(char*)); //������ �ڷ��� char*�� ũ��
	printf("size of int*: %ld byte \n", sizeof(int*)); //������ �ڷ��� int*�� ũ��
	printf("size of float*: %ld byte \n", sizeof(float*)); //������ �ڷ��� float*�� ũ��
	printf("size of double*: %ld byte \n", sizeof(double*)); //������ �ڷ��� double*�� ũ��

	return 0;
}
