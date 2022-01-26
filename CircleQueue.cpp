#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

typedef int Element;
Element data[MAX_QUEUE_SIZE];
int front, rear;

void init_queue() { front = rear = 0; ; }
Element is_empty() { return front == rear; }
Element is_full() { return front == (rear + 1) % MAX_QUEUE_SIZE; }
Element size() { return (rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; }

void error(const char* str) {
	fprintf(stderr, "%s\n", str);
	exit(1);
};

void enqueue(Element val) {
	if (is_full())
		error("큐 포화 상태");
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	data[rear] = val;
}

Element dequeue() {
	if (is_empty())
		error("큐 공백 상태");
	front = (front + 1) % MAX_QUEUE_SIZE;
	return data[front];
}

Element peek() {
	if (is_empty())
		error("큐 공백 상태");
	else return data[(front + 1) % MAX_QUEUE_SIZE];
}

void printQ(const char* str) {
	int i;
	printf(" %s [ %2d]= ", str, size());
	for (i = data[front + 1]; i <= data[rear]; i++)
		printf("%3d ", data[i % MAX_QUEUE_SIZE]);
	printf("\n");
}

int main() {
	int i;
	init_queue();
	for (i = 1; i < 10; i++)
		enqueue(i);
	printQ("선형큐 dequeue 9회");
	printf("\tdequeue() --> %d\n", dequeue());
	printf("\tdequeue() --> %d\n", dequeue());
	printf("\tdequeue() --> %d\n", dequeue());
	printQ("선형큐 dequeue 3회");
}