
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char charType; //char형 변수 charType
	int integerType; //int형 변수 intType
	float floatType; //float형 변수 floatType
	double doubleType; //double형 변수 doubleType

	printf("[소프트웨어학과],[정민지],[2018038090]\n");
	printf("size of charType: %ld byte \n", sizeof(charType)); //charType의 크기
	printf("size of intType: %ld byte \n", sizeof(integerType)); //integerType의 크기
	printf("size of floatType: %ld byte \n", sizeof(floatType)); //floatType의 크기
	printf("size of doubleType: %ld byte \n", sizeof(doubleType)); //doubleType의 크기

	printf("----------------------------------------------\n");

	printf("size of char: %ld byte \n", sizeof(char)); //자료형 char의 크기
	printf("size of int: %ld byte \n", sizeof(int)); //자료형 int의 크기
	printf("size of float: %ld byte \n", sizeof(float)); //자료형 float의 크기
	printf("size of double: %ld byte \n", sizeof(double)); //자료형 double의 크기

	printf("----------------------------------------------\n");

	printf("size of char*: %ld byte \n", sizeof(char*)); //포인터 자료형 char*의 크기
	printf("size of int*: %ld byte \n", sizeof(int*)); //포인터 자료형 int*의 크기
	printf("size of float*: %ld byte \n", sizeof(float*)); //포인터 자료형 float*의 크기
	printf("size of double*: %ld byte \n", sizeof(double*)); //포인터 자료형 double*의 크기

	return 0;
}
