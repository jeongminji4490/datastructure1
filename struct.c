/*
 ============================================================================
 Name        : struct.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

struct student1{ //student1 ����ü
	char lastName; //char ����
	int studentId; //int�� ����
	char grade; //char�� ����
};

typedef struct { //typedef ������ �� student2 ����ü-main���� ������ �� struct ���� �ʿ����
	char lastName; //char�� ����
	int studentId; //int�� ����
	char grade; //char�� ����
}student2; //typedef ������ ��� ����ü ���� ������ ����.

int main(void) {

	struct student1 st1={'A',100,'A'}; //student ����ü ���� st1 ����� ���ÿ� ����ü ��� �ʱ�ȭ

	printf("st1.lastName=%c\n",st1.lastName); //str1�� lastName ���
	printf("st1.studentId=%d\n",st1.studentId); //str1�� studentId ���
	printf("st1.grade=%c\n",st1.grade); //str1�� grade ���

	student2 st2={'B',200,'B'}; //student2 ����ü ���� st2 ����� ���ÿ� ����ü ��� �ʱ�ȭ

	printf("\nst2.lastName=%c\n",st2.lastName); //str2�� lastName ���
	printf("st2.studentId=%d\n",st2.studentId); //str2�� studentId ���
	printf("st2.grade=%c\n",st2.grade); //str2�� grade ���

	student2 st3; //student2 ����ü ���� st3 ����

	st3=st2; //st3�� st2�� ġȯ

	printf("\nst3.lastName=%c\n",st3.lastName); //str3�� lastName ���
	printf("st3.studentId=%d\n",st3.studentId); //str3�� studentId ���
	printf("st3.grade=%c\n",st3.grade); //str3�� grade ���

	/*equality test*/ //st3�� st2�� �Ȱ����� �׽�Ʈ, �� �κ��� ����
	/*if(st3==st2)
		printf("equal\n"); //������ equal ���
	else
		printf("not equal\n"); //�ٸ��� not equal ���
*/
	return 0;
}
