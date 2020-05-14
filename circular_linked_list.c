#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int key; //데이터 값
	struct Node* llink; //왼쪽 링크
	struct Node* rlink; //오른쪽 링크
} listNode; //노드


int initialize(listNode** h); //초기화
int freeList(listNode* h); //리스트에 메모리 해제
int insertLast(listNode* h, int key); //리스트의 마지막 부분에 노드 삽입
int deleteLast(listNode* h); //리스트의 마지막 노드 삭제
int insertFirst(listNode* h, int key); //리스트의 첫번째 부분에 노드 삽입
int deleteFirst(listNode* h); //리스트의 첫번째 노드 삭제
int invertList(listNode* h); //리스트 역순으로 바꾸기

int insertNode(listNode* h, int key); //노드 크기순으로 삽입
int deleteNode(listNode* h, int key); //해당하는 노드 삭제

void printList(listNode* h); //리스트의 모든 노드들의 데이터 출력



int main()
{
	char command; //switch문을 실행하는데 사용되는 char형 변수
	int key; //int형 데이터 값
	listNode* headnode=NULL; //headnode가 NULL상태가 되게 함

	printf("소프트웨어학과 2018038090 정민지\n");
	do{
		printf("----------------------------------------------------------------\n");
		printf("                  Doubly Circular Linked List                   \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = "); 
		scanf(" %c", &command); //command입력

		switch(command) {
		case 'z': case 'Z': //'z' 또는 'Z' 일 경우
			initialize(&headnode); //initialize 호출
			break;
		case 'p': case 'P': //'p' 또는 'P' 일 경우
			printList(headnode); //printList 호출
			break;
		case 'i': case 'I': //'p' 또는 'P' 일 경우
			printf("Your Key = ");  
			scanf("%d", &key); //데이터 입력
			insertNode(headnode, key); //insertNode 호출
			break;
		case 'd': case 'D': //'p' 또는 'P' 일 경우
			printf("Your Key = ");
			scanf("%d", &key); //데이터 입력
			deleteNode(headnode, key); //deleteNode 호출
			break;
		case 'n': case 'N': //'p' 또는 'P' 일 경우
			printf("Your Key = ");
			scanf("%d", &key); //데이터 입력
			insertLast(headnode, key); //insertNode 호출
			break;
		case 'e': case 'E': //'p' 또는 'P' 일 경우
			deleteLast(headnode); //deleteLast 호출
			break;
		case 'f': case 'F': //'p' 또는 'P' 일 경우
			printf("Your Key = ");
			scanf("%d", &key); //데이터 입력
			insertFirst(headnode, key); //insertFirst 호출
			break;
		case 't': case 'T': //'p' 또는 'P' 일 경우
			deleteFirst(headnode); //deleteFirst 호출
			break;
		case 'r': case 'R': //'p' 또는 'P' 일 경우
			invertList(headnode); //invertList 호출
			break;
		case 'q': case 'Q': //'p' 또는 'P' 일 경우
			freeList(headnode); //freeList 호출
			break;
		default: //command가 위의 어느 문자에도 해당하지 않는다면
			printf("\n       >>>>>   Concentration!!   <<<<<     \n"); //오류메세지 출력
			break;
		}

	}while(command != 'q' && command != 'Q'); //command가 'q' 또는 'Q'가 아닌 동안 switch문 반복

	return 1; //프로그램 종료
}


int initialize(listNode** h) {

	if(*h != NULL) //*h가 NULL상태가 아니라면
		freeList(*h); //h에 할당된 메모리 해제

	*h = (listNode*)malloc(sizeof(listNode)); //*h에 메모리 할당
	(*h)->rlink = *h; //(*h)->rlink가 *h를 가리키게 함
	(*h)->llink = *h; //(*h)->rlink가 *h를 가리키게 함
	(*h)->key = -9999; //*h의 key에 -9999저장
	return 1;
}


int freeList(listNode* h){

  listNode* fnode=h->rlink; //fnode가 h->rlink가 가리키는 노드를 가리키게 함
  listNode* nfnode=fnode->rlink; //nfnode가 fnode의 다음에 있는 노드를 가리키게 함

  if(fnode->rlink==h) //리스트에 h를 제외하고 노드가 하나 남아있을 경우
  {
    h->rlink=h; //h의 오른쪽 링크가 자기 자신을 가리키게 함
    h->llink=h; //h의 왼쪽 링크가 자기 자신을 가리키게 함
    free(fnode); //fnode에 할당된 메모리 해제
    free(nfnode); //nfnode에 할당된 메모리 해제
    return 0;
  }
  else 
  {
    deleteFirst(h); //리스트의 머리 부분부터 노드 삭제
    free(h); //h에 할당된 메모리 해제
  }

	return 0;
}



void printList(listNode* h) {
	int i = 0; 
	listNode* p;

	printf("\n---PRINT\n");

	if(h == NULL) { //h가 NULL상태라면
		printf("Nothing to print....\n"); //프린트할 것이 없다는 메세지 출력
		return;
	}

	p = h->rlink; //p가 h의 오른쪽 링크가 가리키는 노드를 가리키게 함

	while(p != NULL && p != h) {  //p가 NULL상태가 아니고 h를 가리키지 않을 경우
		printf("[ [%d]=%d ] ", i, p->key); //0번째 노드부터 데이터 출력
		p = p->rlink; //p를 다음 노드로 이동시킴
		i++; //i증가
	}
	printf("  items = %d\n", i);


	/* print addresses */
	printf("\n---checking addresses of links\n");
	printf("-------------------------------\n");
	printf("head node: [llink]=%p, [head]=%p, [rlink]=%p\n", h->llink, h, h->rlink); //h의 오른쪽 링크와 왼쪽 링크가 가리키고 있는 노드와 h의 주솟값 출력

	i = 0;
	p = h->rlink; //p가 h의 오른쪽 링크가 가리키는 노드를 가리키게 함
	while(p != NULL && p != h) { //p가 NULL상태가 아니고 h를 가리키지 않을 경우
		printf("[ [%d]=%d ] [llink]=%p, [node]=%p, [rlink]=%p\n", i, p->key, p->llink, p, p->rlink); //p가 가리키는 노드의 데이터 값,왼쪽 링크와 오른쪽 링크가 가리키는 노드의 주솟값 출력
		p = p->rlink; //p를 다음 노드로 이동시킴
		i++; //i증가
	}

}


int insertLast(listNode* h, int key) {

	listNode* node=(listNode*)malloc(sizeof(listNode)); //노드 생성
    node->key=key; //노드에 데이터 저장

	if(h->rlink == h && h->llink == h) //리스트에 headnode밖에 없을 경우
    {
        h->llink=node; //h의 왼쪽 링크가 노드를 가리킴
        h->rlink=node; //h의 오른족 링크가 노드를 가리킴
        node->llink=h; //노드의 왼쪽 링크가 h를 가리킴
        node->rlink=h; //노드의 오른쪽 링크가 h를 가리킴
		return 1;
    }
	h->llink->rlink=node; //h의 왼쪽 링크가 가리키는 노드의 오른쪽 링크가 생성된 노드를 가리키게 함
	node->llink=h->llink; //생성된 노드의 왼쪽 링크가 h의 왼쪽 링크가 가리키는 노드를 가리키게 함
	node->rlink=h; //생성된 노드의 오른쪽 링크가 h를 가리키게 함
	h->llink=node; //h의 왼쪽 링크가 노드를 가리키게 함
	return 1;
}


int deleteLast(listNode* h) { //하나 남은 노드를 삭제할 경우도 고려해야 함

	if(h->rlink==h && h->llink==h) //리스트에 headnode밖에 없을 경우
	{
		printf("삭제할 노드가 없습니다...!\n");
		return 1;
	}

	listNode* dnode=h->llink; //삭제할 마지막 노드를 가리킴
	listNode* x=h->llink->llink; //삭제할 노드의 이전 노드를 가리킴

	if(x!=h) //x가 h를 가리키지 않을 경우
	{
		h->llink=x; //h의 왼쪽 링크가 x를 가리키게 함
	    x->rlink=h;  //x의 오른쪽 링크가 h를 가리키게 함
	    dnode->rlink=NULL; //마지막 노드의 오른쪽 링크가 NULL상태가 되게 함
	    dnode->llink=NULL; //마지막 노드의 왼쪽 링크가 NULL상태가 되게 함
	    free(dnode); //마지막 노드에 할당된 메모리 해제
	}
	else //x==h, headnode를 제외하고 리스트에 노드가 하나 남아있을 경우
	{
		dnode->rlink=NULL; //마지막 노드의 오른쪽 링크가 NULL상태가 되게 함
		dnode->llink=NULL; //마지막 노드의 왼쪽 링크가 NULL상태가 되게 함
		free(dnode); //마지막 노드에 할당된 메모리 해제
		h->llink=h; //h의 왼쪽 링크가 자기 자신을 가리키게 함
		h->rlink=h; //h의 오른쪽 링크가 자기 자신을 가리키게 함
	}
	
	
	return 1;
}



int insertFirst(listNode* h, int key) {

    listNode* node=(listNode*)malloc(sizeof(listNode)); //노드 생성
    node->key=key; //노드에 데이터 저장

    if(h->rlink == h && h->llink == h) //리스트에 headnode밖에 없을 경우
    {
        h->llink=node; //h의 왼쪽 링크가 노드를 가리킴
        h->rlink=node; //h의 오른족 링크가 노드를 가리킴
        node->llink=h; //노드의 왼쪽 링크가 h를 가리킴
        node->rlink=h; //노드의 오른쪽 링크가 h를 가리킴
		return 1;
    }

	//리스트의 머리 부분에 노드를 추가하는 것이기 때문에 h->llink는 그대로
    h->rlink->llink=node; //h의 오른쪽 링크가 가리키는 노드의 왼족 링크가 생성된 노드를 가리키게 함
	node->rlink=h->rlink; //생성된 노드의 오른쪽 링크가 h의 오른쪽 링크를 가리키게 함
    node->llink=h; //생성된 노드의 왼쪽 링크가 h를 가리키게 함
	h->rlink=node; //h의 오른쪽 링크가 생성된 노드를 가리키게 함
  
	return 1;
}


int deleteFirst(listNode* h) { //하나 남은 노드를 삭제할 경우도 고려해야 함

	if(h->rlink==h && h->llink==h) //리스트에 headnode밖에 없을 경우
	{
		printf("삭제할 노드가 없습니다...!\n");
		return 1;
	}

	listNode* dnode=h->rlink; //삭제할 첫번째 노드를 가리킴
	listNode* x=h->rlink->rlink; //삭제할 첫번째 노드의 다음 노드를 가리킴

	if(x!=h) //x가 h를 가리키지 않을 경우 
	{
		h->rlink=x; //h의 오른쪽 링크가 x를 가리키게 함
	    x->llink=h; //x의 왼쪽 링크가 h를 가리키게 함
	    dnode->rlink=NULL; //첫번째 노드의 오른쪽 링크가 NULL상태가 되게 함
	    dnode->llink=NULL; //첫번째 노드의 왼쪽 링크가 NULL상태가 되게 함
	    free(dnode); //첫번째 노드 삭제
	}
	else //x==h, headnode를 제외하고 리스트에 노드가 하나 남아있을 경우
	{
		dnode->rlink=NULL; //노드의 오른쪽 링크가 NULL상태가 되게 함
		dnode->llink=NULL; //노드의 왼쪽 링크가 NULL상태가 되게 함
		free(dnode); //노드 삭제
		h->llink=h; //h의 왼쪽 링크가 자기자신을 가리키게 함
		h->rlink=h; //h의 오른쪽 링크가 자기자신을 가리키게 함
	}
	
	
	return 1;

}


int invertList(listNode* h) {

	if(h->llink==h && h->rlink==NULL) { //리스트에 headnode밖에 없을 경우
		printf("nothing to invert...\n"); //invert할 노드가 리스트에 존재하지 않는다는 메세지 출력
		return 0;
	}

	listNode *n = h->rlink; //노드 n가 h의 오른쪽 링크가 가리키는 노드를 가리키게 함
	listNode *trail = NULL; //노드 trail이 NULL상태가 되게 함
	listNode *middle = h; //노드 middle이 h를 가리키게 함

	while(n !=h){ //n이 h를 가리키지 않는다면 while문 반복
		trail = middle; //trail이 middle을 가리키게 함
		middle = n; //middle이 n을 가리키게 함
		n = n->rlink; //n이 다음 노드를 가리키게 함
		middle->rlink = trail; //middle의 오른쪽 링크가 trail을 가리키게 함
        middle->llink=n; //middle의 왼쪽 링크가 n을 가리키게 함
		
		if(n!=h) //n이 h를 가리키지 않는다면(n==h일 경우 h의 왼쪽/오른쪽 링크가 이미 역순으로 바뀐 후임)
        {
			h->rlink=h->rlink->rlink; //h의 오른쪽 링크가 h의 오른쪽 링크가 가리키는 노드의 다음 노드를 가리키게 함
			h->llink=h->llink->llink; //h의 왼쪽 링크가 h의 왼쪽 링크가 가리키는 노드의 이전 노드를 가리키게 함
        }
	}
	h->rlink=middle; //h의 오른쪽 링크가 middle이 가리키는 노드를 가리키게 함

	return 0;
}


//큰 데이터가 뒤로 가도록
int insertNode(listNode* h, int key) {

	if(key<h->rlink->key || (h->rlink == h && h->llink == h))//key값이 리스트의 첫번째 노드의 key값보다 작거나, 리스트에 headnode만 존재할 경우
	{
		insertFirst(h,key); //insertFirst함수 호출하여 리스트의 머리 부분에 노드 삽입
		return 0;
	}
	else if(key>h->llink->key) //key값이 리스트의 마지막 노드의 key값보다 크다면
	{
		insertLast(h,key); //insertLast함수 호출하여 리스트의 마지막 부분에 노드 삽입
		return 0;
	}
	else //위의 경우 중 어느 경우에도 해당되지 않는다면
	{
		listNode* prev=h->rlink->rlink; //prev가 h의 오른쪽 링크가 가리키는 노드의 다음 노드를 가리키게 함
		listNode* r=h->rlink; //r이 h의 오른쪽 링크가 가리키는 노드를 가리키게 함
		listNode* node=(listNode*)malloc(sizeof(listNode)); //노드 생성
		node->key=key; //노드에 데이터 저장

		while(1) 
		{
			if(node->key<prev->key) //생성된 노드의 key값이 prev의 key값보다 작을 경우
			{
				prev->llink=node; //prev의 왼쪽 링크가 생성된 노드를 가리키게 함
				node->rlink=prev; //생성된 노드의 오른쪽 링크가 prev가 가리키는 노드를 가리키게 함
				r->rlink=node; //r의 오른쪽 링크가 노드를 가리키게 함
				node->llink=r; //노드의 왼쪽 링크가 r을 가리키게 함
				break;
			}
			else//(node->key>h->rlink->rlink->key)
			{
				prev=prev->rlink; //prev를 다음 노드로 이동시킴
				r=r->rlink; //r을 다음 노드로 이동시킴
		    }
		
		}
    }
	return 0;
}


int deleteNode(listNode* h, int key) {

	if(key==h->rlink->key) //key값이 h의 오른쪽 링크가 가리키는 노드의 key값과 같다면
	{
		deleteFirst(h); //deleteFirst함수 호출하여 첫번째 노드 삭제
		return 0;
	}
	else if(key==h->llink->key) //key값이 h의 왼쪽 링크가 가리키는 노드의 key값과 같다면
	{
		deleteLast(h); //deleteLast함수 호출하여 마지막 노드 삭제
		return 0;
	}
	else
	{
		listNode* prev=h->rlink; //prev가 h의 오른쪽 링크가 가리키는 노드를 가리키게 함
		listNode* x=prev->rlink; //x기 prev가 가리키는 노드의 다음 노드를 가리키게 함
		listNode* r=x->rlink; //r이 x의 오른쪽 링크가 가리키는 노드를 가리키게 함

		while(1)
		{
			if(key==x->key) //key값이 x가 가리키는 노드의 key값과 같다면
			{
				x->rlink=NULL; //x의 오른쪽 링크가 NULL상태가 되게 함
				x->llink=NULL; //x의 왼쪽 링크가 NULL상태가 되게 함
				prev->rlink=r; //prev의 오른쪽 링크가 r을 가리키게 함
				r->llink=prev; //r의 왼쪽 링크가 prev를 가리키게 함
				free(x); //x가 가리키는 노드에 할당된 메모리 해제
				break;
			}
			else //key값이 x가 가리키는 노드의 key값과 다르다면
			{
				prev=prev->rlink; //prev를 다음 노드로 이동시킴
				x=x->rlink; //x를 다음 노드로 이동시킴
				r=r->rlink; //r을 다음 노드로 이동시킴

				if(r==h) //r이 h를 가리키고 있다면
				{
					printf("해당하는 노드가 리스트에 존재하지 않습니다..!\n");
					break;
				}
			}
			
		}
	}
	
	return 0;
}

