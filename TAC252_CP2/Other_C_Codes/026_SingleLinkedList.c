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



     item0                                                                item3             
+------+------+                                                      +------+------+        
|      |      |                                                      |      |      ----->>---????
|value | next |                                                      |value | next |        
|      |      |                     +------------------------->>---->|      |      |                   
+------+--|---+                     |                                +------+------+                    
          |                  item1  |                item2  
          |             +------+----|-+         +------+------+
          |             |      |      |         |      |      |
          |             |value | next |         |value | next |
          +------>>---->|      |      |         |      |      |
                        +------+------+         +------+------+
                        
item2 is no longer in the list.

*/



////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
///WARNING: This is a very simple implementation of single linked list. ////
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
};


void DisplayList(struct Node* item)
{
    int count = 0;
    
    while(item)
    {
        printf("%d...%d\n", ++count, item->value);
        item = item->next;       
    }    
}


void DeleteNode(struct Node *firstNode, struct Node* deleteItem)
{
    while(firstNode->next != deleteItem) firstNode = firstNode->next;
    firstNode->next = deleteItem->next;    
}


void InsertNode(struct Node *location, struct Node *item)
{
    item->next = location->next;
    location->next = item;
}


void main()
{
    struct Node item0, item1, item2, item3;        

    item0.value = 90;
    item0.next = &item1;

    item1.value = 100;
    item1.next = &item2;

    item2.value = 110;
    item2.next = &item3;

    item3.value = 120;
    item3.next = NULL;
    
    printf("The initial list is....\n");
    DisplayList(&item0);
    
    printf("After deleting the 3rd item, the list is...\n");
    DeleteNode(&item0, &item2);
    DisplayList(&item0);
    
    printf("After adding the previously deleted 3rd item at the last location..\n");
    InsertNode(&item3, &item2);
    DisplayList(&item0);
}

