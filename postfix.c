/*
 ============================================================================
 Name        : postfix.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STACK_SIZE 10
#define MAX_EXPRESSION_SIZE 20


typedef enum{
	lparen = 0,  //lparen은 (
	rparen = 9, //rparen은 )
	times = 7, //times 곱하기
	divide = 6, //divide 나누기
	plus = 5, //plus 더하기
	minus = 4, //minus 빼기
	operand = 1 //피연산자 1
} precedence;


char infixExp[MAX_EXPRESSION_SIZE]; //중위 표기식
char postfixExp[MAX_EXPRESSION_SIZE]; //후위 표기식
char postfixStack[MAX_STACK_SIZE]; //후위 연산 담을 스택
int evalStack[MAX_STACK_SIZE]; //계산 결과를 담을 스택

int postfixStackTop = -1; //후위 연산 스택의 top인덱스
int evalStackTop = -1; //결과를 담을 스택의 top인덱스

int evalResult = 0;	//결과값 초기화

void postfixPush(char x) //postfix 스택에 문자 x 넣기
{
	postfixStack[++postfixStackTop] = x;
}

char postfixPop() //postfix 스택에서  문자 Pop
{
    char x;
    if(postfixStackTop == -1) //posfixStackTop이 -1이면(모든 문자가 스택에서 다 나왔을 때)
        return '\0'; //널문자 리턴
    else { //그렇지 않다면
    	x = postfixStack[postfixStackTop--]; //x에 postfixStack의 postfixStackTop번째 배열에 저장된 문자 저장
    }
    return x; //문자가 저장된 x 리턴
}


void evalPush(int x)
{
    evalStack[++evalStackTop] = x; //evalStack의 evalStackTop번째에 x저장
}

int evalPop()
{
    if(evalStackTop == -1) //evalStackTop==-1이라면
        return -1; //더 이상 Pop할 데이터 없음
    else //그렇지 않다면
        return evalStack[evalStackTop--]; //evalStack[evalStackTop]번째 배열 요소 리턴
}


void getInfix()
{
    printf("Type the expression >>> "); //중위표기법으로 수식 입력
    scanf("%s",infixExp); //입력된 수식이 infixExp에 저장됨
}

precedence getToken(char symbol)
{
	switch(symbol) {
	case '(' : return lparen;
	case ')' : return rparen;
	case '+' : return plus;
	case '-' : return minus;
	case '/' : return divide;
	case '*' : return times;
	default : return operand;
	}

}

precedence getPriority(char x)
{
	return getToken(x); //연산자의 우선순위 리턴
}


void charCat(char* c)
{
	if (postfixExp == '\0') //postfixExp가 널문자라면
		strncpy(postfixExp, c, 1); //postfixExp에 c가 참조하는 값을 1바이트 복사
	else //널문자가 아니라면
		strncat(postfixExp, c, 1); //postfixExp뒤에 c가 참조하는 값을 1바이트 붙임
}


void toPostfix()
{

	char *exp = infixExp; //infixExp를 참조하는 char형 변수 exp //1*2+3 ->12*3+
	char x; //문자를 담을 char형 변수 x
	int i=0; //배열 인덱스

	while(*exp != '\0')  //exp가  참조하는 값이 널문자일 때까지
	{
		if(getPriority(*exp)==1) //숫자라면
		{
			postfixExp[i]=*exp; //후위표기식에 그냥 넣기
			i++;
			exp++;
		}
		else //연산자라면
		{
			switch(*exp) //연산자에 따라 스택에 대한 연산이 달라지게 하는 switch문
			{
			case '(': //문자가 '('라면
				postfixPush(*exp); //postfixStack에 넣기
				exp++;
				break;
			case ')': //문자가 ')'라면
				while(1) //반복
				{
					x=postfixPop(); //postfixStack에서
					if(x=='(') //x가 '('일 때까지 문자 Pop
						break; //'('만나면 break;
					postfixExp[i++]=x; //x를 후위표기식에 저장
				}
				break;
			case '*': case '/': //*,/,+.-라면
			case '+': case '-':
				if(getPriority(postfixStack[postfixStackTop])>getPriority(*exp)) //우선 순위 비교. 만약 스택에 있는 연산자의 우선순위가 더 높다면
				{
					while(postfixStackTop!=-1) //스택에 있던 모든 연산자가 다 빠져나올 때까지
					{
						x=postfixPop(); //스택에서 우선순위 높은 연산자 빼서 반환한 값 x에 저장
						postfixExp[i++]=x; //후위표기식에 연산자 넣기
					}
				}
				else //아니라면
				{
					postfixPush(*exp); //스택에 exp[i]넣기
					exp++;
				}
			}
		}
	}
	while(postfixStackTop!=-1) //postfixStackTop이 -1일 때까지
		postfixExp[i++]=postfixPop(); //후위증가식에 스택에 남아있는 연산자 넣기

}
void debug()
{
	printf("\n---DEBUG\n");
	printf("infixExp =  %s\n", infixExp);
	printf("postExp =  %s\n", postfixExp);
	printf("eval result = %d\n", evalResult);

	printf("postfixStack : ");
	for(int i = 0; i < MAX_STACK_SIZE; i++)
		printf("%c  ", postfixStack[i]);

	printf("\n");
	printf("complete!><\n");

}

void reset()
{
	infixExp[0] = '\0';
	postfixExp[0] = '\0';

	for(int i = 0; i < MAX_STACK_SIZE; i++)
		postfixStack[i] = '\0';

	postfixStackTop = -1;
	evalStackTop = -1;
	evalResult = 0;
}

void evaluation()
{
	int i;
	int a,b;
	int explen=strlen(postfixExp);
	for(i=0;i<explen;i++)
	{
		if(getPriority(postfixExp[i])==1) //숫자라면
		{
			evalPush(postfixExp[i]-'0');
		}
		else
		{
			a=evalPop();
			b=evalPop();

			switch(postfixExp[i])
			{
			case '*':
				evalPush(a*b);
				break;
			case '/':
				evalPush(a/b);
				break;
			case '+':
				evalPush(a+b);
				break;
			case '-':
				evalPush(a-b);
			    break;
			}
		}
	}
	evalResult=evalPop();
}


int main()
{
	char command;

	do{
		printf("----------------------------------------------------------------\n");
		printf("               Infix to Postfix, then Evaluation               \n");
		printf("----------------------------------------------------------------\n");
		printf(" Infix=i,   Postfix=p,  Eval=e,   Debug=d,   Reset=r,   Quit=q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'i': case 'I':
			getInfix();
			break;
		case 'p': case 'P':
			toPostfix();
			break;
		case 'e': case 'E':
			evaluation();
			break;
		case 'd': case 'D':
			debug();
			break;
		case 'r': case 'R':
			reset();
			break;
		case 'q': case 'Q':
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 0;

}
