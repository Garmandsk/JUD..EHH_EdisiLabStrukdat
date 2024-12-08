#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Barang {
    int id;
    string nama;
    int jumlah;
    int total_harga;
};

class TokoOnline {
private:
    vector<Barang> keranjang; 

public:
    void tambahKeKeranjang(int id, string nama, int jumlah, int harga_per_unit) {
        Barang barang;
        barang.id = id;
        barang.nama = nama;
        barang.jumlah = jumlah;
        barang.total_harga = jumlah * harga_per_unit;
        keranjang.push_back(barang);
        cout << nama << " berhasil ditambahkan ke keranjang!" << endl;
    }

    void lihatKeranjang() {
        if (keranjang.empty()) {
            cout << "Keranjang belanja Anda kosong." << endl;
            return;
        }

        cout << "\nDaftar Barang di Keranjang:\n";
        cout << "---------------------------------------------\n";
        cout << setw(5) << left << "ID" 
             << setw(20) << left << "Nama Produk" 
             << setw(10) << left << "Jumlah" 
             << setw(15) << left << "Total Harga" << endl;
        cout << "---------------------------------------------\n";
        for (const auto &barang : keranjang) {
            cout << setw(5) << left << barang.id 
                 << setw(20) << left << barang.nama 
                 << setw(10) << left << barang.jumlah 
                 << setw(15) << left << barang.total_harga << endl;
        }
        cout << "---------------------------------------------\n";
    }

    void hapusBarang(int id) {
        for (auto it = keranjang.begin(); it != keranjang.end(); ++it) {
            if (it->id == id) {
                cout << it->nama << " berhasil dihapus dari keranjang." << endl;
                keranjang.erase(it);
                return;
            }
        }
        cout << "Barang dengan ID " << id << " tidak ditemukan di keranjang." << endl;
    }
};

int main() {
    TokoOnline toko;

    toko.tambahKeKeranjang(1, "Buku", 2, 50000);
    toko.tambahKeKeranjang(2, "Pensil", 5, 2000);
    toko.tambahKeKeranjang(3, "Penggaris", 1, 15000);

    toko.lihatKeranjang();

    toko.hapusBarang(2);

    toko.lihatKeranjang();

    return 0;
}
