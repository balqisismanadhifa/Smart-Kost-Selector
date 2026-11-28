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
void hitungpoin();
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

void tampilDanUrutkan() {
    if (jumlahKost == 0) {
        cout << "\nData Kosong (isi dulu di Menu 1)\n";
        return;
    }
    cout << "\n===============================================================================\n";
    cout << left << setw(6)  << "ID"
         << setw(18) << "Nama Kosan"
         << setw(14) << "Harga (Rp)"
         << setw(12) << "Jarak (m)"
         << setw(20) << "Fasilitas"
         << setw(8)  << "Poin" << endl;
    cout << "-------------------------------------------------------------------------------\n";
    for (int i = 0; i < jumlahKost; i++) {
        cout << left << setw(6)  << daftarKost[i].id
             << setw(18) << daftarKost[i].nama
             << setw(14) << daftarKost[i].harga
             << setw(12) << daftarKost[i].jarak
             << setw(20) << daftarKost[i].fasilitas
             << setw(8)  << daftarKost[i].poinFasilitas << endl;
    }
    cout << "===============================================================================\n";

    int pilihSort;
    cout << "\nMau diurutkan berdasarkan apa?\n";
    cout << "1. Harga Termurah\n";
    cout << "2. Harga Termahal\n";
    cout << "3. Jarak Terdekat\n";
    cout << "4. Fasilitas Terlengkap\n";
    cout << "Pilih (1-4): ";
    cin >> pilihSort;

    for (int i = 0; i < jumlahKost - 1; i++) {
        for (int j = 0; j < jumlahKost - i - 1; j++) {
            if (pilihSort == 1) {
                if (daftarKost[j].harga > daftarKost[j + 1].harga) {
                    Kost sementara = daftarKost[j];
                    daftarKost[j] = daftarKost[j + 1];
                    daftarKost[j + 1] = sementara;
                }
            }
            else if (pilihSort == 2) {
                if (daftarKost[j].harga < daftarKost[j + 1].harga) {
                    Kost sementara = daftarKost[j];
                    daftarKost[j] = daftarKost[j + 1];
                    daftarKost[j + 1] = sementara;
                }
            }
            else if (pilihSort == 3) {
                if (daftarKost[j].jarak > daftarKost[j + 1].jarak) {
                    Kost sementara = daftarKost[j];
                    daftarKost[j] = daftarKost[j + 1];
                    daftarKost[j + 1] = sementara;
                }
            }
            else if (pilihSort == 4) {
                if (daftarKost[j].poinFasilitas < daftarKost[j + 1].poinFasilitas) {
                    Kost sementara = daftarKost[j];
                    daftarKost[j] = daftarKost[j + 1];
                    daftarKost[j + 1] = sementara;
                }
            }

        }
    }
    if (pilihSort >= 1 && pilihSort <= 4) {
        cout << "\n--- TABEL HASIL PENGURUTAN ---\n";
        cout << "===============================================================================\n";
        cout << left << setw(6)  << "ID"
             << setw(18) << "Nama Kosan"
             << setw(14) << "Harga (Rp)"
             << setw(12) << "Jarak (m)"
             << setw(20) << "Fasilitas"
             << setw(8)  << "Poin" << endl;
        cout << "-------------------------------------------------------------------------------\n";

        for (int i = 0; i < jumlahKost; i++) {
            cout << left << setw(6)  << daftarKost[i].id
                 << setw(18) << daftarKost[i].nama
                 << setw(14) << daftarKost[i].harga
                 << setw(12) << daftarKost[i].jarak
                 << setw(20) << daftarKost[i].fasilitas
                 << setw(8)  << daftarKost[i].poinFasilitas << endl;
        }

long long totalHargaRekursif(int index) {
    if (index >= jumlahKost) {
        return 0;
    }
    return daftarKost[index].harga + totalHargaRekursif(index + 1);
}

void cariDanRataRata() {
    if (jumlahKost == 0) {
        cout << "\nData Kosong (isi dulu di Menu 1)\n";
        return;
    }

    string keyword;
    cin.ignore();
    cout << "\n=== CARI KOSAN & RATA-RATA HARGA ===\n";
    cout << "Masukkan ID atau Nama Kosan: ";
    getline(cin, keyword);

    string keyKecil = keyword;
    for (int i = 0; i < (int)keyKecil.length(); i++) {
        if (keyKecil[i] >= 'A' && keyKecil[i] <= 'Z') {
            keyKecil[i] = keyKecil[i] + 32;
        }
    }

    bool ditemukan = false;

    for (int i = 0; i < jumlahKost; i++) {
        string idKecil = daftarKost[i].id;
        for (int j = 0; j < (int)idKecil.length(); j++) {
            if (idKecil[j] >= 'A' && idKecil[j] <= 'Z') {
                idKecil[j] = idKecil[j] + 32;
            }
        }

        string namaKecil = daftarKost[i].nama;
        for (int j = 0; j < (int)namaKecil.length(); j++) {
            if (namaKecil[j] >= 'A' && namaKecil[j] <= 'Z') {
                namaKecil[j] = namaKecil[j] + 32;
            }
        }

        if (idKecil == keyKecil || namaKecil.find(keyKecil) != string::npos) {
            ditemukan = true;
            cout << "\n+--------------------------------------------------+\n";
            cout << "| DETAIL DATA KOSAN                                |\n";
            cout << "+--------------------------------------------------+\n";
            cout << "  ID Kosan       : " << daftarKost[i].id << "\n";
            cout << "  Nama Kosan     : " << daftarKost[i].nama << "\n";
            cout << "  Harga Sewa     : Rp " << daftarKost[i].harga << " / bulan\n";
            cout << "  Jarak Kampus   : " << daftarKost[i].jarak << " m (" << daftarKost[i].labelJarak << ")\n";
            cout << "  Fasilitas      : " << daftarKost[i].fasilitas << "\n";
            cout << "  Poin Fasilitas : " << daftarKost[i].poinFasilitas << "/100\n";
            cout << "+--------------------------------------------------+\n";
        }
    }

    if (!ditemukan) {
        cout << "\nData kosan tidak ditemukan.\n";
    } else {
        long long totalHarga = totalHargaRekursif(0);
        double rataRata = static_cast<double>(totalHarga) / jumlahKost;

        cout << fixed << setprecision(2);
        cout << "Total Harga Seluruh Kos (" << jumlahKost << " data) : Rp " << totalHarga << "\n";
        cout << "Rata-rata Harga Sewa Kosan       : Rp " << rataRata << "\n";
    }
}
		
void hitungpoin(){
    long long hargaMin = daftarKost[0].harga;
    long long hargaMax = daftarKost[0].harga;
    double jarakMin = daftarKost[0].jarak;
    double jarakMax = daftarKost[0].jarak;
    
    for(int i = 0; i<jumlahKost ; i++){
    	if (daftarKost[i].harga < hargaMin ) hargaMin = daftarKost[i].harga;
    	if (daftarKost[i].harga > hargaMax ) hargaMax = daftarKost[i].harga;
		if (daftarKost[i].jarak < jarakMin ) jarakMin = daftarKost[i].jarak;
		if (daftarKost[i].jarak > jarakMax ) jarakMax = daftarKost[i].jarak;
	}
	
	for(int i = 0; i<jumlahKost ;i++){
		double pointKostjarak;
		if(jarakMax==jarakMin){
			pointKostjarak = 100 ;
		} else {
			pointKostjarak = 100 - (daftarKost[i].jarak-jarakMin)/(jarakMax - jarakMin )*80;
		}
		daftarKost[i].poinJarak = static_cast<int>(pointKostjarak+0.5);
		
		double pointKostharga;
		if(hargaMax==hargaMin){
			pointKostharga = 100 ;
		} else {
			pointKostharga =  100 - (daftarKost[i].harga-hargaMin)/(hargaMax - hargaMin )*80;
		}
		daftarKost[i].poinHarga = static_cast<int>(pointKostharga+0.5);
		
		double totalPoin = (daftarKost[i].poinHarga*0.30)+
						   (daftarKost[i].poinJarak*0.40)+
						   (daftarKost[i].poinFasilitas*0.30);
						   
		daftarKost[i].skorAkhir = static_cast<int>(totalPoin+0.5);
	}
}

void rekomendasiFinal(){
	if(jumlahKost == 0){
		cout<<"\nData Kosong (isi dulu di menu 1)\n";
		return;
	}
	
	hitungp oin();
	
	for(int i = 0; i<jumlahKost-1; i++){
		for(int j = 0; j<jumlahKost-i-1 ; i++){
			bool tukar = false;
			if(daftarKost[j].skorAkhir < daftarKost[j+1].skorAkhir){
				tukar = true;
			} else if ( daftarKost[j].skorAkhir == daftarKost[j+1].skorAkhir && 
					daftarKost[j].jarak > daftarKost[j+1].jarak){
						tukar = true;
					}
					
			if(tukar){
				Kost sementara = daftarKost[i];
				daftarKost[j] = daftarKost[j+1];
				daftarKost[j+1] = sementara;
			}
		}
	}
	
    cout << "                    REKOMENDASI & RANKING KOST TERBAIK                          \n";
    cout << "================================================================================\n";
    cout << left << setw(6)  << "ID"
         << setw(18)  << "ID"
         << setw(14) << "Nama Kosan"
         << setw(12) << "Harga (Rp)"
         << setw(20) << "Jarak (m)"
         << setw(9)  << "P.Jarak"
         << setw(9)  << "P.Harga"
         << setw(8)  << "Skor Akhir" << endl;
    cout << "--------------------------------------------------------------------------------\n";

    for (int i = 0; i < jumlahKost; i++) {
        cout << left << setw(6)  << (i + 1)
             << setw(7)  << daftarKost[i].id
             << setw(18) << daftarKost[i].nama
             << setw(13) << daftarKost[i].harga
             << setw(10) << daftarKost[i].jarak
             << setw(9)  << daftarKost[i].poinJarak
             << setw(9)  << daftarKost[i].poinHarga
             << setw(8)  << daftarKost[i].skorAkhir << endl;
    }

    cout << "--------------------------------------------------------------------------------\n";
    cout << "Rekomendasi Utama : " << daftarKost[0].nama
         << " (ID: " << daftarKost[0].id
         << ", Jarak: " << daftarKost[0].jarak << " m"
         << ", Skor: " << daftarKost[0].skorAkhir << ")\n";
    cout << "================================================================================\n";
}
        cout << "===============================================================================\n";
    } else {
        cout << "\nPilihan tidak valid!\n";
    }
}
