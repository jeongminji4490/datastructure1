/*
 ============================================================================
 Name        : lala.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int** create_matrix(int row,int col) //2���� �迭 ���� �Լ�
{
	int i;
	int** matrix;

	if(row <= 0 || col <=0)//���� 0���� �۰� ���ų�, ���� 0���� �۰� ������
	{
		printf("Check the sizes of row and col!\n"); //��� ���� ũ�⸦ Ȯ���϶�� �޼���
		exit(-1); //���� �Ұ�!(���ϰ��� int**�̶� -1�� �������� �ʰ� exit�Լ��� �̿��� �����մϴ�)
	}

	matrix=(int**)malloc(row*sizeof(int*)); //���� ������ŭ �迭 ����

	for(i=0;i<row;i++) //���� ������ŭ �ݺ��Ͽ�(�� ��� �ϳ��� ��)
		matrix[i]=(int*)malloc(col*sizeof(int)); //�� �ϳ����� �������� �޸𸮸� �Ҵ��Ͽ� �� ����

	if(matrix == NULL) //���� ������ matrix�� �ּڰ��� NULL�̶��
	{
		printf("Matrix is NULL!\n");
		exit(-1);//���� �Ұ�!
	}
	return matrix; //������ 2���� �迭 ��ȯ
}
int free_matrix(int** matrix,int row,int col) //2���� �迭�� �������� �Ҵ�� �޸𸮸� �����ϴ� �Լ�
{
	if(row <= 0 || col <=0)//���� 0���� �۰� ���ų�, ���� 0���� �۰� ������
	{
		printf("Check the sizes of row and col!\n"); //��� ���� ũ�⸦ Ȯ���϶�� �޼���
		return -1; //���� �Ұ�!
	}
	if(matrix == NULL) //���� ������ matrix�� �ּڰ��� NULL�̶��
	{
		printf("Matrix is NULL!\n");
		return -1;//���� �Ұ�!
	}

	int i; //�ݺ����� ���� ���� ����
	for(i=0;i<row;i++) //���� ������ŭ
		free(matrix[i]); //���� �Ҵ�Ǿ��� �޸� ����

	free(matrix); //�� �� �� ����

	return 1; //���������� �Լ��� �۵������� �˸��� ���ϰ�
}
int fill_data(int **matrix, int row, int col) //���޹��� 2���� �迭�� ��� ���п� 0~19������ ������ �������� �����ϴ� �Լ�
{
	if(row <= 0 || col <=0)//���� 0���� �۰� ���ų�, ���� 0���� �۰� ������
	{
		printf("Check the sizes of row and col!\n"); //��� ���� ũ�⸦ Ȯ���϶�� �޼���
		return -1; //���� �Ұ�!
	}

	int i,j; //�ݺ����� ���� ������

	for(i=0;i<row;i++) //���� ũ�⸸ŭ �ݺ��ϴ� outer loop
	{
		for(j=0;j<col;j++) //���� ũ�⸸ŭ �ݺ��ϴ� inner loop
			matrix[i][j]=rand()%20; //rand�� �̿��� 0���� 19���� �������� ����
	}

	if(matrix == NULL) //���� ������ matrix�� �ּڰ��� NULL�̶��
	{
		printf("Matrix is NULL!\n");
		return -1;//���� �Ұ�!
	}
	return 1; //���������� �Լ��� �۵������� �˸��� ���ϰ�
}
void print_matrix(int** matrix, int row, int col)
{
	//��ȯ���� void�� ����/������ ���Ḧ ��������� ������ ���ϱ� ������ ���ǹ����� 3���� ��� ���� �ش� ���ǹ��� �ش����� ������ ���� ���ǹ����� �Ѿ���� ����.
	if(row <= 0 || col <=0)//���� 0���� �۰� ���ų�, ���� 0���� �۰� ������
	{
		printf("Check the sizes of row and col!\n"); //��� ���� ũ�⸦ Ȯ���ϼ���
	}
	else if(matrix == NULL) //���� ������ matrix�� �ּڰ��� NULL�̶��
	{
		printf("Matrix is NULL!\n");
	}
	else //�� �� ���� ��쿡 �ش����� �ʴ´ٸ�
	{
		int i,j;
		for(i=0;i<row;i++) //���� ũ�⸸ŭ �ݺ��ϴ� outer loop
		{
			for(j=0;j<col;j++) //���� ũ�⸸ŭ �ݺ��ϴ� inner loop
				printf("matrix[%d][%d]=%d\n",i,j,matrix[i][j]); //matrix[i][j]�� ������ ���
		}
	}
}
int transpose_matrix(int **matrix, int **matrix_t, int row, int col) //�Ű������� ���� matrix�� ��� ���� �ٲ� matrix_t�� �����ϴ� �Լ�
{
	if(row <= 0 || col <=0)//���� 0���� �۰� ���ų�, ���� 0���� �۰� ������
	{
		printf("Check the sizes of row and col!\n"); //��� ���� ũ�⸦ Ȯ���ϼ���
		return -1; //���� �Ұ�!
	}

	int i,j;

	for(i=0;i<row;i++) //���� ũ�⸸ŭ �ݺ��ϴ� outer loop
	{
		for(j=0;j<col;j++) //���� ũ�⸸ŭ �ݺ��ϴ� inner loop
		{
			matrix_t[i][j]=matrix[j][i]; //matrix_t[��][��]�� matrix[��][��]�� �����϶�.
		}
	}

	if(matrix_t == NULL) //���� ������ matrix�� �ּڰ��� NULL�̶��
	{
		printf("Matrix is NULL!\n");
		return -1;//���� �Ұ�!
	}

	return 1; //���������� �Լ��� �۵������� �˸��� ���ϰ�
}
int addition_matrix(int **matrix_a, int **matrix_b, int **matrix_sum,int row, int col) //�Ű������� ���� matrix_a,matrix_b�� ���Ͽ� matrix_sum�� �����ϴ� �Լ�
{
	if(row <= 0 || col <=0)//���� 0���� �۰� ���ų�, ���� 0���� �۰� ������
	{
			printf("Check the sizes of row and col!\n"); //��� ���� ũ�� Ȯ���ϼ���.
			return -1; //���� �Ұ�!
	}

	int i,j;
	for(i=0;i<row;i++) //���� ũ�⸸ŭ �ݺ��ϴ� outer loop
	{
		for(j=0;j<col;j++) //���� ũ�⸸ŭ �ݺ��ϴ� inner loop
			matrix_sum[i][j]=matrix_a[i][j]+matrix_b[i][j]; //matrix_sum�� matrix_a+ matrix_b ����
	}

	if(matrix_sum == NULL) //���� ������ matrix�� �ּڰ��� NULL�̶��
	{
		printf("Matrix is NULL!\n");
		return -1;//���� �Ұ�!
	}
	return 1; //���������� �Լ��� �۵������� �˸��� ���ϰ�
}
int subtraction_matrix(int **matrix_a, int **matrix_b, int **matrix_sub,int row, int col) //�Ű������� ���� matrix_a,matrix_b�� ���� matrix_sub�� �����ϴ� �Լ�
{
	if(row <= 0 || col <=0)//���� 0���� �۰� ���ų�, ���� 0���� �۰� ������
	{
		printf("Check the sizes of row and col!\n"); //��� ���� ũ�⸦ Ȯ���ϼ���.
		return -1; //���� �Ұ�!
	}

	int i,j;
	for(i=0;i<row;i++) //���� ũ�⸸ŭ �ݺ��ϴ� outer loop
	{
		for(j=0;j<col;j++) //���� ũ�⸸ŭ �ݺ��ϴ� inner loop
			matrix_sub[i][j]=matrix_a[i][j]-matrix_b[i][j]; //matrix_sub�� matrix_a- matrix_b ����
	}

	if(matrix_sub == NULL) //���� ������ matrix�� �ּڰ��� NULL�̶��
	{
		printf("Matrix is NULL!\n");
		return -1;//���� �Ұ�!
	}

	return 1; //���������� �Լ��� �۵������� �˸��� ���ϰ�
}
int multiply_matrix(int **matrix_a, int **matrix_t, int **matrix_axt,int row, int col) //�Ű������� ���� matrix_a,matrix_t�� ���ؼ� matrix_axt�� �����ϴ� �Լ�
{
	if(row <= 0 || col <=0)//���� 0���� �۰� ���ų�, ���� 0���� �۰� ������
	{
		printf("Check the sizes of row and col!\n"); //��� ���� ũ�� Ȯ���ϼ���.
		return -1; //���� �Ұ�!
	}

	int i,j;
	for(i=0;i<row;i++) //���� ũ�⸸ŭ �ݺ��ϴ� outer loop
	{
		for(j=0;j<col;j++) //���� ũ�⸸ŭ �ݺ��ϴ� inner loop
			matrix_axt[i][j]=matrix_a[i][j]*matrix_t[i][j]; //matrix_axt�� matrix_a*matrix_t ����
	}

	if(matrix_axt == NULL) //���� ������ matrix�� �ּڰ��� NULL�̶��
	{
		printf("Matrix is NULL!\n");
		return -1;//���� �Ұ�!
	}
	return 1; //���������� �Լ��� �۵������� �˸��� ���ϰ�
}
int main(void) {
	int row,col; //row:�� col:��
	int** matrix1; //create_matrix�Լ��� ���� ������ ����� ���� ���� ������ ����1
	int** matrix2; //create_matrix�Լ��� ���� ������ ����� ���� ���� ������ ����2
	int** matrix3; //������ ����� ���� ���� ������ ����3

	printf("����Ʈ�����а� 2018038090 ������\n\n");

	printf("��� ���� 1�̻����� �Է����ּ���:");
	fflush(stdout); //��� ���� ����
	scanf("%d %d",&row,&col); //��� �� �Է�

	matrix1=create_matrix(row,col); //matrix1 ����
	matrix2=create_matrix(row,col); //matrix2 ����
	matrix3=create_matrix(row,col); //matrix3 ����

	if(fill_data(matrix1,row,col)==1) //fill_data�� �Ű������� matrix1,row,col�� �������� �� ���ϰ��� 1�̸�
	{
		printf("matrix1�� 0~19������ ���� ���� ������\n"); //matrix1�� 0~19������ ������ �������� ����Ǿ��ٴ� ���� �˸�
	}
	if(fill_data(matrix2,row,col)==1) //fill_data�� �Ű������� matrix2,row,col�� �������� �� ���ϰ��� 1�̸�
	{
		printf("matrix2�� 0~19������ ���� ���� ������\n"); //matrix2�� 0~19������ ������ �������� ����Ǿ��ٴ� ���� �˸�
	}
	if(transpose_matrix(matrix1,matrix3,row,col)==1) //transpose_matrix�� �Ű������� matrix1,matrix3,row,col�� �������� �� ���ϰ��� 1�̸�
	{
		printf("transpose_matrix:\n");
		print_matrix(matrix3,row,col); //print_matrix�� matrix3(matrix1�� ��� ���� �ٲ� ������ �����),row,col �����Ͽ� matrix3�� ���� ���
	}

	if(addition_matrix(matrix1,matrix2,matrix3,row,col)==1) //addition_matrix�� �Ű������� matrix1,matrix2,matrix3,row,col�� �������� �� ���ϰ��� 1�̸�
	{
		printf("addition_matrix:\n");
		print_matrix(matrix3,row,col); //print_matrix�� matrix3(matrix1+matrix2),row,col �����Ͽ� matrix3�� ���� ���
	}
	if(subtraction_matrix(matrix1,matrix2,matrix3,row,col)==1) //subtraction_matrix�� �Ű������� matrix1,matrix2,matrix3,row,col�� �������� �� ���ϰ��� 1�̸�
	{
		printf("subtraction_matrix:\n");
		print_matrix(matrix3,row,col); //print_matrix�� matrix3(matrix1-matrix2),row,col �����Ͽ� matrix3�� ���� ���
	}
	if(multiply_matrix(matrix1,matrix2,matrix3,row,col)==1) //multiply_matrix�� �Ű������� matrix1,matrix2,matrix3,row,col�� �������� �� ���ϰ��� 1�̸�
	{
		printf("multiply_matrix:\n");
		print_matrix(matrix3,row,col); //print_matrix�� matrix3(matrix1*matrix2),row,col �����Ͽ� matrix3�� ���� ���
	}
	if(free_matrix(matrix1,row,col)==1) //matrix1�� �������� �Ҵ�Ǿ��� �޸� ����
	{
		printf("free matrix1!\n"); //free�Լ��� ����Ǿ� �޸𸮰� �����Ǿ��ٴ� ���� �˸�
	}
	if(free_matrix(matrix2,row,col)==1) //matrix2�� �������� �Ҵ�Ǿ��� �޸� ����
	{
		printf("free matrix2!\n"); //free�Լ��� ����Ǿ� �޸𸮰� �����Ǿ��ٴ� ���� �˸�
	}
	if(free_matrix(matrix3,row,col)==1) //matrix3�� �������� �Ҵ�Ǿ��� �޸� ����
	{
		printf("free matrix3!\n"); //free�Լ��� ����Ǿ� �޸𸮰� �����Ǿ��ٴ� ���� �˸�
	}
	return 0;
}
