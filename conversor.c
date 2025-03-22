#include <stdio.h>

// Tasas de conversión (valores aproximados, pueden cambiar)
#define USD_TO_GTQ 7.80
#define EUR_TO_GTQ 8.50
#define GTQ_TO_USD (1.0 / USD_TO_GTQ)
#define GTQ_TO_EUR (1.0 / EUR_TO_GTQ)
#define USD_TO_EUR 0.91
#define EUR_TO_USD (1.0 / USD_TO_EUR)

// Función para realizar la conversión de monedas
double convertir(double cantidad, int moneda_origen, int moneda_destino) {
    if (moneda_origen == moneda_destino) {
        return cantidad; // Si es la misma moneda, no hay conversión
    }

    switch (moneda_origen) {
        case 1: // Quetzales a otras monedas
            if (moneda_destino == 2) return cantidad * GTQ_TO_USD;
            if (moneda_destino == 3) return cantidad * GTQ_TO_EUR;
            break;
        case 2: // Dólares a otras monedas
            if (moneda_destino == 1) return cantidad * USD_TO_GTQ;
            if (moneda_destino == 3) return cantidad * USD_TO_EUR;
            break;
        case 3: // Euros a otras monedas
            if (moneda_destino == 1) return cantidad * EUR_TO_GTQ;
            if (moneda_destino == 2) return cantidad * EUR_TO_USD;
            break;
    }
    return 0; // En caso de error
}

int main() {
    int moneda_origen, moneda_destino;
    double cantidad, resultado;

    printf("Conversor de Monedas (GTQ, USD, EUR)\n");
    printf("Seleccione la moneda de origen:\n");
    printf("1. Quetzales (GTQ)\n2. Dólares (USD)\n3. Euros (EUR)\n");
    printf("Ingrese la opción: ");
    scanf("%d", &moneda_origen);

    if (moneda_origen < 1 || moneda_origen > 3) {
        printf("Opción inválida.\n");
        return 1;
    }

    printf("Ingrese la cantidad: ");
    scanf("%lf", &cantidad);

    printf("Seleccione la moneda de destino:\n");
    printf("1. Quetzales (GTQ)\n2. Dólares (USD)\n3. Euros (EUR)\n");
    printf("Ingrese la opción: ");
    scanf("%d", &moneda_destino);

    if (moneda_destino < 1 || moneda_destino > 3) {
        printf("Opción inválida.\n");
        return 1;
    }

    resultado = convertir(cantidad, moneda_origen, moneda_destino);
    printf("Resultado: %.2f\n", resultado);

    return 0;
}
