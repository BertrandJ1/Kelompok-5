#include <stdio.h>
#include <string.h>
#include "kasir.h"

// Variabel global untuk menyimpan produk, member, dan transaksi
Produk products[MAX_PRODUCTS];
Member members[MAX_MEMBERS];
Transaksi transactions[MAX_TRANSACTIONS];
int productCount = 0, memberCount = 0, transactionCount = 0;

// Fungsi untuk menampilkan menu utama
void menu() {
    int pilihan;
    do {
        printf("\n=== Menu Kasir ===\n");
        printf("1. Login\n");
        printf("2. Kelola Produk\n");
        printf("3. Kelola Member\n");
        printf("4. Pembayaran\n");
        printf("5. Laporan Penjualan\n");
        printf("6. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                if (login()) {
                    printf("Login sukses!\n");
                } else {
                    printf("Login gagal! Coba lagi.\n");
                }
                break;
            case 2:
                kelolaProduk();
                break;
            case 3:
                kelolaMember();
                break;
            case 4:
                pembayaran();
                break;
            case 5:
                laporanPenjualan();
                break;
            case 6:
                printf("Terima kasih! Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Coba lagi.\n");
        }
    } while (pilihan != 6);
}

// Fungsi untuk menambahkan produk baru
void tambahProduk() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Stok produk penuh!\n");
        return;
    }
    
    Produk newProduct;
    printf("Masukkan ID produk: ");
    scanf("%d", &newProduct.id);
    printf("Masukkan nama produk: ");
    getchar();  // Menghapus karakter newline yang tersisa
    fgets(newProduct.nama, sizeof(newProduct.nama), stdin);
    newProduct.nama[strcspn(newProduct.nama, "\n")] = 0;  // Menghapus newline pada nama produk
    printf("Masukkan harga produk: ");
    scanf("%lf", &newProduct.harga);
    printf("Masukkan stok produk: ");
    scanf("%d", &newProduct.stok);
    printf("Masukkan kategori produk: ");
    getchar();  // Menghapus karakter newline
    fgets(newProduct.kategori, sizeof(newProduct.kategori), stdin);
    newProduct.kategori[strcspn(newProduct.kategori, "\n")] = 0;  // Menghapus newline pada kategori produk
    
    products[productCount++] = newProduct;
    printf("Produk %s telah ditambahkan!\n", newProduct.nama);
}

// Fungsi untuk menampilkan daftar produk
void lihatProduk() {
    if (productCount == 0) {
        printf("Belum ada produk di toko.\n");
        return;
    }
    
    printf("\nDaftar Produk:\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d, Nama: %s, Harga: %.2lf, Stok: %d, Kategori: %s\n",
               products[i].id, products[i].nama, products[i].harga, products[i].stok, products[i].kategori);
    }
}

// Fungsi untuk menambah stok produk
void tambahStok() {
    int id, stok;
    printf("Masukkan ID produk yang ingin ditambah stok: ");
    scanf("%d", &id);
    
    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            printf("Masukkan jumlah stok yang akan ditambah: ");
            scanf("%d", &stok);
            products[i].stok += stok;
            printf("Stok produk %s telah ditambah sebanyak %d. Total stok: %d\n", products[i].nama, stok, products[i].stok);
            return;
        }
    }
    printf("Produk dengan ID %d tidak ditemukan!\n", id);
}

// Fungsi untuk mengurangi stok produk
void kurangiStok() {
    int id, stok;
    printf("Masukkan ID produk yang ingin dikurangi stok: ");
    scanf("%d", &id);
    
    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            printf("Masukkan jumlah stok yang akan dikurangi: ");
            scanf("%d", &stok);
            if (stok > products[i].stok) {
                printf("Jumlah stok yang diminta lebih banyak dari stok yang tersedia!\n");
            } else {
                products[i].stok -= stok;
                printf("Stok produk %s telah dikurangi sebanyak %d. Total stok: %d\n", products[i].nama, stok, products[i].stok);
            }
            return;
        }
    }
    printf("Produk dengan ID %d tidak ditemukan!\n", id);
}

// Fungsi untuk melihat laporan penjualan
void laporanPenjualan() {
    printf("\nLaporan Penjualan:\n");
    for (int i = 0; i < transactionCount; i++) {
        printf("Transaksi ID: %d, Member ID: %d, Total Harga: %.2lf, Diskon: %.2lf, Total Bayar: %.2lf\n",
               transactions[i].id_transaksi, transactions[i].id_member, transactions[i].total_harga,
               transactions[i].diskon, transactions[i].total_bayar);
    }
}

// Fungsi untuk kelola produk (menu)
void kelolaProduk() {
    int pilihan;
    do {
        printf("\n=== Kelola Produk ===\n");
        printf("1. Tambah Produk\n");
        printf("2. Lihat Produk\n");
        printf("3. Tambah Stok\n");
        printf("4. Kurangi Stok\n");
        printf("5. Kembali ke Menu Utama\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahProduk();
                break;
            case 2:
                lihatProduk();
                break;
            case 3:
                tambahStok();
                break;
            case 4:
                kurangiStok();
                break;
            case 5:
                break;
            default:
                printf("Pilihan tidak valid. Coba lagi.\n");
        }
    } while (pilihan != 5);
}

// Fungsi untuk kelola member (menu)
void kelolaMember() {
    printf("Fungsi kelola member belum diimplementasikan.\n");
}

// Fungsi untuk melakukan pembayaran
void pembayaran() {
    printf("Fungsi pembayaran belum diimplementasikan.\n");
}

