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

void deleteFirst_2311104035(Node*& head) {
    if (head == nullptr) return;
    Node* temp = head;
    if (head->next != nullptr) {
        head = head->next;
        head->prev = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
}

void deleteLast_2311104035(Node*& head) {
    if (head == nullptr) return;
    Node* temp = head;
    if (temp->next == nullptr) {
        head = nullptr;
        delete temp;
    } else {
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        delete temp;
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
    insertLast_2311104035(head, 10);
    insertLast_2311104035(head, 15);
    insertLast_2311104035(head, 20);
    
    deleteFirst_2311104035(head);
    deleteLast_2311104035(head);
    
    cout << "DAFTAR ANGGOTA LIST SETELAH PENGHAPUSAN: ";
    display_2311104035(head);

    return 0;
}