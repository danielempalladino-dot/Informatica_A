#include <stdio.h>
#include <stdlib.h>

// Struttura dell'albero binario
typedef struct ET {
    int val;
    struct ET *left, *right;
} treeNode;

typedef treeNode *tree;

// Funzioni
int numeroNodi(tree root);
int valoreNodi(tree root);
float media (tree root);
tree cn(int val);
void stampaAlbero(tree r, int spazio);
int checkTree(tree root);
int checkTree1(tree r);
tree costruisciAlbero1();
tree costruisciAlbero2();
tree costruisciAlbero3();
tree costruisciAlbero4();

int main() {
    tree t1=costruisciAlbero1();
    tree t2=costruisciAlbero2();
    tree t3=costruisciAlbero3();
    tree t4=costruisciAlbero4();

    printf("Albero 1: %d\n", checkTree(t1));
    printf("Albero 2: %d\n", checkTree(t2));
    printf("Albero 3: %d\n", checkTree(t3));
    printf("Albero 4: %d\n", checkTree(t4));

    return 0;
}
int checkTree(tree root)
{
	if (root == NULL)
		return 0;
	return (checkTree1(root->left) + checkTree1(root->right) == 0);
}
int checkTree1(tree root) {
	//FUNZIONE DA SCRIVERE
	if (root == NULL)
        return 0;

    // foglia: sempre soddisfatta
    if (root->left == NULL && root->right == NULL)
        return 0;

    // se non è foglia, devono esistere entrambi i sottoalberi
    if (root->left == NULL || root->right == NULL)
        return 1 + checkTree1(root->left) + checkTree1(root->right);

    // condizione: entrambe le medie dei due sottoalberi > valore del nodo
    if (media(root->left) > root->val && media(root->right) > root->val)
        return checkTree1(root->left) + checkTree1(root->right);

    return 1 + checkTree1(root->left) + checkTree1(root->right);
}

//AGGIUNGERE QUI FUNZIONI AUSILIARIE
int numeroNodi(tree root)
{
	if(root == NULL)
		return 0;
		
	return 1+ numeroNodi(root->left) + numeroNodi(root->right);
}

int valoreNodi(tree root)
{
	if(root == NULL)
		return 0;
	return root->val + valoreNodi(root->left) + valoreNodi(root->right);
	
}

float media(tree root)
{
	if(root == NULL)
		return 0;
	float valori = (float)valoreNodi(root);
	float nNodi = (float)numeroNodi(root);
	return valori/nNodi;
}

tree cn(int val){
    tree newNode=(tree)malloc(sizeof(treeNode));
    newNode->val=val;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

tree costruisciAlbero1(){
    tree r=cn(1);
    r->left=cn(5);
    r->right=cn(7);
    r->left->left=cn(21);
    r->left->right=cn(38);
    r->right->left=cn(12);
    r->right->right=cn(24);
    r->left->left->left=cn(100);
    r->left->left->right=cn(83);
    r->left->right->left=cn(67);
    r->right->right->left=cn(91);
    r->right->right->right=cn(75);
    return r;
}

tree costruisciAlbero2(){
    tree r=cn(8);
    r->left=cn(4);
    r->right=cn(2);
    r->left->left=cn(6);
    r->left->right=cn(11);
    r->right->left=cn(10);
    r->right->right=cn(14);
    r->left->left->left=cn(18);
    r->left->left->right=cn(30);
    r->left->right->left=cn(54);
    r->right->right->left=cn(72);
    r->right->right->right=cn(75);
    return r;
}

tree costruisciAlbero3(){
    tree r=cn(10);
    r->left=cn(5);
    r->right=cn(15);
    r->left->left=cn(1);
    r->left->right=cn(7);
    r->right->left=cn(12);
    r->right->right=cn(20);
    r->left->left->left=cn(0);
    r->left->left->right=cn(2);
    r->left->right->left=cn(6);
    r->right->right->left=cn(18);
    r->right->right->right=cn(5);
    return r;
}

tree costruisciAlbero4(){
    tree r=cn(9);
    r->left=cn(4);
    r->right=cn(14);
    r->left->left=cn(1);
    r->left->right=cn(6);
    r->right->left=cn(10);
    r->right->right=cn(18);
    r->left->left->left=cn(0);
    r->left->left->right=cn(2);
    r->left->right->left=cn(5);
    r->right->right->left=cn(17);
    r->right->right->right=cn(30);
    return r;
}

