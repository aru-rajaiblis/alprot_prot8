//Fithrianny Rahmadhany
//D121251032

#include <iostream>
#include <stack>
#include <algorithm> 

using namespace std;

// 1. FUNGSI REKURSIF UNTUK MENGHITUNG TOTAL TINGGI
int hitungTinggi(stack<int> s) {
    if (s.empty()) return 0; // Jika habis, tingginya 0
    int balokTeratas = s.top();
    s.pop();
    return balokTeratas + hitungTinggi(s); // Panggil diri sendiri
}

// 2. FUNGSI REKURSIF UTAMA PENYELARASAN MENARA
int selaraskanMenara(stack<int>& s1, int t1, stack<int>& s2, int t2, stack<int>& s3, int t3) {
    // Kondisi Sukses: Jika tinggi ketiga menara sudah sama
    if (t1 == t2 && t2 == t3) return t1;

    // Kondisi Gagal: Jika salah satu menara sudah habis (tinggi 0)
    if (t1 == 0 || t2 == 0 || t3 == 0) return 0;

    //mencari target menara terpendek untuk menentukan mana yang harus di POP
    int target = min({t1, t2, t3});

    // Proses POP dilakukan pada menara yang lebih tinggi dari target
    if (t1 > target) {
        int buang = s1.top(); s1.pop();
        return selaraskanMenara(s1, t1 - buang, s2, t2, s3, t3);
    }
    if (t2 > target) {
        int buang = s2.top(); s2.pop();
        return selaraskanMenara(s1, t1, s2, t2 - buang, s3, t3);
    }
    if (t3 > target) {
        int buang = s3.top(); s3.pop();
        return selaraskanMenara(s1, t1, s2, t2, s3, t3 - buang);
    }
    
    return 0;
}

int main() {
    stack<int> s1, s2, s3;

    // Mengisi Stack secara manual satu per satu dari bawah (sesuai dengan urutan yang diberikan)
    s1.push(1); s1.push(1); s1.push(1); s1.push(2); s1.push(3);
    s2.push(2); s2.push(3); s2.push(4);
    s3.push(1); s3.push(4); s3.push(1); s3.push(1);

    // Menghitung tinggi awal tiap menara 
    int tinggi1 = hitungTinggi(s1);
    int tinggi2 = hitungTinggi(s2);
    int tinggi3 = hitungTinggi(s3);

    // Jalankan proses penyelarasan menara 
    int hasil = selaraskanMenara(s1, tinggi1, s2, tinggi2, s3, tinggi3);

    cout << "Hasil Tinggi Maksimal: " << hasil << endl;

    return 0;
}