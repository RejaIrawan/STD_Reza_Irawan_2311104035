#include <iostream>

using namespace std;

struct InfoProyek {
    string nama;
    int durasi;
};

struct Proyek {
    InfoProyek info;
    Proyek *next;
};

struct InfoPegawai {
    string nama;
    string id;
};

struct Pegawai {
    InfoPegawai info;
    Pegawai *next;
    Proyek *nextProyek;
};

struct List {
    Pegawai *first;
};

void createPegawai(InfoPegawai info, Pegawai &P) {
    P.info.nama = info.nama;
    P.info.id = info.id;
    P.next = nullptr;
    P.nextProyek = nullptr;
}

void createProyek(InfoProyek info, Proyek &Pro) {
    Pro.info.nama = info.nama;
    Pro.info.durasi = info.durasi;
    Pro.next = nullptr;
}

void insertPegawai(List &L, Pegawai &P) {
    if (L.first == nullptr) {
        L.first = &P;
    } else {
        Pegawai *current = L.first;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = &P;
    }
}

void insertProyek(Pegawai &P, Proyek &Pro) {
    if (P.nextProyek == nullptr) {
        P.nextProyek = &Pro;
    } else {
        Proyek *current = P.nextProyek;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = &Pro;
    }
}

void deleteProyekFirst(Pegawai &P) {
    if (P.nextProyek != nullptr) {
        Proyek *temp = P.nextProyek;
        P.nextProyek = P.nextProyek->next;
        temp->next = nullptr;
    }
}

void showList(List &L) {
    if (L.first != nullptr) {
        Pegawai *currentPegawai = L.first;

        cout << "Daftar Pegawai dan Proyek:" << endl;

        while (currentPegawai != nullptr) {
            cout << currentPegawai->info.nama << ":" << endl;
            
            if (currentPegawai != nullptr) {
                Proyek *currentProyek = currentPegawai->nextProyek;

                while (currentProyek != nullptr) {
                    cout << "- " << currentProyek->info.nama << ": " << currentProyek->info.durasi << " bulan" << endl;

                    currentProyek = currentProyek->next;
                }
            }

            currentPegawai = currentPegawai->next;
        }
    }
}

void printSeparator() {
    cout << "-----------------------------------------------------" << endl;
}

int main() {
    List L;
    L.first = nullptr;

    Pegawai p1;
    Pegawai p2;
    Pegawai p3;

    createPegawai({ "Andi", "P001" }, p1);
    createPegawai({ "Budi", "P002" }, p2);
    createPegawai({ "Citra", "P003" }, p3);

    Proyek pro1;
    Proyek pro2;
    Proyek pro3;

    createProyek({ "Aplikasi Mobile", 12 }, pro1);
    createProyek({ "Sistem Akuntansi", 8 }, pro2);
    createProyek({ "E-commerce", 10 }, pro3);

    insertPegawai(L, p1);
    insertPegawai(L, p2);
    insertPegawai(L, p3);

    printSeparator();
    showList(L);
    printSeparator();

    insertProyek(p1, pro1);
    insertProyek(p2, pro2);
    insertProyek(p3, pro3);

    showList(L);
    printSeparator();

    Proyek pro4;
    createProyek({ "Analisis Data", 6 }, pro4);
    insertProyek(p1, pro4);

    showList(L);
    printSeparator();

    deleteProyekFirst(p1);

    showList(L);
    printSeparator();

    return 0;
}