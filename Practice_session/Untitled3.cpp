typedef struct TreeNode{
	int value;
	struct TreeNode *right;
	struct TreeNode *left;
}TreeNode;
typedef TreeNode *Tree;

typedef struct CountNode{
	int value;
	int count;
	struct CountNode *next;
}CountNode;
typedef CountNode é pCountNode;

int verificKElementi(Tree root, int k); 
pCountNode popolaLista(Tree root, pCountNode head);
//popola la lista e scorre l'abero e chiama aggiorna lista 
//con il valore che trova
pCountNode aggiornaLista(pCountNode head, int value);
//guarda se nella lista c'è value --> incrementa
//altrimeni aggiunge il nodo
int controllaLista(pCountNode head, int k);

int controllaLista(pCountNode head, int k) //controllo la lista se ce un contatore = k
{
	while (head != NULL)
	{
		if(head->count == k) //albero ha k elementi uguali con quel valore
			return 1;
		head = head->next;
	}
	return 0;
}

pCountNode popolaLista(Tree root, pCountNode head)
{
	if(root == NULL)
		return head;
	head = aggiornaLista(head, root->data); 
	//controlla nella lista se c'è gia il valore oppure crea un nuovo nodo
	head = popolaLista(root->left, head);
	head = popolaLista(root->right, head);
}

pCountNode aggiornaLista(pCountNode head, int value)
{
	//caso base --> lista vuota
	if(head == NULL)
	{
		head = malloc(sizeof(CountNode));
		head->value = value;
		head->count = 1;
		head->next = NULL;
		return head;
	}
	//caso base --> ho trovato il mio valore
	if(head->value == value)
	{
		head->count++;
		return head;
	}
	head->next = aggiornaLista(head->next, value);
	return head;
}

int verificKElementi(Tree root, int k) 
//crea la lista e la controlla se c'è un elemento presente k volte
{
	pCountNode head = popolaLista(root, NULL);
	return controllaLista(head, k);
}
