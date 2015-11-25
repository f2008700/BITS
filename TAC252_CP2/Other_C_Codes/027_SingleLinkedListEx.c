/*

This program explains the single linked list data structure and it's operations


Recap that array is a continous area in the memory.


"long a[4]" will occupy a continous area in the RAM like this...
+---------------------------+
|      | base | base | base |
| base |   +  |   +  |  +   |
|      |   4  |   8  |  12  |
+---------------------------+
  a[0]   a[1]   a[2]   a[3]
  
  
  
Arrays are useful in dealing with simillar data.

For example, you can score the total marks of 60 students in an array, like this...

int marks[60];


But, suppose that we don't know how many students are there in a class.
In such a case, we will ask the user to enter the no. of students in the class.
There could be 10 students in the class or 100 students in the class.

In such a case, our fixed sized arrays may be either too big or too small to hold the data.


So, in order to use memory efficiently, we can go for linked lists.

In this program, the concept of linked list is explained.

Consider a code fragment like this.....
////////////////////////////////////////
typedef struct
{
    int value;
    item *next;
    
}item;

item item0, item1, item2, item3;

item0.value = 0;
item0.next = &item1;

item1.value = 1;
item1.next = &item2;

item2.value = 2;
item2.next = &item3;

item3.value = 3;
item3.next = NULL;
////////////////////////////////////////


     item0                                                                item3             
+------+------+                                                      +------+------+        
|      |      |                                                      |      |      ----->>---????
|value | next |                                                      |value | next |        
|      |      |                                            +-->>---->|      |      |                   
+------+--|---+                                            |         +------+------+                    
          |                  item1                   item2 |
          |             +------+------+         +------+---|--+
          |             |      |      |         |      |      |
          |             |value | next |         |value | next |
          +------>>---->|      |      --->>---->|      |      |
                        +------+------+         +------+------+
                        
                        
Here, you can observe that, item0, item1, item2 and item3 are located at different locations in the RAM.
But, they are connected through some link.

suppose that one student is moved to some other class and his data is to be removed...
it is easy to do so if we are using single linked lists.

If we wish to remove item2 from the list, we can simply connect item1's next to item3 like this...

and, we need to delete item2 from the memory



     item0                                                                item3             
+------+------+                                                      +------+------+        
|      |      |                                                      |      |      ----->>---????
|value | next |                                                      |value | next |        
|      |      |                     +------------------------->>---->|      |      |                   
+------+--|---+                     |                                +------+------+                    
          |                  item1  |                item2 <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< delete 
          |             +------+----|-+         +------+------+
          |             |      |      |         |      |      |
          |             |value | next |         |value | next |
          +------>>---->|      |      |         |      |      |
                        +------+------+         +------+------+
                        
item2 is no longer in the list.

*/


# include <stdio.h>
# include <stdlib.h>

struct Node
{
    int value;
    struct Node* next;
};


struct SingleLinkedList
{
    struct Node *head;
    struct Node *tail;
};

struct Node* CreateNewNode()
{
    return (struct Node*) malloc(sizeof(struct Node));
}


void CreateSingleLinkedList(struct SingleLinkedList *list)
{
    list->head = CreateNewNode();
    list->tail = CreateNewNode();
    
    list->head->next = list->tail;
    list->tail->next = NULL;
    printf("List is created\n");
}


void DestroySingleLinkedList(struct SingleLinkedList *list)
{
    struct Node* item;
    struct Node* temp;
    
    if(!list) return;
    
    item = list->head;    
    while(item)
    {
        temp = item->next;
        free(item);
        item = temp;
    }
    list->head = NULL;
    list->tail = NULL;
    printf("List is deleted\n");
}


void DisplayList(struct SingleLinkedList* list)
{
    int count = 0;
    struct Node *item = list->head->next;
    
    printf("The list elements are......\n");
    printf("###....value....address\n");
    
    while(item != list->tail)
    {
        printf("%3d...%6d....%x\n", count++, item->value, (unsigned int)item);
        item = item->next;       
    }   
    printf("-----------------------\n\n"); 
}

struct Node* GetNode(int value, struct SingleLinkedList *list)
{
    struct Node* item = list->head->next;
    
    while(item != list->tail)
    {
        if(item->value == value)
        {
            printf("The node with the value ...%d is found at the address ...%x\n", value, (unsigned int) item);
            return item;
        }
        item = item->next;                
    }
    printf("Unable to find a node with the given value...%d\n", value);
    return NULL;
}

void DeleteNodeWithValue(int value, struct SingleLinkedList *list)
{
    struct Node* item0 = list->head;
    struct Node* item1 = item0->next;
    
    while(item1 != list->tail)
    {
        if(item1->value == value)
        {
            item0->next = item1->next;
            free(item1);
            printf("Node with value...%d is deleted\n", value);
            return;            
        }
        item0 = item1;
        item1 = item1->next;                
    }
    printf("Unable to find a node with value...%d\nDeletion failed\n", value);
}


void DeleteNodeWithAddress(struct Node* item, struct SingleLinkedList *list)
{
    struct Node* item0 = list->head;
    struct Node* item1 = item0->next;
    
    if(!item) return;
    
    while(item1 != list->tail)
    {
        if(item1 == item)
        {
            item0->next = item1->next;
            free(item1);
            printf("Node with address...%x is deleted\n", (unsigned int)item);
            return;            
        }
        item0 = item1;
        item1 = item1->next;                
    }
    printf("Unable to find a node with address...%x\nDeletion failed\n", (unsigned int)item);
}


void InsertNode(int value, struct Node* item)
{
    struct Node* newItem = CreateNewNode();
    newItem->value = value;
    newItem->next = item->next;
    
    item->next = newItem;
    printf("A new item with value .. %d is added after the node with address..%x\n", value, (unsigned int)item);
}


void InsertValueAt(int value, int index, struct SingleLinkedList *list)
{
    int count = 0;
    struct Node* item0 = list->head;
    struct Node* item1 = item0->next;
    
    while(item1 != list->tail)
    {
        if(count == index)
        {
            printf("A new item with value..%d is added after the index...%d\n", value, index);
            InsertNode(value, item0);
            return;            
        }
        item0 = item1;
        item1 = item1->next;
        count++;
    }
    
    printf("The mentioned index is...%d\n", index);
    printf("The size of the list is..%d\n", count);
    printf("A new item with value %d will be added at the end\n", value);
    
    InsertNode(value, item0);    
}


void main()
{
    struct SingleLinkedList list;
    struct Node* temp;
    int value = 100;
    int index = 0;
    
    CreateSingleLinkedList(&list);
    DisplayList(&list);
    
    InsertValueAt(value, index, &list);
    DisplayList(&list);
    
    value = 200;
    index = 1;
    InsertValueAt(value, index, &list);
    DisplayList(&list);
    
    value = 150;
    index = 1;
    InsertValueAt(value, index, &list);
    DisplayList(&list);
    
    
    value = 400;
    index = 20;
    InsertValueAt(value, index, &list);
    DisplayList(&list);
    
    temp = GetNode(200, &list);
    InsertNode(300, temp);
    DisplayList(&list);
    
    DeleteNodeWithValue(150, &list);
    DisplayList(&list);    
    
    temp = GetNode(400, &list);
    DeleteNodeWithAddress(temp, &list);
    DisplayList(&list);
    
    DestroySingleLinkedList(&list);
    
}

