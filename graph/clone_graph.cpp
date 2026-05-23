#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// 1. FONDASI: Cetak Biru Struktur Node
struct Node {
  int val;
  vector<Node *> neighbors;

  // Constructor
  Node(int _val) : val(_val) {}
};

// BUKU CATATAN GLOBAL
unordered_map<Node *, Node *> visitedDFS;

// 2. FUNGSI CLONING (DFS)
Node *cloneGraphDFS(Node *node) {
  if (!node)
    return nullptr;

  // Jika sudah pernah dikloning, kembalikan dari map
  if (visitedDFS.find(node) != visitedDFS.end()) {
    return visitedDFS[node];
  }

  // Kloning fisik & registrasi
  Node *copy = new Node(node->val);
  visitedDFS[node] = copy;

  // Perulangan & penjahitan jalur
  for (Node *neighbor : node->neighbors) {
    copy->neighbors.push_back(cloneGraphDFS(neighbor));
  }

  return copy;
}

// 3. FUNGSI PEMBANTU: Untuk mencetak Graph ke terminal (biar kelihatan
// hasilnya)
void printGraph(Node *node, unordered_map<Node *, bool> &visited) {
  if (!node || visited[node])
    return;

  visited[node] = true;
  cout << "Node [" << node->val << "] berteman dengan: ";
  for (Node *neighbor : node->neighbors) {
    cout << neighbor->val << " ";
  }
  cout << endl;

  for (Node *neighbor : node->neighbors) {
    printGraph(neighbor, visited);
  }
}

// 4. MOTOR UTAMA
int main() {
  cout << "=== MEMBUAT GRAPH ASLI ===" << endl;

  // 1. Mendeklarasikan Node
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);

  // 2. Menghubungkan edges nya: 1 <-> 2 <-> 3
  n1->neighbors.push_back(n2);
  n2->neighbors.push_back(n1);

  n2->neighbors.push_back(n3);
  n3->neighbors.push_back(n2);

  // 3. Mencetak Graph Asli
  unordered_map<Node *, bool> visitedPrint1;
  printGraph(n1, visitedPrint1);

  // 4. Proses Cloning
  Node *clonedGraph = cloneGraphDFS(n1);

  cout << "\n=== MEMERIKSA GRAPH HASIL KLONING ===" << endl;
  unordered_map<Node *, bool> visitedPrint2;
  printGraph(clonedGraph, visitedPrint2);

  // Cek pembuktian alamat memori (Deep Copy)
  cout << "\nPembuktian Alamat Memori (Harus Berbeda):" << endl;
  cout << "Alamat Node 1 Asli   : " << n1 << endl;
  cout << "Alamat Node 1 Kloning: " << clonedGraph << endl;

  return 0;
}