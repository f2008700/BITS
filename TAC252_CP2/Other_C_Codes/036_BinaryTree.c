/*
program to implement binary tree

A binary tree is like a triple linked list.

A node will have two links
1)smaller
2)greater

smaller link points to another node, whose value is less than the current node's value
greater link points to another node, whose value is greater than the current node's value



example, if we have a list of no.s 30, 40, 10, 20, 90

then the binary tree will be formed like this....
////////////////////////////////////////////////////////////
STEP 1: A single node with no smaller and greater links
                                  +----+----+----+
                                  |  < | 30 |  > |
                                  +----+----+----+
  
////////////////////////////////////////////////////////////                                
STEP 2:
A single node with only greater link and no smaller link

                                  +----+----+----+
                                  | ?  | 30 |  > |
                                  +----+----+----+
                                                  \
                                                   \                           
                                                    \
                                                     +----+----+----+
                                                     | <  | 40 | >  |
                                                     +----+----+----+
                                                     


////////////////////////////////////////////////////////////
STEP 3:  Adding 10.
10 is less than 30.  So it is connected to the smaller link of the node.

                                  +----+----+----+
                                  | <  | 30 |  > |
                                  +----+----+----+
                                 /                \
                                /                  \                           
                               /                    \
               +----+----+----+                      +----+----+----+
               | <  | 10 | >  |                      | <  | 40 | >  |
               +----+----+----+                      +----+----+----+
                                                     
                                                     
////////////////////////////////////////////////////////////                                                     
STEP 4: Adding 20

20 should be added to the smaller link of the 30.
But, smaller(30) is already linked to 10.
So, we will link 20 to 10.

                                  +----+----+----+
                                  | <  | 30 |  > |
                                  +----+----+----+
                                 /                \
                                /                  \                           
                               /                    \
               +----+----+----+                      +----+----+----+
               | <  | 10 | >  |                      | <  | 40 | >  |
               +----+----+----+                      +----+----+----+ 
                               \
                                \
                                 \
                                  +----+----+----+
                                  | <  | 20 |  > |
                                  +----+----+----+
                                  
                                  
////////////////////////////////////////////////////////////                                                     
STEP 5: Adding 90

90 should be added to the greater link of the 30.
But, greater(30) is already linked to 40.
So, we will link 90 to 40.

                                  +----+----+----+
                                  | <  | 30 |  > |
                                  +----+----+----+
                                 /                \
                                /                  \                           
                               /                    \
               +----+----+----+                      +----+----+----+
               | <  | 10 | >  |                      | <  | 40 | >  |
               +----+----+----+                      +----+----+----+
                               \                                     \
                                \                                     \
                                 \                                     \
                                  +----+----+----+                      +----+----+----+
                                  | <  | 20 |  > |                      |  < | 90 |  > |
                                  +----+----+----+                      +----+----+----+
               
               
               
*/

# include <stdio.h>
# include <stdlib.h>

struct BinaryNode
{
    int value;
    struct BinaryNode* smaller;
    struct BinaryNode* greater;
};


struct BinaryNode* root = NULL;

void PreOrder(struct BinaryNode* node)
{
    if(!node) return;
    
    printf("%d,", node->value);
    
    PreOrder(node->smaller);
    PreOrder(node->greater);
}



void PostOrder(struct BinaryNode* node)
{
    if(!node) return;    
    
    PostOrder(node->smaller);
    PostOrder(node->greater);
    
    printf("%d,", node->value);
}




void InOrder(struct BinaryNode* node)
{
    if(!node) return;
    
    InOrder(node->smaller);
    printf("%d,", node->value);
    InOrder(node->greater);
}


struct BinaryNode* CreateNewNode(int value)
{
    struct BinaryNode* node = (struct BinaryNode*) malloc(sizeof(struct BinaryNode));

    node->value = value;
    node->smaller = NULL;
    node->greater = NULL;
    
    return node;
}

void Insert(int value, struct BinaryNode* node)
{
    if(!root) 
    {
        root = CreateNewNode(value);
        return;
    }    
    
    if(value > node->value)
    {
        if(node->greater) Insert(value, node->greater);
        else node->greater = CreateNewNode(value);
    }
    else if(value < node->value)
    {
        if(node->smaller) Insert(value, node->smaller);
        else node->smaller = CreateNewNode(value);
    }
}


void DeleteBinaryTree(struct BinaryNode *node)
{
    if(!node) return;
    
    DeleteBinaryTree(node->smaller);
    DeleteBinaryTree(node->greater);
    free(node);
}


void main(int count, char** arguments)
{
    int loop;
    int value;
    
    for(loop = 1; loop < count; loop++)
    {
        value = atoi(arguments[loop]);
        Insert(value, root);
    }
    
    printf("This is the pre order...\n");
    PreOrder(root);
    printf("\n");
    
    printf("This is the post order...\n");
    PostOrder(root);
    printf("\n");
    
    printf("This is the in order...\n");
    InOrder(root);
    printf("\n");
    
    DeleteBinaryTree(root);
    
}
