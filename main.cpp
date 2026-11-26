#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;

struct Kost {
    string id;
    string nama;
    long long harga;
    double jarak;
    string labelJarak;
    string fasilitas;
    int poinFasilitas;
    int poinHarga;
    int poinJarak;
    int skorAkhir;
};

const int MAX_KOST = 100;
Kost daftarKost[MAX_KOST];
int jumlahKost = 0;

void inputKosan();                                  
void tampilDanUrutkan();                           
void cariDanRataRata();                             
long long totalHargaRekursif(int index);            
void rekomendasiFinal();                            

int main() {
    int pilihan;

    do {
        cout << "\n========================================\n";
        cout << "          SMART KOST SELECTOR           \n";
        cout << "========================================\n";
        cout << "1. Tambah Data Kosan\n";
        cout << "2. Lihat Daftar & Urutkan Kosan\n";
        cout << "3. Cari Kosan & Rata-rata Harga\n";
        cout << "4. Rekomendasi Kosan Terbaik (Ranking)\n";
        cout << "5. Keluar\n";
        cout << "----------------------------------------\n";
        cout << "Pilih Menu (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                inputKosan();
                break;
            case 2:
                tampilDanUrutkan();
                break;
            case 3:
                cariDanRataRata();
                break;
            case 4:
                rekomendasiFinal();
                break;
            case 5:
                cout << "\nProgram selesai\n";
                break;
            default:
                cout << "\nPilihan tidak valid, masukkan angka 1-5.\n";
        }
    } while (pilihan != 5);

    return 0;
}
