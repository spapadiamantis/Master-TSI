/* TP8  linked lists */
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;


/* function to swap data of two nodes a and b*/
void swap(struct node *a, struct node *b)
{
    int temp = a->val;
    a->val = b->val;
    b->val = temp;
}

void print_list(node_t* head)
{
    node_t* tmp=head;
    while((*tmp).next != NULL)
    {
        printf("%d",(*tmp).val);
        tmp = (*tmp).next;
            printf(" -> ");
    }

    printf("%d",(*tmp).val);
    printf("\n");
}

void add_to_list(node_t* head,int n)
{
    node_t* tmp=head;

    while((*tmp).next!= NULL)
        tmp = (*tmp).next;

    (*tmp).next = malloc(sizeof(node_t));
    tmp = (*tmp).next;
    (*tmp).val = n;
    (*tmp).next = NULL;

    return;

}
void add_to_sorted_list(node_t* head,int n)
{
    node_t* tmp=head;

    while((*tmp).next!=NULL && ((*tmp).next)->val < (*tmp).val)
        tmp = (*tmp).next;

    if((*tmp).next!=NULL)
    {
        (*tmp).next = malloc(sizeof(node_t));
        tmp = (*tmp).next;
        (*tmp).val = n;
        (*tmp).next = NULL;
    }
    else
    {
        node_t * new = malloc(sizeof(node_t));
        (*new).next = (*tmp).next;
        (*new).val = n;
        (*tmp).next = new;

    }


    return;

}

/* Function to reverse the linked list */
void reverse(struct node** head_ref)
{
    struct node* prev = NULL;
    struct node* current = *head_ref;
    struct node* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

int search(struct node* head, int key)
{
    int index;
    struct node *curNode;

    index = 0;
    curNode = head;

    // Iterate till last element until key is not found
    while (curNode != NULL && curNode->val != key)
    {
        index++;
        curNode = curNode->next;
    }


    return (curNode != NULL) ? index : -1;
}

int searchRecursive(int key, struct node *curNode, int index)
{
    if (curNode == NULL)                // Element not found in the list
        return -1;
    else if (curNode->val == key)   // Element found, return index
        return index;
    else                                // Not found, look in next element
        return searchRecursive(key, curNode->next, index + 1);
}


/* Bubble sort the given linked list */
void bubbleSort(struct node *start)
{
    int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;

    /* Checking for empty list */
    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (ptr1->val > ptr1->next->val)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}




int main(void)
{
    node_t * head = NULL;
    head = malloc(sizeof(node_t));
    if (head == NULL) {
        return 1;
    }

    head->val = 1;
    head->next = NULL;

    printf("Add elements to list\n");
    int n =0;
    scanf("%d",&n);
    while(n>0) {
        add_to_sorted_list(head, n);
        scanf("%d",&n);
    }

    print_list(head);

}