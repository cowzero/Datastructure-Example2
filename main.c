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


        STACK* stack_tmp = create_stack();
        STACK* stack_merged = create_stack();
  while(stack->count!=0){
    push(stack_tmp, pop(stack));
    printf("\nsuccess\n");
  }
  while(stack_tmp->count!=0){
    push(stack_merged, pop(stack_tmp));
    printf("\nsuccess\n");
  }
   while(stack2->count!=0){
       push(stack_tmp, pop(stack2));
       printf("\nsuccess\n");
     }
   while(stack_tmp->count!=0){
       push(stack_merged, pop(stack_tmp));
       printf("\nsuccess\n");
     }
   while(stack_merged->count !=0){
    printf("%d\n",*(int*)pop(stack_merged));
   }
    return 0;
}


