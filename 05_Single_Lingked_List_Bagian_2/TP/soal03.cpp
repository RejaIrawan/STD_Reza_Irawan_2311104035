#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insertSorted_2311104035(Node* head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr || data < head->data) {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr && data >= current->data) {
        previous = current;
        current = current->next;
    }

    newNode->next = current;
    previous->next = newNode;
    return head;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    cout << "Masukkan " << n << " elemen integer: ";
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        head = insertSorted_2311104035(head, data);
    }

    cout << "List terurut: ";
    printList(head);

    int newElement;
    cout << "Masukkan elemen baru: ";
    cin >> newElement;

    head = insertSorted_2311104035(head, newElement);

    cout << "List terurut setelah menambahkan elemen baru: ";
    printList(head);

    return 0;
}