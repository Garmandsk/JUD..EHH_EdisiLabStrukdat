// Fungsi untuk menambahkan produk ke keranjang
void tambahkanKeKeranjang(int id) {
    if (hashProduk.find(id) != hashProduk.end()) {
        keranjang.push_back(hashProduk[id]);
        cout << "Produk berhasil ditambahkan ke keranjang!\n";
    } else {
        cout << "Produk tidak ditemukan!\n";
    }
}

// Fungsi untuk menghapus produk dari keranjang
void hapusDariKeranjang(int id) {
    auto it = find_if(keranjang.begin(), keranjang.end(), [id](const Produk &produk) { return produk.id == id; });
    if (it != keranjang.end()) {
        keranjang.erase(it);
        cout << "Produk berhasil dihapus dari keranjang!\n";
    } else {
        cout << "Produk tidak ditemukan di keranjang!\n";
    }
}

// Fungsi untuk melihat keranjang
void lihatKeranjang() {
    string pilihan;
   
    do {
        system("cls");
        if (keranjang.empty()) {
            cout << "Keranjang belanja kosong!\n";
            return;
        }
        // Menampilkan isi keranjang
        for (const auto &produk : keranjang) {
            cout << produk.id << ". " << produk.nama << " - " << produk.kategori 
                 << " - Rp " << fixed << setprecision(2) << produk.harga << endl;
        }
        
        // Memberikan pilihan ke pengguna
        cout << "\nTekan 'h' untuk menghapus barang dari keranjang\n";
        cout << "Tekan 'k' untuk kembali\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        
        // Mengolah pilihan
        if (pilihan == "h" || pilihan == "H") {
            int idHapus;
            cout << "Masukkan ID produk yang ingin dihapus dari keranjang: ";
            cin >> idHapus;
            hapusDariKeranjang(idHapus);
        } else if (pilihan == "k" || pilihan == "K") {
            cout << "Kembali ke menu utama...\n";
        } else {
            cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    } while (pilihan != "k" && pilihan != "K");
}

// Fungsi untuk melakukan pembayaran
void lakukanPembayaran() {
    if (keranjang.empty()) {
        cout << "Keranjang kosong! Tidak ada yang bisa dibayar.\n";
        return;
    }

    // Menghitung total harga produk dalam keranjang
    double totalHarga = 0;
    for (const auto &produk : keranjang) {
        totalHarga += produk.harga;
    }

    // Menampilkan opsi lokasi tujuan pengiriman
    int pilihan;
    cout << "Daftar Lokasi Pengiriman Yang Bisa Diantar Dari Indonesia:\n";
    cout << "1. Malaysia\n";
    cout << "2. Australia\n";
    cout << "3. Jepang\n";
    cout << "4. Yunani\n";
    cout << "5. Korea Utara\n\n";
    cout << "Masukkan nomor tujuan pengantaran Anda (1-5): ";
    cin >> pilihan;

    // Memetakan nomor pilihan ke lokasi tujuan
    unordered_map<int, string> tujuanMap = {
        {1, "Malaysia"},
        {2, "Australia"},
        {3, "Jepang"},
        {4, "Yunani"},
        {5, "Korea Utara"}
    };

    // Memeriksa apakah nomor valid
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

    // Cari jarak ke tujuan
    if (graf.find(lokasiAsal) != graf.end()) {
        for (const auto &tujuanInfo : graf[lokasiAsal]) {
            if (tujuanInfo.first == lokasiTujuan) {
                jarak = tujuanInfo.second;
                break;
            }
        }
    }

    // Hitung biaya pengiriman
    double biayaPengiriman = 0;
    if (jarak < numeric_limits<double>::max()) {
        double biayaPerKm = 10000; // Biaya per km dalam rupiah
        biayaPengiriman = jarak * biayaPerKm;
    } else {
        cout << "\nRute tidak ditemukan! Pastikan lokasi tujuan benar.\n";
        return;
    }

    // Menampilkan total pembayaran
    double totalPembayaran = totalHarga + biayaPengiriman;
    cout << "\nDetail Pembayaran:\n";
    cout << "Total Harga Produk: Rp " << fixed << setprecision(2) << totalHarga << endl;
    cout << "Biaya Pengiriman: Rp " << fixed << setprecision(2) << biayaPengiriman << endl;
    cout << "Total Pembayaran: Rp " << fixed << setprecision(2) << totalPembayaran << endl;

    // Konfirmasi pembayaran
    char konfirmasi;
    cout << "\nLakukan pembayaran? (Y/N): ";
    cin >> konfirmasi;

    if (tolower(konfirmasi) == 'y') {
        riwayatPembayaran.push_back({idTransaksiGlobal++, keranjang, totalPembayaran});
        keranjang.clear();
        cout << "\nPembayaran berhasil dilakukan! Terima kasih telah berbelanja.\n";
    } else {
        cout << "\nPembayaran dibatalkan.\n";
    }
}

// Fungsi untuk melihat riwayat pembayaran
void lihatRiwayatPembayaran() {
    if (riwayatPembayaran.empty()) {
        cout << "Riwayat pembayaran kosong!\n";
        return;
    }
    for (const auto &pembayaran : riwayatPembayaran) {
        cout << "ID Transaksi: " << pembayaran.idTransaksi << " - Total: Rp " << fixed << setprecision(2) << pembayaran.totalHarga << endl;
    }
}