#include <iostream>
#include <string>
using namespace std;

struct Batalyon {
    int ID;
    string nama_general;
    string tipe_pasukan;
    int jumlah_pasukan;
};

string pasukan[3] = {"Infantry", "Kavaleri", "Archer"};
Batalyon batalyon[100];
int jumlahBatalyon = 0;
int idBatalyon = 1;

bool pasukanValid(string Type) {
    for (int i = 0; i < 3; i++) {
        if (Type == pasukan[i]) {
            return true;
        }
    }
    return false;
}

void tambahBatalyon();
void cariBatalyon();

int main() {
    int pilih;
    string keluar;
    do {
        cout << "\nMENU" << endl;
        cout << "1. Tambah Batalyon" << endl;
        cout << "2. Cari Batalyon" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih Menu: ";
        cin >> pilih;

        switch (pilih) {
        case 1:
            tambahBatalyon();
            break;
        case 2:
            cariBatalyon();
            break;
        case 3:
            cout << "Apakah Anda ingin keluar? (Y/N): ";
            cin >> keluar;
            if (keluar == "Y" || keluar == "y") {
                cout << "Anda telah keluar" << endl;
                return 0;
            }
            break;
        default:
            cout << "Menu tidak tersedia" << endl;
        }
    } while (pilih != 3);
    return 0;
}

void tambahBatalyon() {
    if (jumlahBatalyon >= 100) {
        cout << "Batalyon sudah penuh" << endl;
        return;
    }

    cin.ignore();
    cout << "Masukkan Nama General: ";
    string nama_general;
    getline(cin, nama_general);

    if (nama_general.empty()) {
        cout << "Nama general tidak boleh kosong" << endl;
        return;
    }

    for (int i = 0; i < jumlahBatalyon; i++) {
        if (batalyon[i].nama_general == nama_general) {
            cout << "General sudah terdaftar" << endl;
            return;
        }
    }

    cout << "Masukkan Tipe Pasukan (Infantry, Kavaleri, Archer): ";
    string tipe_pasukan;
    getline(cin, tipe_pasukan);

    if (!pasukanValid(tipe_pasukan)) {
        cout << "Tipe pasukan tidak valid" << endl;
        return;
    }

    cout << "Masukkan Jumlah Pasukan: ";
    int jumlah_pasukan;
    cin >> jumlah_pasukan;

    if (jumlah_pasukan <= 0) {
        cout << "Jumlah pasukan tidak valid" << endl;
        return;
    }

    batalyon[jumlahBatalyon].ID = idBatalyon++;
    batalyon[jumlahBatalyon].nama_general = nama_general;
    batalyon[jumlahBatalyon].tipe_pasukan = tipe_pasukan;
    batalyon[jumlahBatalyon].jumlah_pasukan = jumlah_pasukan;
    jumlahBatalyon++;

    cout << "Batalyon berhasil ditambahkan" << endl;
}

void cariBatalyon() {
    if (jumlahBatalyon == 0) {
        cout << "Tidak ada batalyon yang tersedia" << endl;
        return;
    }

    cin.ignore();
    string namaGeneral;
    cout << "Masukkan Nama General yang ingin dicari: ";
    getline(cin, namaGeneral);

    bool ditemukan = false;
    for (int i = 0; i < jumlahBatalyon; i++) {
        if (batalyon[i].nama_general == namaGeneral) {
            ditemukan = true;
            cout << "ID: " << batalyon[i].ID << endl;
            cout << "General: " << batalyon[i].nama_general << endl;
            cout << "Tipe Pasukan: " << batalyon[i].tipe_pasukan << endl;
            cout << "Jumlah Pasukan: " << batalyon[i].jumlah_pasukan << endl;
            break;
        }
    }
    if (!ditemukan) {
        cout << "General tidak ditemukan" << endl;
    }
}