#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100 // 스택의 최대 크기

typedef struct {
    int data[MAX_SIZE]; // 데이터를 저장할 배열
    int top;            // 스택의 맨 위를 가리키는 변수
} Stack;

// 스택 초기화
void initStack(Stack* stack) {
    stack->top = -1; // 초기 상태는 스택이 비어있음
}

// 스택의 현재 크기 반환
int getSize(Stack* stack) {
    return stack->top + 1;
}

// 스택이 비어있는지 확인
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// 스택이 가득 찼는지 확인
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}\

// 스택에 요소 추가 (push)
void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %d.\n", item);
    }
    stack->data[++(stack->top)] = item;
}

// 스택에서 요소 제거 (pop)
void pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop.\n");
    }
    stack->top--;
}

// 스택의 맨 위 요소를 확인 (peek)
int peek(Stack* stack){
    if (isEmpty(stack)) {
        printf("Stack is empty! Cannot peek.\n");
        return 0; // 실패
    }
    return stack->data[stack->top];
}



int main() {
    Stack *stack = (Stack*)malloc(sizeof(Stack));

    // 스택 초기화
    initStack(stack);

    // 데이터 삽입
    printf("Pushing 10, 20, 30 onto the stack...\n");
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    // 스택 크기 확인
    printf("Stack size: %d\n", getSize(stack));

    // 스택 맨 위 요소 확인
    printf("Top element is: %d\n", peek(stack));

    // 데이터 제거
    printf("Popping elements from the stack...\n");
    while (!isEmpty(stack)) {
        printf("Popped: %d\n", peek(stack));
        pop(stack);
    }

    return 0;
}
