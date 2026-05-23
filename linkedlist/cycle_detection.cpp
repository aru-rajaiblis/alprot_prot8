#include <iostream>


using namespace std;

// blueprint pembuatan nodenya
struct Node {
  int data;
  Node *next;
  Node(int val)
      : data(val), next(nullptr) {
  } // disetiap node berisi nilai, dan pointer menuju alamat selanjutnya
};

// Fungsi 1: Versi Original
bool has_cycle_original(Node *head) {
  if (head == nullptr)
    return false;
  Node *kurakura = head;
  Node *kelinci = head; // penunjuk 1 dan penunjuk 2 mulai di titik yang sama
  while (kelinci != nullptr && kelinci->next != nullptr) {
    kurakura = kurakura->next;
    kelinci = kelinci->next->next;
    if (kurakura == kelinci)
      return true;
  } // proses pengecekan dilakukan selama kelinci (penunjuk 2) memiliki alamat,
    // dan terdapat pointer alamat selanjutnya
  return false;
}

int main() {
  // 1. Persiapan Data: Membuat List
  int n = 10;
  Node *head = new Node(0);
  Node *temp = head;
  for (int i = 1; i < n; i++) {
    temp->next = new Node(i);
    temp = temp->next;
  }

  // Buat Cycle di tengah agar algoritma harus bekerja keras
  temp->next = head;

  // Test Case 1: Mengecek apakah cycle yang dibuat terdeteksi
  if (has_cycle_original(head)) {
    cout << "Test Case 1: Cycle terdeteksi! (Sesuai ekspektasi)" << endl;
  } else {
    cout << "Test Case 1: Tidak ada cycle terdeteksi. (Gagal)" << endl;
  }

  return 0;
}