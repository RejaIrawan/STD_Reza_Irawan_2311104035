#include <iostream>
using namespace std;

struct Node {
    string nama;
    int nim;
    Node* next;
};

Node* front = nullptr;
Node* back = nullptr;

bool isEmpty() {
    return front == nullptr;
}

void enqueueAntrian(string nama, int nim) {
    Node* newNode = new Node{nama, nim, nullptr};

    if (isEmpty()) {
        front = back = newNode;
    } else {
        if (front->nim > nim) {
            newNode->next = front;
            front = newNode;
        } else {
            Node* temp = front;
            while (temp->next != nullptr && temp->next->nim <= nim) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            if (temp == back) {
                back = newNode;
            }
        }
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            back = nullptr;
        }
    }
}

int countQueue() {
    int count = 0;
    Node* temp = front;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void clearQueue() {
    while (!isEmpty()) {
        dequeueAntrian();
    }
}

void viewQueue() {
    cout << "Data antrian teller:" << endl;
    Node* temp = front;
    int position = 1;
    while (temp != nullptr) {
        cout << position << ". " << temp->nama << " (" << temp->nim << ")" << endl;
        temp = temp->next;
        position++;
    }
}

int main() {
    int choice;
    do {
        cout << "\nMenu Antrian Mahasiswa\n";
        cout << "1. Tambah Mahasiswa ke Antrian\n";
        cout << "2. Hapus Mahasiswa dari Antrian\n";
        cout << "3. Lihat Antrian\n";
        cout << "4. Hapus Semua Antrian\n";
        cout << "5. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string nama;
                int nim;
                cout << "Masukkan Nama Mahasiswa: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan NIM Mahasiswa: ";
                cin >> nim;
                enqueueAntrian(nama, nim);
                break;
            }
            case 2:
                dequeueAntrian();
                break;
            case 3:
                viewQueue();
                break;
            case 4:
                clearQueue();
                break;
            case 5:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Opsi tidak valid. Silakan coba lagi.\n";
        }
    } while (choice != 5);

    return 0;
}
