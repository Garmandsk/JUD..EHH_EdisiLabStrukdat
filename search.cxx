#include <iostream>
#include <unordered_map>
#include <string>
#include "hashtable.cpp"
using namespace std;

void cariProduk(const unordered_map<int, Produk>& produk, int idProduk) {
    auto it = produk.find(idProduk);
    if (it != produk.end()) {
        cout << "I=================================================I" << endl;
        cout << "                PRODUK DITEMUKAN!\n";
        cout << "I=================================================I" << endl;
        cout << " Nama               : " << it->second.nama << endl;
        cout << " Kategori           : " << it->second.kategori << endl;
        cout << " Harga              : Rp" << it->second.harga << endl;
        cout << "I=================================================I";
    } else {
        cout << "Produk dengan ID tersebut tidak ditemukan.\n";
    }
}

int main() {
    system("cls");
    unordered_map<int, Produk> produk = buatProduk();

    int idProduk;
    cout << "Masukkan ID Produk yang ingin dicari: ";
    cin >> idProduk;

    cariProduk(produk, idProduk);

    return 0;
}
