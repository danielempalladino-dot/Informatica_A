#include <stdio.h>
#include <stdlib.h>


typedef struct n {
        int val;
        struct n * left;
struct n * right;
} nodo;
typedef nodo * albero;


albero createVal(int val);
albero creaAlbero1(); albero creaAlbero2(); albero creaAlbero3();
void print(albero t);
void stampa(albero T);
int confronto (albero, albero);
int valoriInComune (albero, albero);


int main(){
    int ris=0;
    albero T1,T2,T3;
    T1 = creaAlbero1(); T2 = creaAlbero2(); T3 = creaAlbero3();
    printf("\nT1: "); stampa(T1);
    printf("\nT2: "); stampa(T2);
    printf("\nT3: "); stampa(T3);


   //LA FUNZIONE valoriInComune  VIENE INVOCATA QUI
	ris = valoriInComune(T1, T2);
	printf("%d\n", ris);
	ris = valoriInComune(T1, T3);
	printf("%d\n", ris);
	ris = valoriInComune(T2, T3);
	printf("%d\n", ris);
	

   //VIENE STAMPATO IL RISULTATO DELLE INVOCAZIONI PER RESTITUIRE COME DA ESEMPIO 


    return 0;
}

int valoriInComune(albero T1, albero T2)
{
	int ris = 0;
	if(T1 == NULL)
		return 0;
	ris = confronto(T1, T2);
	ris = ris + valoriInComune(T1->left, T2) + valoriInComune(T1->right, T2);
	
	return ris;
	
}

int confronto(albero T1, albero T2)
{
	int ris = 0;
	if (T2 == NULL)
		return 0;
	ris = confronto(T1,T2->left) + confronto(T1, T2->right);
	if(T1->val == T2->val)
		ris++;
	return ris;	
}

//
// TODO: SVILUPPARE QUI valoriInComune 
//


albero creaAlbero1() {
    albero tmp = createVal(7);
    tmp->left = createVal(3);tmp->left->left = createVal(9);tmp->left->right = createVal(10);
    tmp->right = createVal(8);tmp->right->left = createVal(5);tmp->right->right = createVal(12);
    tmp->right->right->left = createVal(11); tmp->right->right->right = createVal(6);
    return tmp;
}


albero creaAlbero2() {
    albero tmp = createVal(7);
    tmp->right = createVal(3);tmp->right->right = createVal(9);tmp->right->left = createVal(10);
    tmp->left = createVal(1);tmp->left->right = createVal(5);tmp->left->left = createVal(12);
    tmp->left->left->right = createVal(11);tmp->left->left->left = createVal(6);
    return tmp;
}


albero creaAlbero3() {
    albero tmp = createVal(7);
    tmp->right = createVal(3);tmp->right->right = createVal(9);tmp->right->left = createVal(10);
    tmp->left = createVal(4);tmp->left->right = createVal(5);tmp->left->left = createVal(12);
    tmp->left->left->right = createVal(2);tmp->left->left->left = createVal(6);
    return tmp;
}


void print(albero t){
       if(t==NULL)return;       
       else{printf(" (");print(t->left);printf(" %d ",t->val);print(t->right);printf(") ");}       
}


void stampa(albero T){print(T);printf("\n");}


albero createVal(int val) {
    albero tmp = (albero)malloc(sizeof(nodo));
    tmp->val = val;    tmp->left = NULL;    tmp->right = NULL;
    return tmp;
}

