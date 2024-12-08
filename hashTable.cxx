// Fungsi untuk melihat detail transaksi
void lihatDetailTransaksi(int idTransaksi) {
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