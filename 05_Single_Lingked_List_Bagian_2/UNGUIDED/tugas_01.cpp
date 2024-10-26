#include <iostream>
#include <string>

using namespace std;

struct Node {
    int nim;
    string nama;
    Node* next;
};

// Fungsi untuk membuat node baru
Node* newNode(int nim, string nama) {
    Node* node = new Node;
    node->nim = nim;
    node->nama = nama;
    node->next = nullptr;
    return node;
}

// Fungsi untuk menambahkan node ke dalam Linked List
void addNode(Node** head, int nim, string nama) {
    Node* new_node = newNode(nim, nama);
    new_node->next = *head;
    *head = new_node;
}

// Fungsi untuk mencari mahasiswa berdasarkan NIM
Node* findNode(Node* head, int nim) {
    while (head != nullptr) {
        if (head->nim == nim) {
            return head;
        }
        head = head->next;
    }
    return nullptr;
}

// Fungsi untuk menampilkan Linked List
void printList(Node* head) {
    while (head != nullptr) {
        cout << "NIM: " << head->nim << ", Nama: " << head->nama << endl;
        head = head->next;
    }
}

int main() {
    Node* head = nullptr;

    // Menambahkan beberapa node
    addNode(&head, 231110435, "reza");

    cout << "Daftar Mahasiswa: " << endl;
    printList(head);

    Node* foundNode = findNode(head, 2311104035);
    if (foundNode != nullptr) {
        cout << "Mahasiswa ditemukan: " << foundNode->nama << endl;
    } else {
        cout << "Mahasiswa dengan NIM 77777 tidak ditemukan" << endl;
    }

    foundNode = findNode(head, 2311104035);
}
    