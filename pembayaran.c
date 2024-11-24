#include "global.h"

// Melakukan pembayaran
void pembayaran() {
    int id, jumlah;
    printf("Masukkan ID barang: ");
    scanf("%d", &id);
    printf("Masukkan jumlah barang: ");
    scanf("%d", &jumlah);

    int ditemukan = 0;
    for (int i = 0; i < jumlahBarang; i++) {
        if (barang[i].id == id) {
            if (barang[i].stok >= jumlah) {
                float total = barang[i].harga * jumlah;
                barang[i].stok -= jumlah;
                printf("Pembayaran berhasil! Total: %.2f\n", total);

                // Menyimpan penjualan
                penjualan[jumlahPenjualan].idBarang = id;
                penjualan[jumlahPenjualan].jumlah = jumlah;
                penjualan[jumlahPenjualan].totalHarga = total;
                jumlahPenjualan++;
            } else {
                printf("Error: Stok tidak mencukupi!\n");
            }
            ditemukan = 1;
            break;
        }
    }
    if (!ditemukan) {
        printf("Error: Barang tidak ditemukan!\n");
    }
}

// Memberikan diskon
void diskon() {
    float persenDiskon;
    printf("Masukkan persentase diskon (0-100): ");
    scanf("%f", &persenDiskon);

    for (int i = 0; i < jumlahBarang; i++) {
        barang[i].harga -= barang[i].harga * (persenDiskon / 100.0);
    }
    printf("Diskon berhasil diterapkan!\n");
}

