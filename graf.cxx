// Fungsi untuk menghitung biaya pengiriman
void hitungBiayaPengiriman() {
    int pilihan;
    
    // Menampilkan daftar lokasi tujuan
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

    // Hitung dan tampilkan biaya pengiriman
    if (jarak < numeric_limits<double>::max()) {
        double biayaPerKm = 10000; // Biaya per km dalam rupiah
        cout << "\nBiaya pengiriman dari " << lokasiAsal << " ke " << lokasiTujuan << " adalah Rp " 
             << fixed << setprecision(0) << jarak * biayaPerKm << endl; // Menampilkan dengan format tetap dan tanpa desimal
    } else {
        cout << "\nRute tidak ditemukan! Pastikan lokasi tujuan benar.\n";
    }
}