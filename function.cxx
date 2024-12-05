#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <cctype>
#include <functional>
#include <queue>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map> 
#include <windows.h>

using namespace std;

struct Produk {
    int id;
    string nama;
    string kategori;
    int harga;
};

    vector<Produk> produk = {
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

    /* Menambahkan produk baru
    produk.push_back({6, "Tablet Apple iPad Air", "Elektronik", 10000000});
    */
    
    // Tampilkan semua produk
void tampilkanProduk(){
    for (const auto& p : produk) {
        cout << "ID: " << p.id << endl;
        cout << "Nama: " << p.nama << endl;
        cout << "Kategori: " << p.kategori << endl;
        cout << "Harga: " << p.harga << endl;
        cout << "----------------------" << endl;
    }
}

// Fungsi untuk menampilkan menu utama
void showMenuPelanggan() {
    cout << "====================================\n";
    cout << "     SELAMAT DATANG DI TOKO JUD..EHH\n";
    cout << "====================================\n";
    cout << "\nKami siap melayani kebutuhan Anda!\n";
    cout << "Silahkan pilih produk dari sistem kami:\n\n";
    cout << "====================================\n";
    cout << "   SISTEM PEMESANAN PRODUK ONLINE\n";
    cout << "====================================\n";
    cout << "1. Urutkan Menu Berdasarkan Kategori/Harga (Sorting dan Hash)\n";
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

void showMenuPemilik() {
    cout << "====================================\n";
    cout << "  \"RUANG ADMIN\"\n";
    cout << "====================================\n";
    cout << "1. Lihat dan Simpan Daftar Pelanggan\n"; 
    cout << "2. Cari Data Pelanggan\n";
    cout << "3. Hapus Data Pelanggan\n";
    cout << "4. Tambah Menu\n";
    cout << "5. Kembali Ke Menu Awal\n"; 
    cout << "====================================\n";
    cout << "Pilih opsi (1-5): ";
}