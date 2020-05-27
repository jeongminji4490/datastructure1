/*
 * Binary Search Tree #2
 *
 * Data Structures
 *
 * Department of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int key; 
	struct node *left; //노드의 왼쪽 링크
	struct node *right; //노드의 오른쪽 링크
} Node;

/* for stack */
#define MAX_STACK_SIZE		20 //MAX_STACK_SIZE를 20으로 정의
Node* stack[MAX_STACK_SIZE]; //길이가 20인 Node*형 스택 생성
int top = -1; //top을 -1로 설정

Node* pop(); //스택에서 노드 리턴
void push(Node* aNode); //스택에 노드 저장

/* for queue */
#define MAX_QUEUE_SIZE		20 //MAX_QUEUE_SIZE를 20으로 정의
Node* queue[MAX_QUEUE_SIZE]; //길이가 20인 Node*형 큐 생성
int front = -1; //front를 -1로 설정
int rear = -1; //rear을 -1로 설정

Node* deQueue(); //큐에서 노드 리턴
void enQueue(Node* aNode); //큐에 노드 저장


int initializeBST(Node** h); //이진탐색트리 초기화

/* functions that you have to implement */
void recursiveInorder(Node* ptr);	  /* recursive inorder traversal */
void iterativeInorder(Node* ptr);     /* iterative inorder traversal */
void levelOrder(Node* ptr);	          /* level order traversal */
int insert(Node* head, int key);      /* insert a node to the tree */
int deleteNode(Node* head, int key);  /* delete the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */


//void printStack(); 



int main()
{
	char command; //switch문의 변수가 될 char형 변수
	int key; //key값
	Node* head = NULL; //헤드노드를 NULL상태로 설정

	printf("소프트웨어학과 2018038090 정민지\n");
	
	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #2                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = i      Delete Node                  = d \n");
		printf(" Recursive Inorder    = r      Iterative Inorder (Stack)    = t \n");
		printf(" Level Order (Queue)  = l      Quit                         = q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = "); 
		scanf(" %c", &command); //command값 입력

		switch(command) {
		case 'z': case 'Z': //'z' 또는 'Z'라면
			initializeBST(&head); //initializeBST 호출
			break;
		case 'q': case 'Q': //'q' 또는 'Q'라면
			freeBST(head); //freeBST호출
			break;
		case 'i': case 'I': //'i' 또는 'I'라면
			printf("Your Key = ");
			scanf("%d", &key); //키 입력
			insert(head, key); //insert호출
			break;
		case 'd': case 'D': //'d' 또는 'D'라면
			printf("Your Key = ");
			scanf("%d", &key); //키 입력
			deleteNode(head, key); //deleteNode호출
			break;

		case 'r': case 'R': //'r' 또는 'R'라면
			recursiveInorder(head->left); //recursiveInorder호출
			break;
		case 't': case 'T': //'t' 또는 'T'라면
			iterativeInorder(head->left); //iterativeInorder호출
			break;

		case 'l': case 'L': //'l' 또는 'L'라면
			levelOrder(head->left); //levelorder 호출
			break;

		//case 'p': case 'P': //'p' 또는 'P'라면
			//printStack(); 
			//break;

		default: //command가 어떤 값에도 해당하지 않는다면
			printf("\n       >>>>>   Concentration!!   <<<<<     \n"); //오류메세지 출력 
			break;
		}

	}while(command != 'q' && command != 'Q'); //'q' 와 'Q'가 입력되면 반복문 탈출

	return 1; //프로그램 종료
}

int initializeBST(Node** h) {

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL)
		freeBST(*h);

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node));
	(*h)->left = NULL;	/* root */
	(*h)->right = *h;
	(*h)->key = -9999;

	top = -1; //top을 다시 -1로 설정 

	front = rear = -1; //front와 rear을 -1로 설정

	return 1;
}



void recursiveInorder(Node* ptr)
{
	if(ptr) {
		recursiveInorder(ptr->left); //recursiveInorder호출
		printf(" [%d] ", ptr->key); //ptr의 키값 출력
		recursiveInorder(ptr->right); //recursiveInorder호출
	}
}

/**
 * textbook: p 224 //스택 이용
 */
void iterativeInorder(Node* node)
{
    for(;;){

        for(;node;node=node->left) //노드가 존재할 때까지 왼쪽 자식 노드로 이동
        push(node); //스택에 삽입

        node=pop(); //스택에서 삭제

        if(!node) //노드가 존재하지 않는다면
        break; 

        printf(" [%d] ",node->key); //노드의 key값 출력
        node=node->right; //오른쪽 자식 노드로 이동
    }
}

/**
 * textbook: p 225 //큐 사용
 */
void levelOrder(Node* ptr)
{
    if(!ptr) //ptr이 존재하지 않는다면
    return; 

    enQueue(ptr); //큐에 ptr저장

    for(;;){
        ptr=deQueue(); //큐에서 노드 빼서 ptr에 저장

        if(ptr) //ptr이 존재한다면
        {
            printf(" [%d] ",ptr->key); //ptr의 key값 출력
            if(ptr->left) //ptr의 왼쪽 자식 노드가 존재한다면
            enQueue(ptr->left); //ptr의 왼쪽 자식 노드 큐에 저장 
            if(ptr->right) //ptr의 오른쪽 자식 노드가 존재한다면 
            enQueue(ptr->right); //ptr의 오른쪽 자식 노드 저장
        }
        else //그렇지 않다면
        break;     
    }
}


int insert(Node* head, int key)
{
	Node* newNode = (Node*)malloc(sizeof(Node)); //노드 생성
	newNode->key = key; //생성된 노드에 key값 저장
	newNode->left = NULL; //생성된 노드의 왼쪽 링크를 NULL상태로 설정
	newNode->right = NULL; //생성된 노드의 오른쪽 링크를 NULL상태로 설정

	if (head->left == NULL) { //트리에 헤드 노드만 존재한다면
		head->left = newNode; //루트 노드 생성
		return 1; 
	}

	/* head->left is the root */
	Node* ptr = head->left; //ptr이 루트 노드를 가리키게 함

	Node* parentNode = NULL; //부모 노드를 NULL상태로 설정
	while(ptr != NULL) { //ptr이 존재한다면

		/* if there is a node for the key, then just return */
		if(ptr->key == key) return 1;

		/* we have to move onto children nodes,
		 * keep tracking the parent using parentNode */
		parentNode = ptr;

		/* key comparison, if current node's key is greater than input key
		 * then the new node has to be inserted into the right subtree;
		 * otherwise the left subtree.
		 */
		if(ptr->key < key) 
			ptr = ptr->right;
		else
			ptr = ptr->left;
	}

	/* linking the new node to the parent */
	if(parentNode->key > key)
		parentNode->left = newNode;
	else
		parentNode->right = newNode;
	return 1;
}

//3 case-단말 노드일 경우/1개의 자식 노드가 있는 경우/2개 이상의 자식 노드가 있는 경우//
int deleteNode(Node* head, int key)
{
	Node* cNode=head->left; //현재 노드(시작-루트 노드)
  Node* pNode=head; //cNode의 부모 노드
  Node* dNode; //삭제할 노드를 가리킬 노드

  while(cNode!=NULL) //cNode가 가리키는 노드가 존재한다면
  {
    if(key==cNode->key) //삭제하려는 노드의 key가 cNode의 key와 같다면
    {
      //삭제할 노드가 단말 노드일 경우//
      if(cNode->right==NULL && cNode->left==NULL)
      {
        if(pNode->right==pNode) //삭제하려는 노드가 루트 노드일 경우
        {
          pNode->left=NULL; //pNode의 왼쪽 링크를 NULL상태로 만듦
          free(cNode); //cNode의 메모리 해제
        }
        else if(key<pNode->key) //삭제하려는 노드의 key가 부모 노드의 key보다 작다면
        {
          pNode->left=NULL; //pNode의 왼쪽 링크를 NULL상태로 만듦
          free(cNode); //cNode의 메모리 해제
        }
        else //삭제하려는 노드의 key가 부모 노드의 key보다 크다면
        {
          pNode->right=NULL; //pNode의 오른쪽 링크를 NULL상태로 만듦
          free(cNode); //cNode의 메모리 해제
        }
      }
      //삭제할 노드의 자식 노드가 1개 존재할 경우
      else if(cNode->left==NULL || cNode->right==NULL)
      {
        if(pNode->right==pNode) //삭제하려는 노드가 루트 노드일 경우
        {
          if(cNode->left!=NULL) //루트 노드에서 왼쪽 자식노드 하나만 존재한다면
          {
            pNode->left=cNode->left; //pNode의 왼쪽 링크가 루트노드의 왼쪽 자식노드를 가리키게 함
            free(cNode); //cNode의 메모리 해제
          }
          else //루트 노드에서 오른쪽 자식노드 하나만 존재한다면
          {
            pNode->left=cNode->right; //pNode의 왼쪽 링크가 루트노드의 오른쪽 자식노드를 가리키게 함
            free(cNode); //cNode의 메모리 해제
          }
        }
        //삭제하려는 노드가 루트 노드가 아닌 경우
        else if(cNode->left!=NULL) //삭제하려는 노드의 왼쪽 자식노드가 존재
        {
          if(cNode->key<pNode->key) //삭제하려는 노드의 키가 부모노드의 키보다 작다면
          {
            pNode->left=cNode->left; //pNode의 왼쪽 링크가 cNode의 왼쪽 자식노드를 가리키게 함
            free(cNode); //cNode의 메모리 해제
          }
          else //삭제하려는 노드의 키가 부모노드의 키보다 크다면
          { 
            pNode->right=cNode->left; //pNode의 오른쪽 링크가 cNode의 왼쪽 자식노드를 가리키게 함
            free(cNode); //cNode의 메모리 해제
          }
        }
        else //삭제하려는 노드의 오른쪽 자식노드가 존재
        {
          if(cNode->key<pNode->key) //삭제하려는 노드의 키가 부모노드의 키보다 작다면
          {
            pNode->left=cNode->right; //pNode의 왼쪽 링크가 cNode의 오른쪽 자식 노드를 가리키게 함
            free(cNode); //cNode의 메모리 해제
          }
          else //삭제하려는 노드의 키가 부모노드의 키보다 크다면
          {
            pNode->right=cNode->right; //pNode의 오른쪽 링크가 cNode의 오른쪽 자식 노드를 가리키게 함
            free(cNode); //cNode의 메모리 해제
          }
        }
      }
      //삭제할 노드의 자식 노드가 2개 이상 존재할 경우//
      else
      {
        if(pNode->right==pNode) //삭제하려는 노드가 루트노드일 경우
        {
          pNode->left=cNode->right; //pNode의 왼쪽 링크가 cNode의 오른쪽 자식 노드를 가리키게 함
          cNode->right->left=cNode->left; //cNode의 오른쪽 자식 노드의 왼쪽 링크가 cNode의 왼쪽 자식노드를 가리키게 함

          free(cNode); //cNode의 메모리 해제
        }
        else //루트노드가 아닐 경우
        {
          dNode=cNode; //dNode가 cNode를 가리키게 함

          while(1)
          {
            if(cNode->left==NULL && cNode->right==NULL) //단말노드 만나면 반복문 탈출
            break;

            cNode=cNode->left; //cNode를 왼쪽 자식노드로 이동
          }
          dNode->key=cNode->key; //삭제하려는 노드의 key값으로 cNode의 key값 저장
          free(cNode); //cNode의 메모리 해제
        }
      }
    }
    else if(key<cNode->key) //key가 cNode의 key보다 작다면
    {
      pNode=cNode; //pNode가 cNode가 가리키는 노드를 가리키게 함
      cNode=cNode->left; //cNode를 왼쪽 자식노드로 이동
    }
    else if(key>cNode->key) //key가 cNode의 key보다 크다면
    {
      pNode=cNode; //pNode가 cNode가 가리키는 노드를 가리키게 함
      cNode=cNode->right; //cNode를 오른쪽 자식노드로 이동
    }
    else //노드 중복
    {
      printf("동일한 키를 가진 노드가 이미 존재합니다...!\n");
      return 0;
    }
  return 0;
}
}


void freeNode(Node* ptr)
{
	if(ptr) { //ptr이 존재한다면 
		freeNode(ptr->left); //ptr의 왼쪽 노드의 메모리 해제
		freeNode(ptr->right); //ptr의 오른쪽 노드의 메모리 해제
		free(ptr); //ptr의 메모리 해제
	}
}

int freeBST(Node* head)
{

	if(head->left == head) //헤드노드만 존재한다면
	{ 
		free(head); //헤드노드의 메모리 해제
		return 1;
	}

	Node* p = head->left; //노드 p가 루트 노드를 가리키게 함

	freeNode(p); //free노드 호출하여 bst의 모든 노드에 할당된 메모리 해제

	free(head); //헤드노드의 메모리 해제
	return 1;
}



Node* pop()
{
    if(top==-1) //스택이 비어있다면
        return NULL; 
    
    return stack[top--]; //스택의 top이 가리키는 곳에 저장되어 있는 노드 리턴
}

void push(Node* aNode)
{
    if(top>MAX_STACK_SIZE) //스택이 꽉 찼다면
        return;
    
    stack[++top]=aNode; //스택의 top이 가리키는 곳에 노드 저장
}



Node* deQueue()
{
    if(front>MAX_QUEUE_SIZE) //큐가 비었다면
        return NULL; 
    
    return queue[++front]; //큐의 front가 가리키는 곳에 저장되어 있는 노드 리턴
}

void enQueue(Node* aNode)
{
    if(rear>MAX_QUEUE_SIZE) //큐가 꽉 찼다면
        return;
    
    queue[++rear]=aNode; //큐의 rear이 가리키는 곳에 노드 저장
}




