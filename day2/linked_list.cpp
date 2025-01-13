#include <iostream>
using namespace std;

// Node 구조체 정의
struct Node {
    int data;       // 데이터
    Node* next;     // 다음 노드의 포인터
};

// push_front: 리스트의 앞에 노드 추가
Node* push_front(Node* head, int value) {
    Node* newNode = new Node{value, head};
    return newNode;
}

// push_back: 리스트의 뒤에 노드 추가
Node* push_back(Node* head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (head == nullptr) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// pop_front: 리스트의 첫 번째 노드 제거
Node* pop_front(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return nullptr;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

// pop_back: 리스트의 마지막 노드 제거
Node* pop_back(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return nullptr;
    }
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

// insert: 특정 위치에 노드 삽입
Node* insert(Node* head, int key, int value) {
    if (head == nullptr) {
        cout << "List is empty! Cannot insert after key " << key << "." << endl;
        return head;
    }
    Node* temp = head;
    while(temp != nullptr && temp->data != key){
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Key " << key << " not found in the list!" << endl;
        return head;
    }
    
    Node* newNode = new Node{value, temp->next};
    temp->next = newNode;
    return head;
}

// remove: 특정 값을 가진 노드 제거
Node* remove(Node* head, int value) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return nullptr;
    }
    if (head->data == value) {
        return pop_front(head);
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }
    if (temp->next == nullptr) {
        cout << "Value not found!" << endl;
        return head;
    }
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
    return head;
}

// clear: 리스트의 모든 노드 제거
Node* clear(Node* head) {
    while (head != nullptr) {
        head = pop_front(head);
    }
    return nullptr;
}

// display: 리스트의 모든 노드 출력
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// 메인 함수
int main() {
    Node* head = nullptr; // 리스트 초기화

    head = push_front(head, 10);
    head = push_back(head, 20);
    head = push_back(head, 30);
    display(head); // 출력: 10 20 30

    head = pop_front(head);
    display(head); // 출력: 20 30

    head = pop_back(head);
    display(head); // 출력: 20

    head = insert(head, 1, 40);
    display(head); // 출력: 20 40

    head = insert(head, 0, 50);
    display(head); // 출력: 50 20 40

    head = remove(head, 20);
    display(head); // 출력: 50 40

    head = clear(head);
    display(head); // 출력: (비어 있음)

    return 0;
}
