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

#define MAX_QUEUE_SIZE 4 //ť�� �ִ� ũ��� MAX_QUEUE_SIZE - 1 = 3

typedef char element; //char�ڷ����� element�� ����
typedef struct {
	element queue[MAX_QUEUE_SIZE]; //MAX_QUEUE_SIZE ũ���� char�� �迭 ����
	int front, rear; //ť�� ������ ����/������ ���� ����
}QueueType; //����ü �̸� QueueType���� ����

QueueType *createQueue(); //ť ����
int isEmpty(QueueType *cQ); //ť�� ������� Ȯ��
int isFull(QueueType *cQ); //ť�� �� á���� Ȯ��
void enQueue(QueueType *cQ, element item); //ť�� ������ ����
void deQueue(QueueType *cQ, element* item); //ť�� ������ ����
void printQ(QueueType *cQ); //ť�� �迭 ��� ���
void debugQ(QueueType *cQ); //ť �����

element getElement(); //������ �Է� �� ��ȯ


int main(void)
{
	QueueType *cQ = createQueue(); //ť ����
	element data; //element�� ���� data����

	char command; //char�� ���� command

	printf("����Ʈ�����а� 2018039090 ������\n");
	do{
		printf("\n-----------------------------------------------------\n");
		printf("                     Circular Q                   \n");
		printf("------------------------------------------------------\n");
		printf(" Insert=i,  Delete=d,   PrintQ=p,   Dubug=b,   Quit=q \n");
		printf("------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command); //command �Է�

		switch(command) { //switch��
    case 'i': case 'I': //command�� i �Ǵ� I���
      data=getElement(); //getElement�Լ� ȣ�� �� ��ȯ���� ���� data�� ����
      enQueue(cQ,data); //ť�� ������ �߰�
      break;
    case 'd': case 'D': //command�� d �Ǵ� D���
			deQueue(cQ,&data); //ť�� ������ ����
			break;
		case 'p': case 'P': //command�� p �Ǵ� P���
			printQ(cQ); //ť�� ������ ���
			break;
		case 'b': case 'B': //command�� b �Ǵ� B���
			debugQ(cQ); //ť �����
			break;
		case 'q': case 'Q': //command�� q �Ǵ� Q���
			break;
		default: //�ش��ϴ� ���ڰ� �Էµ��� �ʾҴٸ�
			printf("\n       >>>>>   Concentration!!   <<<<<     \n"); //���� �޼��� ���
			break;
		}

	}while(command != 'q' && command != 'Q'); //command�� q �Ǵ� Q�� �ƴ� ������ �ݺ��ϼ���


	return 1; //���α׷� ����
}


QueueType *createQueue()
{
	QueueType *cQ; //QueueType������ cQ����ü ����
	cQ = (QueueType *)malloc(sizeof(QueueType)); //cQ����ü�� QueueTypeũ���� �޸� �������� �Ҵ�
	cQ->front = 0; //cQ->front�� 0���� �ʱ�ȭ
	cQ->rear = 0; //cQ->rear�� 0���� �ʱ�ȭ
	return cQ; //cQ ��ȯ
}

element getElement()
{
	element item; //element�� ���� item ����
	printf("Input element = ");
	scanf(" %c", &item); //�Է�
	return item; //item ��ȯ
}


/* complete the function */
int isEmpty(QueueType *cQ)
{
  if(cQ->rear==cQ->front) //cQ->rear==cQ->front���
  return true; //������ ��ȯ
  else //�ƴϸ�
  return false; //�������� ��ȯ
}

/* complete the function */
int isFull(QueueType *cQ)
{
  if(cQ->rear==MAX_QUEUE_SIZE) //cQ->rear==MAX_QUEUE_SIZE���
  return true; //������ ��ȯ
  else //�ƴϸ�
  return false; //�������� ��ȯ
}


/* complete the function */
void enQueue(QueueType *cQ, element item)
{
  (cQ->rear)++; //cQ->rear ��������
  if(isFull(cQ)) //ť�� �� á�ٸ� 1�� ���ϵ� ��->���ǹ� ����
  {
    printf("Q is Full, so reset rear\n"); //ť�� �� á����, rear�� 1�� �ʱ�ȭ�ϰڽ��ϴ�.
    cQ->rear=1; //1�� �ʱ�ȭ, �迭�� �� ���ڸ��� ����� ��/�� á������ ���ϱ����� ��������ϱ�
  }
  cQ->queue[cQ->rear]=item; //queue�� cQ->rear��° �迭��  item ����
  printf("enqueue success!\n"); //ť�� ������ ���� ������ �ǹ��ϴ� �޼��� ���
}

/* complete the function */
void deQueue(QueueType *cQ,element* item)
{
  if(isEmpty(cQ)) //ť�� ����ٸ� 1�� ��ȯ�� ��
  {
    printf("Q is Empty, so reset front.\n"); //ť�� ������� �� �̻� ���� �Ұ�
    cQ->front=0;
  }
  (cQ->front)++; //cQ->front ��������

  if(cQ->queue[cQ->front]==*item) //cQ->queue[cQ->front]�� item�� ������ ���� ���ٸ�
  {
	  cQ->queue[cQ->front]='0'; //������ ����
  }

}

void printQ(QueueType *cQ)
{
	int i, first, last; //int�� ���� i,first,last

	first = (cQ->front + 1)%MAX_QUEUE_SIZE; //modulo����
	last = (cQ->rear + 1)%MAX_QUEUE_SIZE; //modulo����

	printf("Circular Queue : [");

	i = first;
	while(i != last){ //i�� last�� �ƴ� ������
		printf("%3c", cQ->queue[i]); //queue�� i��° �迭�� ������ ���
		i = (i+1)%MAX_QUEUE_SIZE; //i�� modulo������ �̿��� ������Ŵ

	}
	printf(" ]\n");
}


void debugQ(QueueType *cQ)
{

	printf("\n---DEBUG\n");
	for(int i = 0; i < MAX_QUEUE_SIZE; i++) //i�� 0���� MAX_QUEUE_SIZE�� ������ �ݺ��ϴ� for��
	{
		if(i == cQ->front) { //i�� cQ->front�� ���ٸ�
			printf("  [%d] = front\n", i); //
			continue;  //�ݺ����� ó������ ���ư�
		}
		printf("  [%d] = %c\n", i, cQ->queue[i]);

	}
	printf("front = %d, rear = %d\n", cQ->front, cQ->rear); //cQ->front�� cQ->rear���
}




