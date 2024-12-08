// Fungsi untuk mencari produk berdasarkan ID
void cariProduk(int idProduk) {
    auto it = hashProduk.find(idProduk);
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