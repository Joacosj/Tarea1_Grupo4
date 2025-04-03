#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metrics.h"
#include "utils.h"

#define MAX_METRICS 10

int main(int argc, char *argv[]) {
    // Verificar que se haya pasado el archivo CSV y al menos una métrica
    if (argc < 3) {
        printf("Uso: %s <archivo_csv> <metrica1> [<metrica2> ...]\n", argv[0]);
        return 1;
    }

    // Obtener el nombre del archivo CSV
    const char *csv_file = argv[1];

    // Leer datos del archivo CSV
    int order_count = 0;
    Order *orders = read_csv(csv_file, &order_count);
    if (!orders) {
        printf("Error al leer el archivo CSV '%s'.\n", csv_file);
        return 1;
    }

    // Arreglo de punteros a funciones para las métricas
    MetricFunction metrics[] = {
        pizza_mas_vendida,
        pizza_menos_vendida,
        fecha_mas_ventas_dinero,
        fecha_menos_ventas_dinero,
        fecha_mas_ventas_pizzas,
        fecha_menos_ventas_pizzas,
        promedio_pizzas_por_orden,
        promedio_pizzas_por_dia,
        ingrediente_mas_vendido,
        pizzas_por_categoria
    };

    // Nombres de las métricas correspondientes
    const char *metric_names[] = {
        "pms", "pls", "dms", "dls", "dmsp", "dlsp", "apo", "apd", "ims", "hp"
    };

    // Procesar las métricas solicitadas
    for (int i = 2; i < argc; i++) {
        int metric_found = 0;
        for (int j = 0; j < MAX_METRICS; j++) {
            if (strcmp(argv[i], metric_names[j]) == 0) {
                char *result = metrics[j](order_count, orders);
                printf("%s: %s\n", argv[i], result);
                free(result); // Liberar memoria si la métrica devuelve un string dinámico
                metric_found = 1;
                break;
            }
        }
        if (!metric_found) {
            printf("Métrica desconocida: %s\n", argv[i]);
        }
    }

    // Liberar memoria de las órdenes
    free(orders);

    return 0;
}