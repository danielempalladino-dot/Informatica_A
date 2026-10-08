#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//è sbagliato controllo vincitore ma solo perche non ho capito la consegna

typedef struct El {
    char nome[100];
    int punteggio;
    struct El *left, *right;
} Nodo;


typedef Nodo * Tree;


Tree nN(char nome[],int punteggio);
int altezza(Tree t);
void stampaSpazi(int n);
void stampaLivello(Tree t,int liv,int cur,int spaz);
void stampaAlbero(Tree t);
Tree costruisci1();
Tree costruisci2();
Tree costruisci3();
Tree costruisci4();
Tree costruisci5();
int controllaTorneo(Tree t);
int lunghezza(Tree t);
int controllol(Tree t);
int is_nodo_foglia(Tree t);
int controlloavanzamento(Tree t);
// TODO PROTOTIPI




int main(){
    Tree t1=costruisci1(),t2=costruisci2(),t3=costruisci3(),t4=costruisci4(),t5=costruisci5();
    stampaAlbero(t1);printf("\n");
    stampaAlbero(t2);printf("\n");
    stampaAlbero(t3);printf("\n");
    stampaAlbero(t4);printf("\n");
    stampaAlbero(t5);printf("\n");


	if(controllaTorneo(t1))
		printf("t1: OK\n");
	else printf("t1: NON OK\n");
	if(controllaTorneo(t2))
		printf("t2: OK\n");
	else printf("t2: NON OK\n");
	if(controllaTorneo(t3))
		printf("t3: OK\n");
	else printf("t3: NON OK\n");
	if(controllaTorneo(t4))
		printf("t4: OK\n");
	else printf("t4: NON OK\n");
	if(controllaTorneo(t5))
		printf("t5: OK\n");
	else printf("t5: NON OK\n");


    return 0;
}


//funzione da modificare e funzioni da aggiungere
int controllaTorneo(Tree t){
	//inserire qui codice
	if(controllol(t)!=0)
		return 0;
	if(is_nodo_foglia(t)!= 0)
		return 0;
	if(controlloavanzamento(t->left)!=0)
		return 0;
	if(controlloavanzamento(t->right)!=0)
		return 0;
	return 1;
}
int lunghezza(Tree t)
{
	if (t == NULL)
		return 0;
	int sx = lunghezza(t->left);
	int dx = lunghezza(t->right);
	if(sx>dx)
		return sx + 1;
	return dx + 1;
}

int controllol(Tree t)
{
	if (t== NULL)
		return 0;
	if (lunghezza(t->right)!=lunghezza(t->left))
		return 1;
	return controllol(t->right) + controllol(t->left);
}

int is_nodo_foglia(Tree t)
{
	if(t == NULL)
		return 0;
	if ((t->left == NULL && t->right != NULL)||(t->left != NULL && t->right == NULL))
		return 1;
	return is_nodo_foglia(t->left) + is_nodo_foglia(t->right);
}

int controlloavanzamento(Tree t)
{
	if(t == NULL || t->left == NULL || t->right == NULL)
		return 0;
	int flag = 0;
	Tree sx = t->left, dx = t->right;
	
	if((sx->punteggio > dx->punteggio) && (strcmp(sx->nome, t->nome) == 0))
		flag = 0;
	else if ((dx->punteggio > sx->punteggio) && (strcmp(dx->nome, t->nome) == 0))
		flag = 0;
	else flag = 1;
	return flag + controlloavanzamento(sx) + controlloavanzamento(dx);
	
}

Tree nN(char nome[],int punteggio){
    Tree nodo=(Tree)malloc(sizeof(Nodo));
    nodo->punteggio=punteggio;strcpy(nodo->nome,nome);
    nodo->left=NULL;nodo->right=NULL;
    return nodo;
}
int altezza(Tree t){int l,r;if(t==NULL)return 0;else{l=altezza(t->left);r=altezza(t->right);if(l>r)return(l+1);else return(r+1);}}
void stampaSpazi(int n){int i;for(i=0;i<n;i++){printf(" ");}}
void stampaLivello(Tree t,int liv,int cur,int spazi){
    if(t==NULL){if(liv>=cur)stampaSpazi(spazi);return;}
    if(liv==cur){stampaSpazi(spazi/4-4);printf("%s(%d)",t->nome,t->punteggio);stampaSpazi(spazi/4-4);}else if(liv>cur){stampaLivello(t->left,liv,cur+1,spazi/2);stampaLivello(t->right,liv,cur+1,spazi/2);}
}
void stampaAlbero(Tree t){int i,h=altezza(t);for(i=1;i<=h;i++){stampaLivello(t,i,1,100);printf("\n");}}
Tree costruisci1(){Tree r=nN("GG",0);r->left=nN("CC",50);r->right=nN("GG",80);r->left->left=nN("CC",100);r->left->right=nN("AA",90);r->right->left=nN("GG",30);r->right->right=nN("BB",20);return r;}
Tree costruisci2(){Tree r=nN("GG",0);r->left=nN("CC",50);r->right=nN("GG",80);r->left->left=nN("CC",100);r->left->right=nN("AA",90);r->right->left=nN("GG",30);r->right->right = nN("BB",50);return r;}
Tree costruisci3(){Tree r=nN("GG",0);r->left=nN("CC",50);r->right=nN("GG",80);r->left->left=nN("CC",100);r->right->left=nN("GG",30);r->right->right=nN("BB",20);return r;}
Tree costruisci4(){Tree r=nN("GG",0);r->left=nN("CC", 50);r->right=nN("GG",80);r->left->left=nN("CC",100);r->left->right=nN("AA",90);r->right->left=nN("GG",30);r->right->right=nN("BB",20);r->right->right->right=nN("BB",50);r->right->right->left=nN("DD",10);return r;}
Tree costruisci5(){Tree r=nN("GG",0);r->left=nN("CC",50);r->right=nN("GG",80);r->left->left=nN("CC",100);r->left->right=nN("AA",90);r->right->left=nN("HH",30);r->right->right=nN("BB",20);return r;}

