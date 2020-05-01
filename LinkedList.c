#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key;
    struct Node* link;
}listNode; //데이터 key와 link로 이루어진 구조체 listNode

typedef struct Head {
	struct Node* first;
}headNode; //link로만 이루어진, 리스트의 첫 부분을 가리키는 head

typedef struct Tail
{
	struct Node* last;
}tailNode; //link로만 이루어진, 리스트의 마지막 부분을 가리키는 tail

headNode* initialize(headNode* h); //headNode 초기화
tailNode* initializet(tailNode* t); //tailNode 초기화
int freeList(headNode* h); //리스트에 할당된 메모리 해제

int insertFirst(headNode* h, int key); //앞에서부터 노드 추가 
int insertNode(headNode* h, tailNode* t,int key); //노드 추가
int insertLast(tailNode* t, int key); //뒤에서부터 노드 추가

int deleteFirst(headNode* h); //앞에서부터 노드 삭제
int deleteNode(headNode* h, int key); //노드 삭제
int deleteLast(headNode* h,tailNode* t); //뒤에서부터 노드 삭제
int invertList(headNode* h,tailNode* t); //리스트 순서를 역순으로 바꿈

void printList(headNode* h); //리스트 출력

int main()
{
	char command; //switch문에 적용될 char형 변수 command
	int key; //노드에 저장할 데이터
	headNode* headnode=NULL; //리스트의 첫번째 노드를 가리킬 head
	tailNode* tailnode=NULL; //리스트의 마지막 노드를 가리킬 head

    printf("소프트웨어학과 2018038090 정민지\n");

	do{
		printf("----------------------------------------------------------------\n");
		printf("                     Singly Linked List                         \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n"); 
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = "); 
		scanf(" %c", &command); //command에 문자 입력

		switch(command) { 
		case 'z': case 'Z': //command가 z 또는 Z이면
			headnode = initialize(headnode); //headnode 초기화
            tailnode = initializet(tailnode); //tailnode 초기화
			break;
		case 'p': case 'P': //command가 p 또는 P이면
			printList(headnode); //리스트 출력
			break;
		case 'i': case 'I': //command가 i 또는 I이면
			printf("Your Key = ");
			scanf("%d", &key); //노드에 들어갈 데이터 입력
			insertNode(headnode, tailnode, key); //노드에 입력한 데이터 삽입
			break;
		case 'd': case 'D': //command가 d 또는 D이면
			printf("Your Key = ");
			scanf("%d", &key); //삭제할 데이터 입력
			deleteNode(headnode, key); //해당 데이터를 찾아서 노드 삭제
			break;
		case 'n': case 'N': //command가 n 또는 N이면
			printf("Your Key = ");
			scanf("%d", &key); //데이터 입력
			insertLast(tailnode, key); //입력한 데이터 리스트의 마지막에 삽입
			break;
		case 'e': case 'E': //command가 e 또는 E이면
			deleteLast(headnode,tailnode); //리스트의 마지막 노드부터 삭제
			break;
		case 'f': case 'F': //command가 f 또는 F이면
			printf("Your Key = ");
			scanf("%d", &key); //데이터 입력
			insertFirst(headnode,key); //첫 번째 노드에 데이터 삽입
			break;
		case 't': case 'T': //command가 t 또는 T이면
			deleteFirst(headnode); //리스트의 첫번째 노드부터 삭제
			break;
		case 'r': case 'R': //command가 r 또는 R이면
			invertList(headnode,tailnode); //리스트 순서를 역순으로 바꿈
			break;
		case 'q': case 'Q': //command가 q 또는 Q이면
			freeList(headnode); //리스트에 할당된 메모리 해제 후 종료
			break;
		default: //command가 어떤 case에도 해당하지 않는다면
			printf("\n       >>>>>   Concentration!!   <<<<<     \n"); //오류메세지 출력
			break;
		}

	}while(command != 'q' && command != 'Q'); //command가 q 그리고 Q가 아닐 때까지 반복

	return 1; //프로그램 종료
}

tailNode* initializet(tailNode* t)
{
  if(t != NULL) //tailNode형 변수 t가 NULL이 아니라면
		free(t); //h\t에 할당된 메모리 해제

	tailNode* temp = (tailNode*)malloc(sizeof(tailNode)); //tailNode형 변수 temp에 메모리 할당
	temp->last = NULL; //temp가 아무것도 가리키지 않도록 함
	return temp; //temp 반환
}

headNode* initialize(headNode* h) {

	if(h != NULL) //headNode형 변수 h가 NULL이 아니라면
		freeList(h); //h에 할당된 메모리 해제

	headNode* temp = (headNode*)malloc(sizeof(headNode)); //headNode형 변수 temp에 메모리 할당
	temp->first = NULL; //temp가 아무것도 가리키지 않도록 함
	return temp; //temp 반환
}


int freeList(headNode* h){

	listNode* p = h->first; //listNode형 변수 p가 headNode가 가리키는 첫번째 노드를 가리키게 함
    listNode* prev = NULL; //listNode형 변수 prev는 NULL
    
	while(p != NULL) { //p가 NULL이 아니라면(h->first를 가리키고 있다면)
		prev = p; //prev가 p를 가리키게 함
		p = p->link; //p가 다음 노드를 가리키게 함
		free(prev); //prev가 가리키고 있는 노드(p가 이동 전에 가리키고 있던 노드) 해제
	}
   
	free(h); //headNode 해제
	return 0; 
}

int insertFirst(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode)); //메모리를 동적으로 할당하여 노드 생성
	node->key = key; //노드의 key 부분에 매개변수로 받은 key 저장
 
	node->link = h->first; //생성한 노드와 리스트의 머리 부분 연결
	h->first = node; //리스트의 head 포인터가 노드를 가리키게 함
	return 0;
}

int insertNode(headNode* h,tailNode*t, int key) {

	if(h->first==NULL) //리스트에 노드가 존재하지 않을 때
	{
		listNode* node=(listNode*)malloc(sizeof(listNode)); //메모리를 동적으로 할당하여 노드 생성
		node->key=key; //노드의 key 부분에 매개변수로 받은 key저장
		node->link=NULL;  //노드가 아무것도 가리키지 않게 함
		t->last=node; //리스트의 tail 포인터가 노드를 가리키게 함 
		h->first=node; //리스트의 head 포인터가 노드를 가리키게 함
	}
	else //그렇지 않다면
	{
		insertFirst(h,key);
	}
	return 0;
}


int insertLast(tailNode* t, int key) {

    listNode* node = (listNode*)malloc(sizeof(listNode)); //동적으로 메모리를 할당하여 노드 생성
	node->key = key; //노드의 key 부분에 매개변수로 받은 key저장

	t->last->link=node; //리스트의 tail 포인터가 가리키는 노드가 생성된 노드를 가리키게 함
	t->last=node; t->last=node; //리스트의 tail 포인터가 노드를 가리키게 함 
	node->link=NULL; //노드가 아무것도 가리키지 않게 함
	return 0;
}


int deleteFirst(headNode* h) {

    listNode* x=(listNode*)malloc(sizeof(listNode)); //노드를 삭제하기 위해 동적으로 메모리를 할당하여 노드 x 생성

    x=h->first; //노드 x가 리스트의 첫번째 노드를 가리키게 함

	if(h->first->link==NULL) //첫번째 노드가 마지막 노드라면
	{
		free(x); //x의 메모리 해제
	}
	else 
	{
		h->first=h->first->link; //head포인터가 다음 노드를 가리키게 함
		free(x); //x가 가리키고 있던 노드의 메모리를 해제
	}
	return 0;
}


int deleteNode(headNode* h, int key) {

	listNode* x=(listNode*)malloc(sizeof(listNode)); //노드를 삭제하기 위한 노드 x를 동적으로 메모리를 할당하여 생성
    listNode* trail; //삭제하려는 노드의 선행 노드를 가리키기 위한 변수
    x=h->first; //x가 리스트의 머리 부분을 가리키게함
    trail=h->first; //trail이 리스트의 머리 부분을 가리키게 함

	while(1) 
	{
		if(x==NULL) //x가 NULL이면
		{
			printf("삭제할 데이터가 리스트에 존재하지 않습니다.\n"); //오류 메세지 출력
			return 0;
		}
		if(x->key==key) //x의 데이터가 삭제하려는 데이터와 일치한다면
		break; //반복문 빠져나오기
		
		trail=x; //선행 노드가 x(삭제하려는 노드)를 가리키게 하고
		x=x->link; //x는 다음 노드를 가리킴
	}
	if(x==h->first) //x가 리스트의 머리 부분과 같다면
	{
		h->first=h->first->link; //head포인터를 다음 노드로 이동
		free(x); //x메모리 해제
	}
	else //그렇지 않다면
	{
		trail->link=x->link; //trail의 link 부분이 x가 가리키는 노드의 다음 노드를 가리키게함 
		free(x); //x메모리 해제
	}

	return 0;
}


int deleteLast(headNode* h,tailNode* t) {

    listNode* x=(listNode*)malloc(sizeof(listNode)); //노드를 삭제하기 위해 동적으로 메모리를 할당하여 노드 x 생성
	x=h->first; //x가 head포인터가 가리키는 노드를 가리키게 함

	if(h->first==t->last) //마지막 노드만 존재한다면
	{
		free(x); //x의 메모리 해제
	}
	else //그렇지 않다면
	{
		while(x->link!=t->last) //x의 link가 tail포인터가 가리키는 노드(마지막 노드)를 가리키지 않는 동안 반복(tail이 마지막 노드의 선행 노드를 가리키게 함)
		{
			x=x->link; //x가 다음 노드를 가리키게 함
		}
		t->last=x; //tail 포인터가 선행 노드를 가리키게 함
	    x=x->link; //x를 다음 노드(마지막 노드)로 옮김
	    free(x); //x에 할당된 메모리 해제
	    t->last->link=NULL; //tail포인터의 link 부분이 아무것도 가리키지 않게 함
	    return 0;
	}
}


int invertList(headNode* h,tailNode* t) {

  //head와 tail의 위치변경
  listNode* vf=h->first; //리스트의 첫번째 노드를 가리키도록 하는 vf노드 생성
  h->first=t->last; //head포인터가 마지막 노드를 가리키게 함
  t->last=vf; //tail포인터가 첫번째 노드를 가리키게 함
  
  while(1)
  {
	  if(h->first->link==t->last) //head포인터의 link가 tail포인터가 가리키는 노드를 가리키지 않을 때까지 반복
	  break;
		   
	  h->first->link=t->last; //head 포인터의 링크가 tail포인터가 가리키는 노드를 가리키게 함
	  t->last=t->last->link; //tail포인터가 다음 노드를 가리키게 함
  }
  return 0;
}


void printList(headNode* h) {
	int i = 0; //반복문을 위한 변수 i
	listNode* p; //리스트 포인터 p

	printf("\n---PRINT\n");

	if(h == NULL) { //head포인터가 아무것도 가리키지 않을 때
		printf("Nothing to print....\n"); //출력할 게 없다는 오류 메세지 출력
		return; 
	}
 
 	p = h->first; //p가 리스트의 머리 부분을 가리키게 함
 
	while(p != NULL) { //p가 NULL이 아닐 동안
 		printf("[ [%d]=%d ] ", i, p->key); //p의 데이터 부분 출력
		p = p->link; //p가 다음 노드를 가리키게 함
		i++; //i 증가
	}

	printf("  items = %d\n", i); 
}








