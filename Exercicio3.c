#include <stdio.h>
#include <string.h>
#include <ctype.h>

void verificarDia(char p[], char d[]) {
    
    int ultimoDigito = p[strlen(p) - 1] - '0';

    
    for (int i = 0; d[i]; i++) {
        d[i] = tolower(d[i]);
    }

 
    if (strcmp(d, "sabado") == 0 || strcmp(d, "domingo") == 0) {
        printf("Nao ha proibicao no fim de semana\n");
    } 

    else if (strcmp(d, "segunda-feira") == 0 || strcmp(d, "terca-feira") == 0 ||
             strcmp(d, "quarta-feira") == 0 || strcmp(d, "quinta-feira") == 0 ||
             strcmp(d, "sexta-feira") == 0) {
 
        if ((ultimoDigito == 0 || ultimoDigito == 1) && strcmp(d, "segunda-feira") == 0)
            printf("%s nao pode circular %s\n", p, d);
        else if ((ultimoDigito == 2 || ultimoDigito == 3) && strcmp(d, "terca-feira") == 0)
            printf("%s nao pode circular %s\n", p, d);
        else if ((ultimoDigito == 4 || ultimoDigito == 5) && strcmp(d, "quarta-feira") == 0)
            printf("%s nao pode circular %s\n", p, d);
        else if ((ultimoDigito == 6 || ultimoDigito == 7) && strcmp(d, "quinta-feira") == 0)
            printf("%s nao pode circular %s\n", p, d);
        else if ((ultimoDigito == 8 || ultimoDigito == 9) && strcmp(d, "sexta-feira") == 0)
            printf("%s nao pode circular %s\n", p, d);
        else
            printf("%s pode circular %s\n", p, d);
    } 

    else {
        printf("Dia da semana invalido\n");
    }
}

int main() {
    char p[9];
    char d[15];

    scanf("%s", p);
    scanf("%s", d);


    if ((strlen(p) == 8 && p[3] == '-') || (strlen(p) == 7 && p[2] != '-')) {
        verificarDia(p, d);
    } else {
        printf("Placa invalida\n");
    }

    return 0;
}
