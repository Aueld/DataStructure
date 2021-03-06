#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 4

typedef int Element;
typedef struct {
	Element queue[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

QueueType* createQueue() {
	QueueType* Q;
	Q = (QueueType*)malloc(sizeof(QueueType));
	Q->front = -1;
	Q->rear = -1;
	return Q;
}

int isEmpty(QueueType* Q) {
	if (Q->front == Q->rear) {
		printf(" Queue is empty");
		return 1;
	}
	else return 0;
}

int isFull(QueueType* Q) {
	if (Q->rear == MAX_QUEUE_SIZE - 1) {
		printf("Queue is Full");
		return 1;
	}
	else return 0;
}

void enQueue(QueueType* Q, Element item) {
	if (isFull(Q)) return;
	else {
		Q->rear++;
		Q->queue[Q->rear] = item;
	}
}

Element deQueue(QueueType* Q) {
	if (isFull(Q)) return 0;
	else {
		Q->front++;
		return Q->queue[Q->front];
	}
}

Element peek(QueueType* Q) {
	if (isEmpty(Q)) exit(1);
	else return Q->queue[Q->front + 1];
}

void printQ(QueueType* Q) {
	int i;
	printf(" Queue : [");
	for (i = Q->front + 1; i <= Q->rear; i++)
		printf("%3c ", Q->queue[i]);
	printf(" ]");
}

int main() {
	QueueType* Q1 = createQueue();
	Element data;
	printf("\n ***** 순차 큐 연산 ***** \n");
	printf("\n 삽입 A >>"); enQueue(Q1, 'A'); printQ(Q1);
	printf("\n 삽입 B >>"); enQueue(Q1, 'B'); printQ(Q1);
	printf("\n 삽입 C >>"); enQueue(Q1, 'C'); printQ(Q1);
	data = peek(Q1);
	printf(" peek item : %c \n", data);
	printf("\n 삭제 >>"); data = deQueue(Q1); printQ(Q1);
	printf("\t 삭제 데이터: %c", data);
	printf("\n 삭제 >>"); data = deQueue(Q1); printQ(Q1);
	printf("\t 삭제 데이터: %c", data);
	printf("\n 삭제 >>"); data = deQueue(Q1); printQ(Q1);
	printf("\t\t 삭제 데이터: %c", data);

	printf("\n 삽입 D >>"); enQueue(Q1, 'D'); printQ(Q1);
	printf("\n 삽입 E >>"); enQueue(Q1, 'E'); printQ(Q1);

}
