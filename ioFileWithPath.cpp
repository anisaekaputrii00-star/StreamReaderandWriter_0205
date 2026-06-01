#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string baris, NamaFile;

    cout << "Masukkan nama file : ";
    cin >> NamaFile;

    ofstream outfile;

    outfile.open(NamaFile + ".txt", ios::out);

    cout << ">= Menulis file, \'q\' untuk keluar" << endl;

    while (true)
    {
        cout << "- ";

        getline(cin, baris);

        if (baris == "q") break;

        outfile << baris << endl;
    }

    
}