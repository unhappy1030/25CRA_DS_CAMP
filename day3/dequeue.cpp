#include <iostream>
using namespace std;

// Node 구조체 정의
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// push_front: Dequeue 앞쪽에 노드 추가
Node* push_front(Node* head, int value) {
    Node* newNode = new Node{value, head, nullptr};
    if (head != nullptr) {
        head->prev = newNode;
    }
    return newNode;
}

// push_back: Dequeue 뒤쪽에 노드 추가
Node* push_back(Node* head, int value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (head == nullptr) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// pop_front: Dequeue 앞쪽에서 노드 제거
Node* pop_front(Node* head) {
    if (head == nullptr) {
        cout << "Dequeue is empty!" << endl;
        return nullptr;
    }
    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
    return head;
}

// pop_back: Dequeue 뒤쪽에서 노드 제거
Node* pop_back(Node* head) {
    if (head == nullptr) {
        cout << "Dequeue is empty!" << endl;
        return nullptr;
    }
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    delete temp;
    return head;
}

// insert: 특정 위치 뒤에 새로운 노드 삽입
Node* insert(Node* head, int key, int value) {
    if (head == nullptr) {
        cout << "Dequeue is empty! Cannot insert after key " << key << "." << endl;
        return head;
    }

    Node* temp = head;
    while (temp != nullptr && temp->data != key) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Key " << key << " not found in the list!" << endl;
        return head;
    }

    Node* newNode = new Node{value, temp->next, temp};
    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    return head;
}

// remove: 특정 값을 가진 노드 제거
Node* remove(Node* head, int value) {
    if (head == nullptr) {
        cout << "Dequeue is empty! Cannot remove value " << value << "." << endl;
        return head;
    }

    Node* temp = head;
    while (temp != nullptr && temp->data != value) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Value " << value << " not found in the list!" << endl;
        return head;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next; // If the node to remove is the head
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    delete temp;
    return head;
}

// clear: 모든 노드 제거
Node* clear(Node* head) {
    while (head != nullptr) {
        head = pop_front(head);
    }
    return nullptr;
}

// display: Dequeue의 모든 노드 출력
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
    Node* head = nullptr; // Dequeue 초기화

    // push_front, push_back 테스트
    head = push_front(head, 10);
    head = push_back(head, 20);
    head = push_back(head, 30);
    display(head); // 출력: 10 20 30

    // insert 테스트
    head = insert(head, 20, 25);
    display(head); // 출력: 10 20 25 30

    // remove 테스트
    head = remove(head, 20);
    display(head); // 출력: 10 25 30

    // clear 테스트
    head = clear(head);
    display(head); // 출력: (비어 있음)

    return 0;
}
