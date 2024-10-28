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

void displayForward_2311104035(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr)
            cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

void displayBackward_2311104035(Node* head) {
    if (head == nullptr) return;
    
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->prev != nullptr)
            cout << " <-> ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    insertLast_2311104035(head, 1);
    insertLast_2311104035(head, 2);
    insertLast_2311104035(head, 3);
    insertLast_2311104035(head, 4);

    cout << "Daftar elemen dari depan ke belakang: ";
    displayForward_2311104035(head);
    
    cout << "Daftar elemen dari belakang ke depan: ";
    displayBackward_2311104035(head);

    return 0;
}