#include <iostream>
#include <string.h>
#include<cstring>
#include<stdlib.h>
#include<iomanip>
#include "main.h"
#include <windows.h>
using namespace std;

// Warna teks pada Windows
#define BLACK     0
#define RED       FOREGROUND_RED
#define GREEN     FOREGROUND_GREEN
#define YELLOW    FOREGROUND_RED | FOREGROUND_GREEN
#define BLUE      FOREGROUND_BLUE
#define MAGENTA   FOREGROUND_RED | FOREGROUND_BLUE
#define CYAN      FOREGROUND_GREEN | FOREGROUND_BLUE
#define WHITE     FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE


//kamus global
mahasiswa mhs;
int pil; // variabel untuk switch case
int y; // variabel untuk looping yang didalam fungsi
string cari;//untuk mencari data mahasiswa
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//diskripsi
int main(){



    // Set warna teks menjadi kuning
    SetConsoleTextAttribute(hConsole, YELLOW);
    cout << setw(55) << setfill('*')<<"*"<<endl;

    // Set warna teks menjadi ijo
    SetConsoleTextAttribute(hConsole, GREEN);
    cout  << setw(45)<<setfill(' ')<<right<<"SELAMAT DATANG DI PROGRAM SIADIN"<<endl;
    // Set warna teks menjadi kuning
    SetConsoleTextAttribute(hConsole, YELLOW);
    cout << setw(55) << setfill('*') <<"*"<< endl;

    //set warna teks menjadi biru muda
    SetConsoleTextAttribute(hConsole, CYAN);
        cout << "Pilih Menu"<<endl;
        cout << "1. Buat Kartu Hasil Studi"<<endl;
        cout << "2. Cek Kartu Hasil Studi"<<endl;
         // Set warna teks menjadi putih

        cout << "Pilih Menu: "; cin >> pil;
        cin.ignore(); // Mengabaikan inputan getline sebelumnya
        system("cls"); // menghapus tampilan menu jika sudah memilih menu
        // set warna teks menjadi putih
    SetConsoleTextAttribute(hConsole, WHITE);

      switch(pil){
        case 1:
                // Set warna teks menjadi kuning
                SetConsoleTextAttribute(hConsole, YELLOW);
                cout << setw(55) << setfill('*')<<"*"<<endl;

                // Set warna teks menjadi Greeb
                SetConsoleTextAttribute(hConsole, GREEN);
                cout  << setw(45)<<setfill(' ')<<right<<"BUAT KARTU HASIL STUDI"<<endl;
                // Set warna teks menjadi yellow
                SetConsoleTextAttribute(hConsole, YELLOW);
                cout << setw(55) << setfill('*') <<"*"<< endl;

                //reset warna teks menjadi putih
                SetConsoleTextAttribute(hConsole, WHITE);

                mhs.inputprofil();//input profil mahasiswa
                cin.ignore();
                cout << "Berapa jumlah matkul yang ingin anda input: ";
                cin >> y;

                mhs.isidatamatkul(y);//input matkul yang diambil mahasiswa beserta sks dan nilainya
                system("cls");//menghapus tampilan inputan
                mhs.output(y); //menampilkan output untuk data yang akan disimpan kedalam database
                mhs.simpandata(y);//menyimpan data kedalam database


                break;

            case 2:
                  // Set warna teks menjadi yellow
                SetConsoleTextAttribute(hConsole, YELLOW);
                cout << setw(55) << setfill('*') <<"*"<< endl;
                  // Set warna teks menjadi cyan
                SetConsoleTextAttribute(hConsole, GREEN);
                cout  << setw(45)<<setfill(' ')<<right<<"CEK KARTU HASIL STUDI"<<endl;
                // Set warna teks menjadi yellow
                SetConsoleTextAttribute(hConsole, YELLOW);
                cout << setw(55) << setfill('*') <<"*"<< endl;

                //reset warna teks menjadi putih
                SetConsoleTextAttribute(hConsole, WHITE);
                cout << "Masukkan Nim Anda: ";
                cin >> cari;
                mhs.caridata(cari);
                break;

    }
};
