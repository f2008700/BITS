/*

This program explains the double linked list data structure and it's operations


Recap that single linked list is a list, maintained with the help of links to the 
next nodes.  In double linked list, along with the links to the next nodes, we maintain
the links to the previous nodes also.


*/



////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
///WARNING: This is a very simple implementation of double linked list. ////
///This program intends to introduce the basic concepts to the students.////
///Error checking is not done in this program.                          ////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

# include <stdio.h>
# include <stdlib.h>

struct Node;

struct Node
{
    int value;
    struct Node* next;
    struct Node* back;
};


void DisplayListForward(struct Node* item)
{
    int count = 0;
    
    printf("from first to last...\n");
    while(item)
    {
        printf("%d...%d\n", ++count, item->value);
        item = item->next;       
    }    
}


void DisplayListBackward(struct Node* item)
{
    int count = 0;
    
    printf("from last to first...\n");    
    while(item)
    {
        printf("%d...%d\n", ++count, item->value);
        item = item->back;       
    }    
}


void DeleteNode(struct Node *node)
{
    //Warning: this function is just to explain the basic concept.
    //Don't  delete the first or last node in the list
    //using this function.
    struct Node *previousNode = node->back;
    struct Node *nextNode = node->next;    
    
    previousNode->next = nextNode;
    nextNode->back = previousNode;
}


void InsertNode(struct Node *location, struct Node *item)
{
    item->back = location;
    item->next = location->next;
    location->next = item;
}


/*
OK... I'm not going to implement the double linked list creation, deletion and all other
book keeping stuff.

It is left as an exercise to you.

Refer 027_SingleLinkedListEx.c and write 029_DoubleLinkedListEx.c on your own
*/
void main()
{
    struct Node item0, item1, item2, item3;        

    item0.value = 90;
    item0.next = &item1;
    item0.back = NULL;

    item1.value = 100;
    item1.next = &item2;
    item1.back = &item0;

    item2.value = 110;
    item2.next = &item3;
    item2.back = &item1;

    item3.value = 120;
    item3.next = NULL;
    item3.back = &item2;
    
    printf("The initial list is....\n");
    DisplayListForward(&item0);
    DisplayListBackward(&item3);
    
    printf("After deleting the 3rd item, the list is...\n");
    DeleteNode(&item2);
    DisplayListForward(&item0);
    DisplayListBackward(&item3);
    
    printf("After adding the previously deleted 3rd item at the last location..\n");
    InsertNode(&item3, &item2);
    DisplayListForward(&item0);
    
    //item3 is no longer the last element of the list.  item2 is the "new END node" of the list.
    DisplayListBackward(&item2);
}

