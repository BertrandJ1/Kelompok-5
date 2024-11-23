// produk.c
#include <stdio.h>
#include "kasir.h"

// Fungsi untuk menambahkan produk
void tambahProduk() {
    Produk p;
    printf("Masukkan nama produk: ");
    scanf("%s", p.nama);
    printf("Masukkan harga produk: ");
    scanf("%lf", &p.harga);
    printf("Masukkan stok produk: ");
    scanf("%d", &p.stok);
    printf("Masukkan kategori produk: ");
    scanf("%s", p.kategori);
    
    p.id = productCount + 1;
    products[productCount++] = p;
    printf("Produk berhasil ditambahkan\n");
}

// Fungsi untuk melihat daftar produk
void lihatProduk() {
    printf("Daftar Produk:\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d. %s - Harga: %.2f, Stok: %d, Kategori: %s\n", 
               products[i].id, products[i].nama, products[i].harga, 
               products[i].stok, products[i].kategori);
    }
}

// Fungsi untuk menambah stok produk
void tambahStok() {
    int id, stok;
    printf("Masukkan ID produk yang akan ditambah stok: ");
    scanf("%d", &id);
    printf("Masukkan jumlah stok yang akan ditambah: ");
    scanf("%d", &stok);

    if (id <= productCount && id > 0) {
        products[id - 1].stok += stok;
        printf("Stok produk %d berhasil ditambah\n", id);
    } else {
        printf("Produk tidak ditemukan\n");
    }
}

// Fungsi untuk mengurangi stok produk
void kurangiStok() {
    int id, stok;
    printf("Masukkan ID produk yang akan dikurangi stok: ");
    scanf("%d", &id);
    printf("Masukkan jumlah stok yang akan dikurangi: ");
    scanf("%d", &stok);

    if (id <= productCount && id > 0) {
        if (products[id - 1].stok >= stok) {
            products[id - 1].stok -= stok;
            printf("Stok produk %d berhasil dikurangi\n", id);
        } else {
            printf("Stok tidak mencukupi\n");
        }
    } else {
        printf("Produk tidak ditemukan\n");
    }
}

