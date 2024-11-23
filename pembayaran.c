// pembayaran.c
#include <stdio.h>
#include "kasir.h"

// Fungsi untuk melakukan pembayaran
void pembayaran() {
    int id_member;
    double total = 0, diskon = 0, total_bayar;
    printf("Masukkan ID Member: ");
    scanf("%d", &id_member);

    printf("Masukkan jumlah produk yang dibeli: ");
    int jumlah_produk;
    scanf("%d", &jumlah_produk);

    for (int i = 0; i < jumlah_produk; i++) {
        int id_produk, jumlah;
        printf("Masukkan ID produk yang dibeli: ");
        scanf("%d", &id_produk);
        printf("Masukkan jumlah produk yang dibeli: ");
        scanf("%d", &jumlah);

        if (id_produk <= productCount && id_produk > 0) {
            total += products[id_produk - 1].harga * jumlah;
        } else {
            printf("Produk tidak ditemukan\n");
        }
    }

    // Memberikan diskon jika ada
    for (int i = 0; i < memberCount; i++) {
        if (members[i].id_member == id_member) {
            diskon = total * 0.1; // Diskon 10% untuk member
            break;
        }
    }

    total_bayar = total - diskon;
    printf("Total harga: %.2f\n", total);
    printf("Diskon: %.2f\n", diskon);
    printf("Total yang harus dibayar: %.2f\n", total_bayar);
}

