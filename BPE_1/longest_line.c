//
// Created by joan_ on 5.3.2023 г..
// Напишете функцията main на програмата за най-дългия ред така, че да може правилно да отпечатва
// дължината на произволно дълги редове и да визуализира колкото се може по-голяма част от текста.

#include <stdio.h>

#define MAXLINE 1000
#define END 94

int max;
char line[MAXLINE];
char longest[MAXLINE];

int getlines(void);
void copy(void);

int main(){
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = getlines()) > 0) if (len > max) {
            max = len;
            copy();
    }
    if (max > 0) printf("%s", longest);

    return 0;
}

int getlines(void) {
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != END && c != '\n'; ++i) line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    return i;
}

void copy(void) {
    int i;
    extern char line[], longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0') ++i;
}