#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>
#include <iomanip>
#include <windows.h>

using namespace std;

// Struktur produk
struct Produk {
    int id;
    string nama;
    string kategori;
    double harga;
};

// Struktur pembayaran
struct Pembayaran {
    int idTransaksi;
    vector<Produk> keranjang;
    double totalHarga;
};

// Daftar produk dan data lainnya
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
    
vector<Produk> keranjang;
vector<Pembayaran> riwayatPembayaran;
unordered_map<int, Produk> hashProduk;
int idTransaksiGlobal = 1;

void masukkanKeHash() {
    for (const auto &p : daftarProduk) {
        hashProduk[p.id] = p;
    }
}

#include "array.cxx"
#include "graf.cxx"
#include "hashTable.cxx"
#include "sort.cxx"
#include "search.cxx"

// Fungsi untuk menampilkan produk
void tampilkanProduk() {
    for (const auto &produk : daftarProduk) {
        cout << produk.id << ". " << produk.nama << " - " << produk.kategori << " - Rp " << fixed << setprecision(2) << produk.harga << endl;
    }
}

void showMenu(){
    
    cout << "====================================\n";
        cout << "     SELAMAT DATANG DI TOKO JUD..EHH\n";
        cout << "====================================\n";
        cout << "\nKami siap melayani kebutuhan Anda!\n";
        cout << "Silahkan pilih produk dari sistem kami:\n\n";
        cout << "====================================\n";
        cout << "   SISTEM PEMESANAN PRODUK ONLINE\n";
        cout << "====================================\n";
        cout << "1. Urutkan Menu Berdasarkan Kategori/Harga (Sorting)\n";
        cout << "2. Menambahkan Produk Ke Keranjang Belanja (Array)\n";
        cout << "3. Mencari Produk Berdasarkan ID (Search dan Hash)\n";
        cout << "4. Melihat Daftar Barang Di Keranjang (Array)\n";
        cout << "5. Menghapus Barang Dari Keranjang (Array)\n";
        cout << "6. Menghitung Biaya Pengiriman Berdasarkan Jarak (Graf - Shortest Path)\n";
        cout << "7. Melakukan Pembayaran Dan Menyimpan Riwayat Pembayaran (Array)\n";
        cout << "8. Melihat Riwayat Pembayaran (Array)\n";
        cout << "9. Melihat Detail Setiap Transaksi Pada Riwayat Pembayaran (Array dan Hash)\n";
        cout << "10. Keluar\n";
        cout << "====================================\n";
        cout << "Pilih opsi (1-10): ";
        
}