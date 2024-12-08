#include "function.cxx"
   
// Menu utama
int main() {
    
    masukkanKeHash();
    
    while (true) {
        system("cls");
        showMenu();

        int opsi;
        cin >> opsi;

        switch (opsi) {
            case 1:
                system("cls");
                // Sorting produk
                urutkanProduk();
                cin.ignore();
                cin.get();
                break;
            case 2:
                system("cls");
                // Tambah ke keranjang
                int idTambah;
                cout << "Masukkan ID produk yang ingin ditambahkan ke keranjang: ";
                cin >> idTambah;
                tambahkanKeKeranjang(idTambah);
                cin.ignore();
                cin.get();
                break;
            case 3:
                system("cls");
                // Cari produk
                int idCari;
                cout << "Masukkan ID produk yang ingin dicari: ";
                cin >> idCari;
                cariProduk(idCari);
                cin.ignore();
                cin.get();
                break;
            case 4:
                system("cls");
                // Lihat keranjang
                cout << "Produk dalam keranjang:\n";
                lihatKeranjang();
                cin.ignore();
                cin.get();
                break;
            case 5:
                system("cls");
                // Hapus dari keranjang
                int idHapus;
                cout << "Masukkan ID produk yang ingin dihapus dari keranjang: ";
                cin >> idHapus;
                hapusDariKeranjang(idHapus);
                cin.ignore();
                cin.get();
                break;
            case 6:
                system("cls");
                // Hitung biaya pengiriman
                hitungBiayaPengiriman();
                cin.ignore();
                cin.get();
                break;
            case 7:
                system("cls");
                // Lakukan pembayaran
                lakukanPembayaran();
                cin.ignore();
                cin.get();
                break;
            case 8:
                system("cls");
                // Lihat riwayat pembayaran
                lihatRiwayatPembayaran();
                cin.ignore();
                cin.get();
                break;
            case 9:
                system("cls");
                // Lihat detail transaksi
                int idTransaksi;
                cout << "Masukkan ID transaksi yang ingin dilihat: ";
                cin >> idTransaksi;
                lihatDetailTransaksi(idTransaksi);
                cin.ignore();
                cin.get();
                break;
            case 10:
                // Keluar
                cout << "Terima kasih telah berbelanja di toko kami!\n";
                return 0;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    }
    
    return 0;
}