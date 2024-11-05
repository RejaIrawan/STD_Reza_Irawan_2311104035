#include <iostream>
#include <stack>
#include <string>
#include <cctype> // untuk fungsi tolower() dan isspace()
using namespace std;

// buat ngecek apakah kalimat tersebut polindrom atau tidak

// Fungsi untuk membersihkan string:
// - Menghapus semua spasi
// - Mengubah semua huruf menjadi huruf kecil
string cleanString(string str) {
    string result = "";
    for(char c : str) {
        if(!isspace(c)) { // jika bukan spasi
            result += tolower(c); // tambahkan ke hasil dalam bentuk huruf kecil
        }
    }
    return result;
}

// Fungsi untuk mengecek apakah string adalah palindrom menggunakan stack
// Palindrom: kata yang dibaca sama dari depan dan belakang klo dibalik bisa dibaca intinya.
bool isPalindrome(string str) {
    stack<char> charStack;  // Membuat stack untuk menyimpan karakter
    
    // Bersihkan string dari spasi dan ubah ke huruf kecil
    string cleanStr = cleanString(str);
    int length = cleanStr.length();
    int mid = length / 2;  // untuk menentukan titik tengah string
    
    // Step 1: Push setengah karakter pertama ke dalam stack
    // Contoh: untuk "kasur rusak", push "kasu"
    for(int i = 0; i < mid; i++) {
        charStack.push(cleanStr[i]);
    }
    
    // Step 2: menentukan indeks mulai untuk pembandingan
    // klo panjang ganjil, skip karakter tengah
    // Contoh: "kasur rusak" -> skip 'r' di tengah
    int startIndex = (length % 2 == 0) ? mid : mid + 1;
    
    // Step 3: ngebandingin setengah karakter terakhir dengan isi stack
    // Pop setiap karakter dari stack dan bandingkan
    // Contoh: bandingkan "rusak" dengan "kasu" (dalam stack)
    for(int i = startIndex; i < length; i++) {
        // Jika stack kosong atau karakter tidak cocok
        if(charStack.empty() || charStack.top() != cleanStr[i]) {
            return false;  // Bukan palindrom
        }
        charStack.pop();  // Hapus karakter top dari stack
    }
    
    // Jika semua karakter cocok dan stack kosong, maka palindrom
    return charStack.empty();
}

int main() {
    string input;
    
    // Minta input dari user
    cout << "Masukan Kalimat : ";
    getline(cin, input);  // Menggunakan getline untuk membaca kalimat dengan spasi
    
    // nampilin hasil
    cout << "Kalimat tersebut adalah : ";
    if(isPalindrome(input)) {
        cout << "Palindrom" << endl;
    } else {
        cout << "Bukan Palindrom" << endl;
    }
    
    // Contoh cara kerja untuk input "kasur rusak":
    // 1. Bersihkan string: "kasurrusak"
    // 2. Push "kasu" ke stack
    // 3. Skip 'r' tengah
    // 4. Bandingkan "rusak" dengan isi stack
    // 5. Karena semua cocok, maka palindrom
    
    return 0;
}