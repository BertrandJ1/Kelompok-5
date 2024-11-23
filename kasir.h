// kasir.h
#ifndef KASIR_H
#define KASIR_H

#define MAX_PRODUCTS 100
#define MAX_MEMBERS 50
#define MAX_TRANSACTIONS 100

// Struktur data untuk produk
typedef struct {
    int id;
    char nama[50];
    double harga;
    int stok;
    char kategori[30];
} Produk;

// Struktur data untuk member
typedef struct {
    int id_member;
    char nama[50];
    int poin;
} Member;

// Struktur data untuk transaksi
typedef struct {
    int id_transaksi;
    int id_member;
    double total_harga;
    double diskon;
    double total_bayar;
} Transaksi;

// Deklarasi fungsi
int login();
void tambahProduk();
void lihatProduk();
void tambahStok();
void kurangiStok();
void tambahMember();
void tambahPoin();
void pembayaran();
void laporanPenjualan();
void menu();

extern Produk products[MAX_PRODUCTS];
extern Member members[MAX_MEMBERS];
extern Transaksi transactions[MAX_TRANSACTIONS];

extern int productCount;
extern int memberCount;
extern int transactionCount;

#endif // KASIR_H

