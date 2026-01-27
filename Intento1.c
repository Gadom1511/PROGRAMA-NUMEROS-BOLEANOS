#include <stdio.h>
#include <math.h>
void main() {
    int verdadero = 1, falso = 0;
    int num_variables, op;
    int i, j;
    int bit;
    // =========================
    // VALIDAR num_variables
    // =========================
    do {
        printf("Ingrese el numero de variables (1 a 10): ");
        scanf("%d", &num_variables);
        if (num_variables < 1 || num_variables > 10) {
            printf("Error: debe estar entre 1 y 10.\n\n");
        }
    } while (num_variables < 1 || num_variables > 10);
    int filas = (int)pow(2, num_variables);
    // Validación extra por seguridad
    if (filas > 1024) {
        printf("Error: demasiadas filas para el limite del programa.\n");
        return;
    }
    int salida[1024];
    printf("\nSe generaran %d filas (2^n)\n", filas);
    // =========================
    // VALIDAR SALIDAS (0 o 1)
    // =========================
    printf("\nIngrese las salidas (0 o 1):\n");
    for (i = 0; i < filas; i++) {
        do {
            printf("Fila %d: ", i);
            scanf("%d", &salida[i]);

            if (salida[i] != 0 && salida[i] != 1) {
                printf("Error: solo se permite 0 o 1.\n");
            }
        } while (salida[i] != 0 && salida[i] != 1);
    }
    // =========================
    // MOSTRAR TABLA
    // =========================
    printf("\nTabla de verdad:\n\n");
    for (j = 0; j < num_variables; j++)
        printf(" %c ", 'A' + j);
    printf("| Y\n");
    for (i = 0; i < filas; i++) {
        for (j = 0; j < num_variables; j++) {
            bit = (i >> (num_variables - 1 - j)) & 1;
            printf(" %d ", bit);
        }
        printf("| %d\n", salida[i]);
    }
    // =========================
    // VALIDAR OPCIÓN (1 o 2)
    // =========================
    do {
        printf("\nIngrese la opcion (1 para SOP, 2 para POS): ");
        scanf("%d", &op);

        if (op < 1 || op > 2) {
            printf("Opcion no valida. Solo 1 o 2.\n");
        }
    } while (op < 1 || op > 2);
    // =========================
    // SOP / POS
    // =========================
    switch (op) {
        case 1: {
            printf("\nUsted selecciono SOP\n");
            printf("SOP = ");
            int primero = 1;
            int hayTermino = 0;
            for (i = 0; i < filas; i++) {
                if (salida[i] == verdadero) {
                    hayTermino = 1;

                    if (!primero) printf(" + ");
                    primero = 0;

                    printf("(");
                    for (j = 0; j < num_variables; j++) {
                        bit = (i >> (num_variables - 1 - j)) & 1;
                        if (bit == 1) printf("%c", 'A' + j);
                        else printf("%c'", 'A' + j);
                    }
                    printf(")");
                }
            }
            // Validación lógica: si no hubo ningún 1
            if (!hayTermino) printf("0");
            break;
        }
        case 2: {
            printf("\nUsted selecciono POS\n");
            printf("POS = ");
            int primero = 1;
            int hayTermino = 0;

            for (i = 0; i < filas; i++) {
                if (salida[i] == falso) {
                    hayTermino = 1;
                    if (!primero) printf(" . ");
                    primero = 0;
                    printf("(");
                    for (j = 0; j < num_variables; j++) {
                        bit = (i >> (num_variables - 1 - j)) & 1;
                        if (j > 0) printf(" + ");
                        if (bit == 1) printf("%c'", 'A' + j);
                        else printf("%c", 'A' + j);
                    }
                    printf(")");
                }
            }
            // Validación lógica: si no hubo ningún 0
            if (!hayTermino) printf("1");
            break;
        }
    }
    printf("\n\n");
}