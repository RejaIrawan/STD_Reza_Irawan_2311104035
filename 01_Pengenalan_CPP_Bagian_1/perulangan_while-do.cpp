#include <iostream>

using namespace std;

int main (){
    int bilangan, asli, jumlah;

    cout << "Masukan Bilangan Asli: ";
    cin >> asli;

    bilangan = 1;
    jumlah = 0;
    while ( bilangan <= asli)
    {
        if (bilangan % 2 == 0 )
        {
            jumlah += bilangan;
        }
        bilangan ++;
    }
    cout << "Jumlah Bilangan Genap: " << jumlah << endl;

    return 0;
}