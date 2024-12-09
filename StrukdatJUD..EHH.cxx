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
                tampilkanProduk();
                cin.ignore();
                cin.get();
                break;
            case 2:
                system("cls");
                // Lihat keranjang
                cout << "Produk dalam keranjang:\n";
                lihatKeranjang();
                cin.ignore();
                cin.get();
                break;
            case 3:
                system("cls");
                // Lakukan pembayaran
                lakukanPembayaran();
                cin.ignore();
                cin.get();
                break;
            case 4:
                system("cls");
                // Lihat riwayat pembayaran
                lihatRiwayatPembayaran();
                cin.ignore();
                cin.get();
                break;
            case 5:
                system("cls");
                // Lihat detail transaksi
                int idTransaksi;
                cout << "Masukkan ID transaksi yang ingin dilihat: ";
                cin >> idTransaksi;
                lihatDetailTransaksi(idTransaksi);
                cin.ignore();
                cin.get();
                break;
            case 6:
                // Keluar
                cout << "Terima kasih telah berbelanja di toko kami!\n";
                return 0;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    }
    
    return 0;
}