#include <stdio.h>
#define MAX_SIZE 100

void insert(int arr[],int *n,int element) {
    if (*n<MAX_SIZE) {
        arr[*n] = element;
        (*n)++;
    } else {
        printf("List is full. Insertion not possible.\n");
    }
}

void delete(int arr[], int *n, int element) {
    int i, found = 0;
    for (i = 0; i < *n; i++) {
        if (arr[i] == element) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (int j = i; j < *n - 1; j++) {
            arr[j] = arr[j + 1];
        }
        (*n)--;
    } else {
        printf("Element not found\n");
    }
}

void print(int arr[], int n) {
    printf("List: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        if (i<n-1) {
        }
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int n = 0;
    char choice;
    int element;

    do {
        printf("I - Insert\nD - Delete\nP - Print\nQ - Quit\n");
        printf("Enter option: ");
        scanf(" %c", &choice);
        switch (choice) {
            case 'I':
            case 'i':
                printf("Element to insert: ");
                scanf("%d", &element);
                insert(arr, &n, element);
                break;
            case 'D':
            case 'd':
                printf("Element to delete: ");
                scanf("%d", &element);
                delete(arr, &n, element);
                break;
            case 'P':
            case 'p':
                print(arr, n);
                break;
            case 'Q':
            case 'q':
                break;
            default:
                printf("Invalid option!\n");
                break;
        }
    } while (choice != 'Q' && choice != 'q');

    return 0;
}