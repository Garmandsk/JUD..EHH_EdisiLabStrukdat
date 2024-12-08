#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Struktur untuk produk
struct Produk {
    int id;
    string nama;
    string kategori;
    int harga;
};

// Fungsi untuk menampilkan daftar produk
void tampilkanProduk(const vector<Produk>& produk) {
    for (const auto& p : produk) {
        cout << "ID: " << p.id << " | Nama: " << p.nama 
             << " | Kategori: " << p.kategori 
             << " | Harga: Rp " << p.harga << endl;
    }
    cout << endl;
}

// Fungsi untuk mengurutkan produk berdasarkan harga
void urutkanBerdasarkanHarga(vector<Produk>& produk, bool ascending = true) {
    if (ascending) {
        sort(produk.begin(), produk.end(), [](const Produk& a, const Produk& b) {
            return a.harga < b.harga;
        });
    } else {
        sort(produk.begin(), produk.end(), [](const Produk& a, const Produk& b) {
            return a.harga > b.harga;
        });
    }
}

// Fungsi untuk mengurutkan produk berdasarkan kategori
void urutkanBerdasarkanKategori(const vector<Produk>& produk) {
    unordered_map<string, vector<Produk>> hashTable;

    // Memasukkan produk ke dalam hash table berdasarkan kategori
    for (const auto& p : produk) {
        hashTable[p.kategori].push_back(p);
    }

    // Menampilkan produk per kategori
    for (const auto& pair : hashTable) {
        cout << "Kategori: " << pair.first << endl;
        tampilkanProduk(pair.second);
    }
}

int main() {
    // Daftar produk
    vector<Produk> daftarProduk = {
        {1, "Smartphone Samsung Galaxy S23", "Elektronik", 12000000},
        {2, "Laptop ASUS ROG Zephyrus G14", "Elektronik", 25000000},
        {3, "TV LED LG 43 Inch", "Elektronik", 6500000},
        {4, "Earbuds Apple AirPods Pro", "Elektronik", 3500000},
        {5, "Kamera DSLR Canon EOS 90D", "Elektronik", 17000000},
        {6, "Sepeda MTB Polygon", "Fitness", 5000000},
        {7, "Dumbbell 5kg", "Fitness", 200000},
        {8, "Matras Yoga", "Fitness", 250000},
        {9, "Mesin Elliptical", "Fitness", 7500000},
        {10, "Resistance Band", "Fitness", 100000},
        {11, "Serum Wajah Vitamin C", "Kecantikan", 150000},
        {12, "Masker Wajah Aloe Vera", "Kecantikan", 75000},
        {13, "Lipstik Matte L'Oréal", "Kecantikan", 120000},
        {14, "Parfum Chanel", "Kecantikan", 2500000},
        {15, "Sabun Cuci Muka Himalaya", "Kecantikan", 35000},
        {16, "Roti Tawar Serba Roti", "Konsumsi", 15000},
        {17, "Kopi Arabica 100g", "Konsumsi", 50000},
        {18, "Mie Instan", "Konsumsi", 5000},
        {19, "Susu UHT Indomilk 1 Liter", "Konsumsi", 18000},
        {20, "Teh Kotak Sosro 500ml", "Konsumsi", 7500},
    };

    // Menu utama
    int pilihan;
    cout << "Pilih jenis sorting:\n";
    cout << "1. Urutkan berdasarkan harga (Ascending)\n";
    cout << "2. Urutkan berdasarkan harga (Descending)\n";
    cout << "3. Urutkan berdasarkan kategori\n";
    cout << "Pilihan: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            urutkanBerdasarkanHarga(daftarProduk, true);
            tampilkanProduk(daftarProduk);
            break;
        case 2:
            urutkanBerdasarkanHarga(daftarProduk, false);
            tampilkanProduk(daftarProduk);
            break;
        case 3:
            urutkanBerdasarkanKategori(daftarProduk);
            break;
        default:
            cout << "Pilihan tidak valid!\n";
            break;
    }

    return 0;
}
