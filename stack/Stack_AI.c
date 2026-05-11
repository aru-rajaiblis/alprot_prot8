// Fithrianny Rahmadhany
//D121251032

#include <stdio.h>
#include <stdlib.h>

int equalStacks(int h1_count, int* h1, int h2_count, int* h2, int h3_count, int* h3) {
    long sum1 = 0, sum2 = 0, sum3 = 0;

    // 1. Hitung total tinggi secara manual dengan loop
    for (int i = 0; i < h1_count; i++) sum1 += h1[i];
    for (int i = 0; i < h2_count; i++) sum2 += h2[i];
    for (int i = 0; i < h3_count; i++) sum3 += h3[i];

    int i1 = 0, i2 = 0, i3 = 0;

    // 2. Loop sampai tinggi ketiga tumpukan sama
    while (!(sum1 == sum2 && sum2 == sum3)) {
        // Jika salah satu tumpukan menjadi kosong, tinggi maksimal yang sama adalah 0
        if (i1 == h1_count || i2 == h2_count || i3 == h3_count) {
            return 0;
        }

        // Cari tumpukan tertinggi dan buang elemen teratasnya
        if (sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= h1[i1];
            i1++;
        } else if (sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= h2[i2];
            i2++;
        } else if (sum3 >= sum1 && sum3 >= sum2) {
            sum3 -= h3[i3];
            i3++;
        }
    }

    return (int)sum1;
}

int main() {
    // Contoh sesuai Sample Input
    int h1[] = {3, 2, 1, 1, 1};
    int h2[] = {4, 3, 2};
    int h3[] = {1, 1, 4, 1};

    int result = equalStacks(5, h1, 3, h2, 4, h3);
    printf("%d\n", result); // Output: 5

    return 0;
}