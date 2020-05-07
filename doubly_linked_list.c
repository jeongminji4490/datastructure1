#include<stdio.h>
#include<stdlib.h>

//이중연결리스트 프로그래밍//
typedef struct Node {
	int key; //데이터
	struct Node* llink; //왼쪽 링크
	struct Node* rlink; //오른쪽 링크
} listNode; //listNode 구조체



typedef struct Head { //리스트의 머리부분을 가리키는 
	struct Node* first; //링크(포인터 부분)
}headNode; //headNode 구조체


int initialize(headNode** h); //headNode 초기화

int freeList(headNode* h); //list초기화 

int insertNode(headNode* h, int key); //노드 삽입
int insertLast(headNode* h, int key); //노드 마지막 삽입
int insertFirst(headNode* h, int key); //노드 첫번째 삽입
int deleteNode(headNode* h, int key); //노드 삭제
int deleteLast(headNode* h); //마지막 노드 삭제
int deleteFirst(headNode* h); //첫번째 노드 삭제
int invertList(headNode* h); //리스트 역순으로 바꾸기

void printList(headNode* h); //리스트의 데이터 출력

 
int main()
{
	char command; //switch문의 변수가 될 char형 변수 command
	int key; //데이터 값
	headNode* headnode=NULL; //headnode가 NULL 상태가 되게 함

	printf("소프트웨어학과 2018038090 정민지\n");

	do{
		printf("----------------------------------------------------------------\n");
		printf("                     Doubly Linked  List                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command); //command 입력 

		switch(command) {
		case 'z': case 'Z': //command가 z 또는 Z이면
			initialize(&headnode); //리스트 초기화
			break;
		case 'p': case 'P': //command가 p 또는 P이면
			printList(headnode); //리스트 출력
			break;
		case 'i': case 'I': //command가 i 또는 I이면
			printf("Your Key = ");  
			scanf("%d", &key); //데이터 입력
			insertNode(headnode, key); //입력한 데이터 node에 삽입
			break;
		case 'd': case 'D': //command가 d 또는 D이면
			printf("Your Key = "); 
			scanf("%d", &key); //데이터 입력
			deleteNode(headnode, key); //입력한 데이터 삭제
			break;
		case 'n': case 'N': //command가 n 또는 N이면
			printf("Your Key = ");
			scanf("%d", &key); //데이터 입력
			insertLast(headnode, key); //마지막 노드에 해당 데이터 삽입
			break;
		case 'e': case 'E': //command가 e 또는 E이면
			deleteLast(headnode); //마지막 노드 삭제
			break;
		case 'f': case 'F': //command가 f 또는 F이면
			printf("Your Key = ");
			scanf("%d", &key); //데이터 입력
			insertFirst(headnode, key); //리스트의 맨 처음에 있는 노드에 해당 데이터 삽입
			break;
		case 't': case 'T': //command가 t 또는 T이면
			deleteFirst(headnode); //리스트의 맨 처음에 있는 노드 삭제
			break;
		case 'r': case 'R': //command가 r 또는 R이면
			invertList(headnode); //리스트 역순으로 바꾸기
			break;
		case 'q': case 'Q': //command가 q 또는 Q이면
			freeList(headnode); //리스트에 할당된 메모리 해제
			break;
		default: //command가 어느것에도 해당하지 않으면
			printf("\n       >>>>>   Concentration!!   <<<<<     \n"); //오류메세지 출력
			break;
		}

	}while(command != 'q' && command != 'Q'); //command가 q나 Q가 아닐 때까지 반복

	return 1; //프로그램 종료
}


int initialize(headNode** h) {

    if(*h!=NULL) //리스트가 비어있지 않다면
    freeList(*h); //리스트 메모리 해제

    *h=(headNode*)malloc(sizeof(headNode*)); //h에 메모리 할당
    (*h)->first=NULL; //h->first를 NULL로 지정

	return 0;
}

int freeList(headNode* h){

    listNode* p = h->first; //listNode형 변수 p가 리스트의 첫번째 노드를 가리키게 함
    listNode* prev = NULL; //listNode형 변수 prev는 NULL
    
	while(p != NULL) { //p가 NULL 상태가 아니라면
		prev = p; //prev가 p를 가리키게 함
		p = p->rlink; //p가 다음 노드를 가리키게 함
		free(prev); //prev가 가리키고 있는 노드(p가 이동 전에 가리키고 있던 노드) 해제
	}
   
	free(h); //headNode 해제

	return 0;
}


void printList(headNode* h) {
	int i = 0; //반복문을 위한 변수 i
	listNode* p; //노드 p

	printf("\n---PRINT\n");

	if(h->first == NULL) { //리스트가 비어있다면
		printf("Nothing to print....\n"); //출력할 게 없다는 메세지 출력
		return;
	}

	p = h->first; //노드 p가 리스트의 첫번째 노드를 가리키게 함

	while(p != NULL) { //리스트의 마지막 노드까지 반복
		printf("[ [%d]=%d ] ", i, p->key); //p가 가리키는 노드의 key출력
		p = p->rlink; //p를 다음 노드로 이동
		i++; //변수 i증가
	}

	printf("  items = %d\n", i); //리스트 내에 있는 데이터의 갯수 출력
}


int insertLast(headNode* h, int key) { //리스트에 노드가 존재하지 않을때,리스트에 노드가 존재할 때의 2가지 케이스로 나누기

    if(h->first==NULL) //리스트에 노드가 존재하지 않을 때
	{
		insertFirst(h,key); //InsertFirst함수 호출
		return 0;
	}

    listNode* lf=h->first; //리스트의 첫번째 노드를 가리키는 lf

    while (1) //반복문
    {
        if(h->first->rlink==NULL) //탈출조건: first의 rlink가 NULL이면(h->first가 마지막 노드를 가리키면)
        break; //반복문 탈출

        h->first=h->first->rlink; //h->first가 다음 노드를 가리키게 함
    }

	
		listNode* node=(listNode*)malloc(sizeof(listNode)); //노드 생성
		node->key=key; //생성된 노드에 데이터 저장
		node->rlink=NULL;

		h->first->rlink=node; //h->first의 오른쪽 link가 노드를 가리키게 함
        node->llink=h->first; //노드의 왼쪽 link가 h->first가 가리키는 노드를 가리키게 함
		h->first=lf;  //h->first를 원래 위치로 되돌림
	
	return 0;
}


int deleteLast(headNode* h) { //리스트에 노드가 존재할 때와 존재하지 않을 때의 두가지 케이스로 나눔

    listNode* lf=h->first; //리스트의 첫번째 노드를 가리키는 lf

    if(h->first==NULL) //리스트에 노드가 존재하지 않을 때
	{
		printf("삭제할 노드가 리스트에 존재하지 않습니다!\n");
		return 0;
	}
	else //리스트에 노드가 존재할 때
	{
		while (1) //반복문
		{
			if(h->first->rlink==NULL) //탈출조건: first의 rlink가 NULL이면(h가 마지막 노드를 가리키면)
			break; //반복문 탈출
			
			h->first=h->first->rlink; //h->first가 다음 노드를 가리키게 함
		}

		listNode* dlnode=h->first; //삭제할 노드(마지막 노드)를 가리키는 노드
		h->first=h->first->llink; //h->first가 왼쪽으로 이동하여 이전의 노드를 가리키게 함
		h->first->rlink=NULL; //h->first의 오른쪽 링크를 NULL상태로 바꿈
		dlnode->llink=NULL; //dlnode가 가리키고 있는 노드의 왼쪽 링크를 NULL상태로 바꿈
		free(dlnode); //dlnode가 가리키고 있던 노드의 메모리 해제
	}
    h->first=lf; //h->first를 원래 위치로 옮김
	return 0;
}



int insertFirst(headNode* h, int key) { //리스트에 노드가 존재할 때와 존재하지 않을 때의 두가지 케이스로 나눔
    
	listNode* node=(listNode*)malloc(sizeof(listNode)); //노드 생성
    node->key=key; //생성된 노드에 데이터 저장

	if(h->first==NULL) //리스트에 노드가 존재하지 않을 때
	{
		h->first=node; //h->first가 노드를 가리키게 함
		node->rlink=NULL; //노드의 오른쪽 link가 NULL상태가 되게 함
		node->llink=NULL; //노드의 왼쪽 link가 NULL상태가 되게 함
	}
	else //리스트에 노드가 존재할 때
    {
		node->llink=NULL; //노드의 왼쪽 link부분을 NULL로 지정
		node->rlink=h->first; //노드의 오른쪽 link부분이 첫번째 노드를 가리키게 함
		h->first->llink=node; //첫번째 노드의 왼쪽 link부분이 노드를 가리키게 함
		h->first=node; //첫번째 노드가 노드를 가리키게 함
	}

	return 0;
}


int deleteFirst(headNode* h) { //리스트에 노드가 존재하지 않을 때와 리스트에 노드가 존재할 때의 두 가지 케이스로 나눔
 
    if(h->first==NULL) //리스트에 노드가 존재하지 않을 때
	{
		printf("삭제할 노드가 리스트에 존재하지 않습니다!\n"); //삭제할 노드가 없다는 메세지 출력
		return 0;
	}
	else //리스트에 노드가 존재할 때
	{
		listNode* dfnode=h->first; //삭제할 노드(첫번째 노드)를 가리키는 노드
		h->first=h->first->rlink; //h->first가 다음 노드를 가리키게 함
		h->first->llink=NULL; //h->first의 왼쪽 링크가 NULL상태가 되게 함
		dfnode->rlink=NULL; //dfnode가 가리키는 노드(첫번째 노드)의 오른쪽 링크가 NULL이 되게 함

		free(dfnode); //dfnode가 가리키는 노드의 메모리 해제
	}
	return 0;
}



int invertList(headNode* h) {
	
	if(h->first == NULL) { //리스트에 노드가 존재하지 않을 때
		printf("nothing to invert...\n"); 
		return 0;
	}

	listNode *n = h->first; //노드 n가 리스트의 머리 부분을 가리키게 함
	listNode *trail = NULL; //노드 trail이 NULL상태가 되게 함
	listNode *middle = NULL; //노드 middle이 NULL상태가 되게 함

	while(n != NULL){ //n이 NULL 상태가 아닌 동안 반복
		trail = middle; //trail이 middle을 가리키게 함
		middle = n; //middle이 n을 가리키게 함
		n = n->rlink; //n이 다음 노드를 가리키게 함
		middle->rlink = trail; //middle의 오른쪽 link가 trail을 가리키게 함
	}

	h->first = middle; //h->first가 middle을 가리키게 함

	return 0;
}


//리스트를 검색하여, 입력받은 key보다 큰 값이 나오는 노드 바로 앞에 삽입
int insertNode(headNode* h, int key) {

      if(h->first==NULL) //리스트에 노드가 존재하지 않을 때
	  {
		  insertFirst(h,key); //insertFirst함수 호출
		  return 0;
	  }

    listNode* lf=h->first; //리스트의 첫번째 노드를 가리키는 lf

    while(h->first->rlink!=NULL) //h->first가 마지막 노드를 가리킬 때까지 반복
    {
        //첫번째 케이스//
        if(h->first->key>key || h->first->key==key) 
        break; //탈출
        //두번째 케이스//
        h->first=h->first->rlink; //h->first가 다음 노드를 가리키도록 이동
    } //중간에 탈출하지 못하고 while의 조건이 끝나서야 탈출한 경우는 h->first가 마지막 노드를 가리킬 때까지 if문의 조건이 충족되지 않았다는 것
	//=생성된 노드의 key값이 리스트 각 노드의 값 중에 제일 크다는 뜻

    if(h->first->llink==NULL) //리스트의 첫번째 부분에 생성된 노드를 삽입해야 하는 경우
    {
        insertFirst(h,key); //insertFirst함수 호출
    }
    else if(h->first->rlink==NULL) //리스트의 마지막 부분에 생성된 노드를 삽입해야 하는 경우 
    {
        insertLast(h,key); //insertLast함수 호출
        h->first=lf; //h->first를 원래 위치로 옮김
    }
    else //리스트의 중간 부분에 생성된 노드를 삽입해야 하는 경우 
    {
		listNode* prev=h->first->llink; //h->first가 가리키는 노드의 이전 노드를 가리키는 노드 prev
		listNode* node=(listNode*)malloc(sizeof(listNode)); //메모리를 동적으로 할당하여 노드 생성
		node->key=key; //노드에 데이터 저장 

		node->rlink=h->first; //노드의 오른쪽 link가 h->first가 가리키는 노드를 가리키게 함
		node->llink=prev; //노드의 왼쪽 노드가 prev가 가리키는 노드를 가리키게 함
		prev->rlink=node; //prev의 오른쪽 link가 노드를 가리키게 함
        h->first=lf; //h->first를 원래 위치로 옮김
    }
    return 0;
}



int deleteNode(headNode* h, int key) {

  listNode* x; //노드를 삭제하기 위한 노드 x를 동적으로 메모리를 할당하여 생성
  listNode* trail; //삭제하려는 노드의 선행 노드를 가리키기 위한 변수
  x=h->first; //x가 리스트의 머리 부분을 가리키게함
  trail=h->first; //trail이 리스트의 머리 부분을 가리키게 함

	while(1) 
	{
		if(x==NULL) //리스트에 노드가 존재하지 않는다면
		{
			printf("삭제할 데이터가 리스트에 존재하지 않습니다.\n"); 
			return 0;
		}
		if(x->key==key) //x의 데이터가 삭제하려는 데이터와 일치한다면
		break; //반복문 빠져나오기
		
		trail=x; //선행 노드가 x(삭제하려는 노드)를 가리키게 하고
		x=x->rlink; //x는 다음 노드를 가리킴
	}
	if(x==h->first) //x가 리스트의 머리 부분과 같다면
	{
		h->first=h->first->rlink; //head포인터를 다음 노드로 이동
		free(x); //x메모리 해제
	}
	else //그렇지 않다면
	{
		trail->rlink=x->rlink; //trail의 link 부분이 x가 가리키는 노드의 다음 노드를 가리키게함 
		free(x); //x메모리 해제
	}

	return 0;
}