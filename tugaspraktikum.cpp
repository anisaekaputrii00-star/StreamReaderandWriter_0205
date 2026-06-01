#include <iostream> 
#include <array> 
#include <fstream> 
#include <vector> 
#include <string> 

using namespace std;


class TokoElektronik
{
private:
    // Array private sebagai penerapan enkapsulasi
    array<string, 3> etalase;

public:

    // Constructor untuk mengisi data awal etalase
    TokoElektronik()
    {
        etalase[0] = "Laptop ASUS";
        etalase[1] = "Smartphone Samsung";
        etalase[2] = "Headset Logitech";
    }

    // Method mengambil produk berdasarkan nomor rak
    string ambilProduk(size_t nomorRak)
    {
        try
        {
            // Mengakses array menggunakan at()
            // at() akan mengecek batas indeks
            return etalase.at(nomorRak);
        }

        // Menangkap exception bawaan out_of_range
        catch (const out_of_range&)
        {
            // Melempar ulang pesan error custom
            throw string(
                "Gagal Mengambil Barang : Rak nomor "
                + to_string(nomorRak)
                + " kosong atau tidak tersedia!"
            );
        }
    }
};


// Menambahkan barang baru ke file gudang.txt
void tambahBarang()
{
    // Mode append agar data baru ditambahkan
    // tanpa menghapus isi file sebelumnya
    ofstream file("gudang.txt", ios::app);

    string nama;
    int stok;
    double harga;

    cin.ignore();

    // Input data barang
    cout << "\nNama Barang : ";
    getline(cin, nama);

    cout << "Stok : ";
    cin >> stok;

    cout << "Harga : ";
    cin >> harga;

    // Menyimpan data ke file
    file << nama << "|" << stok << "|" << harga << endl;

    file.close();

    cout << "\nBarang berhasil ditambahkan!\n";
}


// Membaca dan menampilkan isi file
void tampilBarang()
{
    ifstream file("gudang.txt");

    string line;

    cout << "\n===== DATA GUDANG =====\n";

    // Jika file belum tersedia
    if (!file)
    {
        cout << "File belum tersedia.\n";
        return;
    }

    int nomor = 1;

    // Membaca data file baris per baris
    while (getline(file, line))
    {
        cout << nomor++ << ". " << line << endl;
    }

    file.close();
}


// Mengubah data barang di file
void updateBarang()
{
    ifstream file("gudang.txt");

    // Vector sebagai penyimpanan sementara
    vector<string> data;

    string line;

    // Membaca seluruh isi file ke vector
    while (getline(file, line))
    {
        data.push_back(line);
    }

    file.close();

    // Validasi jika data kosong
    if (data.empty())
    {
        cout << "\nData kosong.\n";
        return;
    }

    tampilBarang();

    int pilih;

    cout << "\nNomor data yang ingin diubah : ";
    cin >> pilih;

    // Validasi pilihan user
    if (pilih < 1 || pilih > data.size())
    {
        cout << "Data tidak valid!\n";
        return;
    }

    string nama;
    int stok;
    double harga;

    cin.ignore();

    // Input data baru
    cout << "Nama baru : ";
    getline(cin, nama);

    cout << "Stok baru : ";
    cin >> stok;

    cout << "Harga baru : ";
    cin >> harga;

    // Mengganti data lama
    data[pilih - 1] =
        nama + "|" +
        to_string(stok) + "|" +
        to_string(harga);

    // Menulis ulang file
    ofstream tulis("gudang.txt");

    for (string isi : data)
    {
        tulis << isi << endl;
    }

    tulis.close();

    cout << "\nData berhasil diupdate!\n";
}


// Menghapus data barang dari file
void hapusBarang()
{
    ifstream file("gudang.txt");

    vector<string> data;
    string line;

    // Membaca seluruh isi file
    while (getline(file, line))
    {
        data.push_back(line);
    }

    file.close();

    if (data.empty())
    {
        cout << "\nData kosong.\n";
        return;
    }

    tampilBarang();

    int pilih;

    cout << "\nNomor data yang ingin dihapus : ";
    cin >> pilih;

    // Validasi nomor data
    if (pilih < 1 || pilih > data.size())
    {
        cout << "Data tidak valid!\n";
        return;
    }

    // Menghapus data yang dipilih
    data.erase(data.begin() + (pilih - 1));

    // Menulis ulang file setelah penghapusan
    ofstream tulis("gudang.txt");

    for (string isi : data)
    {
        tulis << isi << endl;
    }

    tulis.close();

    cout << "\nData berhasil dihapus!\n";
}


// Menguji exception handling
void simulasiEtalase()
{
    TokoElektronik toko;

    cout << "\n===== SIMULASI ETALASE =====\n";

    // SKENARIO 1 : indeks valid
    try
    {
        cout << "\nSkenario 1 (Rak 1)\n";

        cout << "Barang : "
             << toko.ambilProduk(1)
             << endl;
    }

    catch (string pesan)
    {
        cout << pesan << endl;
    }

    // SKENARIO 2 : indeks tidak valid
    try
    {
        cout << "\nSkenario 2 (Rak 5)\n";

        cout << "Barang : "
             << toko.ambilProduk(5)
             << endl;
    }

    catch (string pesan)
    {
        cout << pesan << endl;
    }
}


int main()
{
    // Variabel pilihan menu
    int pilihan;

    // Looping menu sampai user keluar
    do
    {
        cout << "\n==================================";
        cout << "\n  SISTEM TOKO ELEKTRONIK";
        cout << "\n        GIBRAN JAYA";
        cout << "\n==================================";

        // Read otomatis saat menu dibuka
        tampilBarang();

        // Menu utama program
        cout << "\n========== MENU ==========\n";
        cout << "1. Tambah Barang (Create)\n";
        cout << "2. Lihat Barang (Read)\n";
        cout << "3. Update Barang\n";
        cout << "4. Hapus Barang\n";
        cout << "5. Simulasi Etalase\n";
        cout << "0. Keluar\n";

        cout << "\nPilihan : ";
        cin >> pilihan;

        // Menjalankan menu berdasarkan pilihan user
        switch (pilihan)
        {
        case 1:
            tambahBarang();
            break;

        case 2:
            tampilBarang();
            break;

        case 3:
            updateBarang();
            break;

        case 4:
            hapusBarang();
            break;

        case 5:
            simulasiEtalase();
            break;

        case 0:
            cout << "\nProgram selesai.\n";
            break;

        default:
            cout << "\nPilihan tidak tersedia!\n";
        }

    }
    while (pilihan != 0);

    return 0;
}