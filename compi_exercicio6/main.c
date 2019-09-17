#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int tabelaEstado(int estado_maquina, char express){
    switch(express){
        case '/':
            switch(estado_maquina){
            case 1:
                return 2;
            case 3:
                return 3;
            case 4:
                return 5;
            default:
                return 0;
            }
        case '*':
            switch(estado_maquina){
            case 2:
                return 3;
            case 3:
                return 4;
            case 4:
                return 4;
            default:
                break;
            }
        default:
            switch(estado_maquina){
            case 3:
                return 3;
            case 4:
                return 3;
            default:
                return 0;
            }
            break;
        }
}

int main()
{
    int estado_maquina;
    int estado;
    int tam;
    char express [60];
    int i = 0;
    bool fim;

    printf("\nDigite a expressao a ser testada: ");
    scanf("%s", express);

    estado_maquina = 1;
    while(!(estado_maquina == 5 ) && estado_maquina < 5 && !(estado_maquina == 0) && i <= strlen(express)){
        estado = tabelaEstado(estado_maquina, express[i]);
        if(tabelaEstado(estado_maquina, express[i])){
            estado_maquina = estado;
        }
        printf("\n%d", estado_maquina);
        i++;
    }

    if(estado_maquina == 5){
        printf("\nAceitacao!\n\n");
    }else{
        printf("\nERRO!\n\n");
    }

    system("pause");
    return 0;

}

