#include "BST.h"

void BST::deleteNode(Node* node) {
	if (node->left)
		deleteNode(node->left);
	if (node->right)
		deleteNode(node->right);

	delete node;
}

void BST::clear() {
	deleteNode(root);
}

BST::BST() {
	reset();
}

BST::~BST() {
	clear();
}

void BST::reset() {
	root = nullptr;
}

void BST::insertNode(Node*& node, const Plane& pl) {
	if (!node)
		node = new Node(pl);
	else 
		(pl > node->value) ? insertNode(node->right, pl) : insertNode(node->left, pl);
}

void BST::insert(const Plane& pl) {
	insertNode(root, pl);
}

Plane& BST::search(unsigned long long id) {
	return searchNode(root, id);
}

Plane& BST::searchNode(Node* root, unsigned long long id) {
	if (!root || root->value.getID() == id) return root->value;
	if (id < root->value.getID()) return searchNode(root->left, id);
	return searchNode(root->right, id);
}

void BST::inOrder(Node* root) {
	if (root) {
		inOrder(root->left);
		std::cout << root->value;
		inOrder(root->right);
	}
}

void BST::print() {
	inOrder(root);
}
