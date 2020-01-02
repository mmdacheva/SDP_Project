#pragma once
#include "Plane.h"

struct Node {
	Plane value;
	Node* left, * right;

	Node(const Plane& value) : value(value), left(nullptr), right(nullptr) {}
};

class BST {
	Node* root;

	void deleteNode(Node* node);
	void insertNode(Node*& node, const Plane& pl);
	Plane& searchNode(Node* root, unsigned long long id);

public:
	BST();
	BST(const BST&) = delete;
	BST& operator=(const BST&) = delete;
	~BST();

	void reset();
	void clear();

	void insert(const Plane& pl);
	Plane& search(unsigned long long id);
	void inOrder(Node* root);
	void print();
};

