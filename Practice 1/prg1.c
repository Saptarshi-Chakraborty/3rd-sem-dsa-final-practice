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
void displayLinkedList(void);
void insertAtBeginning(int);
void insertAtEnd(int);
void insertAtPosition(int, int);
void insertByValue(int, int);
void deleteFromBeginning();
void deleteFromEnd();
void deleteFromPosition(int);
void deleteByValue(int);

int main()
{
    int choice, data, position;

    head = NULL;
    printf("Hello World\n");

    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    system("cls");

    while (1)
    {
        printMenu();
        printf("Enter a number of choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            return 1;

        case 1:
            displayLinkedList();
            break;

        case 2:
            printf("Enter the data to Insert : ");
            scanf("%d", &data);
            insertAtBeginning(data);

            displayLinkedList();
            break;

        case 3:
            printf("Enter the data to Insert : ");
            scanf("%d", &data);
            insertAtEnd(data);

            displayLinkedList();
            break;

        case 4:
            printf("Enter the data to Insert : ");
            scanf("%d", &data);

            displayLinkedList();

            printf("\nEnter the position at which you want to Insert : ");
            scanf("%d", &position);

            insertAtPosition(data, position);

            displayLinkedList();
            break;

        case 5:
            printf("Enter the data to Insert : ");
            scanf("%d", &data);

            displayLinkedList();

            printf("Enter the value where you want to Insert : ");
            scanf("%d", &position);

            insertByValue(data, position);

            displayLinkedList();
            break;

        case 6:
            printf("\n >> Deleting the Starting node from the list <<\n");
            deleteFromBeginning();

            displayLinkedList();

            break;

        case 7:
            printf("\n >> Deleting the ending node from the list <<\n");
            deleteFromEnd();

            displayLinkedList();

            break;

        case 8:

            displayLinkedList();

            printf("Enter the position of the node which you want to delete : ");
            scanf("%d", &position);

            deleteFromPosition(position);

            displayLinkedList();
            break;

        case 99:
            system("cls");
            break;

        default:
            return 1;
            break;
        }
    }

    return 0;
}

void printMenu()
{
    printf("\n\t:  AVAILABLE  OPTIONS  :\n\n");
    printf("0. Exit\n");
    printf("1. Display Linked List\n");
    printf("2. Insert At Beginning\n");
    printf("3. Insert At End\n");
    printf("4. Insert At A Specific Position\n");
    printf("5. Insert By Value\n");
    printf("6. Delete From Beginning\n");
    printf("7. Delete From End\n");
    printf("8. Delete From A Specific Position\n");
    printf("9. Delete By Value\n");
    printf("99. CLEAR TERMINAL\n");
    printf("\n");
}

void displayLinkedList(void)
{
    struct Node *temp;

    printf("\n>> LINKED LIST is : ");

    if (head == NULL)
    {
        printf(" EMPTY\n");
        return;
    }

    for (temp = head; temp != NULL; temp = temp->next)
    {
        printf("%d , ", temp->data);
    }

    printf("\b\b  \n");
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

void insertAtEnd(int data)
{
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    for (temp = head; temp->next != NULL; temp = temp->next)
        ;

    temp->next = newNode;
}

void insertAtPosition(int data, int postion)
{
    struct Node *newNode, *tempNode;
    int count;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    // If the linked list is empty ignore the postion
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    else if (postion == 0)
    {
        insertAtBeginning(data);
        return;
    }

    for (tempNode = head, count = 2; count < postion; tempNode = tempNode->next, count++)
        ;

    newNode->next = tempNode->next;
    tempNode->next = newNode;
}

void insertByValue(int item, int value)
{
    struct Node *newNode, *temp;
    int hasFound = 0;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = item;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    for (temp = head; temp != NULL; temp = temp->next)
    {
        if (temp->data != value)
            continue;

        hasFound = 1;

        newNode->next = temp->next;
        temp->next = newNode;
        break;
    }

    if (hasFound == 0)
    {
        printf(">> Not found %d in the list\n", value);
    }
}

void deleteFromBeginning()
{
    if (head == NULL)
    {
        printf("\n!!! The Link is Empty. Can't Delete a Node !!!\n");
        return;
    }
    else if (head->next == NULL)
    {
        head = NULL;
        return;
    }

    head = head->next;
}

void deleteFromEnd()
{

    struct Node *temp;

    if (head == NULL)
    {
        printf("\n !!! The Link is Empty. Can't Delete a Node !!!\n");
        return;
    }
    else if (head->next == NULL)
    {
        head = NULL;
        return;
    }

    for (temp = head; temp->next->next != NULL; temp = temp->next)
        ;
    printf("LAST NODE VALUE = %d\n", temp->data);

    temp->next = NULL;
}

void deleteFromPosition(int position)
{
    struct Node *temp, *temp2;
    int count;

    if (head == NULL || position == 0)
    {
        printf("\n !!! The Link is Empty. Can't Delete a Node !!!\n");
        return;
    }
    else if (head->next == NULL)
    {
        head = NULL;
        return;
    }
    else if (position == 1)
    {
        head = head->next;
        return;
    }

    for (temp = head, count = 2; count < position; count++, temp = temp->next)
        ;

    printf("\nThe Prev Node Value : %d\n", temp->data);

    temp2 = temp->next;
    temp->next = temp2->next;
}

void deleteByValue(int value)
{
    struct Node *temp;
    int hasFound = 0;

    if (head == NULL)
    {
        printf("\n !!! The Link is Empty. Can't Delete a Node !!!\n");
        return;
    }

    for (temp = head; temp != NULL; temp = temp->next)
    {
        if (temp->data == value)
        {
            hasFound = 1;
                








            break;
        }
    }

    if (hasFound == 0)
        printf("\n>> Not found a node with value %d <<\n", value);
}

//  HEAD -> 10 -> 20 -> 30 -> 40 -> NULL
// END OF PROGRAM