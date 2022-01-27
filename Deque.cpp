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
		error("Å¥ Æ÷È­ »óÅÂ");
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	data[rear] = val;
}

Element dequeue() {
	if (is_empty())
		error("Å¥ °ø¹é »óÅÂ");
	front = (front + 1) % MAX_QUEUE_SIZE;
	return data[front];
}

Element peek() {
	if (is_empty())
		error("Å¥ °ø¹é »óÅÂ");
	else return data[(front + 1) % MAX_QUEUE_SIZE];
}

void init_deque() {
	init_queue();
}

void add_rear(Element val) {
	enqueue(val);
}

Element delete_front() {
	return dequeue();
}

Element get_front() {
	return peek();
}

void printQ(const char* str) {
	int i = front;
	printf("%s\t[%2d]= ", str, (rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE);
	if (!is_empty()) {
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%3d", data[i]);
			if (i == rear)
				break;
		} while (i != front);
	}
	printf("\n");
}

void add_front(Element val) {
	if (is_full())
		error(" µ¦ Æ÷È­ ¿¡·¯");
	data[front] = val;
	front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

Element delete_rear() {
	Element ret;
	if (is_empty())
		error(" µ¦ °ø¹é ¿¡·¯");
	ret = data[rear];
	rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return ret;
}

Element get_rear() {
	if (is_empty())
		error(" µ¦ °ø¹é ¿¡·¯");
	return data[rear];
}

int main()
{
	int i;
	init_deque();
	for (i = 1; i < 10; i++) {
		if (i % 2) add_front(i);
		else add_rear(i);
	}
	printQ("¿øÇü µ¦ È¦¼ö-Â¦¼ö ");
	printf("\tdelete_front() --> %d\n", delete_front());
	printf("\tdelete_rear () --> %d\n", delete_rear());
	printf("\tdelete_front() --> %d\n", delete_front());
	printQ("¿øÇü µ¦ »èÁ¦-È¦Â¦È¦");
}