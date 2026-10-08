#include <stdio.h>
#include <stdlib.h>
typedef struct El {
    char c;
    struct El * left, * right;
} Nodo;


typedef Nodo* Tree;


int wrap(Tree albero);
int verifica(Tree albero);
Tree costruisci1();
Tree costruisci2();
void visualizzaAlbero(Tree albero);


int main() {
    int risultato1,risultato2;
	Tree albero1,albero2;
    albero1=costruisci1();
    albero2=costruisci2();
    visualizzaAlbero(albero1);
    printf("\n");
    visualizzaAlbero(albero2);
    printf("\n");
    risultato1 = verifica(albero1);
    risultato2 = verifica(albero2);


    if (risultato1) {
        printf("Albero 1: albero ordinato\n");
    } else {
        printf("Albero 1: albero NON ordinato\n");
    }


    if (risultato2) {
        printf("Albero 2: albero ordinato\n");
    } else {
        printf("Albero 2: albero NON ordinato\n");
    }


    return 0;
}

int verifica(Tree albero)
{
	if(albero == NULL)
		return 1;
	if(wrap(albero)==0)
		return 1;
	return 0;
}

int wrap(Tree albero) {
	if(albero == NULL || albero->left == NULL || albero->right == NULL)
		return 0;
	Tree sx = albero-> left;
	Tree dx = albero->right;
	int flag = 0;
	if(albero->c > sx->c && albero->c < dx->c)
		flag = 0;
	else flag = 1;
    return flag + verifica(sx)+ verifica(dx);
}


void visualizzaAlbero(Tree albero) {
    if (albero == NULL) {
        return;
    }


    printf("(", albero->c);
    visualizzaAlbero(albero->left);


    printf("(%c)", albero->c);


    // Stampa i sottoalberi
    visualizzaAlbero(albero->right);
    printf(")", albero->c);


} 


Tree costruisci1(){
    Tree albero1;
    albero1 = (Tree)malloc(sizeof(Nodo));
    albero1->c = 'k';    albero1->left = (Tree)malloc(sizeof(Nodo));    albero1->left->c = 'd';    albero1->left->left = (Tree)malloc(sizeof(Nodo));    albero1->left->left->c = 'b';    albero1->left->left->left = NULL;    albero1->left->left->right = NULL;    albero1->left->right = NULL;    albero1->right = (Tree)malloc(sizeof(Nodo));    albero1->right->c = 'r';    albero1->right->left = (Tree)malloc(sizeof(Nodo));    albero1->right->left->c = 'q';    albero1->right->left->left = NULL;    albero1->right->left->right = NULL;    albero1->right->right = (Tree)malloc(sizeof(Nodo));    albero1->right->right->c = 'z';    albero1->right->right->left = NULL;    albero1->right->right->right = NULL;
	return albero1;
}


Tree costruisci2(){
    Tree albero2;
    albero2 = (Tree)malloc(sizeof(Nodo));
    albero2->c = 'k';    albero2->left = (Tree)malloc(sizeof(Nodo));    albero2->left->c = 'w';    albero2->left->left = (Tree)malloc(sizeof(Nodo));    albero2->left->left->c = 'b';    albero2->left->left->left = NULL;    albero2->left->left->right = NULL;    albero2->left->right = NULL;    albero2->right = (Tree)malloc(sizeof(Nodo));    albero2->right->c = 'p';    albero2->right->left = (Tree)malloc(sizeof(Nodo));    albero2->right->left->c = 'q';    albero2->right->left->left = NULL;    albero2->right->left->right = NULL;    albero2->right->right = (Tree)malloc(sizeof(Nodo));    albero2->right->right->c = 'z';    albero2->right->right->left = NULL;    albero2->right->right->right = NULL;
    return albero2;
}

