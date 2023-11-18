// Single Linear Linked List using structure pointer (global head)

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;

void printMenu(void);
void insertAtBeginning(int);

int main()
{
    int choice;

    head = NULL;
    printf("Hello World\n");

    while (1)
    {
        printMenu();
        printf("Enter a number of choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            break;

        default:
            return 1;
            break;
        }
    }

    return 0;
}

void insertAtBeginning(int data)
{
    struct Node *temp;

    temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        return;
    }

    temp->next = head;
    head = temp;
}

void printMenu()
{
    printf("\n\t:  AVAILABLE  OPTIONS  :\n\n");
    printf("1. Display Linked List\n");
    printf("2. Insert At Beginning\n");
    printf("3. Insert At End\n");
    printf("4. Insert At A Specific Position\n");
    printf("\n");
}

// END OF PROGRAM