#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void main (){
    int num_variables,op,exponente,base=2,salida,i,j;
    char letra;
    printf("Ingrese el numero de variables: ");
    scanf("%d",&num_variables); 
    exponente = pow(base,num_variables);
    printf("El numero de filas es: %d\n",exponente);
    do
    {
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
    } while (op!=1 && op!=2);
            
}
