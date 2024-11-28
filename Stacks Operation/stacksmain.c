#include<stdio.h>
#include<stdlib.h>
#define STACK_MAX_SIZE 10
#include "stackoperations.c"

int main(){
	int op,x;
	while(1){
		printf("1. Push\n2. Pop\n3. Display\n4. Is empty\n5. Peek\n6. Exit\n");
		printf("Enter your option: ");
		scanf("%d",&op);
		switch(op){
			case 1:
				printf("Enter element: ");
				scanf("%d",&x);
				push(x);
				break;
			case 2:
				pop();
				break;
			case 3:
			    display();
			    break;
			case 4:
			    isempty();
				break;
			case 5:
		        peek();
				break;
			case 6:
			    exit(0);	
		}
}
}