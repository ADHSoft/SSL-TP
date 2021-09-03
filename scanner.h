/* 
FDT: Fin de texto (EOF)
SEP: Separador (,)
CAD: Cadena
 */

enum tokens { FDT , SEP , CAD , NINGUNO };

typedef enum tokens token_t;

token_t get_token( char* );

