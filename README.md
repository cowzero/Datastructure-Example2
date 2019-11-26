# Datastructure-Example2

-개요 : 스택에 숫자를 담아 차례대로 출력한다.

<make file>



사용하기 편하도록 ADT_Stack.o와 main.o를 링킹하여 
merge1파일을 만들었고, ADT_Stack.o와 main2.o를 링킹하여 
merge2 파일을 만들었다. 

확인해 본 결과 정상적으로 됐다.

<merge1 실행>


stack_merged를 위에서부터 차례대로 꺼냈을 때 
9 8 7 6 5 4 3 2 1 0 이므로, stack_merged안에는
0 1 2 3 4 5 6 7 8 9 순으로 담겨있다.

<merge2 실행>

stack_merged를 위에서부터 차례대로 꺼냈을 때 
9 4 8 3 7 2 6 1 5 0 이므로, stack_merged안에는
0 5 1 6 2 7 3 8 4 9 순으로 담겨있다.

<ADT_Stack.h>

boolean타입을 정의하기 위한 헤더 파일
bool함수인 push()를 정의하기 위해 사용하였다. 

#include<stdbool.h>

typedef struct node{
	void* data_ptr;
	struct node* link;
}STACK_NODE;

typedef struct{
	int count;
	STACK_NODE *top;
}STACK;

STACK* create_stack();


함수 정의
bool push(STACK* stack, void* in);

void* pop(STACK* stack);






<ADT_Stack.c>

ADT_Stack.h 에 있는 구조체들을 사용하기 위함  


malloc 함수를 사용하기 위함
#include"ADT_Stack.h" 
#include <stdlib.h>

STACK* create_stack(){
	STACK* stack = (STACK*)malloc(sizeof(STACK));
	stack->count = 0;
	stack->top = NULL;
	return stack;
}

bool push(STACK* stack, void* in){
	STACK_NODE* new_node = (STACK_NODE*)malloc(sizeof(STACK_NODE));
	new_node->data_ptr = in;
	new_node->link = stack->top;
	stack->top = new_node;
	(stack->count)++;
	return true;
}

void* pop(STACK* stack){
	if(stack->count == 0)	return NULL;
	else{
		STACK_NODE* temp = stack->top;
		void* data_out = stack->top->data_ptr;
		stack->top =stack->top->link;
		free(temp);
		(stack->count)--;
		return data_out;
	}
}
<Main.c> : 1번 문제

ADT_Stack.h에 있는 구조체와 함수를 사용하기 위함

#include "ADT_Stack.h"
#include <stdio.h>

int main(){
	int s[10] = {0,1,2,3,4,5,6,7,8,9};
	STACK* stack = create_stack();
	STACK* stack2 = create_stack();

	for(int i=0; i <5 ; i ++){
		if(!push(stack, &s[i])) printf("ahahah ?\n");

0~4 까지 차례대로 stack 에 담고,
만약 실패한다면 ahahah ?를 출력한다.
	}
    

	for(int i=5; i <10 ; i ++){
		if(!push(stack2, &s[i])) printf("ahahah ?\n");

5~9 까지 차례대로 stack2 에 담고,
만약 실패한다면 ahahah ?를 출력한다.
	}


임시로 담아둘 stack_tmp 생성

	STACK* stack_tmp = create_stack();

stack과 stack2을 합친 
stack_merged 생성
	STACK* stack_merged = create_stack();

	while(stack->count!=0){
		push(stack_tmp, pop(stack));

stack->count가 0 이 아니라면 stack에서 맨 위에 있는 것부터 
차례대로 임시로 stack_tmp에 담아 놓는다.
그리고 그후에 succeess를 출력한다.
따라서 stack에서는 0~4 순으로 정렬돼 있었지만, 
stack_tmp에는 4~0 순으로 정렬돼 있다.

		printf("\nsuccess\n");
	}





	while(stack_tmp->count!=0){
		push(stack_merged, pop(stack_tmp));

이번에는 stack_tmp에서 stack_merged로 옮긴다.
맨 위에서부터 차례대로 stack_merged에 옮긴 후,
succeess를 출력한다.
따라서 stack_tmp에서는 4~0 순으로 정렬돼 있었지만, 
stack_merged에는 0~4 순으로 정렬돼 있다. 

		printf("\nsuccess\n");
	}
  




	while(stack2->count!=0){
		push(stack_tmp, pop(stack2));

여기서는 stack에서 stack_tmp에 임시로 옮긴 것과 같이
stack2에서 stack_tmp로 임시로 옮긴다.
따라서 stack에서는 5~9 순으로 정렬돼 있었지만,
stack_tmp에서는 9~5 순으로 정렬돼 있다.

		printf("\nsuccess\n");
	}
   



	while(stack_tmp->count!=0){
		push(stack_merged, pop(stack_tmp));

stack_tmp에 임시로 담아 놓은 것을 stack_merged로 옮긴다.
stack_merged에 있는 9~5를 위에서부터 차례대로 옮긴다.
현재 stack_merged에 0~4가 있기 때문에, 5~9를 더 담아
stack_merged에는 0~9 순으로 정렬돼 있다. 

		printf("\nsuccess\n");
	}




	while(stack_merged->count !=0){
		printf("%d\n",*(int*)pop(stack_merged));

최종적으로 stack_merged에 뭐가 담겨있는지 확인하기 위해
위에서부터 차례대로 꺼내서 출력한다. 

	}
    

	return 0;
}
<Main2.c> : 2번 문제

ADT_Stack.h에 있는 구조체와 함수를 사용하기 위함

#include "ADT_Stack.h"
#include <stdio.h>

int main(){
	
	int s[10] = {0,1,2,3,4,5,6,7,8,9};
	STACK* stack = create_stack();
	STACK* stack2 = create_stack();

	for(int i=0; i <5 ; i ++){
		if(!push(stack, &s[i])) printf("ahahah ?\n");
	}

	for(int i=5; i <10 ; i ++){
		if(!push(stack2, &s[i])) printf("ahahah ?\n");
	}

임시로 담아둘 
stack_tmp, stack_tmp2 생성

	STACK* stack_tmp = create_stack();
	STACK* stack_tmp2 = create_stack();
	STACK* stack_merged = create_stack();

	while(stack->count!=0){
		push(stack_tmp, pop(stack));

stack->count가 0 이 아니라면 stack에서 맨 위에 있는 것부터 
차례대로 임시로 stack_tmp에 담아 놓는다.
그리고 그 후에 succeess를 출력한다.
따라서 stack에서는 0~4 순으로 정렬돼 있었지만, 
stack_tmp에는 4~0 순으로 정렬돼 있다.

		printf("\nsuccess\n");
	}





	while(stack2->count!=0){
		push(stack_tmp2, pop(stack2));

stack2->count가 0 이 아니라면 맨 위에 있는 것부터 
차례대로 임시로 stack_tmp2에 담아 놓는다.
그리고 그후에 succeess를 출력한다.
따라서 stack2에서는 5~9 순으로 정렬돼 있었지만, 
stack_tmp2에는 9~5 순으로 정렬돼 있다.

		printf("\nsuccess\n");
	}
   





	while(stack_tmp->count!=0 && stack_tmp2 !=0){
		push(stack_merged, pop(stack_tmp));
		push(stack_merged, pop(stack_tmp2));

stack->count와 stack2->count 둘 다 0 이 아니라면 
stack_tmp에서 맨 위에 있는 것을 stack_merged에 담은 후
stack_tmp2에서 맨 위에 있는 것을 stack_merged에 담는다.
그리고 그후에 succeess를 출력한다.


		printf("\nsuccess\n");
	}





	while(stack_merged->count !=0){

최종적으로 stack_merged에 뭐가 담겨있는지 확인하기 위해
위에서부터 차례대로 꺼내서 출력한다. 

		printf("%d\n",*(int*)pop(stack_merged));
	}


	return 0;
}
