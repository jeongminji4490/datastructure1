/*
 ============================================================================
 Name        : project.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

#define MAX_QUEUE_SIZE 4 //큐의 최대 크기는 MAX_QUEUE_SIZE - 1 = 3

typedef char element; //char자료형을 element로 정의
typedef struct {
	element queue[MAX_QUEUE_SIZE]; //MAX_QUEUE_SIZE 크기의 char형 배열 정의
	int front, rear; //큐의 데이터 저장/삭제를 위한 변수
}QueueType; //구조체 이름 QueueType으로 정의

QueueType *createQueue(); //큐 생성
int isEmpty(QueueType *cQ); //큐가 비었는지 확인
int isFull(QueueType *cQ); //큐가 꽉 찼는지 확인
void enQueue(QueueType *cQ, element item); //큐에 데이터 저장
void deQueue(QueueType *cQ, element* item); //큐의 데이터 삭제
void printQ(QueueType *cQ); //큐의 배열 요소 출력
void debugQ(QueueType *cQ); //큐 디버그

element getElement(); //데이터 입력 후 반환


int main(void)
{
	QueueType *cQ = createQueue(); //큐 생성
	element data; //element형 변수 data선언

	char command; //char형 변수 command

	printf("소프트웨어학과 2018039090 정민지\n");
	do{
		printf("\n-----------------------------------------------------\n");
		printf("                     Circular Q                   \n");
		printf("------------------------------------------------------\n");
		printf(" Insert=i,  Delete=d,   PrintQ=p,   Dubug=b,   Quit=q \n");
		printf("------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command); //command 입력

		switch(command) { //switch문
    case 'i': case 'I': //command가 i 또는 I라면
      data=getElement(); //getElement함수 호출 후 반환받은 값을 data에 저장
      enQueue(cQ,data); //큐에 데이터 추가
      break;
    case 'd': case 'D': //command가 d 또는 D라면
			deQueue(cQ,&data); //큐의 데이터 삭제
			break;
		case 'p': case 'P': //command가 p 또는 P라면
			printQ(cQ); //큐의 데이터 출력
			break;
		case 'b': case 'B': //command가 b 또는 B라면
			debugQ(cQ); //큐 디버그
			break;
		case 'q': case 'Q': //command가 q 또는 Q라면
			break;
		default: //해당하는 문자가 입력되지 않았다면
			printf("\n       >>>>>   Concentration!!   <<<<<     \n"); //오류 메세지 출력
			break;
		}

	}while(command != 'q' && command != 'Q'); //command가 q 또는 Q가 아닐 때까지 반복하세요


	return 1; //프로그램 종료
}


QueueType *createQueue()
{
	QueueType *cQ; //QueueType형태의 cQ구조체 선언
	cQ = (QueueType *)malloc(sizeof(QueueType)); //cQ구조체에 QueueType크기의 메모리 동적으로 할당
	cQ->front = 0; //cQ->front를 0으로 초기화
	cQ->rear = 0; //cQ->rear을 0으로 초기화
	return cQ; //cQ 반환
}

element getElement()
{
	element item; //element형 변수 item 선언
	printf("Input element = ");
	scanf(" %c", &item); //입력
	return item; //item 반환
}


/* complete the function */
int isEmpty(QueueType *cQ)
{
  if(cQ->rear==cQ->front) //cQ->rear==cQ->front라면
  return true; //참임을 반환
  else //아니면
  return false; //거짓임을 반환
}

/* complete the function */
int isFull(QueueType *cQ)
{
  if(cQ->rear==MAX_QUEUE_SIZE) //cQ->rear==MAX_QUEUE_SIZE라면
  return true; //참임을 반환
  else //아니면
  return false; //거짓임을 반환
}


/* complete the function */
void enQueue(QueueType *cQ, element item)
{
  (cQ->rear)++; //cQ->rear 후위증가
  if(isFull(cQ)) //큐가 꽉 찼다면 1이 리턴될 것->조건문 실행
  {
    printf("Q is Full, so reset rear\n"); //큐가 꽉 찼으니, rear을 1로 초기화하겠습니다.
    cQ->rear=1; //1로 초기화, 배열의 맨 앞자리는 비었을 때/꽉 찼을때를 비교하기위해 비어있으니까
  }
  cQ->queue[cQ->rear]=item; //queue의 cQ->rear번째 배열에  item 저장
  printf("enqueue success!\n"); //큐에 데이터 저장 성공을 의미하는 메세지 출력
}

/* complete the function */
void deQueue(QueueType *cQ,element* item)
{
  if(isEmpty(cQ)) //큐가 비었다면 1이 반환될 것
  {
    printf("Q is Empty, so reset front.\n"); //큐가 비었으니 더 이상 삭제 불가
    cQ->front=0;
  }
  (cQ->front)++; //cQ->front 후위증가

  if(cQ->queue[cQ->front]==*item) //cQ->queue[cQ->front]가 item의 데이터 값과 같다면
  {
	  cQ->queue[cQ->front]='0'; //데이터 삭제
  }

}

void printQ(QueueType *cQ)
{
	int i, first, last; //int형 변수 i,first,last

	first = (cQ->front + 1)%MAX_QUEUE_SIZE; //modulo연산
	last = (cQ->rear + 1)%MAX_QUEUE_SIZE; //modulo연산

	printf("Circular Queue : [");

	i = first;
	while(i != last){ //i가 last가 아닐 때까지
		printf("%3c", cQ->queue[i]); //queue의 i번째 배열의 데이터 출력
		i = (i+1)%MAX_QUEUE_SIZE; //i를 modulo연산을 이용해 증가시킴

	}
	printf(" ]\n");
}


void debugQ(QueueType *cQ)
{

	printf("\n---DEBUG\n");
	for(int i = 0; i < MAX_QUEUE_SIZE; i++) //i가 0부터 MAX_QUEUE_SIZE일 때까지 반복하는 for문
	{
		if(i == cQ->front) { //i가 cQ->front와 같다면
			printf("  [%d] = front\n", i); //
			continue;  //반복문의 처음으로 돌아감
		}
		printf("  [%d] = %c\n", i, cQ->queue[i]);

	}
	printf("front = %d, rear = %d\n", cQ->front, cQ->rear); //cQ->front와 cQ->rear출력
}




