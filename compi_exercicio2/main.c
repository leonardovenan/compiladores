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
    int i=0;
    bool fim;

    printf("\nDigite a expressao a ser testada: ");
    scanf("%s", express);

    tam = strlen(express);

    estado_maquina = 1;
    if(express[i] == '/'){
        i++;
        estado_maquina = 2;
        printf("%i\n", estado_maquina);
        if(express[i] == '*'){
            i++;
            estado_maquina = 3;
            fim = false;
            printf("%i\n", estado_maquina);
            while(fim == false){
                while(express[i] != '*'){
                    i++;
                }
                estado_maquina = 4;
                printf("%i\n", estado_maquina);
                while(express[i] == '*'){
                    i++;
                }
                if(express[i]=='/'){
                    fim = true;
                }
                i++;
            }
            printf("Aceitacao\n");
            estado_maquina = 5;
            printf("%i\n", estado_maquina);
        }else{
            printf("Outro processamento\n");
        }
    }else{
        printf("Outro processamento\n");
    }

    return 0;
}
