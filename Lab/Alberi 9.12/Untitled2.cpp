#include <stdio.h>
#include <stdlib.h>

typedef struct a{
	int val;
	struct a *next;
}Nodo;
typedef Nodo *Lista;

typedef struct b{
	int val;
	struct b *right;
	struct b *left;
}Albero;
typedef albero *Tree;


Tree InsInFondo(int elem);
Tree alberoOrdinato(Tree root, Lista lista);
int main()
{
	
}

Tree alberoOrdinato(Tree root, Lista lista)
{
	if(lista == NULL)
		return root;
	if(root==NULL)
	{
		Tree temp = InsInFondo(lista->val);
		return temp;
	}
	if(root->val > lista->val)
		root->left = alberoOrdinato(root->left, lista);
	else
		root->right = alberoOrdinato(root->right, lista);
	
	root = alberoOrdinato(root, lista->next);
	return root;
}
Tree InsInFondo(int elem) 
{
	Tree punt = (tree)malloc(sizeof(Albero));
	punt->right = NULL; 
	punt->left = NULL;
	punt->val = elem; 
	return punt;
}
