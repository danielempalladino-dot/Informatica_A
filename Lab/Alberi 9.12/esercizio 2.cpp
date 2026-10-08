#include <stdio.h>
#include <stdlib.h>


typedef struct n {
        int val;
        struct n * left;
		struct n * right;
} nodo;
typedef nodo * albero;


albero createVal(int val);
albero creaAlbero1();albero creaAlbero2();albero creaAlbero3();
void print(albero t);
void stampa(albero T);
int f(albero t);
int prova(albero, int);


int main(){
    int ris=0;
    albero T1,T2,T3;
    T1 = creaAlbero1(); T2 = creaAlbero2(); T3 = creaAlbero3();
    printf("\nT1: "); stampa(T1);
    printf("\nT2: "); stampa(T2);
    printf("\nT3: "); stampa(T3);


   //LA FUNZIONE DA SVILUPPARE VIENE USATA QUI
   




   if(f(T1)==1)
        printf("T1 ok\n");
    else printf("T1 non ok\n");


   if(f(T2)==1)
        printf("T2 ok\n");
    else printf("T2 non ok\n");


   if(f(T3)==1)
        printf("T3 ok\n");
    else printf("T3 non ok\n");


    return 0;
}


//
// TODO: SVILUPPARE QUI DENTRO QUANTO RICHIESTO
//

int f(albero t)
{
    return prova(t, 1);
}


int prova(albero root, int livello)
{
    if (root == NULL)
        return 1;   // nessuna violazione

    // controllo del nodo corrente
    if (root->val <= livello)
        return 0;

    // incremento corretto del livello
    return prova(root->left, livello + 1) &&
           prova(root->right, livello + 1);
}




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

