int sommaFoglie(Tree root)
{
	//caso base albero vuoto
	if(root == NULL)
		return 0
	// caso base sono una foglia
	if(root->left == NULL && root->right == NULL)
		return root->data;
	//somma ricorsiva
	return sommaFoglie(root->left) + sommaFoglie(root->right);
}

int trovaNodo(Tree root, int value)
{
	//caso base -> albero vuoto
	if(root == NULL)
		return 0;
	//caso base --> trovi un valore, si ferma la ricorsione
	if(root->data == value)
		return 1;
		
	return trovaNodo(root->left, value) || trovaNodo(root->right, value);
}

int verificaSommaUgualeNodo(Tree root1, Tree root2)
{
	int value = sommaFoglie(root2);
	if(trovaNodo(root1, value)) //restituisce 1 o 2 --> booleano
		return 1;
	value = sommaFoglie(root1);
	if(trovaNodo(root2, value))
		return 1;
	return 0; 
}


