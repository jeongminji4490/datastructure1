/*
 ============================================================================
 Name        : hola2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i;
		int *ptr;
		int **dptr;

		i=1234;

		printf("[checking values before ptr = &i]\n");
		printf("value of i == %d\n",i); /*���� i�� ���� ���*/
		printf("address of i == %p\n",&i); /*���� i�� �ּҰ��� ���*/
		printf("value of ptr == %p\n", ptr); /*�̱� ������ ���� ptr �޸��� �ּҰ� ���*/
		printf("address of ptr == %p\n",&ptr); /*�̱� ������ ���� ptr�� ������ �ִ� �ּҰ� ���*/

		ptr = &i; /*�̱� ������ ���� ptr�� ���� i�� �ּҰ��� �������� ��*/

		printf("[checking values after ptr = &i]\n");
		printf("value of i == %d\n",i); /*���� i�� �����͸� ���*/
		printf("address of i == %p\n",&i); /*���� i�� �ּҰ� ���*/
		printf("value of ptr == %p\n", ptr); /*�̱� ������ ���� ptr �޸��� �ּҰ� ���*/
		printf("address of ptr == %p\n",&ptr); /*�̱� ������ ���� ptr�� ���� �ּҰ� ���*/
		printf("value of *ptr == %d\n",*ptr); /*�̱� ������ ���� ptr�� ������ �ִ� �ּҰ��� ����ִ� �����͸� ���*/

		dptr=&ptr;

		printf("\n[checking values after dptr = &ptr]\n"); /*dptr�� ptr�� �ּҸ� ������ �غ��ô�.*/
		printf("value of i == %d\n",i); /*���� i�� ������ ���*/
		printf("address of i == %p\n", &i); /*���� i�� �ּҰ� ���*/
		printf("value of ptr == %p\n", ptr); /*�̱� ������ ptr �޸��� �ּҰ� ���*/
		printf("address of ptr == %p\n", &ptr); /*�̱� ������ ptr�� ���� �ּҰ� ���*/
		printf("value of *ptr == %d\n", *ptr); /* �̱� ������ ptr�� ������ �ִ� �ּҰ��� ����ִ� ������ ���*/
		printf("value of dptr == %p\n", dptr); /*���� ������ dptr �޸��� �ּҰ� ���*/
		printf("address of dptr == %p\n", &dptr); /*���� ������ dptr�� ������ �ִ� �ּҰ� ���*/
		printf("value of *dptr == %p\n", *dptr); /*���� ������ dptr�� ������ �ִ� �ּҰ��� ������ �ִ� �� ��� */
		printf("value of **dptr == %d\n", **dptr); /*���� ������ dptr�� ������ �ִ� �ּҰ��� ���� �ּҰ��� ������ �ִ� ������ ��� */

		*ptr = 7777; /* changing the value of *ptr*/

		printf("\n[after *ptr = 7777\n"); /* �̱� ������ ptr�� ������ �ִ� �ּҰ��� �ش��ϴ� �޸𸮿� 7777���� */
		printf("value of i == %d\n", i); /* ���� i�� �� ��� */
		printf("value of *ptr == %d\n", *ptr); /* �̱� ������  ptr�� ������ �ִ� �ּҰ��� ����ִ� ������ ��� */
		printf("value of **dptr == %d\n", **dptr);  /*���� ������ dptr�� ������ �ִ� �ּҰ��� ���� �ּҰ��� ������ �ִ� ������ ��� */

		**dptr = 8888;  /* changing the value of **dptr */

		printf("\n[after **dptr = 8888]\n"); /*���� ������ dptr�� ���� �ּҰ��� ���� �ּҰ��� �ش��ϴ� �޸𸮿� 8888���� */
		printf("value of i == %d\n",i); /* ���� i�� ������ ��� */
		printf("value of *ptr == %d\n", *ptr); /* �̱� ������ ���� ptr�� ���� �ּҰ��� ����ִ� ������ ��� */
		printf("value of **dptr == %d\n", **dptr);  /*���� ������ ���� dptr�� ������ �ִ� �ּҰ��� ���� �ּҰ��� ������ �ִ� ������ ��� */


		return 0;
}
