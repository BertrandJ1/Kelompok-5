#include "global.h"

// Menampilkan laporan penjualan
void laporanPenjualan() {
    printf("\nLaporan Penjualan:\n");
    printf("ID Barang\tJumlah\t\tTotal Harga\n");
    printf("------------------------------------\n");
    for (int i = 0; i < jumlahPenjualan; i++) {
        printf("%d\t\t%d\t\t%.2f\n",
               penjualan[i].idBarang, penjualan[i].jumlah,
               penjualan[i].totalHarga);
    }
}

