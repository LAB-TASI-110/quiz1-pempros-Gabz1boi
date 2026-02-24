#include <stdio.h>

int main() {
    int N, kodeKelompok, totalNilai = 0;

 
    scanf("%d", &N);

    int nilai[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &nilai[i]);
    }

    scanf("%d", &kodeKelompok);

 
    for (int i = 0; i < N; i++) {
        if (kodeKelompok == 1) {
         
            if (i % 2 == 0) {
                totalNilai += nilai[i];
            }
        } else if (kodeKelompok == 2) {
    
            if (i % 2 != 0) {
                totalNilai += nilai[i];
            }
        }
    }

    // Output hasil penjumlahan
    printf("%d\n", totalNilai);

    return 0;
}