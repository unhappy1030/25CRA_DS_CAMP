// 큐 ADT

// 구성 요소 : 배열, 데이터, 

int data[100];
int front; 0
int rear; 6

for(int i = front; i < rear; i++){ i : 0 ~ 5
    data[i] = data[i+1]; //data[0] = data[1];
}
rear--;
front 0
rear 5

dequeue