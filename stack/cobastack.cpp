//Fithrianny Rahmadhany
//D121251032

#include <iostream>
#include <stack>

using namespace std;

//Menghitung total tinggi tiap menara 
int TotalTinggi (stack<int> TumpukanSilinder) {
    int total = 0; 
    while (!TumpukanSilinder.empty()) { //mengecek apakah stack masih ada isinya atau tidak 
        total = total + TumpukanSilinder.top(); //top adalah angka yang paling atas
        TumpukanSilinder.pop(); //setelah digunakan, angka paling atas tadi akan di pop (dikeluarkan) agar while bisa berhenti. 
    }
    return total; 
}
int main (){
    stack <int> s1, s2, s3;
    //isi silinder 1 = 3, 2, 1, 1, 1 (atas ke bawah)
    //di push dari bawah 
    s1.push(1);
    s1.push(1);
    s1.push(1);
    s1.push(2);
    s1.push(3);

    //isi silinder 2 = 4, 3, 2 (atas ke bawah)
    //push dari bawah
    s2.push(2);
    s2.push(3);
    s2.push(4);

    //isi silinder 3 = 1, 1, 4, 1 (atas ke bawah)
    //push dari bawah 
    s3.push(1);
    s3.push(4);
    s3.push(1);
    s3.push(1);

    //hasil dari menghitung tinggi tiap menara
    int Tinggi_s1 = TotalTinggi (s1);
    int Tinggi_s2 = TotalTinggi (s2);
    int Tinggi_s3 = TotalTinggi (s3);

    cout << "Tinggi awal silinder 1 adalah: " << Tinggi_s1 << endl;
    cout << "Tinggi awal silinder 2 adalah: " << Tinggi_s2 << endl;
    cout << "Tinggi awal silinder 3 adalah: " << Tinggi_s3 << endl;

    while (true){
        //mengecek apakah tinggi silinder sudah sama
        if (Tinggi_s1 == Tinggi_s2 && Tinggi_s1 == Tinggi_s3){
            cout << "Silinder sudah memiliki tinggi yang sama, yaitu: " << Tinggi_s1 << endl; 
            break;
        }
        //mengecek apakah ada silinder yang sudah habis
        if (s1.empty() || s2.empty() || s3.empty()){
            cout << "Silinder ada yang habis, hasilnya adalah = 0" << endl;
            break;
        }
        if (Tinggi_s1 > Tinggi_s2 || Tinggi_s1 > Tinggi_s3){
            cout << "pop silinder 1: " << s1.top() << endl;
            Tinggi_s1 = Tinggi_s1 - s1.top(); //kurangi tinggi silinder 1 dengan angka paling atas
            s1.pop(); //angka paling atas tadi di pop agar bisa berhenti
            cout << "Tinggi silinder 1: " << Tinggi_s1 << endl;
        }
        else if (Tinggi_s2 > Tinggi_s1 || Tinggi_s2 > Tinggi_s3){
            cout << "pop silinder 2: " << s2.top() << endl;
            Tinggi_s2 = Tinggi_s2 - s2.top(); //kurangi tinggi silinder 2 dengan angka paling atas
            s2.pop(); //angka paling atas tadi di pop agar bisa berhenti
            cout << "Tinggi silinder 2: " << Tinggi_s2 << endl;
        }
        else {
            cout << "pop silinder 3: " << s3.top() << endl;
            Tinggi_s3 = Tinggi_s3 - s3.top(); //kurangi tinggi silinder 3 dengan angka paling atas
            s3.pop(); //angka paling atas tadi di pop agar bisa berhenti
            cout << "Tinggi silinder 3: " << Tinggi_s3 << endl;
        }
    }
    return 0;
}
