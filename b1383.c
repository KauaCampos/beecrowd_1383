#include <stdio.h>

#define NUM 81

void inicializarM(int* ptr);
int testarMatriz(int* ptr);
int testarLinha(int* ptr, int linha);
int testarColuna(int* ptr, int coluna);
int testarBloco(int* ptr, int linha, int coluna);

int main() {
    int cont, matriz[NUM];
    int* ptr = matriz;
    scanf("%d", &cont);
    for (int x = 1; x <= cont; x++) {
        inicializarM(ptr);
        ptr = matriz;

        printf("Instancia %d\n", x);
        if (testarMatriz(ptr))
            puts("SIM");
        else
            puts("NAO");
        putchar('\n');
    }
    return 0;
}

void inicializarM(int* ptr) {
    for (int i = 0; i < NUM; i++, ptr++)
        scanf("%d", ptr);
}

int testarMatriz(int* ptr) {
    for (int linha = 0; linha < 9; linha++) {
        if (!testarLinha(ptr, linha))
            return 0;
    }

    for (int coluna = 0; coluna < 9; coluna++) {
        if (!testarColuna(ptr, coluna))
            return 0;
    }

    for (int linha = 0; linha < 9; linha += 3) {
        for (int coluna = 0; coluna < 9; coluna += 3) {
            if (!testarBloco(ptr, linha, coluna))
                return 0;
        }
    }

    return 1;
}

int testarLinha(int* ptr, int linha) {
    int soma = 0;
    int numeros[10];
    int* numerosPtr = numeros;
    for (int i = 0; i < 10; i++, numerosPtr++)
        *(numerosPtr) = 0;

    for (int i = 0; i < 9; i++) {
        int num = *(ptr + linha * 9 + i);
        if (num < 1 || num > 9 || *(numeros + num) == 1)
            return 0;
        *(numeros + num) = 1;
        soma += num;
    }
    return soma == 45;
}

int testarColuna(int* ptr, int coluna) {
    int soma = 0;
    int numeros[10];
    int* numerosPtr = numeros;
    for (int i = 0; i < 10; i++, numerosPtr++)
        *(numerosPtr) = 0;

    for (int i = 0; i < 9; i++) {
        int num = *(ptr + coluna + i * 9);
        if (num < 1 || num > 9 || *(numeros + num) == 1)
            return 0;
        *(numeros + num) = 1;
        soma += num;
    }
    return soma == 45;
}

int testarBloco(int* ptr, int linha, int coluna) {
    int soma = 0;
    int numeros[10];
    int* numerosPtr = numeros;
    for (int i = 0; i < 10; i++, numerosPtr++)
        *(numerosPtr) = 0;

    for (int i = linha; i < linha + 3; i++) {
        for (int j = coluna; j < coluna + 3; j++) {
            int num = *(ptr + i * 9 + j);
            if (num < 1 || num > 9 || *(numeros + num) == 1)
                return 0;
            *(numeros + num) = 1;
            soma += num;
        }
    }
    return soma == 45;
}
