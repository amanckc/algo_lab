#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int key; char name[100];
struct node *next;
 };

struct hash {
struct node *head;
int count;
};


struct node * createNode(int key, char *name, int age)
{
    struct node *newnode;
    newnode = (struct node *) malloc(sizeof(struct node));
    newnode->age = age;
    strcpy(newnode->name, name);
    newnode->next = NULL;
    return newnode;
}

void insertToHash(int key, char *name, int age) 
{
    int hashIndex = key % eleCount;
     struct node *newnode = createNode(key, name, age);
    if (!hashTable[hashIndex].head) 
{
    hashTable[hashIndex].head = newnode;
    hashTable[hashIndex].count = 1;
    return;
}
     newnode->next = (hashTable[hashIndex].head);
     hashTable[hashIndex].head = newnode;
     hashTable[hashIndex].count++;
     return;
 }

  int main() {

        int n, ch, key, age;

        char name[100];

        printf("Enter the number of elements:");

        scanf("%d", &n);

        eleCount = n;

        /* create hash table with "n" no of buckets */

        hashTable = (struct hash *) calloc(n, sizeof(struct hash));

        while (1) {

            printf("\n1. Insertion\t2. Deletion\n");

            printf("3. Searching\t4. Display\n5. Exit\n");

            printf("Enter your choice:");

            scanf("%d", &ch);

            switch (ch) {

            case 1:

                printf("Enter the key value:");

                scanf("%d", &key);

                getchar();

                printf("Name:");

                fgets(name, 100, stdin);

                name[strlen(name) - 1] = '\0';

                printf("Age:");

                scanf("%d", &age);

                /*inserting new node to hash table */

                insertToHash(key, name, age);

                break;

     

            case 2:

                printf("Enter the key to perform deletion:");

                scanf("%d", &key);

                /* delete node with "key" from hash table */

                deleteFromHash(key);

                break;

     

            case 3:

                printf("Enter the key to search:");

                scanf("%d", &key);

                searchInHash(key);

                break;

            case 4:

                display();

                break;

            case 5:

                exit(0);

            default:

                printf("U have entered wrong option!!\n");

                break;

            }

        }

        return 0;

    }