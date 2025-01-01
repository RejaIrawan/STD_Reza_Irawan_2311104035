#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10;

class Graph {
public:
    int n; // Jumlah simpul
    int adj[MAX][MAX]; // Matriks ketetanggaan

    Graph(int nodes) {
        n = nodes;
        // Inisialisasi matriks dengan 0
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                adj[i][j] = 0; // Tidak terhubung
            }
        }
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1; // Menandai ada tepi dari u ke v
        adj[v][u] = 1; // Karena graf tidak terarah
    }

    void printGraph() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int jumlahSimpul;
    cout << "Masukkan jumlah simpul: ";
    cin >> jumlahSimpul;

    Graph g(jumlahSimpul);
    
    int u, v;
    cout << "Masukkan pasangan simpul (format: simpul1 simpul2), ketik -1 -1 untuk selesai:\n";
    while (true) {
        cin >> u >> v;
        if (u == -1 && v == -1) break; // Selesai jika input -1 -1
        // Sesuaikan input dari 1-indexed ke 0-indexed
        g.addEdge(u - 1, v - 1); // Kurangi 1 agar sesuai dengan indeks matriks
    }

    g.printGraph();

    return 0;
}