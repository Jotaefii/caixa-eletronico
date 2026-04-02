#include <stdio.h>

/* Prototipos */
void verSaldo(float saldoFix);
float depositar(float saldoFix, float deposito);
float saque(float saldoFix, float valorsaque);

int main(){

    float saldoFix = 1000;
    float deposito = 0;
    float valorsaque = 0;
    int opcao;

    do
    {
        printf("1 - Ver saldo\n");
        printf("2 - Depositar\n");
        printf("3 - Sacar\n");
        printf("4 - Sair\n");

        printf("Opcao: ");
        scanf("%d", &opcao);
        while(getchar() != '\n');
       
        switch (opcao)
        {
            case 1:
                verSaldo(saldoFix);
                break;
            case 2:      
                saldoFix = depositar(saldoFix, deposito);
                break;
            case 3:
                saldoFix = saque(saldoFix, valorsaque);
                break;
        }
    } while (opcao != 4);
    
    return 0;
}

/* Funcoes */
void verSaldo(float saldoFix){
    printf("\n------------------------------\n");
    printf("       JOTACAIXA - SALDO       \n");
    printf("------------------------------\n\n");

    printf("Saldo atual: R$%.2f\n\n", saldoFix);

    printf("------------------------------\n\n");
}

float depositar(float saldoFix, float deposito){
    printf("\n------------------------------\n");
    printf("     JOTACAIXA - DEPOSITAR       \n");
    printf("------------------------------\n\n");

    printf("Valor para deposito: R$");
    scanf("%f", &deposito);
    while (getchar() != '\n');

        /* Validacoes */
        if (deposito < 0) {
            printf("VALOR INVALIDO!\n");
            printf("\n------------------------------\n\n");
            return saldoFix;
        }
        else if (deposito == 0) {
            printf("NADA DEPOSITADO!\n");
        }
        else {
            printf("DEPOSITO CONCLUIDO!!\n");
        }

    printf("\n------------------------------\n\n");

    saldoFix = saldoFix + deposito;
    return saldoFix;
}

float saque(float saldoFix, float valorsaque){
    printf("\n------------------------------\n");
    printf("       JOTACAIXA - SAQUE       \n");
    printf("------------------------------\n\n");

    printf("Valor para saque: R$");
    scanf("%f", &valorsaque);
    while (getchar() != '\n');
    
        /* Validacoes */
        if (valorsaque > saldoFix){
            printf("SALDO INSUFICINETE!!\n");
            printf("\n------------------------------\n\n");
            return saldoFix;
        }
        else if (valorsaque <= 0) {
            printf("INVALIDO!!");
            printf("\n------------------------------\n\n");
            return saldoFix;
        }
        else {
            printf("SAQUE CONCLUIDO!!\n");
        }
    

    printf("\n------------------------------\n\n");

    saldoFix = saldoFix - valorsaque;
    return saldoFix;
}