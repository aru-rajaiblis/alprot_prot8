//Fithrianny Rahma
//D121251032

#include <stdio.h>

int findMin(long a, long b, long c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

int equalStacks(int n1, int* h1, int n2, int* h2, int n3, int* h3) {
    long s1 = 0, s2 = 0, s3 = 0;
    int i = 0, j = 0, k = 0;


    for (int x = 0; x < n1; x++) s1 += h1[x];
    for (int x = 0; x < n2; x++) s2 += h2[x];
    for (int x = 0; x < n3; x++) s3 += h3[x];

    long target = findMin(s1, s2, s3);

    while (s1 != s2 || s2 != s3) {
        
       
        while (s1 > target && i < n1) s1 -= h1[i++];
        target = findMin(s1, s2, s3); 


        while (s2 > target && j < n2) s2 -= h2[j++];
        target = findMin(s1, s2, s3);   

        while (s3 > target && k < n3) s3 -= h3[k++];
        target = findMin(s1, s2, s3); 
        
        if (s1 == 0 || s2 == 0 || s3 == 0) return 0;
    }

    return (int)s1;
}  
int main(void) {
    int h1[] = {3, 2, 1, 1, 1};
    int h2[] = {4, 3, 2};
    int h3[] = {1, 1, 4, 1};

    int hasil = equalStacks(5, h1, 3, h2, 4, h3);
    
    printf("Hasil Tinggi Maksimal: %d\n", hasil);

return 0;
}
   