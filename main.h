#include <iostream>
#include <string.h>
#include <string>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
using namespace std;


class mahasiswa{
    public:
    //attribut utama
    string nama;
    string prodi;
    string nim;
    string matkul[100];
    string sks[100];
    string nilaihuruf[100];
    float nilaitugas[100];
    float nilaiuts[100];
    float nilaiuas[100];
    string tp;
    //attribut untuk mengolah file database
    fstream data;
    //attribut temporary
    string mtk;
    string skks;
    string nhuruf;
    float ntugas;
    float nuast;
    float nuasp;
    float nutst;
    float nutsp;
    float nuts;
    float nilaiakhir;

    void inputprofil(){
    cout << "Masukkan Nama Mahasiswa: "; getline(cin,nama);
    cout << "Masukkan Nim Mahasiswa: "; getline(cin,nim);
    cout << "Masukkan prodi Mahasiswa: "; getline(cin,prodi);
    }
   void inputmatkul() {
        cout << "Masukkan Mata Kuliah: ";
        getline(cin, mtk);
        cin.ignore(); // Mengabaikan inputan getline sebelumnya
        cout << "Masukkan sks " << mtk;
        cin >> skks;
        cout << "teori atau Praktek: (t/p/tp)";
        cin >> tp;
}

    //prosedur untuk input nilai matakuliah berdasarkan kondisi teori praktek
    void inputnilai(string tpp){
     if(tpp == "tp"){
        cout << "masukkan nilai tugas: "; cin >> ntugas;
        cout << "masukkan nilai uts teori: "; cin >> nutst;
        cout << "masukkan nilai uts praktek: "; cin >> nutsp;
        cout << "masukkan nilai uas teori: "; cin >> nuast;
        cout << "masukkan nilai uas praktek: "; cin >> nuasp;
     }
     else if(tpp =="t"){
        cout << "masukkan nilai tugas: "; cin >> ntugas;
        cout << "masukkan nilai uts teori: "; cin >> nutst;
        cout << "masukkan nilai uas teori: "; cin >> nuast;

     }
     else if(tpp == "p"){
         cout << "masukkan nilai tugas"; cin >> ntugas;
        cout << "masukkan nilai uts praktek"; cin >> nutsp;
        cout << "masukkan nilai uas praktek"; cin >> nuasp;
        }
     }

     //fungsi untuk menghitun nilai uts teori praktek
      float hitungnilaiuts(float ntst, float ntsp) {
        return (ntst + ntsp) / 2;
    }

    //fungsi untuk menghitun nilai uas teori praktek
    float hitungnilaiuas(float nast, float nasp) {
        return (nast + nasp) / 2;
    }

    //fungsi untuk menentukan nilai akhir dari nuts nuas dan ntugas
    float totalnilai(float utst, float utsp, float uast, float uasp, float tgs,string tpp){
     float nilai;
     if(tpp == "tp"){
        nilai = (((utst + utsp) / 2) + ((uast + uasp) / 2) + tgs) / 3;
     }
     else if(tpp =="t"){
         nilai = (utst  + uast  + tgs) / 3;;
    }
    else if(tpp == "p"){
         nilai = (utsp  + uasp  + tgs) / 3;;
    }
    return nilai;
    }

    string konversihuruf(float nilai) {
        nilai = totalnilai(nutst, nutsp, nuast, nuasp, ntugas,tp);
        if (nilai >= 80) {
            return "A";
        } else if (nilai >= 70) {
            return "B";
        } else if (nilai >= 60) {
            return "C";
        } else if (nilai >= 50) {
            return "D";
        } else {
            return "E";
        }
    }


    //prosedur untuk input mata kuliah dan pengoperasian nilai
    void isidatamatkul(int n) {
        int x = 0;
        while (x<n) {

            inputmatkul();
            inputnilai(tp);
            matkul[x] = mtk;
            cin.ignore();
            sks[x] = skks;
            nilaitugas[x] = ntugas;
            nilaiuts[x] = hitungnilaiuts(nutst, nutsp);
            nilaiuas[x] = hitungnilaiuas(nuast, nuasp);
            nilaihuruf[x] = konversihuruf(nilaiakhir);
            x++;
        }
    }
    void output(int n){
        int x;//kamus local untukk loop
        //table header 1
        cout << setw(100) << setfill('=') << "=" << endl;
        cout << setw(38) << setfill(' ') << " "
         << " Kartu Hasil Studi Mahasiswa " << setw(30) << setfill(' ') << " " << endl;
            cout << setw(100) << setfill('=') << "=" << setfill(' ') << endl;
        // table header 2
        cout << setw(5) << left << "Nama: " << nama << setw(20) << right << "Prodi: " << prodi << endl;
        cout << setw(5) << left << "Nim : " << nim << endl;
        cout << setfill('-') << setw(100) << '-' << setfill(' ') << endl;
        cout << setw(19) << right << "Mata Kuliah" << setw(18) << right << "SKS" << setw(15) << right << "Nilai UAS" << setw(15) << right << "Nilai UTS" << setw(15) << right << "Nilai Tugas" << setw(10) << right << "Nilai" << endl;
        cout << setfill('-') << setw(100) << '-' << setfill(' ') << endl;
        x = 0;
        while (x < n)
        {
            // isi tabel utama
            cout << setw(30) << left << matkul[x] << setw(1) << "|" << setw(5) << right << sks[x] << setw(5) << right << "|" << setw(8) << right << nilaiuts[x] << setw(7) << right << "|" << setw(8) << nilaiuas[x] << setw(6) << right << "|" << setw(8) << nilaitugas[x] << setw(6) << right << "|" << setw(5) << right << " " << setw(3) << left << nilaihuruf[x] << endl;
            cout << setfill('-') << setw(100) << '-' << setfill(' ') << endl;
            x++;
    }


    }

    //Operasi File

    //prosedur untuk menyimpan data
    void simpandata(int n){
        //data adalah variabel bertype fstream untuk mengisi data pada file database
        data.open("data.txt", ios::app);// membuka file txt
        //table header 1
        data<< setw(100) << setfill('=') << "=" << endl;
        data << setw(38) << setfill(' ') << " "
         << " Kartu Hasil Studi Mahasiswa " << setw(30) << setfill(' ') << " " << endl;
        data << setw(100) << setfill('=') << "=" << setfill(' ') << endl;
        // table header 2
        data << setw(5) << left << "Nama: " << nama << setw(20) << right << "Prodi: " << prodi << endl;
        data << setw(5) << left << "Nim : " << nim << endl;
        data << setfill('-') << setw(100) << '-' << setfill(' ') << endl;
        data << setw(19) << right << "Mata Kuliah" << setw(18) << right << "SKS" << setw(15) << right << "Nilai UAS" << setw(15) << right << "Nilai UTS" << setw(15) << right << "Nilai Tugas" << setw(10) << right << "Nilai" << endl;
        data << setfill('-') << setw(100) << '-' << setfill(' ') << endl;
        int x = 0;
        while (x < n)
        {
            // isi tabel utama
            data<< setw(30) << left << matkul[x] << setw(1) << "|" << setw(5) << right << sks[x] << setw(5) << right << "|" << setw(8) << right << nilaiuts[x] << setw(7) << right << "|" << setw(8) << nilaiuas[x] << setw(6) << right << "|" << setw(8) << nilaitugas[x] << setw(6) << right << "|" << setw(5) << right << " " << setw(3) << left << nilaihuruf[x] << endl;
            data << setfill('-') << setw(100) << '-' << setfill(' ') << endl;
            x++;
        }

        data.close();//menutup file
    }

  void caridata(string nim) { //mengecek kartu hasil studi mahasiswa berdasarkan nim
    ifstream data("data.txt");//membaca data txt

    if (data.is_open()){//kondisi jika data terbuka
        string line;
        bool found = false;
        while (getline(data, line)) {
            if (line.find("Nim : " + nim) != string::npos) {//mencari nim
                found = true;
                while (getline(data, line)) {//menampilkan baris baris dari database yang sesuai dengan nim yang dicari
                    cout << line << endl;
                }

            }
        }

        if (!found) {//kondisi jika nim tidak ketemu
            cout << "Data dengan NIM " << nim << " tidak ditemukan." << endl;
        }

        data.close();
    } else {
        cout << "File tidak dapat dibuka." << endl;
    }
}
};
