#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
	struct tree *left;
	struct tree *right;
	int data;
}Tree;

typedef Tree *Btree;

Btree tree_insert(Btree bt, int newdata);
Btree tree_delete(Btree bt, int data);
void inorder_trav(Btree bt);
void preorder_trav(Btree bt);
void postorder_trav(Btree bt);
int search(Btree bt, int val);
int level(Btree bt, int val);
int level_tail(Btree bt, int val, int res);
int height(Btree bt);
Btree parent(Btree bt, int data, Btree p);

int main()
{
	Btree bt=NULL;
	bt=tree_insert(bt,15);
	bt=tree_insert(bt,25);
	bt=tree_insert(bt,10);
	bt=tree_insert(bt,5);
	bt=tree_insert(bt,3);
	bt=tree_insert(bt,12);
	bt=tree_insert(bt,11);
	bt=tree_insert(bt,13);
	bt=tree_insert(bt,35);
	bt=tree_insert(bt,28);
	bt=tree_insert(bt,40);
	printf("\n\n");
	inorder_trav(bt);
	printf("\n\n");
	preorder_trav(bt);
	printf("\n\n");
	postorder_trav(bt);
	printf("\n\n");
	printf("The height of the tree is %d\n\n\n",height(bt));

/*	if(search(bt,8))
		printf("8 is in Btree\n");
	else
		printf("8 is NOT in Btree\n");
	if(search(bt,9))
		printf("9 is in Btree\n");
	else
		printf("9 is NOT in Btree\n");
	if(search(bt,10))
		printf("10 is in Btree\n");
	else
		printf("10 is NOT in Btree\n");
	if(search(bt,6))
		printf("6 is in Btree\n");
	else
		printf("6 is NOT in Btree\n");
	if(search(bt,3))
		printf("3 is in Btree\n");
	else
		printf("3 is NOT in Btree\n");
	printf("level of 4 = %d\n",level(bt,4));
	printf("level of 4_Tail Rec = %d\n",level_tail(bt,4,0));
	printf("level of 5 = %d\n",level(bt,5));
	printf("level of 5_Tail Rec = %d\n",level_tail(bt,5,0));
	printf("level of 7 = %d\n",level(bt,7));
	printf("level of 7_Tail Rec = %d\n",level_tail(bt,7,0));
	printf("level of 8 = %d\n",level(bt,8));
	printf("level of 9 = %d\n",level(bt,9));
	printf("level of 12 = %d\n",level(bt,12));
	printf("level of 14 = %d\n",level(bt,14));
	printf("level of 10 = %d\n",level(bt,10));
	printf("level of 6 = %d\n",level(bt,6));
	printf("level of 3 = %d\n",level(bt,3));
	printf("level of 16 = %d\n",level(bt,16));
*/
	
	bt=tree_delete(bt,15);
	inorder_trav(bt);
	printf("\n\n");
	bt=tree_delete(bt,10);
	inorder_trav(bt);
	printf("\n\n");
	bt=tree_delete(bt,5);
	inorder_trav(bt);
	printf("\n\n");
	bt=tree_delete(bt,28);
	inorder_trav(bt);
	printf("\n\n");
/*	bt=tree_delete(bt,12);
	inorder_trav(bt);
	printf("\n\n");
	bt=tree_delete(bt,9);
	inorder_trav(bt);
	printf("\n\n");
	bt=tree_delete(bt,8);
	inorder_trav(bt);
	printf("\n\n");
*/
	return 0;
}


Btree tree_insert(Btree bt, int newdata)
{
	if(bt==NULL)
	{	Btree b;
		b=(Btree)malloc(sizeof(Tree));
		b->data=newdata;
		b->left=NULL;
		b->right=NULL;
		return b;
	}
	else if(bt->data==newdata)
		return bt;
	else if(bt->data > newdata)
	{	bt->left=tree_insert(bt->left,newdata);
		return bt;
	}
	else
	{	bt->right=tree_insert(bt->right,newdata);
		return bt;
	}
}

Btree tree_delete(Btree bt, int data)
{	Btree p=NULL;
	Btree cur=NULL;
	Btree curSucc=NULL;
	if(bt==NULL)
		return bt;
	else if(bt->data==data)
	{	cur=bt;
	}
	else
	{	p=parent(bt,data,NULL);
		if(p!=NULL)
		{	if((p->left!=NULL)&&(p->left->data==data))
				cur=p->left;
			else
				cur=p->right;
		}
		else
		{			printf("No such element available\n");
			return bt;
		}
	}
	if((cur->left!=NULL)&&(cur->right!=NULL))
	{	p=cur;
		curSucc=cur->right;
		while(curSucc->left!=NULL)
		{		p=curSucc;
			curSucc=curSucc->left;
		}
		cur->data=curSucc->data;
		cur=curSucc;
	}
	if((cur->left==NULL)&&(cur->right==NULL))
	{	if(p==NULL)
			return NULL;
		else
		{			if(p->right==cur)
				p->right=NULL;
			else
				p->left=NULL;
			free(cur);
			return bt;
		}
	}
	if((cur->left==NULL)&&(cur->right!=NULL))
	{	if(p==NULL)
		{			bt=cur->right;
		}
		else
		{		if(p->left==cur)
				p->left=cur->right;
			else
				p->right=cur->right;
		}
		free(cur);
		return bt;
	}
	if((cur->left!=NULL)&&(cur->right==NULL))
	{		if(p==NULL)
		{			bt=cur->left;
		}
		else
		{			if(p->left==cur)
				p->left=cur->left;
			else

				p->right=cur->left;
		}
		free(cur);
		return bt;
	}
	return bt;
}

Btree parent(Btree bt, int data, Btree p)
{	if(bt==NULL)
		return NULL;
	else if(bt->data==data)
		return p;
	else if(bt->data > data)
	{	p=bt;
		return (parent(bt->left,data,p));
	}
	else
	{	p=bt;
		return (parent(bt->right,data,p));
	}
}

void inorder_trav(Btree bt)
{	if(bt!=NULL)
	{		inorder_trav(bt->left);
		printf("%d\t",bt->data);
		inorder_trav(bt->right);
	}
}

void preorder_trav(Btree bt)
{	if(bt!=NULL)
	{	printf("%d\t",bt->data);
		preorder_trav(bt->left);
		preorder_trav(bt->right);
	}
}

void postorder_trav(Btree bt)
{	if(bt!=NULL)
	{	postorder_trav(bt->left);
		postorder_trav(bt->right);
		printf("%d\t",bt->data);
	}
}

int search(Btree bt, int val)
{	if(bt==NULL)
		return 0;
	else if(bt->data==val)
		return 1;
	else if(bt->data > val)
		return search(bt->left,val);
	else
		return search(bt->right,val);
}

int level(Btree bt, int val)
{	int x;
	if (bt==NULL)
		return -1;
	else if(bt->data==val)
		return 0;
	else if(bt->data > val)
	{	x=level(bt->left,val);
		if(x>=0)
			return 1+x;
		else
			return x;
	}
	else
	{	x=level(bt->right,val);
		if(x>=0)
			return 1+x;
		else
			return x;
	}
}

int level_tail(Btree bt, int val, int res)
{	if (bt==NULL)
		return -1;
	else if(bt->data==val)
		return res;
	else if(bt->data > val)
		return level_tail(bt->left,val,res+1);
	else
		return level_tail(bt->right,val,res+1);
}

int height(Btree bt)
{	int x,y;
	if (bt==NULL)
		return -1;
	else
	{	x=height(bt->left);
		y=height(bt->right);
		if(x>y)
			return 1+x;
		else
			return 1+y;
	}
}
