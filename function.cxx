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
    string pilihan;
    char pilihanPesanan;
    int jumlahPesanan;

    do {
        system("cls"); 

        // Tampilkan daftar produk
        cout << "Daftar Produk:\n";
        for (const auto &produk : daftarProduk) {
            cout << produk.id << ". " << produk.nama << " - " << produk.kategori 
                 << " - Rp " << fixed << setprecision(2) << produk.harga << endl;
        }

        cout << "\nTekan 's' Untuk Mengurutkan Produk\n";
        cout << "Tekan 'c' Untuk Mencari Produk Berdasarkan ID\n";
        cout << "Tekan 'k' Untuk Keluar\n";
        cout << "Catatan: Pilih produk berdasarkan ID!\n";
        
        cout << "\nMasukkan pilihan: ";
        cin >> pilihan;

        // Input untuk pengurutan
        if (pilihan == "s" || pilihan == "S") {
            urutkanProduk();
            cin.ignore();
            cin.get();
        } 
        // Input untuk pencarian
        else if (pilihan == "c" || pilihan == "C") {
            int idCari;
            cout << "Masukkan ID produk yang ingin dicari: ";
            cin >> idCari;
            cariProduk(idCari);
            cout << "\nTekan Enter untuk kembali...";
            cin.ignore();
            cin.get();
        } 
        // Input untuk keluar
        else if (pilihan == "k" || pilihan == "K") {
            return;
        } 
        // Penanganan untuk pemilihan berdasarkan ID produk
        else {
            int idPilihan;
            try {
                idPilihan = stoi(pilihan);
            } catch (const invalid_argument&) {
                cout << "\nMasukkan tidak valid (harus angka)." << endl;
                cin.ignore();
                cin.get();
                continue;
            }

            // Cek validitas ID produk
            auto it = find_if(daftarProduk.begin(), daftarProduk.end(),
                              [idPilihan](const Produk& p) { return p.id == idPilihan; });
            if (it == daftarProduk.end()) {
                cout << "\nProduk dengan ID " << idPilihan << " tidak ditemukan.\n";
                cin.ignore();
                cin.get();
                continue;
            }

            // Pesan jumlah produk
            cout << "Jumlah yang ingin dipesan: ";
            cin >> jumlahPesanan;
            if (jumlahPesanan <= 0) {
                cout << "\nJumlah harus lebih dari 0.\n";
                cin.ignore();
                cin.get();
                continue;
            }

            // Tambahkan produk ke keranjang
            for (int i = 0; i < jumlahPesanan; ++i) {
                keranjang.push_back(*it);
            }
            
            cout << jumlahPesanan << " " << it->nama << " telah ditambahkan ke keranjang.\n";
            cout << "Pesan lagi (Y/T)? ";
            cin >> pilihanPesanan;

            if (pilihanPesanan == 't' || pilihanPesanan == 'T') {
                return;
            }
        }
    } while (true);
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
        cout << "1. Lihat Produk\n";
        cout << "2. Lihat Keranjang\n";
        cout << "3. Konfirmasi Pembayaran\n";
        cout << "4. Lihat Riwayat Pembayaran\n";
        cout << "5. Lihat Detail Transaksi\n";
        cout << "6. Keluar\n";
        cout << "====================================\n";
        cout << "Pilih opsi (1-6): ";
}