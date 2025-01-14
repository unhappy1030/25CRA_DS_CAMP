#include<iostream>//C++

using namespace std;

struct Node{
    int data;
    Node* next;
};
//정사각형 텅빈 박스하나(노드의 주소를 저장할 수 있다.)

Node* push_front(Node* head, int value){
    Node* newNode = new Node;//(Node*)malloc(sizeof(Node))
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

Node* push_back(Node* head, int value){
    Node* temp = head;
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    if(head == nullptr){
        return newNode;
    }
    while(temp->next != nullptr){
        temp = temp->next;
    }
    //temp는 리스트의 마지막 노드
    temp->next = newNode;
    return head;
}

Node* pop_front(Node* head){
    if(head == nullptr){
        return nullptr;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

void display(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << "  ->  ";
        temp = temp->next;
    }
    //temp == nullptr
    cout << endl;
}


using namespace std;

int main() {
    Node* head = nullptr;

    head = push_front(head, 27);
    display(head);
    head = push_front(head, 99);
    display(head);
    head = push_front(head, 54);
    display(head);
    head = push_front(head, 26);
    display(head);
    head = push_back(head, 33);
    display(head);
    head = pop_front(head);
    display(head);


    
}