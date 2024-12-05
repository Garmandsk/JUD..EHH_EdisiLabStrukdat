#include "function.cxx"
   
// Fungsi utama
int main() {
    system("cls");
            
            int pilihan;
            
            do {
                system("cls");
                showMenuPelanggan();
                cin >> pilihan;
        
                switch (pilihan) {
                    case 1:
                        system("cls");
                        /* Isi Dengan Function Saja */
                        cout << endl << "Enter Untuk Kembali";
                        cin.ignore();
                        cin.get();  
                        break;
                    case 2:
                        system("cls");

                        /* Isi Dengan Function Saja */
                        cout << endl << "Enter Untuk Kembali";
                        cin.ignore();
                        cin.get();  
                        break;
                    case 4:
                        system("cls");
                        /* Isi Dengan Function Saja */
                        cout << endl << "Enter Untuk Kembali";
                        cin.ignore();
                        cin.get();  
                        break;
                    case 5:
                        system("cls");
                        /* Isi Dengan Function Saja */
                        cout << endl << "Enter Untuk Kembali";
                        cin.ignore();
                        cin.get();  
                        break;
                    case 6:
                        system("cls");
                        /* Isi Dengan Function Saja */
                        cout << endl << "Enter Untuk Kembali";
                        cin.ignore();
                        cin.get();  
                        break;
                    case 7:
                        system("cls");
                        /* Isi Dengan Function Saja */
                        cout << endl << "Enter Untuk Kembali";
                        cin.ignore();
                        cin.get();  
                        break;
                    case 8:
                        system("cls");
                        /* Isi Dengan Function Saja */
                        cout << endl << "Enter Untuk Kembali";
                        cin.ignore();
                        cin.get();  
                        break;
                    case 9:
                        system("cls");
                        /* Isi Dengan Function Saja */
                        cout << endl << "Enter Untuk Kembali";
                        cin.ignore();
                        cin.get();  
                        break;                   
                    case 10:
                        return 0;
                        break;
                    default:
                        system("cls");
                        cout << "\nPilihan tidak valid. Silakan coba lagi.\n";
                }
            } while (pilihan != 4);
    
    return 0;
}