#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int romanToDecimal(char *num) {
    int valores[26];
    valores['I' - 'A'] = 1;
    valores['V' - 'A'] = 5;
    valores['X' - 'A'] = 10;
    valores['L' - 'A'] = 50;
    valores['C' - 'A'] = 100;
    valores['D' - 'A'] = 500;
    valores['M' - 'A'] = 1000;

    int decimal = 0;
    int valorAnterior = 0;

    int tamanho = strlen(num);
    for (int i = tamanho - 1; i >= 0; i--) {
        int valorAtual = valores[num[i] - 'A'];

        if (valorAtual >= valorAnterior) {
            decimal += valorAtual;
        } else {
            decimal -= valorAtual;
        }
        valorAnterior = valorAtual;
    }

    return decimal;
}

void decimalParaBinario(int n) {
    int numBinario[32];
    int i = 0;
    while (n > 0) {
        numBinario[i] = n % 2;
        n = n / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", numBinario[j]);
    }
}

int main() {
    char numeroRomano[13];
    scanf("%s", numeroRomano);
    int numeroDecimal = romanToDecimal(numeroRomano);
    printf("%s na base 2: ", numeroRomano);
    decimalParaBinario(numeroDecimal);
    printf("\n");
    printf("%s na base 10: %d\n", numeroRomano, numeroDecimal);
    printf("%s na base 16: %x\n", numeroRomano, numeroDecimal);

    return 0;
}