#include "global.h"

// Menambahkan barang baru
void tambahBarang() {
    if (jumlahBarang >= MAX_BARANG) {
        printf("Error: Kapasitas barang penuh!\n");
        return;
    }
    Barang barangBaru;
    barangBaru.id = jumlahBarang + 1;
    printf("Masukkan nama barang: ");
    scanf(" %[^\n]", barangBaru.nama);
    printf("Masukkan kategori: ");
    scanf(" %[^\n]", barangBaru.kategori);
    printf("Masukkan stok: ");
    scanf("%d", &barangBaru.stok);
    printf("Masukkan harga: ");
    scanf("%f", &barangBaru.harga);

    barang[jumlahBarang++] = barangBaru;
    printf("Barang berhasil ditambahkan!\n");
}

// Menghapus barang berdasarkan ID
void hapusBarang() {
    int id;
    printf("Masukkan ID barang yang akan dihapus: ");
    scanf("%d", &id);

    int ditemukan = 0;
    for (int i = 0; i < jumlahBarang; i++) {
        if (barang[i].id == id) {
            ditemukan = 1;
            for (int j = i; j < jumlahBarang - 1; j++) {
                barang[j] = barang[j + 1];
            }
            jumlahBarang--;
            printf("Barang berhasil dihapus!\n");
            break;
        }
    }
    if (!ditemukan) {
        printf("Error: Barang tidak ditemukan!\n");
    }
}

// Menambahkan stok barang
void tambahStok() {
    int id, jumlah;
    printf("Masukkan ID barang: ");
    scanf("%d", &id);
    printf("Masukkan jumlah stok yang akan ditambahkan: ");
    scanf("%d", &jumlah);

    int ditemukan = 0;
    for (int i = 0; i < jumlahBarang; i++) {
        if (barang[i].id == id) {
            barang[i].stok += jumlah;
            printf("Stok berhasil ditambahkan!\n");
            ditemukan = 1;
            break;
        }
    }
    if (!ditemukan) {
        printf("Error: Barang tidak ditemukan!\n");
    }
}

// Mengurangi stok barang
void kurangiStok() {
    int id, jumlah;
    printf("Masukkan ID barang: ");
    scanf("%d", &id);
    printf("Masukkan jumlah stok yang akan dikurangi: ");
    scanf("%d", &jumlah);

    int ditemukan = 0;
    for (int i = 0; i < jumlahBarang; i++) {
        if (barang[i].id == id) {
            if (barang[i].stok >= jumlah) {
                barang[i].stok -= jumlah;
                printf("Stok berhasil dikurangi!\n");
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

// Menampilkan daftar barang
void daftarBarang() {
    printf("\nID\tNama\t\tKategori\tStok\tHarga\n");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < jumlahBarang; i++) {
        printf("%d\t%s\t\t%s\t\t%d\t%.2f\n",
               barang[i].id, barang[i].nama, barang[i].kategori,
               barang[i].stok, barang[i].harga);
    }
}

