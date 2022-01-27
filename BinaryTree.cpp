#include <stdio.h>
#include <stdlib.h>

typedef char TElement;
typedef struct BinTrNode {
	TElement data;
	struct BinTrNode* left;
	struct BinTrNode* right;
} TNode;

TNode* root = NULL;

typedef int Element;
typedef struct LinkedNode {
	TNode* data;
	struct LinkedNode* link;
}Node;

Node* front = NULL;
Node* rear = NULL;

void error(const char* str) {
	fprintf(stderr, "%s\n", str);
	exit(1);
}
Element is_empty() { return front == NULL; }
void init_queue() { front = rear = NULL; }

int size() {
	Node* p;
	int count = 0;
	for (p = front; p != NULL; p = p->link)
		count++;
	return count;
}

void enqueue(TNode* e) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->link = NULL;
	if (is_empty())
		front = rear = p;
	else {
		rear->link = p;
		rear = p;
	}
}

TNode* dequeue() {
	Node* p;
	TNode* e;

	if (is_empty())
		error("큐 공백 에러");
	p = front;
	front = front->link;
	if (front == NULL)
		rear = NULL;
	e = p->data;
	free(p);

	return e;
}


void initTree() {
	root = NULL;
}

int isEmpty() {
	return root == NULL;
}

TNode* getRoot() {
	return root;
}

TNode* createTree(TElement val, TNode* l, TNode* r) {
	TNode* n = (TNode*)malloc(sizeof(TNode));
	n->data = val;
	n->left = l;
	n->right = r;
	return n;
}

void preOrder(TNode* n) {
	if (n != NULL) {
		printf("[%c] ", n->data);
		preOrder(n->left);
		preOrder(n->right);
	}
}

void inOrder(TNode* n)
{
	if (n != NULL) {
		inOrder(n->left);
		printf("[%c] ", n->data);
		inOrder(n->right);
	}
}

void postOrder(TNode* n)
{
	if (n != NULL) {
		postOrder(n->left);
		postOrder(n->right);
		printf("[%c] ", n->data);
	}
}

void levelOrder(TNode* root) {
	TNode* n;


	init_queue();

	if (root == NULL)
		return;

	enqueue(root);
	while (!is_empty()) {
		n = dequeue();
		if (n != NULL) {
			printf("[%c] ", n->data);
			enqueue(n->left);
			enqueue(n->right);
		}
	}
}

int main() {
	TNode* b, * c, * d, * e, * f;
	initTree();
	d = createTree('D', NULL, NULL);
	e = createTree('E', NULL, NULL);
	b = createTree('B', d, e);
	f = createTree('F', NULL, NULL);
	c = createTree('C', f, NULL);
	root = createTree('A', b, c);

	printf("\n	   In-Order : ");
	inOrder(root);
	printf("\n	  Pre-Order : ");
	preOrder(root);
	printf("\n	 Post-Order : ");
	postOrder(root);
	printf("\n	Level-Order : ");
	levelOrder(root);
}
