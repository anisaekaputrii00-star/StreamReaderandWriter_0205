#include <iostream>
using namespace std;

int main()
{
    try
    {
        cout << "Selamat belajar di prodi TI UMY" << endl;
        
        cout << "Pernyataan tidak akan ditampilkan" << endl;
    }
    catch (int a)
    {
        cout << "Pengecualian akan di eksekusi" << endl;
    }
    catch (...)
    {
        cout << "default pengecualian diekseskusi" << endl;
    }
    return 0;  
}