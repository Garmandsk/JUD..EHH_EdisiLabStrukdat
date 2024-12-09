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
                tampilkanProduk();     
                cin.ignore();
                cin.get();
                break;
            case 2:
                system("cls");
                lihatKeranjang();
                cin.ignore();
                cin.get();
                break;

            case 3:
                system("cls");
                lakukanPembayaran();
                cin.ignore();
                cin.get();
                break;

            case 4:
                system("cls");
                lihatRiwayatPembayaran();
                cin.ignore();
                cin.get();
                break;

            case 5:
                system("cls");
                lihatDetailTransaksi();
                cin.ignore();
                cin.get();
                break;
          
            case 6:
                cout << "Terima kasih telah berbelanja di toko kami!\n";
                return 0;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    }
    
    return 0;
}