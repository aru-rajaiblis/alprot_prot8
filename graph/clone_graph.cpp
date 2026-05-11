#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <chrono>
#include <numeric>

using namespace std;

struct Node {
    int val;
    vector<Node*> neighbors;
    Node(int _val) {
        val = _val;
    }
};

// fungsi original (Depth first searcjj)

unordered_map<Node*, Node*> visitedDFS;
Node* cloneGraphDFS(Node* node) {
    if (!node) return nullptr;
    if (visitedDFS.find(node) != visitedDFS.end()) 
        return visitedDFS[node];

    Node* copy = new Node(node->val);
    visitedDFS[node] = copy;
    for (Node* neighbor : node->neighbors) {
        copy->neighbors.push_back(cloneGraphDFS(neighbor));
    }
    return copy;
}

// --- ai ---

// Fungsi yang udh dioptimasi oleh ai

Node* cloneGraphBFS(Node* node) {
    if (!node) return nullptr;
    unordered_map<Node*, Node*> copies;
    queue<Node*> q;

    copies[node] = new Node(node->val);
    q.push(node);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        for (Node* neighbor : curr->neighbors) {
            if (copies.find(neighbor) == copies.end()) {
                copies[neighbor] = new Node(neighbor->val);
                q.push(neighbor);
            }
            copies[curr]->neighbors.push_back(copies[neighbor]);
        }
    }
    return copies[node];
}

// --- Persiapan Benchmark ---

Node* createLargeGraph(int n) {
    if (n <= 0) return nullptr;
    vector<Node*> nodes;
    for (int i = 1; i <= n; i++) nodes.push_back(new Node(i));
    for (int i = 0; i < n - 1; i++) {
        nodes[i]->neighbors.push_back(nodes[i+1]);
        nodes[i+1]->neighbors.push_back(nodes[i]);
    }
    return nodes[0];
}

void runTestGantian(int numNodes) {
    cout << "\n>>> TESTING DENGAN " << numNodes << " NODES <<<" << endl;
    Node* original = createLargeGraph(numNodes);

    // 1. Jalankan BFS 
    cout << "Menjalankan BFS... " << flush; // flush agar teks muncul segera
    auto s1 = chrono::high_resolution_clock::now();
    cloneGraphBFS(original);
    auto e1 = chrono::high_resolution_clock::now();
    double bfsTime = chrono::duration<double, milli>(e1 - s1).count();
    cout << "SELESAI!" << endl;
    cout << "Hasil BFS : " << bfsTime << " ms" << endl;

    // 2. Baru Jalankan DFS
    cout << "Menjalankan DFS (Risiko Crash)... " << flush;
    visitedDFS.clear();
    auto s2 = chrono::high_resolution_clock::now();
    cloneGraphDFS(original);
    auto e2 = chrono::high_resolution_clock::now();
    double dfsTime = chrono::duration<double, milli>(e2 - s2).count();
    cout << "SELESAI!" << endl;
    cout << "Hasil DFS : " << dfsTime << " ms" << endl;
}

int main() {
    cout << "=== MEMULAI BENCHMARK  ===" << endl;

    // TAHAP 1: Skenario Normal (Aman)
    runTestGantian(10000);

    // TAHAP 2: Skenario Ekstrim (BFS pasti tampil, DFS mungkin crash)
    runTestGantian(500000); 

    return 0;
}