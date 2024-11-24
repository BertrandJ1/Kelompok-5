#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BARANG 100
#define MAX_MEMBER 100
#define MAX_PENJUALAN 100

// Struktur data untuk barang
typedef struct {
    int id;
    char nama[50];
    char kategori[30];
    int stok;
    float harga;
} Barang;

// Struktur data untuk member
typedef struct {
    int id;
    char nama[50];
    int poin;
} Member;

// Struktur data untuk penjualan
typedef struct {
    int idBarang;
    int jumlah;
    float totalHarga;
} Penjualan;

// Deklarasi variabel global
extern Barang barang[MAX_BARANG];
extern Member member[MAX_MEMBER];
extern Penjualan penjualan[MAX_PENJUALAN];
extern int jumlahBarang, jumlahMember, jumlahPenjualan;

#endif

