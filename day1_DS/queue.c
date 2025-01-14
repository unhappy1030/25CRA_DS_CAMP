#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // 큐의 최대 크기

typedef struct {
    int data[MAX_SIZE]; // 데이터를 저장할 배열
    int front;          // 큐의 앞쪽을 가리키는 변수
    int rear;           // 큐의 뒤쪽을 가리키는 변수
    int size;           // 현재 큐에 있는 데이터 개수
} Queue;


// 0 1 2 
// front 0, rear -1
// front 0 rear 2 full
// front 1 rear 2 
// front 1 rear 0

// 큐 초기화
void initQueue(Queue* queue) {
    if (queue == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
}

// 큐 메모리 해제
void freeQueue(Queue* queue) {
    free(queue);
}

// 큐의 현재 크기 반환
int getSize(Queue* queue) {
    return queue->size;
}

// 큐가 비어있는지 확인
int isEmpty(Queue* queue) {
    return queue->size == 0;
}

// 큐가 가득 찼는지 확인
int isFull(Queue* queue) {
    return queue->size == MAX_SIZE;
}

// 큐에 요소 추가 (enqueue)
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue overflow! Cannot enqueue %d.\n", item);
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    // 0 1 2 3 4 5
    //MAX_SIZE = 6
    // rear = 4, enqueue | (rear + 1) % 6 = 5
    // rear = 5, enqueue | (rear + 1) % 6 = 0 
    queue->data[queue->rear] = item;
    queue->size++;
}

// 큐에서 요소 제거 (dequeue)
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow! Cannot dequeue.\n");
        return -1; // 실패를 나타내는 값
    }
    int item = queue->data[queue->front];
    // 0 1 2 3 4
    //front 1, rear 3
    //item = data[front] = data[1] = ?;
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->size--;
    return item;
}

// 큐의 맨 앞 요소를 확인 (peek)
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot peek.\n");
        return -1; // 실패를 나타내는 값
    }
    return queue->data[queue->front];
}

int main() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));

    initQueue(queue);

    // 데이터 삽입
    printf("Enqueuing 10, 20, 30 into the queue...\n");
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    // 큐 크기 확인
    printf("Queue size: %d\n", getSize(queue));

    // 큐 맨 앞 요소 확인
    printf("Front element is: %d\n", peek(queue));

    // 데이터 제거
    printf("Dequeuing elements from the queue...\n");
    while (!isEmpty(queue)) {
        printf("Dequeued: %d\n", dequeue(queue));
    }

    // 빈 큐 상태에서 디큐 시도
    if (dequeue(queue) == -1) {
        printf("No more elements to dequeue!\n");
    }

    // 큐 메모리 해제
    freeQueue(queue);

    return 0;
}
