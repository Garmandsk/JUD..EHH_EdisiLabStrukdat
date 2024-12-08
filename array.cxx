// Fungsi untuk menambahkan produk ke keranjang
void tambahkanKeKeranjang(int id) {
    if (hashProduk.find(id) != hashProduk.end()) {
        keranjang.push_back(hashProduk[id]);
        cout << "Produk berhasil ditambahkan ke keranjang!\n";
    } else {
        cout << "Produk tidak ditemukan!\n";
    }
}

// Fungsi untuk melihat keranjang
void lihatKeranjang() {
    if (keranjang.empty()) {
        cout << "Keranjang belanja kosong!\n";
        return;
    }
    for (const auto &produk : keranjang) {
        cout << produk.id << ". " << produk.nama << " - " << produk.kategori << " - Rp " << fixed << setprecision(2) << produk.harga << endl;
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

// Fungsi untuk melakukan pembayaran
void lakukanPembayaran() {
    if (keranjang.empty()) {
        cout << "Keranjang kosong! Tidak ada yang bisa dibayar.\n";
        return;
    }
    double totalHarga = 0;
    for (const auto &produk : keranjang) {
        totalHarga += produk.harga;
    }
    riwayatPembayaran.push_back({idTransaksiGlobal++, keranjang, totalHarga});
    keranjang.clear();
    cout << "Pembayaran berhasil dilakukan! Total: Rp " << fixed << setprecision(2) << totalHarga << endl;
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