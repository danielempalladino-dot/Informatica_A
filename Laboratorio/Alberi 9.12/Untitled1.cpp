#include <stdio.h>
#include <stdlib.h>


typedef struct t{
    char c;
    struct t* left;
    struct t* right;
} Nodo;
typedef Nodo* Tree;


Nodo* creaNodo(char c);
Tree costruisci();


// TODO: implementa funzioni
int profonditaMassimaRipetizione(Tree);
int prof(Tree, char value, int deep);

int main(){
    Tree t = costruisci();


    int prof_rip;


    // TODO: chiamata funzioni
    prof_rip =  profonditaMassimaRipetizione(t);


    printf("La profondita' massima alla quale si trova ripetuto il carattere '%c' e' %d\n", t->c, prof_rip);


    return 0;
}

int prof(Tree root, char value, int deep)
{
	if(root == NULL)
		return 0;
		
	int max = 0;
	
	if(root->c == value)
		max = deep;
	int sx = prof(root->left, value, deep +1);
	int dx = prof(root->right, value, deep +1);
	
	if(sx > max)
		max = sx;
	if(dx>max)
		max = dx;
		
	return max;
}
int profonditaMassimaRipetizione(Tree root)
{
	if(root==NULL)
		return 0;
	return prof(root, root->c, 1);
}


Nodo* creaNodo(char c){
    Nodo* nodo = (Nodo*) malloc(sizeof(Nodo));
    nodo->c = c;
    nodo->left = NULL;
    nodo->right = NULL;
    return nodo;
}


Tree costruisci(){
    Tree t = creaNodo('i');


    t->left = creaNodo('a');
    t->right = creaNodo('g');


    t->left->left = creaNodo('o');
    t->left->right = creaNodo('i');


    t->right->left = creaNodo('q');
    t->right->right = creaNodo('n');


    t->left->left->left = creaNodo('q');
    t->left->left->right = creaNodo('f');
    t->left->right->left = creaNodo('g');
    t->left->right->right = creaNodo('w');


    t->right->left->left = creaNodo('z');
    t->right->left->right = creaNodo('i');
    t->right->right->left = creaNodo('w');
    t->right->right->right = creaNodo('h');


    t->left->left->left->left = creaNodo('c');
    t->left->left->left->right = creaNodo('e');
    t->left->left->right->left = creaNodo('f');
    t->left->left->right->right= creaNodo('h');
    t->left->right->left->left = creaNodo('a');
    t->left->right->left->right = creaNodo('i');
    t->left->right->right->left = creaNodo('l');
    t->left->right->right->right = creaNodo('m');


    t->right->left->left->left = creaNodo('n');
    t->right->left->left->right = creaNodo('d');
    t->right->left->right->left = creaNodo('r');
    t->right->left->right->right= creaNodo('s');
    t->right->right->left->left = creaNodo('j');
    t->right->right->left->right = creaNodo('p');
    t->right->right->right->left = creaNodo('o');
    t->right->right->right->right = creaNodo('k');


    return t;
}

