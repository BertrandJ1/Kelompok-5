#include "global.h"

// Menambahkan member baru
void tambahMember() {
    if (jumlahMember >= MAX_MEMBER) {
        printf("Error: Kapasitas member penuh!\n");
        return;
    }
    Member memberBaru;
    memberBaru.id = jumlahMember + 1;
    printf("Masukkan nama member: ");
    scanf(" %[^\n]", memberBaru.nama);
    memberBaru.poin = 0;

    member[jumlahMember++] = memberBaru;
    printf("Member berhasil ditambahkan!\n");
}

// Menambahkan poin ke member
void tambahPoinMember() {
    int id, poin;
    printf("Masukkan ID member: ");
    scanf("%d", &id);
    printf("Masukkan jumlah poin: ");
    scanf("%d", &poin);

    int ditemukan = 0;
    for (int i = 0; i < jumlahMember; i++) {
        if (member[i].id == id) {
            member[i].poin += poin;
            printf("Poin berhasil ditambahkan!\n");
            ditemukan = 1;
            break;
        }
    }
    if (!ditemukan) {
        printf("Error: Member tidak ditemukan!\n");
    }
}

