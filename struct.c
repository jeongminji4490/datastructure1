/*
 ============================================================================
 Name        : struct.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

struct student1{ //student1 구조체
	char lastName; //char 변수
	int studentId; //int형 변수
	char grade; //char형 변수
};

typedef struct { //typedef 선언을 한 student2 구조체-main에서 선언할 때 struct 선언 필요없음
	char lastName; //char형 변수
	int studentId; //int형 변수
	char grade; //char형 변수
}student2; //typedef 선언한 경우 구조체 끝에 변수명 선언.

int main(void) {

	struct student1 st1={'A',100,'A'}; //student 구조체 변수 st1 선언과 동시에 구조체 멤버 초기화

	printf("st1.lastName=%c\n",st1.lastName); //str1의 lastName 출력
	printf("st1.studentId=%d\n",st1.studentId); //str1의 studentId 출력
	printf("st1.grade=%c\n",st1.grade); //str1의 grade 출력

	student2 st2={'B',200,'B'}; //student2 구조체 변수 st2 선언과 동시에 구조체 멤버 초기화

	printf("\nst2.lastName=%c\n",st2.lastName); //str2의 lastName 출력
	printf("st2.studentId=%d\n",st2.studentId); //str2의 studentId 출력
	printf("st2.grade=%c\n",st2.grade); //str2의 grade 출력

	student2 st3; //student2 구조체 변수 st3 선언

	st3=st2; //st3을 st2로 치환

	printf("\nst3.lastName=%c\n",st3.lastName); //str3의 lastName 출력
	printf("st3.studentId=%d\n",st3.studentId); //str3의 studentId 출력
	printf("st3.grade=%c\n",st3.grade); //str3의 grade 출력

	/*equality test*/ //st3와 st2이 똑같은지 테스트, 이 부분은 에러
	/*if(st3==st2)
		printf("equal\n"); //같으면 equal 출력
	else
		printf("not equal\n"); //다르면 not equal 출력
*/
	return 0;
}
