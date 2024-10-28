#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* createNode_2311104035(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void insertFirst_2311104035(Node*& head, int data) {
    Node* newNode = createNode_2311104035(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertLast_2311104035(Node*& head, int data) {
    Node* newNode = createNode_2311104035(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void display_2311104035(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr)
            cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    insertFirst_2311104035(head, 10);
    insertFirst_2311104035(head, 5);
    insertLast_2311104035(head, 20);
    
    cout << "DAFTAR ANGGOTA LIST: ";
    display_2311104035(head);

    return 0;
}