// member.c
#include <stdio.h>
#include "kasir.h"

// Fungsi untuk menambahkan member
void tambahMember() {
    Member m;
    printf("Masukkan nama member: ");
    scanf("%s", m.nama);
    printf("Masukkan ID Member: ");
    scanf("%d", &m.id_member);
    m.poin = 0;

    members[memberCount++] = m;
    printf("Member berhasil ditambahkan\n");
}

// Fungsi untuk menambahkan poin ke member
void tambahPoin() {
    int id_member, poin;
    printf("Masukkan ID Member: ");
    scanf("%d", &id_member);
    printf("Masukkan jumlah poin yang akan ditambahkan: ");
    scanf("%d", &poin);

    for (int i = 0; i < memberCount; i++) {
        if (members[i].id_member == id_member) {
            members[i].poin += poin;
            printf("Poin berhasil ditambahkan untuk member %d\n", id_member);
            return;
        }
    }
    printf("Member tidak ditemukan\n");
}

