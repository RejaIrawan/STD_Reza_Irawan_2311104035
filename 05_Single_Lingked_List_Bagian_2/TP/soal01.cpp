#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->next = nullptr;
    return node;
}

// Function to insert a new node at the beginning of the list
Node* insertFirst_2311104035(Node* head, int data) {
    Node* new_node = newNode(data);
    new_node->next = head;
    return new_node;
}

// Function to search for an element in the linked list
Node* searchElement_2311104035(Node* head, int data) {
    int position = 1;
    Node* current = head;
    while (current != nullptr) {
        if (current->data == data) {
            cout << "Elemen " << data << " ditemukan pada posisi " << position << endl;
            return current;
        }
        current = current->next;
        position++;
    }
    cout << "Elemen " << data << " tidak ditemukan" << endl;
    return nullptr;
}

int main() {
    Node* head = nullptr;

    // Input elements from the user
    cout << "Masukkan 6 elemen integer: " << endl;
    for (int i = 0; i < 6; i++) {
        int data;
        cin >> data;
        head = insertFirst_2311104035(head, data);
    }

    // Search for an element
    int search_data;
    cout << "Masukkan elemen yang ingin dicari: ";
    cin >> search_data;
    searchElement_2311104035(head, search_data);

    return 0;
}