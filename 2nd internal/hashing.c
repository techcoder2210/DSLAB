#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
const int TABLE_SIZE = 128;
char key[100]; 
char value[100];
 
struct entry { 
    char key[100]; 
    char value[100]; 
}; 
 
typedef struct entry *ENTRY; 
 
ENTRY table[128]; 
 
ENTRY createNode(char key[100], char value[100]) { 
    ENTRY temp = (ENTRY)malloc(sizeof(struct entry)); 
    strcpy(temp->key, key); 
    strcpy(temp->value, value); 
    return temp; 
} 
 
int hashf(char *key) { 
    int asciiSum = 0; 
    int len = strlen(key); 
    int i; 
    for (i = 0; i < len; i++) { 
        asciiSum = asciiSum + key[i]; 
    } 
    return asciiSum % TABLE_SIZE; 
} 
 
void put(char *key, char *value) { 
    int index = hashf(key); 
    int start = index; 
    while (table[index] != NULL && strcmp(table[index]->key, key) != 0) { 
        index = (index + 1) % TABLE_SIZE; 
        if (index == start) { 
            printf("Dictionary is full.\n"); 
            return; // Added return to exit the function if the dictionary is full 
        } 
    } 
    table[index] = createNode(key, value); 
 
} 
 
char *get(char *key) { 
 int index = hashf(key); 
    int start = index; 
    while (table[index] != NULL && strcmp(table[index]->key, key) != 0) { 
        index = (index + 1) % TABLE_SIZE; 
        if (index == start) { 
            return NULL; 
        } 
    } 
    if (table[index] == NULL) 
        return NULL; 
    else 
        return table[index]->value; 
 
} 
 
int removeFromDict(char *key) { 
 int index = hashf(key); 
    int start = index; 
    while (table[index] != NULL && strcmp(table[index]->key, key) != 0) { 
        index = (index + 1) % TABLE_SIZE; 
        if (index == start) { 
            return 0; 
        } 
    } 
    if (table[index] == NULL) { 
        return 0; 
    } else { 
        free(table[index]); 
        table[index] = NULL; // Set the pointer to NULL after freeing the memory 
        return 1; 
    } 
}

int main() { 
    int choice; 
    while (1) { 
        printf("1.Put\n" 
               "2.Get\n" 
               "3.Remove\n" 
               "4.Exit\n" 
               "Enter Your Choice : "); 
        scanf("%d", &choice); 
        switch (choice) { 
            case 1: { 
                printf("Enter the key: "); 
                scanf("%s", key); 
                printf("Enter the value: "); 
                scanf("%s", value); 
                put(key, value); 
                printf("Inserted successfully\n"); 
                break; 
            } 
            case 2: { 
                printf("Enter the key: "); 
                scanf("%s", key); 
                char *result = get(key); 
                if (result != NULL) { 
                    printf("%s is found with value %s\n", key, result); 
                } else { 
                    printf("%s is not found\n", key); 
                } 
                break; 
            } 
            case 3: { 
                printf("Enter the key: "); 
                scanf("%s", key); 
                if (removeFromDict(key)) { 
                    printf("%s deleted successfully\n", key); 
                } else { 
                    printf("Deletion Failed: %s\n", key); 
                } 
                break; 
            } 
            case 4: 
                exit(0); 
            default: 
                printf("Invalid choice. Please enter a valid option.\n"); 
        } 
    } 
    return 0; 
}
