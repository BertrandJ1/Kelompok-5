// login.c
#include <stdio.h>
#include <string.h>
#include "kasir.h"

// Fungsi untuk login
int login() {
    char username[50], password[50];
    printf("Masukkan username: ");
    scanf("%s", username);
    printf("Masukkan password: ");
    scanf("%s", password);
    
    if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0) {
        printf("Login berhasil sebagai Admin\n");
        return 1;
    } else if (strcmp(username, "kasir") == 0 && strcmp(password, "kasir123") == 0) {
        printf("Login berhasil sebagai Kasir\n");
        return 2;
    } else {
        printf("Login gagal\n");
        return 0;
    }
}

