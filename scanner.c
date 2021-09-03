#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "scanner.h"

token_t get_token( char *cadena ){

    char caracter;
    token_t token = NINGUNO ;
    int continuar = 1;

    cadena[0]='\0'; /* Borra la cadena */

    do {

        caracter=getchar();

        if ( token == CAD ) {   /* Si esta en estado "leyendo Cadena"  */

            if ( isspace(caracter) ) {
                continuar = 0;
            } else {
                if ( caracter == ',' || caracter == EOF ) {
                    continuar = 0;
                    ungetc(caracter,stdin);
                } else { /* caracter de cadena*/
                    strncat(cadena, &caracter, 1);
                }
            
            } 
        }

        if ( token == NINGUNO ) {   /* estado inicial de la funcion  */

            if ( isspace(caracter) ) {
                token = NINGUNO;
                continuar = 1;
            } else {
                if (caracter == ',') {
                    token = SEP; /* Separador */
                    continuar = 0;
                } else {
                    if (caracter == EOF) {
                        token = FDT;    /* EOF es FinDeTexto */
                        continuar = 0;
                    } else {
                        token = CAD; /* Ni espacio; ni eof; ni coma => Es Cadena */
                        continuar = 1;  /* Continuar leyendo caracteres de Cadena */
                        ungetc(caracter,stdin);
                    }
                }
            }
        }

        


    } while ( continuar == 1 );

    return token;

}