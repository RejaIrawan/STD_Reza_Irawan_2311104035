#include <iostream>
#include <string>

using namespace std;

struct Node {
    int IDBuku;
    string JudulBuku;
    string PenulisBuku;
    Node* next;
    Node* prev;
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void tambahBuku(int id, string judul, string penulis) {
        Node* newNode = new Node();
        newNode->IDBuku = id;
        newNode->JudulBuku = judul;
        newNode->PenulisBuku = penulis;
        newNode->next = nullptr;
        newNode->prev = tail;

        if (tail != nullptr) {
            tail->next = newNode;
        }
        tail = newNode;

        if (head == nullptr) {
            head = newNode;
        }
    }

    void tampilkanDariAwal() {
        Node* current = head;
        while (current != nullptr) {
            cout << "ID Buku: " << current->IDBuku << ", Judul Buku: " << current->JudulBuku << ", Penulis Buku: " << current->PenulisBuku << endl;
            current = current->next;
        }
    }

    void tampilkanDariAkhir() {
        Node* current = tail;
        while (current != nullptr) {
            cout << "ID Buku: " << current->IDBuku << ", Judul Buku: " << current->JudulBuku << ", Penulis Buku: " << current->PenulisBuku << endl;
            current = current->prev;
        }
    }
};

int main() {
    DoubleLinkedList dll;
    int id = 1;
    string judul, penulis;
    char tambahLagi;

    do {
        cout << "Masukkan Judul Buku: ";
        getline(cin, judul);
        cout << "Masukkan Penulis Buku: ";
        getline(cin, penulis);

        dll.tambahBuku(id++, judul, penulis);

        cout << "Apakah Anda ingin menambah buku lagi? (y/n): ";
        cin >> tambahLagi;
        cin.ignore(); 

    } while (tambahLagi == 'y' || tambahLagi == 'Y');

    cout << "\nDaftar Buku dari Awal ke Akhir:" << endl;
    dll.tampilkanDariAwal();

    cout << "\nDaftar Buku dari Akhir ke Awal:" << endl;
    dll.tampilkanDariAkhir();

    return 0;
}