#include <stdio.h>
#include <string.h>

int main() {
    char kode_menu[10][5] = {"NGS", "AP", "SA", "BU", "MAP", "GG", "SAM", "RD", "IB", "NUK"};
    char nama_menu[10][30] = {"Nasi Goreng Spesial", "Ayam Penyet", "Sate Ayam (10 Tusuk)", "Bakso Urat", "Mie Ayam Pangsit", "Gado-Gado", "Soto Ayam", "Rendang Daging", "Ikan Bakar", "Nasi Uduk Komplit"};
    int harga_menu[10] = {15000, 20000, 25000, 18000, 15000, 15000, 17000, 25000, 35000, 20000};

    char pesanan_nama[50][30];
    int pesanan_porsi[50];
    int pesanan_harga[50];
    int pesanan_total[50];
    int jumlah_pesanan = 0;

    char input_kode[10];
    int porsi_butet;
    int subtotal = 0;

    while (1) {
        scanf("%s", input_kode);
        if (strcmp(input_kode, "END") == 0) {
            break;
        }

        scanf("%d", &porsi_butet);

        int index_ditemukan = -1;
        for (int i = 0; i < 10; i++) {
            if (strcmp(input_kode, kode_menu[i]) == 0) {
                index_ditemukan = i;
                break;
            }
        }

        if (index_ditemukan != -1) {
            int total_porsi = porsi_butet * 3;
            int total_harga_per_menu = total_porsi * harga_menu[index_ditemukan];

            strcpy(pesanan_nama[jumlah_pesanan], nama_menu[index_ditemukan]);
            pesanan_porsi[jumlah_pesanan] = total_porsi;
            pesanan_harga[jumlah_pesanan] = harga_menu[index_ditemukan];
            pesanan_total[jumlah_pesanan] = total_harga_per_menu;

            subtotal += total_harga_per_menu;
            jumlah_pesanan++;
        }
    }

    int diskon = 0;
    if (subtotal >= 500000) {
        diskon = subtotal * 25 / 100;
    } else if (subtotal >= 400000) {
        diskon = subtotal * 20 / 100;
    } else if (subtotal >= 300000) {
        diskon = subtotal * 15 / 100;
    } else if (subtotal >= 200000) {
        diskon = subtotal * 10 / 100;
    } else if (subtotal >= 100000) {
        diskon = subtotal * 5 / 100;
    }

    int total_pembayaran = subtotal - diskon;

    printf("\n%-25s %-10s %-10s %-10s\n", "Menu", "Porsi", "Harga", "Total");
    printf("============================================================\n");

    for (int i = 0; i < jumlah_pesanan; i++) {
        printf("%-25s %-10d %-10d %-10d\n", pesanan_nama[i], pesanan_porsi[i], pesanan_harga[i], pesanan_total[i]);
    }

    printf("============================================================\n");
    printf("%-47s %d\n", "Total Pembayaran", total_pembayaran);

    return 0;
}