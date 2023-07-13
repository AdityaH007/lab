#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int* array;
    int front;
    int rear;
    int count;
} CircularQueue;

// Function to create a circular queue
CircularQueue* createQueue() {
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue->array = (int*)malloc(sizeof(int) * MAX_SIZE);
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
    return queue;
}

// Function to check if the queue is full
int isFull(CircularQueue* queue) {
    return queue->count == MAX_SIZE;
}

// Function to check if the queue is empty
int isEmpty(CircularQueue* queue) {
    return queue->count == 0;
}

// Function to enqueue an element into the circular queue
void enqueue(CircularQueue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue element.\n");
        return;
    }

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->array[queue->rear] = data;
    queue->count++;
    printf("%d enqueued to the queue.\n", data);
}

// Function to dequeue an element from the circular queue
int dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue element.\n");
        return -1;
    }

    int data = queue->array[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->count--;
    return data;
}

// Function to display the elements of the circular queue
void display(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Elements in the queue: ");
    int i;
    for (i = 0; i < queue->count; i++) {
        int index = (queue->front + i) % MAX_SIZE;
        printf("%d ", queue->array[index]);
    }
    printf("\n");
}

int main() {
    CircularQueue* queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6); // This will exceed the maximum size

    display(queue);

    int dequeuedElement = dequeue(queue);
    printf("Dequeued element: %d\n", dequeuedElement);

    display(queue);

    return 0;
}
