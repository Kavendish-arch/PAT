
typedef struct BinaryNode{
	ElemtType data;

	struct BinaryNode * left_child;
	struct BinaryNode * right_child;

}

initTree(){

}

Status create_binary_tree(){

}


Status pre_order_traverse(BinaryNode T ){
	visit(T->data);
	pre_order_traverse(T->left_child);
	pre_order_traverse(T->right_child);
}

Status in_order_traverse(BinaryNode T ){
	pre_order_traverse(T->left_child);
	visit(T->data);
	pre_order_traverse(T->right_child);
}

Status pre_order_traverse(BinaryNode T ){
	visit(T->data);
	pre_order_traverse(T->left_child);
	pre_order_traverse(T->right_child);
}
