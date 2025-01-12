#include<stdio.h>

#define MAX_SIZE 100 // 큐의 최대 크기

typedef struct {
    int data[MAX_SIZE]; // 데이터를 저장할 배열
    int front;          // 큐의 앞쪽을 가리키는 변수
    int rear;           // 큐의 뒤쪽을 가리키는 변수
} Queue;

// 큐 초기화
void initQueue(Queue* queue);

// 큐 연산 함수
int enqueue(Queue* queue, int item);
int dequeue(Queue* queue, int* item);
int peek(Queue* queue, int* item);
int getSize(Queue* queue);
int isEmpty(Queue* queue);
int isFull(Queue* queue);


int main(){
    return 0;
}