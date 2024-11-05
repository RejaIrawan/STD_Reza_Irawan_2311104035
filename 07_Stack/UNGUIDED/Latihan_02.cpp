#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

// Fungsi untuk membalikkan kata per kata menggunakan stack
string reverseWords(string str) {
    // Inisialisasi stack untuk menyimpan kata-kata
    stack<string> wordStack;
    
    // Gunakan stringstream untuk memisahkan string menjadi kata-kata
    stringstream ss(str);
    string word;
    
    // Step 1: Memisahkan kalimat menjadi kata-kata dan push ke stack
    // Contoh: "Telkom Purwokerto" akan dipisah menjadi:
    // Push "Telkom"
    // Push "Purwokerto"
    while (ss >> word) {
        wordStack.push(word);
    }
    
    // Step 2: Membalik setiap kata individual
    // Contoh: "Telkom" menjadi "mokleT"
    string result = "";
    while (!wordStack.empty()) {
        word = wordStack.top();
        string reversedWord = "";
        
        // Membalik setiap karakter dalam kata
        for (int i = word.length() - 1; i >= 0; i--) {
            reversedWord += word[i];
        }
        
        // Menambahkan kata yang sudah dibalik ke hasil
        result += reversedWord;
        if (wordStack.size() > 1) {
            result += " ";  // Menambah spasi antar kata
        }
        
        wordStack.pop();  // Menghapus kata dari stack
    }
    
    return result;
}

int main() {
    string input;
    
    // Meminta input dari user
    cout << "Masukkan Kata : ";
    getline(cin, input);  // Menggunakan getline untuk membaca kalimat dengan spasi
    
    // Menampilkan hasil pembalikan
    cout << "Datastack Array : " << endl;
    cout << "Data : " << reverseWords(input) << endl;
    
    /* Cara kerja program untuk input "Telkom Purwokerto":
    1. Push kata ke stack:
       Stack: ["Telkom", "Purwokerto"]
       
    2. Pop dan balik setiap kata:
       - Pop "Purwokerto" -> balik menjadi "otrekowruP"
       - Pop "Telkom" -> balik menjadi "mokleT"
       
    3. Gabungkan hasil:
       "otrekowruP mokleT"
    */
    
    return 0;
}