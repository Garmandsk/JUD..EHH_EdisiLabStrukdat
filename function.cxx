#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>
#include <iomanip>
#include <windows.h>

using namespace std;

/* Struct Produk */
struct Produk {
    int id;
    string nama;
    string kategori;
    double harga;
};

/* Struct Pembayaran */
struct Pembayaran {
    int idTransaksi;
    vector<Produk> keranjang;
    double totalHarga;
};

/* Daftar Produk */
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
    
/* Variabel Global */
vector<Produk> keranjang;
vector<Pembayaran> riwayatPembayaran;
unordered_map<int, Produk> hashProduk;
int idTransaksiGlobal = 1;

/* Metode Hash */
void masukkanKeHash() {
    for (const auto &p : daftarProduk) {
        hashProduk[p.id] = p;
    }
}

/* Function No. 1 */
void urutkanProduk() {
    int pilihan;
    cout << "Pilih metode pengurutan:\n";
    cout << "1. Berdasarkan kategori (A-Z)\n";
    cout << "2. Berdasarkan harga (termurah ke termahal)\n";
    cout << "3. Berdasarkan harga (termahal ke termurah)\n";
    cout << "Masukkan pilihan (1-3): ";
    cin >> pilihan;

    if (pilihan == 1) {
        sort(daftarProduk.begin(), daftarProduk.end(), [](const Produk &a, const Produk &b) {
            return a.kategori == b.kategori ? a.nama < b.nama : a.kategori < b.kategori;
        });

        cout << "\nProduk berhasil diurutkan berdasarkan kategori (A-Z):\n";
        string kategoriSekarang = "";
        for (const auto &p : daftarProduk) {
            if (p.kategori != kategoriSekarang) {
                kategoriSekarang = p.kategori;
                cout << "\n==== " << kategoriSekarang << " ====\n";
            }
            cout << "   " << p.id << ". " << p.nama << " - Rp " 
                 << fixed << setprecision(2) << p.harga << endl;
        }
    } else if (pilihan == 2) {
        sort(daftarProduk.begin(), daftarProduk.end(), [](const Produk &a, const Produk &b) {
            return a.harga < b.harga;
        });

        cout << "\nProduk berhasil diurutkan berdasarkan harga (termurah ke termahal):\n";
        for (const auto &p : daftarProduk) {
            cout << p.id << ". " << p.nama << " - " << p.kategori << " - Rp " 
                 << fixed << setprecision(2) << p.harga << endl;
        }
    } else if (pilihan == 3) {
        sort(daftarProduk.begin(), daftarProduk.end(), [](const Produk &a, const Produk &b) {
            return a.harga > b.harga;
        });

        cout << "\nProduk berhasil diurutkan berdasarkan harga (termahal ke termurah):\n";
        for (const auto &p : daftarProduk) {
            cout << p.id << ". " << p.nama << " - " << p.kategori << " - Rp " 
                 << fixed << setprecision(2) << p.harga << endl;
        }
    } else {
        cout << "Pilihan tidak valid!\n";
    }
}

/* Function No. 1 */
void cariProduk() {
    int idCari;
    cout << "Masukkan ID produk yang ingin dicari: ";
    cin >> idCari;
    
    auto it = hashProduk.find(idCari);
    if (it != hashProduk.end()) {
        cout << "I=================================================I\n";
        cout << "                PRODUK DITEMUKAN!\n";
        cout << "I=================================================I\n";
        cout << " Nama               : " << it->second.nama << endl;
        cout << " Kategori           : " << it->second.kategori << endl;
        cout << " Harga              : Rp " << fixed << setprecision(2) << it->second.harga << endl;
        cout << "I=================================================I\n";
    } else {
        cout << "Produk dengan ID tersebut tidak ditemukan.\n";
    }
}

/* Function No. 1 */
void tampilkanProduk() {
    string pilihan;
    char pilihanPesanan;
    int jumlahPesanan;

    do {
        system("cls"); 

        /* Tampilkan Daftar Produk */
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

        if (pilihan == "s" || pilihan == "S") {
            urutkanProduk();
            cin.ignore();
            cin.get();
        }
 
        else if (pilihan == "c" || pilihan == "C") {
            cariProduk();
            cout << "\nTekan Enter untuk kembali...";
            cin.ignore();
            cin.get();
        } 
        
        else if (pilihan == "k" || pilihan == "K") {
            return;
        } 
        
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

            auto it = find_if(daftarProduk.begin(), daftarProduk.end(),
                              [idPilihan](const Produk& p) { return p.id == idPilihan; });
            if (it == daftarProduk.end()) {
                cout << "\nProduk dengan ID " << idPilihan << " tidak ditemukan.\n";
                cin.ignore();
                cin.get();
                continue;
            }

            cout << "Jumlah yang ingin dipesan: ";
            cin >> jumlahPesanan;
            if (jumlahPesanan <= 0) {
                cout << "\nJumlah harus lebih dari 0.\n";
                cin.ignore();
                cin.get();
                continue;
            }

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

/* Function No. 2 */
void lihatKeranjang() {
    string pilihan;
   
    do {
        system("cls");
        if (keranjang.empty()) {
            cout << "Keranjang belanja kosong!\n";
            return;
        }
        
        /* Tampilkan Isi Keranjang */
        for (const auto &produk : keranjang) {
            cout << produk.id << ". " << produk.nama << " - " << produk.kategori 
                 << " - Rp " << fixed << setprecision(2) << produk.harga << endl;
        }
        
        cout << "\nTekan 'h' untuk menghapus barang dari keranjang\n";
        cout << "Tekan 'k' untuk kembali\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        
        if (pilihan == "h" || pilihan == "H") {
            int idHapus;
            cout << "Masukkan ID produk yang ingin dihapus dari keranjang: ";
            cin >> idHapus;
            auto it = find_if(keranjang.begin(), keranjang.end(), [idHapus](const Produk &produk) { return produk.id == idHapus; });
            if (it != keranjang.end()) {
                keranjang.erase(it);
                cout << "Produk berhasil dihapus dari keranjang!\n";
            } else {
                cout << "Produk tidak ditemukan di keranjang!\n";
            }
        } else if (pilihan == "k" || pilihan == "K") {
            cout << "Kembali ke menu utama...\n";
        } else {
            cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    } while (pilihan != "k" && pilihan != "K");
}

/* Function No. 3 */
void lakukanPembayaran() {
    if (keranjang.empty()) {
        cout << "Keranjang kosong! Tidak ada yang bisa dibayar.\n";
        return;
    }

    double totalHarga = 0;
    for (const auto &produk : keranjang) {
        totalHarga += produk.harga;
    }

    int pilihan;
    cout << "Daftar Lokasi Pengiriman Yang Bisa Diantar Dari Indonesia:\n";
    cout << "1. Malaysia\n";
    cout << "2. Australia\n";
    cout << "3. Jepang\n";
    cout << "4. Yunani\n";
    cout << "5. Korea Utara\n\n";
    cout << "Masukkan nomor tujuan pengantaran Anda (1-5): ";
    cin >> pilihan;

    unordered_map<int, string> tujuanMap = {
        {1, "Malaysia"},
        {2, "Australia"},
        {3, "Jepang"},
        {4, "Yunani"},
        {5, "Korea Utara"}
    };

    if (tujuanMap.find(pilihan) == tujuanMap.end()) {
        cout << "\nNomor tujuan tidak valid! Silakan pilih nomor antara 1 dan 5.\n";
        return;
    }

    string lokasiTujuan = tujuanMap[pilihan];

    // Graf statis untuk rute pengiriman dan jarak (dalam km)
    unordered_map<string, vector<pair<string, double>>> graf = {
        {"Indonesia", {{"Malaysia", 500}, 
                       {"Australia", 2750}, 
                       {"Jepang", 5800},
                       {"Yunani", 10400},     
                       {"Korea Utara", 5300}}},
    };

    string lokasiAsal = "Indonesia";
    double jarak = numeric_limits<double>::max();

    /* Cek Lokasi Asal Ke Tujuan */
    if (graf.find(lokasiAsal) != graf.end()) {
        for (const auto &tujuanInfo : graf[lokasiAsal]) {
            if (tujuanInfo.first == lokasiTujuan) {
                jarak = tujuanInfo.second;
                break;
            }
        }
    }

    double biayaPengiriman = 0;
    if (jarak < numeric_limits<double>::max()) {
        double biayaPerKm = 10000; 
        biayaPengiriman = jarak * biayaPerKm;
    } else {
        cout << "\nRute tidak ditemukan! Pastikan lokasi tujuan benar.\n";
        return;
    }

    double totalPembayaran = totalHarga + biayaPengiriman;
    cout << "\nDetail Pembayaran:\n";
    cout << "Total Harga Produk: Rp " << fixed << setprecision(2) << totalHarga << endl;
    cout << "Biaya Pengiriman: Rp " << fixed << setprecision(2) << biayaPengiriman << endl;
    cout << "Total Pembayaran: Rp " << fixed << setprecision(2) << totalPembayaran << endl;

    char konfirmasi;
    cout << "\nLakukan pembayaran? (Y/T): ";
    cin >> konfirmasi;

    if (tolower(konfirmasi) == 'y') {
        riwayatPembayaran.push_back({idTransaksiGlobal++, keranjang, totalPembayaran});
        keranjang.clear();
        cout << "\nPembayaran berhasil dilakukan! Terima kasih telah berbelanja.\n";
    } else {
        cout << "\nPembayaran dibatalkan.\n";
    }
}

/* Function No. 4 */
void lihatRiwayatPembayaran() {
    if (riwayatPembayaran.empty()) {
        cout << "Riwayat pembayaran kosong!\n";
        return;
    }
    for (const auto &pembayaran : riwayatPembayaran) {
        cout << "ID Transaksi: " << pembayaran.idTransaksi << " - Total: Rp " << fixed << setprecision(2) << pembayaran.totalHarga << endl;
    }
}

/* Function No. 5 */
void lihatDetailTransaksi() {
    int idTransaksi;
    
    cout << "Masukkan ID transaksi yang ingin dilihat: ";
    cin >> idTransaksi;
    for (const auto &pembayaran : riwayatPembayaran) {
        if (pembayaran.idTransaksi == idTransaksi) {
            cout << "Detail Transaksi ID " << idTransaksi << ":\n";
            for (const auto &produk : pembayaran.keranjang) {
                cout << produk.id << ". " << produk.nama << " - " << produk.kategori << " - Rp " << fixed << setprecision(2) << produk.harga << endl;
            }
            return;
        }
    }
    cout << "Transaksi tidak ditemukan!\n";
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