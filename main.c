#include "scanner.h"
#include <stdio.h>
#include <string.h>
#define EXIT_SUCCESS 0

int main (void) {

    char cadena_token[100];

    token_t token;

    do {

        token = get_token( cadena_token );

        switch (token) {
            case FDT :
                printf("Fin De Texto:");
                break;
            case SEP :
                printf("Separador: ,");
                break;
            case CAD :
                printf("Cadena: %s",cadena_token);
                break;
            default:
                printf("Token Desconocido:");
                break;
        }
        printf("\n");
        
    } while ( token != FDT );
    

    return EXIT_SUCCESS;
}