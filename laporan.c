// laporan.c
#include <stdio.h>
#include "kasir.h"

// Fungsi untuk laporan penjualan
void laporanPenjualan() {
    printf("Laporan Penjualan:\n");
    for (int i = 0; i < transactionCount; i++) {
        printf("ID Transaksi: %d, ID Member: %d, Total Harga: %.2f, Diskon: %.2f, Total Bayar: %.2f\n", 
               transactions[i].id_transaksi, transactions[i].id_member, 
               transactions[i].total_harga, transactions[i].diskon, 
               transactions[i].total_bayar);
    }
}

