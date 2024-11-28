#include <stdlib.h>
#include <stdio.h>

struct queue {
	int data;
	struct queue *next;
};

typedef struct queue *Q;
Q front = NULL, rear = NULL;

void enqueue(int element) {
	Q newNode = (Q)malloc(sizeof(struct queue));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = element;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Successfully inserted.\n");
}

void dequeue() {
	if (front == NULL) {
        printf("Queue is underflow.\n");
        return;
    }
    Q temp = front;
    printf("Deleted value = %d\n", temp->data);
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
}

void display() {
	if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    Q temp = front;
    printf("Elements in the queue : ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void size() {
	int count = 0;
    Q temp = front;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Queue size : %d\n", count);
}

void isEmpty() {
	if (front == NULL) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
	}
}

int main() {
	int op, x;
	while(1) {	
		printf("1.Enqueue 2.Dequeue 3.Display 4.Is empty 5.Size 6.Exit\n");
		printf("Enter your option : ");
		scanf("%d",&op);
		switch(op) {
			case 1: 
				printf("Enter element : ");
				scanf("%d",&x);
				enqueue(x);
				break;
			case 2: 
				dequeue();
				break;
			case 3: 
				display();
				break;
			case 4:
				isEmpty();
				break;
			case 5:
				size();
				break;
			case 6: exit(0);
		}
	}
}