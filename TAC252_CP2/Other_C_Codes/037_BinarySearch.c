/*
program to implement binary search and linear search
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


void LinearSearch_Recursive(int key, int *list, int comparisions, int maxElements)
{
    if(maxElements < 0)
    {
        printf("Unable to find the key %d, even after ..%d comparisions\n", key, comparisions+1);
        return ;
    }
    if(list[0] == key)
    {
        printf("The key %d is found at %x after %d comparisions\n", key, (unsigned int) list, comparisions+1);
        return;                
    }
    
    LinearSearch_Recursive(key, list+1, comparisions+1, maxElements-1);
}



void LinearSearch_NonRecursive(int key, int *list, int maxElements)
{
    int loop;
    
    for(loop = 0; loop < maxElements; loop++)
    {
        if(list[loop] == key)
        {
            printf("The key %d is found at %x after %d comparisions\n", key, (unsigned int)(list + loop), loop+1);
            return;
        }
    }
    printf("Unable to find the key %d, even after ..%d comparisions\n", key, loop);
}


void BinarySearch_Recursive(int key, struct BinaryNode* node, int comparisions)
{
    if(!node)
    {
        printf("Unable to find the key %d even after %d comparisions\n", key, comparisions+1);
        return;
    }    
    
    if(node->value == key)
    {
        printf("The key %d is found at %x after %d comparisions\n", key, (unsigned int)node, comparisions+1);
    }
    else if(node->value < key) BinarySearch_Recursive(key, node->greater, comparisions+1);
    else BinarySearch_Recursive(key, node->smaller, comparisions+1);
}


void BinarySearch_NonRecursive(int key, struct BinaryNode* node)
{
    int comparisions = 0;
    while(node)
    {
        comparisions++;
        if(node->value == key)
        {
            printf("The key %d is found at %x after %d comparisions\n", key, (unsigned int)node, comparisions);
            return;
        }
        else if(node->value < key) node = node->greater;
        else node = node->smaller;
    }
    printf("Unable to find the key %d, even after ..%d comparisions\n", key, comparisions);
}

void main()
{
    int values[16] = {8, 1, 3, 5, 7, 9, 10, 12, 14, 11, 13, 15, 0, 2, 4, 6};
    int loop;
    
    for(loop = 0; loop < 16; loop++)
    {
        Insert(values[loop], root);
    }
    
    LinearSearch_NonRecursive(9, values, 16);
    LinearSearch_Recursive(9, values, 0, 16);
    
    BinarySearch_Recursive(9, root, 0);
    BinarySearch_NonRecursive(9, root);
    
    
    
    LinearSearch_NonRecursive(16, values, 16);
    LinearSearch_Recursive(17, values, 0, 16);
    
    BinarySearch_Recursive(18, root, 0);
    BinarySearch_NonRecursive(19, root);
    
    DeleteBinaryTree(root);
    
}
