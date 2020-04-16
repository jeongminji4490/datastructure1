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

int** create_matrix(int row,int col) //2차원 배열 생성 함수
{
	int i;
	int** matrix;

	if(row <= 0 || col <=0)//행이 0보다 작고 같거나, 열이 0보다 작고 같으면
	{
		printf("Check the sizes of row and col!\n"); //행과 열의 크기를 확인하라는 메세지
		exit(-1); //실행 불가!(리턴값이 int**이라 -1을 리턴하지 않고 exit함수를 이용해 종료합니다)
	}

	matrix=(int**)malloc(row*sizeof(int*)); //행의 갯수만큼 배열 생성

	for(i=0;i<row;i++) //행의 갯수만큼 반복하여(한 행당 하나의 열)
		matrix[i]=(int*)malloc(col*sizeof(int)); //행 하나마다 동적으로 메모리를 할당하여 열 생성

	if(matrix == NULL) //더블 포인터 matrix의 주솟값이 NULL이라면
	{
		printf("Matrix is NULL!\n");
		exit(-1);//실행 불가!
	}
	return matrix; //생성된 2차원 배열 반환
}
int free_matrix(int** matrix,int row,int col) //2차원 배열에 동적으로 할당된 메모리를 해제하는 함수
{
	if(row <= 0 || col <=0)//행이 0보다 작고 같거나, 열이 0보다 작고 같으면
	{
		printf("Check the sizes of row and col!\n"); //행과 열의 크기를 확인하라는 메세지
		return -1; //실행 불가!
	}
	if(matrix == NULL) //더블 포인터 matrix의 주솟값이 NULL이라면
	{
		printf("Matrix is NULL!\n");
		return -1;//실행 불가!
	}

	int i; //반복문을 위한 변수 생성
	for(i=0;i<row;i++) //행의 갯수만큼
		free(matrix[i]); //열에 할당되었던 메모리 해제

	free(matrix); //또 한 번 해제

	return 1; //정상적으로 함수가 작동했음을 알리는 리턴값
}
int fill_data(int **matrix, int row, int col) //전달받은 2차원 배열의 모든 성분에 0~19까지의 정수를 랜덤으로 저장하는 함수
{
	if(row <= 0 || col <=0)//행이 0보다 작고 같거나, 열이 0보다 작고 같으면
	{
		printf("Check the sizes of row and col!\n"); //행과 열의 크기를 확인하라는 메세지
		return -1; //실행 불가!
	}

	int i,j; //반복문을 위한 변수들

	for(i=0;i<row;i++) //행의 크기만큼 반복하는 outer loop
	{
		for(j=0;j<col;j++) //열의 크기만큼 반복하는 inner loop
			matrix[i][j]=rand()%20; //rand를 이용해 0부터 19까지 랜덤으로 저장
	}

	if(matrix == NULL) //더블 포인터 matrix의 주솟값이 NULL이라면
	{
		printf("Matrix is NULL!\n");
		return -1;//실행 불가!
	}
	return 1; //정상적으로 함수가 작동했음을 알리는 리턴값
}
void print_matrix(int** matrix, int row, int col)
{
	//반환형이 void라 정상/비정상 종료를 결과값으로 보내지 못하기 때문에 조건문으로 3가지 경우 만들어서 해당 조건문에 해당하지 않으면 다음 조건문으로 넘어가도록 설계.
	if(row <= 0 || col <=0)//행이 0보다 작고 같거나, 열이 0보다 작고 같으면
	{
		printf("Check the sizes of row and col!\n"); //헹과 열의 크기를 확인하세요
	}
	else if(matrix == NULL) //더블 포인터 matrix의 주솟값이 NULL이라면
	{
		printf("Matrix is NULL!\n");
	}
	else //위 두 가지 경우에 해당하지 않는다면
	{
		int i,j;
		for(i=0;i<row;i++) //행의 크기만큼 반복하는 outer loop
		{
			for(j=0;j<col;j++) //열의 크기만큼 반복하는 inner loop
				printf("matrix[%d][%d]=%d\n",i,j,matrix[i][j]); //matrix[i][j]의 성분을 출력
		}
	}
}
int transpose_matrix(int **matrix, int **matrix_t, int row, int col) //매개변수로 받은 matrix의 행과 열을 바꿔 matrix_t에 저장하는 함수
{
	if(row <= 0 || col <=0)//행이 0보다 작고 같거나, 열이 0보다 작고 같으면
	{
		printf("Check the sizes of row and col!\n"); //행과 열의 크기를 확인하세요
		return -1; //실행 불가!
	}

	int i,j;

	for(i=0;i<row;i++) //행의 크기만큼 반복하는 outer loop
	{
		for(j=0;j<col;j++) //열의 크기만큼 반복하는 inner loop
		{
			matrix_t[i][j]=matrix[j][i]; //matrix_t[행][열]에 matrix[열][행]을 저장하라.
		}
	}

	if(matrix_t == NULL) //더블 포인터 matrix의 주솟값이 NULL이라면
	{
		printf("Matrix is NULL!\n");
		return -1;//실행 불가!
	}

	return 1; //정상적으로 함수가 작동했음을 알리는 리턴값
}
int addition_matrix(int **matrix_a, int **matrix_b, int **matrix_sum,int row, int col) //매개변수로 받은 matrix_a,matrix_b를 더하여 matrix_sum에 저장하는 함수
{
	if(row <= 0 || col <=0)//행이 0보다 작고 같거나, 열이 0보다 작고 같으면
	{
			printf("Check the sizes of row and col!\n"); //행과 열의 크기 확인하세요.
			return -1; //실행 불가!
	}

	int i,j;
	for(i=0;i<row;i++) //행의 크기만큼 반복하는 outer loop
	{
		for(j=0;j<col;j++) //열의 크기만큼 반복하는 inner loop
			matrix_sum[i][j]=matrix_a[i][j]+matrix_b[i][j]; //matrix_sum에 matrix_a+ matrix_b 저장
	}

	if(matrix_sum == NULL) //더블 포인터 matrix의 주솟값이 NULL이라면
	{
		printf("Matrix is NULL!\n");
		return -1;//실행 불가!
	}
	return 1; //정상적으로 함수가 작동했음을 알리는 리턴값
}
int subtraction_matrix(int **matrix_a, int **matrix_b, int **matrix_sub,int row, int col) //매개변수로 받은 matrix_a,matrix_b를 빼서 matrix_sub에 저장하는 함수
{
	if(row <= 0 || col <=0)//행이 0보다 작고 같거나, 열이 0보다 작고 같으면
	{
		printf("Check the sizes of row and col!\n"); //행과 열의 크기를 확인하세요.
		return -1; //실행 불가!
	}

	int i,j;
	for(i=0;i<row;i++) //행의 크기만큼 반복하는 outer loop
	{
		for(j=0;j<col;j++) //열의 크기만큼 반복하는 inner loop
			matrix_sub[i][j]=matrix_a[i][j]-matrix_b[i][j]; //matrix_sub에 matrix_a- matrix_b 저장
	}

	if(matrix_sub == NULL) //더블 포인터 matrix의 주솟값이 NULL이라면
	{
		printf("Matrix is NULL!\n");
		return -1;//실행 불가!
	}

	return 1; //정상적으로 함수가 작동했음을 알리는 리턴값
}
int multiply_matrix(int **matrix_a, int **matrix_t, int **matrix_axt,int row, int col) //매개변수로 받은 matrix_a,matrix_t를 곱해서 matrix_axt에 저장하는 함수
{
	if(row <= 0 || col <=0)//행이 0보다 작고 같거나, 열이 0보다 작고 같으면
	{
		printf("Check the sizes of row and col!\n"); //행과 열의 크기 확인하세요.
		return -1; //실행 불가!
	}

	int i,j;
	for(i=0;i<row;i++) //행의 크기만큼 반복하는 outer loop
	{
		for(j=0;j<col;j++) //열의 크기만큼 반복하는 inner loop
			matrix_axt[i][j]=matrix_a[i][j]*matrix_t[i][j]; //matrix_axt에 matrix_a*matrix_t 저장
	}

	if(matrix_axt == NULL) //더블 포인터 matrix의 주솟값이 NULL이라면
	{
		printf("Matrix is NULL!\n");
		return -1;//실행 불가!
	}
	return 1; //정상적으로 함수가 작동했음을 알리는 리턴값
}
int main(void) {
	int row,col; //row:행 col:열
	int** matrix1; //create_matrix함수를 통해 생성된 행렬을 담을 더블 포인터 변수1
	int** matrix2; //create_matrix함수를 통해 생성된 행렬을 담을 더블 포인터 변수2
	int** matrix3; //연산의 결과를 담을 더블 포인터 변수3

	printf("소프트웨어학과 2018038090 정민지\n\n");

	printf("행과 열을 1이상으로 입력해주세요:");
	fflush(stdout); //출력 버퍼 비우기
	scanf("%d %d",&row,&col); //행과 열 입력

	matrix1=create_matrix(row,col); //matrix1 생성
	matrix2=create_matrix(row,col); //matrix2 생성
	matrix3=create_matrix(row,col); //matrix3 생성

	if(fill_data(matrix1,row,col)==1) //fill_data의 매개변수로 matrix1,row,col을 전달했을 때 리턴값이 1이면
	{
		printf("matrix1에 0~19까지의 랜덤 성분 지정됨\n"); //matrix1에 0~19까지의 성분이 랜덤으로 저장되었다는 것을 알림
	}
	if(fill_data(matrix2,row,col)==1) //fill_data의 매개변수로 matrix2,row,col을 전달했을 때 리턴값이 1이면
	{
		printf("matrix2에 0~19까지의 랜덤 성분 지정됨\n"); //matrix2에 0~19까지의 성분이 랜덤으로 저장되었다는 것을 알림
	}
	if(transpose_matrix(matrix1,matrix3,row,col)==1) //transpose_matrix의 매개변수로 matrix1,matrix3,row,col을 전달했을 때 리턴값이 1이면
	{
		printf("transpose_matrix:\n");
		print_matrix(matrix3,row,col); //print_matrix에 matrix3(matrix1의 행과 열이 바뀐 성분이 저장된),row,col 전달하여 matrix3의 성분 출력
	}

	if(addition_matrix(matrix1,matrix2,matrix3,row,col)==1) //addition_matrix의 매개변수로 matrix1,matrix2,matrix3,row,col을 전달했을 때 리턴값이 1이면
	{
		printf("addition_matrix:\n");
		print_matrix(matrix3,row,col); //print_matrix에 matrix3(matrix1+matrix2),row,col 전달하여 matrix3의 성분 출력
	}
	if(subtraction_matrix(matrix1,matrix2,matrix3,row,col)==1) //subtraction_matrix의 매개변수로 matrix1,matrix2,matrix3,row,col을 전달했을 때 리턴값이 1이면
	{
		printf("subtraction_matrix:\n");
		print_matrix(matrix3,row,col); //print_matrix에 matrix3(matrix1-matrix2),row,col 전달하여 matrix3의 성분 출력
	}
	if(multiply_matrix(matrix1,matrix2,matrix3,row,col)==1) //multiply_matrix의 매개변수로 matrix1,matrix2,matrix3,row,col을 전달했을 때 리턴값이 1이면
	{
		printf("multiply_matrix:\n");
		print_matrix(matrix3,row,col); //print_matrix에 matrix3(matrix1*matrix2),row,col 전달하여 matrix3의 성분 출력
	}
	if(free_matrix(matrix1,row,col)==1) //matrix1에 동적으로 할당되었던 메모리 해제
	{
		printf("free matrix1!\n"); //free함수가 실행되어 메모리가 해제되었다는 것을 알림
	}
	if(free_matrix(matrix2,row,col)==1) //matrix2에 동적으로 할당되었던 메모리 해제
	{
		printf("free matrix2!\n"); //free함수가 실행되어 메모리가 해제되었다는 것을 알림
	}
	if(free_matrix(matrix3,row,col)==1) //matrix3에 동적으로 할당되었던 메모리 해제
	{
		printf("free matrix3!\n"); //free함수가 실행되어 메모리가 해제되었다는 것을 알림
	}
	return 0;
}
