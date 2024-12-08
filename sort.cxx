void urutkanProduk() {
    int pilihan;
    cout << "Pilih metode pengurutan:\n";
    cout << "1. Berdasarkan kategori (A-Z)\n";
    cout << "2. Berdasarkan harga (termurah ke termahal)\n";
    cout << "3. Berdasarkan harga (termahal ke termurah)\n";
    cout << "Masukkan pilihan (1-3): ";
    cin >> pilihan;

    if (pilihan == 1) {
        // Mengurutkan produk berdasarkan kategori, kemudian nama produk
        sort(daftarProduk.begin(), daftarProduk.end(), [](const Produk &a, const Produk &b) {
            return a.kategori == b.kategori ? a.nama < b.nama : a.kategori < b.kategori;
        });

        // Menampilkan produk per kategori
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
        // Mengurutkan produk berdasarkan harga (termurah ke termahal)
        sort(daftarProduk.begin(), daftarProduk.end(), [](const Produk &a, const Produk &b) {
            return a.harga < b.harga;
        });

        // Menampilkan produk setelah diurutkan
        cout << "\nProduk berhasil diurutkan berdasarkan harga (termurah ke termahal):\n";
        for (const auto &p : daftarProduk) {
            cout << p.id << ". " << p.nama << " - " << p.kategori << " - Rp " 
                 << fixed << setprecision(2) << p.harga << endl;
        }
    } else if (pilihan == 3) {
        // Mengurutkan produk berdasarkan harga (termahal ke termurah)
        sort(daftarProduk.begin(), daftarProduk.end(), [](const Produk &a, const Produk &b) {
            return a.harga > b.harga;
        });

        // Menampilkan produk setelah diurutkan
        cout << "\nProduk berhasil diurutkan berdasarkan harga (termahal ke termurah):\n";
        for (const auto &p : daftarProduk) {
            cout << p.id << ". " << p.nama << " - " << p.kategori << " - Rp " 
                 << fixed << setprecision(2) << p.harga << endl;
        }
    } else {
        cout << "Pilihan tidak valid!\n";
    }
}
