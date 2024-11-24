#include "global.h"

// Deklarasi fungsi menu
void menu();

// Fungsi utama
int main() {
    menu();
    return 0;
}

// Fungsi menu utama
void menu() {
    int pilihan;
    do {
        printf("\n=== Pengelolaan Toko ===\n");
        printf("1. Tambah Barang\n2. Hapus Barang\n3. Tambah Stok\n4. Kurangi Stok\n");
        printf("5. Lihat Daftar Barang\n6. Tambah Member\n7. Tambah Poin Member\n");
        printf("8. Pembayaran\n9. Diskon\n10. Laporan Penjualan\n");
        printf("11. Keluar\nMasukkan pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1: tambahBarang(); break;
            case 2: hapusBarang(); break;
            case 3: tambahStok(); break;
            case 4: kurangiStok(); break;
            case 5: daftarBarang(); break;
            case 6: tambahMember(); break;
            case 7: tambahPoinMember(); break;
            case 8: pembayaran(); break;
            case 9: diskon(); break;
            case 10: laporanPenjualan(); break;
            case 11: printf("Keluar dari program.\n"); break;
            default: printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 11);
}

