#include <stdio.h>
#include <string.h>

#define HARGA_PER_BIJI 500

typedef struct {
    int id;
    char nama[50];
    char asrama[30];
    char tanggal[20];
    char listBarang[100];
    int jumlahBiji;
    long totalHarga;
    char status[20];
} Pesanan;

void tampilkanMenu() {
    printf("\n=== Sistem Operasional Laundry Del ===\n");
    printf("1. Tambah Pesanan Baru\n");
    printf("2. Lihat Semua Pesanan\n");
    printf("3. Update Status Pesanan\n");
    printf("4. Keluar\n");
    printf("Pilih opsi: ");
}

int main() {
    Pesanan daftarPesanan[100];
    int jumlahPesanan = 0;
    int pilihan;

    do {
        tampilkanMenu();
        scanf("%d", &pilihan);
        getchar(); 

        if (pilihan == 1) {
            daftarPesanan[jumlahPesanan].id = jumlahPesanan + 1;
            
            printf("\nNama Mahasiswa    : ");
            fgets(daftarPesanan[jumlahPesanan].nama, sizeof(daftarPesanan[jumlahPesanan].nama), stdin);
            daftarPesanan[jumlahPesanan].nama[strcspn(daftarPesanan[jumlahPesanan].nama, "\n")] = 0;

            printf("Asrama            : ");
            fgets(daftarPesanan[jumlahPesanan].asrama, sizeof(daftarPesanan[jumlahPesanan].asrama), stdin);
            daftarPesanan[jumlahPesanan].asrama[strcspn(daftarPesanan[jumlahPesanan].asrama, "\n")] = 0;

            printf("Tanggal (DD/MM/YY): ");
            fgets(daftarPesanan[jumlahPesanan].tanggal, sizeof(daftarPesanan[jumlahPesanan].tanggal), stdin);
            daftarPesanan[jumlahPesanan].tanggal[strcspn(daftarPesanan[jumlahPesanan].tanggal, "\n")] = 0;

            printf("Daftar Barang     : ");
            fgets(daftarPesanan[jumlahPesanan].listBarang, sizeof(daftarPesanan[jumlahPesanan].listBarang), stdin);
            daftarPesanan[jumlahPesanan].listBarang[strcspn(daftarPesanan[jumlahPesanan].listBarang, "\n")] = 0;

            printf("Jumlah Barang (biji): ");
            scanf("%d", &daftarPesanan[jumlahPesanan].jumlahBiji);
            getchar(); 

            daftarPesanan[jumlahPesanan].totalHarga = (long)daftarPesanan[jumlahPesanan].jumlahBiji * HARGA_PER_BIJI;
            strcpy(daftarPesanan[jumlahPesanan].status, "Diproses");

            printf("Pesanan berhasil ditambahkan! Total Tagihan: Rp %ld\n", daftarPesanan[jumlahPesanan].totalHarga);
            jumlahPesanan++;

        } else if (pilihan == 2) {
            printf("\n%-3s | %-15s | %-12s | %-10s | %-5s | %-10s | %-10s\n", "ID", "Nama", "Asrama", "Tanggal", "Jml", "Harga", "Status");
            printf("--------------------------------------------------------------------------------------\n");
            for (int i = 0; i < jumlahPesanan; i++) {
                printf("%-3d | %-15s | %-12s | %-10s | %-5d | Rp %-7ld | %-10s\n", 
                        daftarPesanan[i].id, 
                        daftarPesanan[i].nama, 
                        daftarPesanan[i].asrama,
                        daftarPesanan[i].tanggal,
                        daftarPesanan[i].jumlahBiji, 
                        daftarPesanan[i].totalHarga, 
                        daftarPesanan[i].status);
            }
            printf("--------------------------------------------------------------------------------------\n");

        } else if (pilihan == 3) {
            int idCari;
            printf("\nMasukkan ID Pesanan yang ingin diupdate: ");
            scanf("%d", &idCari);
            if (idCari > 0 && idCari <= jumlahPesanan) {
                strcpy(daftarPesanan[idCari-1].status, "Selesai");
                printf("Status pesanan ID %d berhasil diperbarui menjadi Selesai.\n", idCari);
            } else {
                printf("ID tidak ditemukan.\n");
            }
        }

    } while (pilihan != 4);

    printf("Terima kasih telah menggunakan sistem Laundry Del.\n");
    return 0;
}