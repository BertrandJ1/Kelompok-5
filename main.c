// main.c
#include <stdio.h>
#include "kasir.h"

// Inisialisasi variabel global
Produk products[MAX_PRODUCTS];
Member members[MAX_MEMBERS];
Transaksi transactions[MAX_TRANSACTIONS];
int productCount = 0, memberCount = 0, transactionCount = 0;

int main() {
    menu();
    return 0;
}

