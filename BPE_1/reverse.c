//
// Created by joan_ on 5.3.2023 г..
// Напишете функция reverse (s), която обръща символния низ s.
// Използвайте я, за да напишете програма, която преобръща входа си ред по ред.
#include <stdio.h>

#define END 94

void reverse(char s[]) {
    int median, i, length = 0;

    while (s[length++]);
    i = --length;
    median = length / 2;
    while (i --> median) {
        // printf("\niteration: i = %d length = %d", i, length);
        if (s[i] == s[length-1-i]) continue;
        s[i]          = s[i] ^ s[length-1-i];
        s[length-1-i] = s[i] ^ s[length-1-i];
        s[i]          = s[i] ^ s[length-1-i];
    }
}

int main(void) {
    char c, line[200];
    unsigned int i = 0;

    printf("End program with ^D:\n");
    while ((c = getchar()) != END) {
        if ((line[i++] = c) == '\n') {
            line[--i] = 0;
            reverse(line);
            printf("%s\n", line);
            i = 0;
        }
    }
}
