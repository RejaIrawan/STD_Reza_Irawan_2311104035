#include <iostream>
using namespace std;

struct Pohon {
    char data;
    Pohon *left, *right, *parent;

    Pohon(char d, Pohon *l = NULL, Pohon *r = NULL, Pohon *p = NULL)
        : data(d), left(l), right(r), parent(p) {}
};

Pohon *root, *baru;

void init() {
    root = NULL;
}

bool isEmpty() {
    return root == NULL;
}

void buatNode(char data) {
    if (isEmpty()) {
        root = new Pohon(data, NULL, NULL, NULL);
        cout << "Node " << data << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "Tree sudah ada." << endl;
    }
}

Pohon* insertLeft(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    if (node->left != NULL) {
        cout << "Node " << node->data << " sudah memiliki child kiri!" << endl;
        return NULL;
    }
    baru = new Pohon(data, NULL, NULL, node);
    node->left = baru;
    cout << "Node " << data << " berhasil ditambahkan di kiri " << node->data << endl;
    return baru;
}

Pohon* insertRight(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    if (node->right != NULL) {
        cout << "Node " << node->data << " sudah memiliki child kanan!" << endl;
        return NULL;
    }
    baru = new Pohon(data, NULL, NULL, node);
    node->right = baru;
    cout << "Node " << data << " berhasil ditambahkan di kanan " << node->data << endl;
    return baru;
}

void tampilkanChild(Pohon *node) {
    if (!node) {
        cout << "Node tidak ditemukan!" << endl;
        return;
    }
    cout << "Node " << node->data << " memiliki child: ";
    if (node->left) cout << "Kiri: " << node->left->data << " ";
    if (node->right) cout << "Kanan: " << node->right->data << " ";
    if (!node->left && !node->right) cout << "Tidak ada.";
    cout << endl;
}

void tampilkanDescendant(Pohon *node) {
    if (!node) return;
    if (node->left) {
        cout << node->left->data << " ";
        tampilkanDescendant(node->left);
    }
    if (node->right) {
        cout << node->right->data << " ";
        tampilkanDescendant(node->right);
    }
}

bool is_valid_bst(Pohon *node, char min_val, char max_val) {
    if (!node) return true;
    if (node->data <= min_val || node->data >= max_val) return false;
    return is_valid_bst(node->left, min_val, node->data) && is_valid_bst(node->right, node->data, max_val);
}

int cari_simpul_daun(Pohon *node) {
    if (!node) return 0;
    if (!node->left && !node->right) return 1;
    return cari_simpul_daun(node->left) + cari_simpul_daun(node->right);
}

int main() {
    init();
    int pilihan;
    char data, parentData;
    Pohon *parent;

    do {
        cout << "\nMenu Binary Tree:\n";
        cout << "1. Buat Root\n";
        cout << "2. Tambah Child Kiri\n";
        cout << "3. Tambah Child Kanan\n";
        cout << "4. Tampilkan Child\n";
        cout << "5. Tampilkan Descendant\n";
        cout << "6. Cek Apakah BST\n";
        cout << "7. Hitung Simpul Daun\n";
        cout << "8. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data root: ";
                cin >> data;
                buatNode(data);
                break;
            case 2:
                cout << "Masukkan parent node: ";
                cin >> parentData;
                parent = root; 
                cout << "Masukkan data: ";
                cin >> data;
                insertLeft(data, parent);
                break;
            case 3:
                cout << "Masukkan parent node: ";
                cin >> parentData;
                parent = root;
                cout << "Masukkan data: ";
                cin >> data;
                insertRight(data, parent);
                break;
            case 4:
                cout << "Masukkan node: ";
                cin >> data;
                parent = root; 
                tampilkanChild(parent);
                break;
            case 5:
                cout << "Masukkan node: ";
                cin >> data;
                parent = root; 
                cout << "Descendants: ";
                tampilkanDescendant(parent);
                cout << endl;
                break;
            case 6:
                cout << (is_valid_bst(root, '0', 'z') ? "Tree adalah BST." : "Tree bukan BST.") << endl;
                break;
            case 7:
                cout << "Jumlah simpul daun: " << cari_simpul_daun(root) << endl;
                break;
            case 8:
                cout << "Keluar." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 8);
    return 0;
}