#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int estado_maquina;
    int tam;
    char express [60];
    int i = 0;
    bool fim;

    printf("\nDigite a expressao a ser testada: ");
    scanf("%s", express);

    tam = strlen(express);

    estado_maquina = 1;
    while(estado_maquina == 1 || estado_maquina ==2){
        switch(estado_maquina){
        case 1:
            if(isalpha(express[i])){
                i++;
                estado_maquina = 2;
            }else{
                estado_maquina = 0;
            }
            break;
        case 2:
            if(isalpha(express[i]) || isalnum(express[i])){
                i++;
                estado_maquina = 2;
            }else{
                estado_maquina = 3;
            }
            break;
        }
    }

    if(estado_maquina == 3){
        printf("Aceitacao\n\n");
    }
    else{
        printf("Erro!\n\n");
    }
    system("pause");
    return 0;
}
