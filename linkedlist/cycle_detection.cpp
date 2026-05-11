#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Fungsi 1: Versi Original (Eksplisit nullptr)
bool has_cycle_original(Node* head) {
    if (head == nullptr) return false;
    Node* kurakura = head;
    Node* kelinci = head;
    while (kelinci != nullptr && kelinci->next != nullptr) {
        kurakura = kurakura->next;
        kelinci = kelinci->next->next;
        if (kurakura == kelinci) return true;
    }
    return false;
}

// Fungsi 2: Versi Optimized (Idiomatik/Implicit)
bool has_cycle_optimized(Node* head) {
    if (!head) return false;
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    // 1. Persiapan Data: Membuat List Raksasa (1 Juta Node)
    int n = 1000000;
    Node* head = new Node(0);
    Node* temp = head;
    for(int i = 1; i < n; i++) {
        temp->next = new Node(i);
        temp = temp->next;
    }
    
    // Buat Cycle di tengah agar algoritma harus bekerja keras
    temp->next = head; 

    cout << "--- Benchmarking 1 Million Nodes (Cycle Detected) ---" << endl;
    
    // 2. Benchmark Versi Optimized
    auto start2 = chrono::high_resolution_clock::now();
    for(int i = 0; i < 100; i++) has_cycle_optimized(head);
    auto end2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2).count();

    // 3. Benchmark Versi Original
    auto start1 = chrono::high_resolution_clock::now();
    for(int i = 0; i < 100; i++) has_cycle_original(head); // Jalankan 100x untuk rata-rata
    auto end1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1).count();

    // 4. Tampilkan Hasil
    cout << "Total Time Original  : " << duration1 << " microseconds" << endl;
    cout << "Total Time Optimized : " << duration2 << " microseconds" << endl;
    cout << "Average Original     : " << (double)duration1/100 << " us/run" << endl;
    cout << "Average Optimized    : " << (double)duration2/100 << " us/run" << endl;

    return 0;
}