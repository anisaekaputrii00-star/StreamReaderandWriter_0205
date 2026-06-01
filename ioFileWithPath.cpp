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

   
}