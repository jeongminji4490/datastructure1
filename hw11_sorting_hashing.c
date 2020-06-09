/*
 * hw5-sorting.c
 *
 *  Created on: May 22, 2019
 *
 *  Homework 5: Sorting & Hashing
 *  Department of Computer Science at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE			13	/* prime number */
#define MAX_HASH_TABLE_SIZE 	MAX_ARRAY_SIZE

/*필요에 따라 함수 추가 가능*/
int initialize(int **a); //초기화
int freeArray(int *a); //배열에 할당된 메모리 해제
void printArray(int *a); //배열 출력

int selectionSort(int *a); //선택정렬
int insertionSort(int *a); //삽입정렬
int bubbleSort(int *a); //버블정렬
int shellSort(int *a); //셀 정렬
/* recursive function으로 구현 */
int quickSort(int *a, int n); //퀵 정렬


/* hash code generator, key % MAX_HASH_TABLE_SIZE */
int hashCode(int key); 

/* array a에 대한 hash table을 만든다. */
int hashing(int *a, int **ht);

/* hash table에서 key를 찾아 hash table의 index return */
int search(int *ht, int key);


int main()
{
	char command; //switch문의 변수가 될 char형 변수 command 
	int *array = NULL; //int형 포인터 array가 NULL상태가 되게 함 
	int *hashtable = NULL; //int형 포인터 hashtable이 NULL상태가 되게 함
	int key = -1; //key를 -1로 선언
	int index = -1; //index를 -1로 선언

	srand(time(NULL)); //난수 구하는 함수

	do{
		printf("----------------------------------------------------------------\n");
		printf("                        Sorting & Hashing                       \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize       = z           Quit             = q\n");
		printf(" Selection Sort   = s           Insertion Sort   = i\n");
		printf(" Bubble Sort      = b           Shell Sort       = l\n");
		printf(" Quick Sort       = k           Print Array      = p\n");
		printf(" Hashing          = h           Search(for Hash) = e\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = "); 
		scanf(" %c", &command); //command 입력

		switch(command) { 
		case 'z': case 'Z': //'Z'또는 'z'일 경우
			initialize(&array);
			break;
		case 'q': case 'Q': //'Q'또는 'q'일 경우
			freeArray(array); 
			break;
		case 's': case 'S': //'S'또는 's'일 경우
			selectionSort(array); 
			break;
		case 'i': case 'I': //'I'또는 'i'일 경우
			insertionSort(array);
			break;
		case 'b': case 'B': //'B'또는 'b'일 경우
			bubbleSort(array);
			break;
		case 'l': case 'L': //'L'또는 'l'일 경우
			shellSort(array);
			break;
		case 'k': case 'K': //'K'또는 'k'일 경우
			printf("Quick Sort: \n");
			printf("----------------------------------------------------------------\n");
			printArray(array); //배열 출력
			quickSort(array, MAX_ARRAY_SIZE); //퀵 정렬로 배열 정렬
			printf("----------------------------------------------------------------\n");
			printArray(array); //정렬된 배열 출력

			break;

		case 'h': case 'H': //'H'또는 'h'일 경우
			printf("Hashing: \n");
			printf("----------------------------------------------------------------\n");
			printArray(array); //배열 출력
			hashing(array, &hashtable); //해싱으로 배열 정렬
			printArray(hashtable); //해시테이블에 저장된 데이터 출력
			break;

		case 'e': case 'E': //'E'또는 'e'일 경우
			printf("Your Key = ");
			scanf("%d", &key); //key 입력
			printArray(hashtable); //해시테이블에 저장된 데이터 출력
			index = search(hashtable, key); //search함수로부터 반환된 값 index에 저장
			printf("key = %d, index = %d,  hashtable[%d] = %d\n", key, index, index, hashtable[index]);
			break;

		case 'p': case 'P': //'p'또는 'P'일 경우
			printArray(array); //배열 출력
			break;
		default: //어느 것에도 해당되는 command가 아닐 때
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q'); //'Q'와 'q'가 입력되지 않을 동안

	return 1;
}

int initialize(int** a)
{
	int *temp = NULL; //int형 포인터 temp가 NULL상태가 되게 함

	/* array가 NULL인 경우 메모리 할당 */
	if(*a == NULL) {
		temp = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE);
		*a = temp;  /* 할당된 메모리의 주소를 복사 --> main에서 배열을 control할 수 있도록 함*/
	} else
		temp = *a; //array가 NULL이 아닐 경우, temp가 a의 주소, 즉 main의 포인터 array를 가리키게 함

	/* 랜덤값을 배열의 값으로 저장 */
	for(int i = 0; i < MAX_ARRAY_SIZE; i++)
		temp[i] = rand() % MAX_ARRAY_SIZE; 

	return 0;
}

int freeArray(int *a)
{
	if(a != NULL) //a가 NULL이 아닐 경우
		free(a); //a의 메모리 해제
	return 0;
}

void printArray(int *a)
{
	if (a == NULL) { //a가 NULL상태라면
		printf("nothing to print.\n"); //print할 것이 없다는 오류 메세지 출력
		return;
	}
	for(int i = 0; i < MAX_ARRAY_SIZE; i++) //MAX_ARRAY_SIZE만큼 반복
		printf("a[%02d] ", i); //i의 앞의 숫자만큼 0 추가
	printf("\n"); 
	for(int i = 0; i < MAX_ARRAY_SIZE; i++)
		printf("%5d ", a[i]); //i를 5칸 내에서 우측정렬
	printf("\n"); 
}


int selectionSort(int *a)
{
	int min; //최솟값
	int minindex; //최솟값을 가진 배열의 인덱스 
	int i, j; //반복문을 위한 변수 i,j 

	printf("Selection Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a); //배열 출력

	for (i = 0; i < MAX_ARRAY_SIZE; i++) //MAX_ARRAY_SIZE만큼 반복
	{
		minindex = i; //minindex를 i로 설정
		min = a[i]; //최솟값은 a[i]의 값
		for(j = i+1; j < MAX_ARRAY_SIZE; j++) //i의 다음값부터 시작해서 j가 MAX_ARRAY_SIZE가 되기 전까지 반복
		{
			if (min > a[j]) //최솟값(a[i])가 a[j]보다 크다면
			{
				min = a[j]; //최솟값을 a[j]로 바꿈
				minindex = j; //최솟값을 가진 배열의 인덱스가 j가 됨
			}
		}
		a[minindex] = a[i]; //a[minindex]에 a[i]값 저장
		a[i] = min; //a[i]에 최솟값 저장(앞자리부터 정렬)
	}

	printf("----------------------------------------------------------------\n");
	printArray(a); //정렬된 배열 출력
	return 0;
}

int insertionSort(int *a)
{
	int i, j, t; 

	printf("Insertion Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a); //배열 출력

	for(i = 1; i < MAX_ARRAY_SIZE; i++) //MAX_ARRAY_SIZE-1만큼 반복
	{
		t = a[i]; //t의 값을 a[i]로 설정
		j = i; 
		while (a[j-1] > t && j > 0) //j-1번째 배열의 값이 j번째 배열의 값보다 크고, j가 0보다 크다면
		{
			a[j] = a[j-1]; //j번째 배열에 j-1번째 배열의 값 저장
			j--; //j 후위감소
		}
		a[j] = t; //j번째 배열에 t저장
	}

	printf("----------------------------------------------------------------\n");
	printArray(a); //정렬된 배열 출력

	return 0;

}

int bubbleSort(int *a)
{
	int i, j, t;

	printf("Bubble Sort: \n"); 
	printf("----------------------------------------------------------------\n");

	printArray(a); //배열 출력

	for(i = 0; i < MAX_ARRAY_SIZE-1; i++) //MAX_ARRAY_SIZE-1만큼 반복
	{
		for (j = 0; j < MAX_ARRAY_SIZE-1-i; j++) //MAX_ARRAY_SIZE-1-i만큼 반복
		{
			if (a[j] > a[j+1]) //j-1번째 배열의 값이 j번째 배열의 값보다 크다면
			{

        //swap//
				t = a[j]; //t에 j-1번째 배열의 값 저장
				a[j] = a[j+1]; //j-1번째 배열에 j번째 배열의 값 저장
				a[j+1] = t; //j번째 배열에 t저장
			}
		}
	}

	printf("----------------------------------------------------------------\n");
	printArray(a); //정렬돤 배열 출력

	return 0;
}

int shellSort(int *a)
{
	int i, j, k, h, v;

	printf("Shell Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a); //배열 출력

	for (h = MAX_ARRAY_SIZE/2; h > 0; h /= 2) //h=MAX_ARRAY_SIZE에서 0보다 작아질 때까지 h를 반으로 나누면서 반복
	{
		for (i = 0; i < h; i++) //h만큼 반복
		{
			for(j = i + h; j < MAX_ARRAY_SIZE; j += h)
      //j의 값을 i에 h를 더한 값으로 지정, j에 h를 더하면서 반복함
			{
				v = a[j]; //v에 j번째 배열의 값 저장
				k = j; //k의 값을 j로 바꿈
				while (k > h-1 && a[k-h] > v) 
        //k가 h-1보다 크고, k-h번째 배열이 v보다 크다면
				{
					a[k] = a[k-h]; //k번째 배열에 k-h번째 배열의 데이터 저장
					k -= h; //k에 h의 값을 뺌
				}
				a[k] = v; //k번째 배열에 v저장
			}
		}
	}
	printf("----------------------------------------------------------------\n");
	printArray(a); //정렬된 배열 출력

	return 0;
}

int quickSort(int *a, int n)
{
	int v, t; 
	int i, j; //배열 인덱스

	if (n > 1) //배열의 크기가 1보다 크다면
	{
		v = a[n-1]; //v에 마지막 배열의 값 저장(피봇) 
		i = -1; //i의 값을 -1로 선언
		j = n - 1; //j의 값을 n-1(마지막 배열의 인덱스)로 선언

		while(1)
		{
			while(a[++i] < v); //i번째 배열의 값이 v보다 작다면
			while(a[--j] > v); //j번째 배열의 값이 v보다 크다면

			if (i >= j) break; //i가 j보다 크거나 같다면 반복문 탈출

			t = a[i]; //t의 값으로 i번째 배열의 값 저장
			a[i] = a[j]; //i번째 배열의 값으로 j번째 배열의 값 저장
			a[j] = t; //j번째 배열의 값으로 t의 값 저장
		}
    //swqp//
		t = a[i]; //t의 값으로 i번째 배열의 값 지정
		a[i] = a[n-1]; //i번째 배열의 값으로 n-1번째 배열의 값 지정
		a[n-1] = t; //n-1번째 배열의 값으로 t의 값 지정

		quickSort(a, i); //재귀함수 호출하여 인자로 배열과 i 전달
		quickSort(a+i+1, n-i-1); //재귀함수 호출하여 인자로 a(주소값이 i+1 증가한 상태)와 n-i-1전달)
	}


	return 0;
}

int hashCode(int key) {
   return key % MAX_HASH_TABLE_SIZE; //key값을 MAX_HASH_TABLE_SIZE로 MOD 연산한 결과를 리턴
}

int hashing(int *a, int **ht)
{
	int *hashtable = NULL; //int형 포인터 hashtable이 NULL상태가 되게 함

	/* hash table이 NULL인 경우 메모리 할당 */
	if(*ht == NULL) {
		hashtable = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE);
		*ht = hashtable;  /* 할당된 메모리의 주소를 복사 --> main에서 배열을 control할 수 있도록 함*/
	} else {
		hashtable = *ht;	/* hash table이 NULL이 아닌 경우, table 재활용, reset to -1 */
	}

	for(int i = 0; i < MAX_HASH_TABLE_SIZE; i++)
		hashtable[i] = -1; //해시테이블의 모든 배열의 데이터 값을 -1로 설정

	/*
	for(int i = 0; i < MAX_HASH_TABLE_SIZE; i++)
		printf("hashtable[%d] = %d\n", i, hashtable[i]);
	*/

	int key = -1; //key를 -1로 설정
	int hashcode = -1; //hashcode를 -1로 설정
	int index = -1; //index를 -1로 설정
	for (int i = 0; i < MAX_ARRAY_SIZE; i++) //MAX_ARRAY_SIZE만큼 반복
	{
		key = a[i]; //key의 값을 i번째 배열의 값으로 설정
		hashcode = hashCode(key); //hashCode함수를 이용해 hashcode생성
		/*
		printf("key = %d, hashcode = %d, hashtable[%d]=%d\n", key, hashcode, hashcode, hashtable[hashcode]);
		*/
		if (hashtable[hashcode] == -1) //hashcode를 이용해 해당 hashcode를 인덱스로 가진 해시테이블 배열을 검색했을 때 데이터 값이 1이라면(즉 해당 배열에 저장된 값이 없다면)
		{
			hashtable[hashcode] = key; //해당 배열에 key저장
		} else 	{ //그렇지 않다면(데이터가 이미 저장되어 있다면)

			index = hashcode; //index의 값을 hashcode의 값으로 저장

			while(hashtable[index] != -1) //해시테이블의 index번째 배열의 값이 -1이 아니라면(데이터가 이미 저장되어 있다면)
			{
				index = (++index) % MAX_HASH_TABLE_SIZE; //index를 MAX_HASH_TABLE_SIZE로 나눈 나머지를 index의 홈 버킷으로 사용->index값 조정
				/*
				printf("index = %d\n", index);
				*/
			}
			hashtable[index] = key; //해시테이블의 index번째 배열에 key저장
		}
	}

	return 0;
}

int search(int *ht, int key)
{
	int index = hashCode(key); //key값으로 만든 해시값을 index값으로 설정 

	if(ht[index] == key)  //해당 인덱스를 가진 해시테이블의 배열의 데이터 값이 key값과 같다면
		return index; //인덱스 리턴

  //다르다면 반복문 실행//
	while(ht[++index] != key) //key값과 다르다면
	{
		index = index % MAX_HASH_TABLE_SIZE;//인덱스 값 조정
	}
  //key값 찾으면 반복문 빠져나옴//
	return index;//인덱스 리턴
}


