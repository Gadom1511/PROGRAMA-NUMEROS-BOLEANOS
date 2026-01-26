#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void main (){
    int verdadero=1 , falso =0,num_variables,op,exponente;
    
    printf("Ingrese el numero de variables: ");
    scanf("%d",&num_variables); 
    printf("Ingrese la opcion (1 para SOP, 2 para POS): ");
    scanf("%d",&op);
    switch(op){
        case 1:
            printf("Usted selecciono la Opcion SOP");

            break;
        case 2:
            printf("Usted selecciono la Opcion POS");
            break;
        default:
            printf("Opcion no valida\n");
    }
            
}