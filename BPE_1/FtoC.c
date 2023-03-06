//
// Created by joan_ on 5.3.2023 г..
// Напишете програма за преобразуване на температурата от Фаренхайт в Целзий, така че да използва отделна функция за преобразуването.
#include <stdio.h>

float ftoc(float f) {
    return (f - 32)*5/9;
}

int main (void) {
    printf("Fahrenheit\tCelsius\n");
    for (int i = 300; i >= 0; i -= 10) {
        printf("%d *F\t\t%g *C\n", i, ftoc(i));
    }
}
