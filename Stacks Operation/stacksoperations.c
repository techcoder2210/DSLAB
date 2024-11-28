#define MAX 8
int stack[MAX];
int top = -1;

void push(int element){
	if(top>MAX){
	printf("Stack is overflow.\n");
	}
	else{
		top++;
		stack[top]=element;
		printf("Successfully pushed.\n");
	}
}

void display(){
	int i;
	if(top==-1){
		printf("Stack is empty.\n");
	}
	else{
		printf("Elements of the Stack are: ");
		for(i=top;i>=0;i--){
			printf("%d ",stack[i]);
		}
		printf("\n");
	}
}

void pop(){
	if(top==-1){
		printf("Stack is underflow.\n");
	}
	else{
		printf("Popped value = %d\n",stack[top]);
		top--;
	}
}

void peek(){
	if(top==-1){
		printf("Stack is underflow.\n");
	}
	else{
		printf("Peek value = %d\n",stack[top]);
	}
}

void isempty(){
	if(top==-1){
		printf("Stack is empty.\n");
	}
	else{
		printf("Stack is not empty.\n");
	}
}