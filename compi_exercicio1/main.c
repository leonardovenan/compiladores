#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
void testNum(char teste [3]){
    if(!(teste >= 0 && teste <= 9)){
       return 0;
       }
}

void testLetra(char teste [3]){
    if(!(teste >= 'a' && teste <= 'z')){
       return 0;
       }
}
*/

int main()
{
    int estado_maquina;
    int tam;
    char express [60];
    int i = 1;

    printf("\nDigite a expressao a ser testada: ");
    scanf("%s", express);

    tam = strlen(express);
    //printf("%i\n", strlen(express));

    estado_maquina = 1;
    if(isalpha(express[0])){
        estado_maquina = 2;
        for(i = 1; i < tam; i++){
            if((isalpha(express[i]) || isalnum(express[i]))){
                estado_maquina = 2;
                printf("\n%i", estado_maquina);
            }
        }
        estado_maquina = 3;
        printf("\naceitacao\n\n");
    }else{
        printf("\nerro ou outros casos\n\n");
    }



    system("pause");
    return 0;
}
