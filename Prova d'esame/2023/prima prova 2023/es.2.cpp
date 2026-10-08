#include <stdio.h>
#include <stdlib.h>
//chat gpt

typedef struct n {
        char val;
        struct n * left;
		struct n * right;
} nodo;
typedef nodo * albero;


albero createVal(char val);
albero creaAlbero1();albero creaAlbero2();albero creaAlbero3();
void print(albero t);
void stampa(albero T);
int f(albero t,char str[]);
int cerca1(albero t, char c);

int main(){
    int ris=0;
    char str1[100]="acacia",str2[100]="sacca";
    albero T1,T2,T3;
    T1 = creaAlbero1(); T2 = creaAlbero2(); T3 = creaAlbero3();
    printf("\nT1: "); stampa(T1);
    printf("\nT2: "); stampa(T2);
    printf("\nT3: "); stampa(T3);
    printf("\n");


   //LA FUNZIONE DA SVILUPPARE VIENE USATA QUI




   printf("%d\n",f(T1,str1));
   printf("%d\n",f(T1,str2));
   printf("%d\n",f(T2,str1));
   printf("%d\n",f(T2,str2));
   printf("%d\n",f(T3,str1));
   printf("%d\n",f(T3,str2));
   
   return 0;
}


//
// TODO: SVILUPPARE QUI DENTRO QUANTO RICHIESTO
//
// Ausiliaria: verifica ricorsivamente che *tutti* i cammini da t a foglia
// abbiano esattamente 2 occorrenze di lettere presenti in str (come insieme).
static int checkAllPaths(albero t, int count, const int present[26]) {
    if (t == NULL) return 1; // nessun cammino da controllare in questo ramo

    // aggiorna conteggio se la lettera del nodo e' presente nella stringa
    if (t->val >= 'a' && t->val <= 'z') {
        count += present[t->val - 'a'];
    }

    // foglia: il cammino termina qui
    if (t->left == NULL && t->right == NULL) {
        return (count == 2);
    }

    // nodo interno: devono essere veri tutti i rami esistenti
    int ok = 1;
    if (t->left)  ok = ok && checkAllPaths(t->left,  count, present);
    if (t->right) ok = ok && checkAllPaths(t->right, count, present);
    return ok;
}

int f(albero t, char str[]) {
    // Costruisco la "membership table" delle lettere presenti in str
    int present[26] = {0};
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            present[str[i] - 'a'] = 1; // insieme: duplicati ignorati
        }
    }

    // Se vuoi trattare l'albero vuoto come "vacuamente vero", restituisci 1.
    // Qui assumiamo albero non vuoto; in caso contrario ritorniamo 0.
    if (t == NULL) return 0;

    return checkAllPaths(t, 0, present);
}


albero creaAlbero1() {
    albero tmp = createVal('a');
    tmp->left = createVal('c');tmp->left->left = createVal('o');tmp->left->right = createVal('b');
    tmp->right = createVal('d');tmp->right->left = createVal('c');tmp->right->right = createVal('r');
    tmp->right->right->left = createVal('c'); tmp->right->right->right = createVal('a');
    return tmp;
}


albero creaAlbero2() {
    albero tmp = createVal('a');
    tmp->left = createVal('c');tmp->left->left = createVal('o');tmp->left->right = createVal('b');
    tmp->right = createVal('d');tmp->right->left = createVal('c');tmp->right->right = createVal('a');
    tmp->right->right->left = createVal('c'); tmp->right->right->right = createVal('a');
    return tmp;
}


albero creaAlbero3() {
    albero tmp = createVal('s');
    tmp->left = createVal('c');tmp->left->left = createVal('o');tmp->left->right = createVal('b');
    tmp->right = createVal('d');tmp->right->left = createVal('c');tmp->right->right = createVal('r');
    tmp->right->right->left = createVal('c'); tmp->right->right->right = createVal('a');
    return tmp;
}


void print(albero t){
       if(t==NULL)return;       
       else{printf(" (");print(t->left);printf(" %c ",t->val);print(t->right);printf(") ");}       
}


void stampa(albero T){print(T);printf("\n");}


albero createVal(char val) {
    albero tmp = (albero)malloc(sizeof(nodo));
    tmp->val = val;    tmp->left = NULL;    tmp->right = NULL;
    return tmp;
}

