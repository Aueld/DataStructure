#include <stdio.h>
#include <stdlib.h>

typedef int TElement;
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
		printf("[%d] ", n->data);
		preOrder(n->left);
		preOrder(n->right);
	}
}

void inOrder(TNode* n)
{
	if (n != NULL) {
		inOrder(n->left);
		printf("[%d] ", n->data);
		inOrder(n->right);
	}
}

void postOrder(TNode* n)
{
	if (n != NULL) {
		postOrder(n->left);
		postOrder(n->right);
		printf("[%d] ", n->data);
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
			printf("[%d] ", n->data);
			enqueue(n->left);
			enqueue(n->right);
		}
	}
}

int countNode(TNode* n)
{
	if (n == NULL) return 0;
	return 1 + countNode(n->left) + countNode(n->right);
}

int countLeaf(TNode* n)
{
	if (n == NULL) return 0;
	if (n->left == NULL && n->right == NULL) return 1;
	else return countLeaf(n->left) + countLeaf(n->right);
}

int calcHeight(TNode* n)
{
	int hLeft, hRight;
	if (n == NULL) return 0;
	hLeft = calcHeight(n->left);
	hRight = calcHeight(n->right);
	return (hLeft > hRight)
		? hLeft + 1 : hRight + 1;
}

int evaluate(TNode* n) {
	int op1, op2;
	if (n == NULL)
		return 0;
	if (n->left == NULL && n->right == NULL)
		return n->data;
	else {
		op1 = evaluate(n->left);
		op2 = evaluate(n->right);
		switch (n->data) {
		case '+': return op1 + op2;
		case '-': return op1 - op2;
		case '*': return op1 * op2;
		case '/': return op1 / op2;
		}
		return 0;
	}
}

TNode* search(TNode* n, int key) {
	if (n == NULL)
		return NULL;
	else if (key == n->data)
		return n;
	else if (key < n->data)
		return search(n->left, key);
	else
		return search(n->right, key);
}

void searchBST(int key) {
	TNode* n = search(root, key);
	if (n != NULL)
		printf("[탐색 연산] : 성공 [%d] = 0x%x\n", n->data, n);
	else
		printf("[탐색 연산] : 실패 No %d!\n", key);
}

int insert(TNode* r, TNode* n) {
	if (n->data == r->data)
		return 0;
	else if (n->data < r->data) {
		if (r->left == NULL)
			r->left = n;
		else
			insert(r->left, n);
	}
	else {
		if (r->right == NULL)
			r->right = n;
		else
			insert(r->right, n);
	}

	return 1;
}

void insertBST(int key) {
	TNode* n = createTree(key, NULL, NULL);
	if (isEmpty())
		root = n;
	else if (insert(root, n) == 0)
		free(n);
}

void delete1(TNode* parent, TNode* node) {
	TNode* child, * succ, * succp;

	//case 1 단말 노드 삭제
	if ((node->left == NULL && node->right == NULL)) {
		if (parent == NULL)
			root = NULL;
		else {
			if (parent->left == node)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
	}

	//case 2 하나의 서브트리만 가진 경우 삭제
	if (node->left == NULL || node->right == NULL) {
		child = (node->left != NULL) ? node->left : node->right;
		if (node == root) root = child;
		else {
			if (parent->left == node)
				parent->left = child;
			else parent->right = child;
		}
	}

	//case 3 두개의 서브트리를 모두 가진 경우
	else {
		succp = node;
		succ = node->right;
		while (succ->left != NULL) {
			succp = succ;
			succ = succ->left;
		}
		if (succp->left == succ)
			succp->left = succ->right;
		else succp->right = succ->right;
		node->data = succ->data;
		node = succ;
	}
	free(node);
}

void deleteBST(int key) {
	TNode* parent = NULL;
	TNode* node = root;

	if (node == NULL)
		return;
	while (node != NULL && node->data != key) {
		parent = node;
		node = (key < node->data) ? node->left : node->right;
	}
	if (node == NULL)
		printf("Error");
	else
		delete1(parent, node);
}

int main() {
	printf("\n[삽입 연산]: 34 18 7 26 12 3 68 22 30 99");

	initTree();

	insertBST(35); insertBST(18); insertBST(7); insertBST(26);
	insertBST(12); insertBST(3); insertBST(68); insertBST(22);
	insertBST(30); insertBST(99);

	printf("\n   In-Order : "); inOrder(root);
	printf("\n  Pre-Order : "); preOrder(root);
	printf("\n Post-Order : "); postOrder(root);
	printf("\nLevel-Order : "); levelOrder(root);

	printf("\n노드의 개수 = %d\n", countNode(root));
	printf("단말의 개수 = %d\n", countLeaf(root));
	printf("트리의 높이 = %d\n", calcHeight(root));

	searchBST(26);
	searchBST(25);

	printf("\noriginal bintree : LevelOrder :"); levelOrder(root);
	deleteBST(3);
	printf("\ncase 1: <3> 삭제 : LevelOrder :"); levelOrder(root);
	deleteBST(68);
	printf("\ncase 2: <68> 삭제 : LevelOrder :"); levelOrder(root);
	deleteBST(18);
	printf("\ncase 3: <18> 삭제 : LevelOrder :"); levelOrder(root);
	deleteBST(35);
	printf("\ncase 3: <35> root : LevelOrder :"); levelOrder(root);


	printf("\n노드의 개수 = %d\n", countNode(root));
	printf("단말의 개수 = %d\n", countLeaf(root));
	printf("트리의 높이 = %d\n", calcHeight(root));
}