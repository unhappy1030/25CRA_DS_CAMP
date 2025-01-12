#include<stdio.h>

#define MAX_SIZE 100 // 스택의 최대 크기

typedef struct {
    int data[MAX_SIZE]; // 데이터를 저장할 배열
    int top;            // 스택의 맨 위를 가리키는 변수
} Stack;

// 스택 초기화
void initStack(Stack* stack);

// 스택 연산 함수
int push(Stack* stack, int item);
int pop(Stack* stack, int* item);
int peek(Stack* stack, int* item);
int getSize(Stack* stack);
int isEmpty(Stack* stack);
int isFull(Stack* stack);

int main(){
    return 0;
}