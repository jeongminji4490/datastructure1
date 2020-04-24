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
	lparen = 0,  //lparen�� (
	rparen = 9, //rparen�� )
	times = 7, //times ���ϱ�
	divide = 6, //divide ������
	plus = 5, //plus ���ϱ�
	minus = 4, //minus ����
	operand = 1 //�ǿ����� 1
} precedence;


char infixExp[MAX_EXPRESSION_SIZE]; //���� ǥ���
char postfixExp[MAX_EXPRESSION_SIZE]; //���� ǥ���
char postfixStack[MAX_STACK_SIZE]; //���� ���� ���� ����
int evalStack[MAX_STACK_SIZE]; //��� ����� ���� ����

int postfixStackTop = -1; //���� ���� ������ top�ε���
int evalStackTop = -1; //����� ���� ������ top�ε���

int evalResult = 0;	//����� �ʱ�ȭ

void postfixPush(char x) //postfix ���ÿ� ���� x �ֱ�
{
	postfixStack[++postfixStackTop] = x;
}

char postfixPop() //postfix ���ÿ���  ���� Pop
{
    char x;
    if(postfixStackTop == -1) //posfixStackTop�� -1�̸�(��� ���ڰ� ���ÿ��� �� ������ ��)
        return '\0'; //�ι��� ����
    else { //�׷��� �ʴٸ�
    	x = postfixStack[postfixStackTop--]; //x�� postfixStack�� postfixStackTop��° �迭�� ����� ���� ����
    }
    return x; //���ڰ� ����� x ����
}


void evalPush(int x)
{
    evalStack[++evalStackTop] = x; //evalStack�� evalStackTop��°�� x����
}

int evalPop()
{
    if(evalStackTop == -1) //evalStackTop==-1�̶��
        return -1; //�� �̻� Pop�� ������ ����
    else //�׷��� �ʴٸ�
        return evalStack[evalStackTop--]; //evalStack[evalStackTop]��° �迭 ��� ����
}


void getInfix()
{
    printf("Type the expression >>> "); //����ǥ������� ���� �Է�
    scanf("%s",infixExp); //�Էµ� ������ infixExp�� �����
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
	return getToken(x); //�������� �켱���� ����
}


void charCat(char* c)
{
	if (postfixExp == '\0') //postfixExp�� �ι��ڶ��
		strncpy(postfixExp, c, 1); //postfixExp�� c�� �����ϴ� ���� 1����Ʈ ����
	else //�ι��ڰ� �ƴ϶��
		strncat(postfixExp, c, 1); //postfixExp�ڿ� c�� �����ϴ� ���� 1����Ʈ ����
}


void toPostfix()
{

	char *exp = infixExp; //infixExp�� �����ϴ� char�� ���� exp //1*2+3 ->12*3+
	char x; //���ڸ� ���� char�� ���� x
	int i=0; //�迭 �ε���

	while(*exp != '\0')  //exp��  �����ϴ� ���� �ι����� ������
	{
		if(getPriority(*exp)==1) //���ڶ��
		{
			postfixExp[i]=*exp; //����ǥ��Ŀ� �׳� �ֱ�
			i++;
			exp++;
		}
		else //�����ڶ��
		{
			switch(*exp) //�����ڿ� ���� ���ÿ� ���� ������ �޶����� �ϴ� switch��
			{
			case '(': //���ڰ� '('���
				postfixPush(*exp); //postfixStack�� �ֱ�
				exp++;
				break;
			case ')': //���ڰ� ')'���
				while(1) //�ݺ�
				{
					x=postfixPop(); //postfixStack����
					if(x=='(') //x�� '('�� ������ ���� Pop
						break; //'('������ break;
					postfixExp[i++]=x; //x�� ����ǥ��Ŀ� ����
				}
				break;
			case '*': case '/': //*,/,+.-���
			case '+': case '-':
				if(getPriority(postfixStack[postfixStackTop])>getPriority(*exp)) //�켱 ���� ��. ���� ���ÿ� �ִ� �������� �켱������ �� ���ٸ�
				{
					while(postfixStackTop!=-1) //���ÿ� �ִ� ��� �����ڰ� �� �������� ������
					{
						x=postfixPop(); //���ÿ��� �켱���� ���� ������ ���� ��ȯ�� �� x�� ����
						postfixExp[i++]=x; //����ǥ��Ŀ� ������ �ֱ�
					}
				}
				else //�ƴ϶��
				{
					postfixPush(*exp); //���ÿ� exp[i]�ֱ�
					exp++;
				}
			}
		}
	}
	while(postfixStackTop!=-1) //postfixStackTop�� -1�� ������
		postfixExp[i++]=postfixPop(); //���������Ŀ� ���ÿ� �����ִ� ������ �ֱ�

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
		if(getPriority(postfixExp[i])==1) //���ڶ��
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
