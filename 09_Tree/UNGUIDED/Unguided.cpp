#include <iostream>
#include <climits> 
using namespace std;

struct Pohon {
    int data;
    Pohon *left, *right, *parent;
};
Pohon *root, *baru;
void init() {
    root = NULL;
}
bool isEmpty() {
    return root == NULL;
}
void buatNode(int data) {
    if (isEmpty()) {
        root = new Pohon{data, NULL, NULL, NULL};
        cout << "Node " << data << " berhasil dibuat menjadi root.\n";
    } else {
        cout << "Pohon sudah dibuat.\n";
    }
}
// Tambah Kiri
Pohon *insertLeft(int data, Pohon *node) {
    if (isEmpty()) {
        cout << "Buat tree terlebih dahulu!\n";
        return NULL;
    }
    if (node->left != NULL) {
        cout << "Node " << node->data << " sudah ada child kiri!\n";
        return NULL;
    }
    baru = new Pohon{data, NULL, NULL, node};
    node->left = baru;
    cout << "Node " << data << " berhasil ditambahkan ke child kiri " << node->data << "\n";
    return baru;
}

// Tambah Kanan
Pohon *insertRight(int data, Pohon *node) {
    if (isEmpty()) {
        cout << "Buat tree terlebih dahulu!\n";
        return NULL;
    }
    if (node->right != NULL) {
        cout << "Node " << node->data << " sudah ada child kanan!\n";
        return NULL;
    }
    baru = new Pohon{data, NULL, NULL, node};
    node->right = baru;
    cout << "Node " << data << " berhasil ditambahkan ke child kanan " << node->data << "\n";
    return baru;
}

// Ubah Data Tree
void update(int data, Pohon *node) {
    if (isEmpty()) {
        cout << "Buat tree terlebih dahulu!\n";
        return;
    }
    if (!node) {
        cout << "Node yang ingin diganti tidak ada!\n";
        return;
    }
    int temp = node->data;
    node->data = data;
    cout << "Node " << temp << " berhasil diubah menjadi " << data << "\n";
}

// Lihat Isi Data Tree
void retrieve(Pohon *node) {
    if (isEmpty()) {
        cout << "Buat tree terlebih dahulu!\n";
        return;
    }
    if (!node) {
        cout << "Node yang ditunjuk tidak ada!\n";
        return;
    }
    cout << "Data node: " << node->data << "\n";
}

// Fungsi rekursif untuk memeriksa apakah tree adalah BST
bool is_valid_bst(Pohon *node, int min_val, int max_val) {
    if (node == NULL)
        return true;

    if (node->data <= min_val || node->data >= max_val)
        return false;

    return is_valid_bst(node->left, min_val, node->data) &&
        is_valid_bst(node->right, node->data, max_val);
}

// Fungsi rekursif untuk menghitung jumlah simpul daun
int cari_simpul_daun(Pohon *node) {
    if (node == NULL)
        return 0;

    if (node->left == NULL && node->right == NULL)
        return 1;

    return cari_simpul_daun(node->left) + cari_simpul_daun(node->right);
}

Pohon *searchNode(Pohon *node, int data) {
    if (!node)
        return NULL;
    if (node->data == data)
        return node;
    Pohon *leftSearch = searchNode(node->left, data);
    if (leftSearch)
        return leftSearch;
    return searchNode(node->right, data);
}

void menu() {
    char pilihan;
    int data;
    Pohon *node;
    do {
        cout << "\n--- MENU BINARY TREE ---\n";
        cout << "1. Buat Node Root\n";
        cout << "2. Tambah Node Kiri\n";
        cout << "3. Tambah Node Kanan\n";
        cout << "4. Update Data Node\n";
        cout << "5. Lihat Data Node\n";
        cout << "6. Periksa Apakah Tree Valid BST\n";
        cout << "7. Hitung Jumlah Simpul Daun\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case '1':
                cout << "Masukkan data root: ";
                cin >> data;
                buatNode(data);
                break;
            case '2':
                cout << "Masukkan data node baru: ";
                cin >> data;
                cout << "Masukkan parent node: ";
                int parentData;
                cin >> parentData;
                node = searchNode(root, parentData);
                insertLeft(data, node);
                break;
            case '3':
                cout << "Masukkan data node baru: ";
                cin >> data;
                cout << "Masukkan parent node: ";
                cin >> parentData;
                node = searchNode(root, parentData);
                insertRight(data, node);
                break;
            case '4':
                cout << "Masukkan data node yang ingin diubah: ";
                cin >> parentData;
                node = searchNode(root, parentData);
                if (node) {
                    cout << "Masukkan data baru: ";
                    cin >> data;
                    update(data, node);
                } else {
                    cout << "Node tidak ditemukan!\n";
                }
                break;
            case '5':
                cout << "Masukkan data node yang ingin dilihat: ";
                cin >> data;
                node = searchNode(root, data);
                retrieve(node);
                break;
            case '6':
                if (is_valid_bst(root, INT_MIN, INT_MAX)) {
                    cout << "Tree adalah Binary Search Tree yang valid.\n";
                } else {
                    cout << "Tree bukan Binary Search Tree yang valid.\n";
                }
                break;
            case '7':
                cout << "Jumlah simpul daun: " << cari_simpul_daun(root) << "\n";
                break;
            case '0':
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != '0');
}

int main() {
    init();
    menu();
    return 0;
}