#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

    estado_maquina = 1;
    tam = strlen(express);
    while(i <= tam && (estado_maquina == 1 || estado_maquina == 2 || estado_maquina == 3 || estado_maquina == 4)){
        switch (estado_maquina){
        case 1:
            if(express[i] == '/'){
            i++;
            estado_maquina = 2;
            printf("%d\n", estado_maquina);
            }else{
                estado_maquina = 0;
            }
            break;

        case 2:
            if(express[i] == '*'){
            i++;
            estado_maquina = 3;
            printf("%d\n", estado_maquina);
            }else{
                estado_maquina = 0;
                printf("%d\n", estado_maquina);
            }
            break;

        case 3:
            if(express[i] == '*'){
            i++;
            estado_maquina = 4;
            printf("%d\n", estado_maquina);
            }else{
                i++;
                printf("%d\n", estado_maquina);
            }
            break;

        case 4:
            if(express[i] == '/'){
            i++;
            estado_maquina = 5;
            printf("%d\n", estado_maquina);
            }
            else if(express[i] == '*'){
                i++;
            }else{
                i++;
                estado_maquina = 3;
                printf("%d\n", estado_maquina);
            }
            break;
        }
    }

    if(estado_maquina == 5){
        printf("\nAceitacao\n\n");
    }else{
        printf("\nERRO!\n\n");
    }

    system("pause");
    return 0;

}

