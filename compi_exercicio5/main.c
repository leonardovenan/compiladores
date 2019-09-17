#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include <string.h>
#include <ctype.h>

int tabelaEstado(int estado_maquina, char express){
    if(isalpha(express)){
        switch(estado_maquina){
        case 1:
            return 2;
        case 2:
            return 2;
        default:
            break;
        }
    }
    if(isalnum(express)){
        switch(estado_maquina){
        case 2:
            return 2;
        default:
            break;
        }
    }if(!(isalpha(express)) && !(isalnum(express))){
        switch(estado_maquina){
        case 2:
            return 3;
        default:
            break;
        }
    }
}
int main()
{
    int estado_maquina;
    int estado;
    char express [60];
    int i = 0;

    printf("\nDigite a expressao a ser testada: ");
    scanf("%s", express);

    estado_maquina = 1;
    while((estado_maquina != 3 && estado_maquina < 3 && estado_maquina != 0 && i <= strlen(express))){
        estado = tabelaEstado(estado_maquina, express[i]);
        if(tabelaEstado(estado_maquina, express[i])){
            estado_maquina = estado;
        }
        i++;
    }


    if(estado_maquina == 3){
        printf("\nAceitacao!\n\n");
    }else{
        printf("\nERRO!\n\n");
    }

    system("pause");
    return 0;

}
