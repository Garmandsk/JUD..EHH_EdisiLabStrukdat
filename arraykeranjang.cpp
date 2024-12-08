#include <iostream>
#include <vector>
#include <string>
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

// Fungsi untuk menampilkan keranjang
void tampilkanKeranjang(const vector<Produk>& keranjang) {
    if (keranjang.empty()) {
        cout << "Keranjang pembelian kosong.\n";
    } else {
        cout << "Isi keranjang pembelian:\n";
        tampilkanProduk(keranjang);
    }
}

// Fungsi untuk menambahkan produk ke keranjang
void tambahkanKeKeranjang(vector<Produk>& keranjang, const vector<Produk>& daftarProduk, int idProduk) {
    auto it = find_if(daftarProduk.begin(), daftarProduk.end(), [idProduk](const Produk& p) {
        return p.id == idProduk;
    });

    if (it != daftarProduk.end()) {
        keranjang.push_back(*it);
        cout << "Produk \"" << it->nama << "\" berhasil ditambahkan ke keranjang.\n";
    } else {
        cout << "Produk dengan ID " << idProduk << " tidak ditemukan.\n";
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

    // Keranjang pembelian
    vector<Produk> keranjang;

    int pilihan;
    do {
        cout << "\nMenu:\n";
        cout << "1. Tampilkan daftar produk\n";
        cout << "2. Tambahkan produk ke keranjang\n";
        cout << "3. Tampilkan isi keranjang\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Daftar Produk:\n";
                tampilkanProduk(daftarProduk);
                break;
            case 2: {
                int idProduk;
                cout << "Masukkan ID produk yang ingin ditambahkan ke keranjang: ";
                cin >> idProduk;
                tambahkanKeKeranjang(keranjang, daftarProduk, idProduk);
                break;
            }
            case 3:
                tampilkanKeranjang(keranjang);
                break;
            case 4:
                cout << "Terima kasih telah menggunakan aplikasi ini.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 4);

    return 0;
}
