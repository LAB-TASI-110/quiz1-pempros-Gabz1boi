#include <stdio.h>

int main() {
    int N, kodeKelompok, totalNilai = 0;

    // Meminta jumlah total data
    scanf("%d", &N);

    int nilai[N];

    // Mengisi array dengan deret nilai
    for (int i = 0; i < N; i++) {
        scanf("%d", &nilai[i]);
    }

    // Memasukkan kode kelompok (1 untuk Ganjil, 2 untuk Genap)
    scanf("%d", &kodeKelompok);

    // Proses penjumlahan berdasarkan pola indeks
    for (int i = 0; i < N; i++) {
        if (kodeKelompok == 1) {
            // Kelompok 1: Indeks 0, 2, 4... (Urutan ke-1, 3, 5...)
            if (i % 2 == 0) {
                totalNilai += nilai[i];
            }
        } else if (kodeKelompok == 2) {
            // Kelompok 2: Indeks 1, 3, 5... (Urutan ke-2, 4, 6...)
            if (i % 2 != 0) {
                totalNilai += nilai[i];
            }
        }
    }

    // Output hasil penjumlahan
    printf("%d\n", totalNilai);

    return 0;
}