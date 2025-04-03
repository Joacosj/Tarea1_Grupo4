#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

Order* read_csv(const char *filename, int *size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error al abrir el archivo");
        return NULL;
    }

    char line[1024];
    int capacity = 10;
    Order *orders = malloc(capacity * sizeof(Order));
    if (!orders) {
        perror("Error al asignar memoria");
        fclose(file);
        return NULL;
    }

    *size = 0;

    // Leer encabezado
    fgets(line, sizeof(line), file);

    // Leer cada línea del archivo
    while (fgets(line, sizeof(line), file)) {
        if (*size >= capacity) {
            capacity *= 2;
            orders = realloc(orders, capacity * sizeof(Order));
            if (!orders) {
                perror("Error al reasignar memoria");
                fclose(file);
                return NULL;
            }
        }

        Order *order = &orders[*size];

        // Usar strtok para manejar los campos
        char *token = strtok(line, ",");
        order->pizza_id = atoi(token);

        token = strtok(NULL, ",");
        order->order_id = atoi(token);

        token = strtok(NULL, ",");
        strncpy(order->pizza_name_id, token, sizeof(order->pizza_name_id));

        token = strtok(NULL, ",");
        order->quantity = atoi(token);

        token = strtok(NULL, ",");
        strncpy(order->order_date, token, sizeof(order->order_date));

        token = strtok(NULL, ",");
        strncpy(order->order_time, token, sizeof(order->order_time));

        token = strtok(NULL, ",");
        order->unit_price = atof(token);

        token = strtok(NULL, ",");
        order->total_price = atof(token);

        token = strtok(NULL, ",");
        strncpy(order->pizza_size, token, sizeof(order->pizza_size));

        token = strtok(NULL, ",");
        strncpy(order->pizza_category, token, sizeof(order->pizza_category));

        // Manejar ingredientes entre comillas dobles
        token = strtok(NULL, "\"");
        strncpy(order->pizza_ingredients, token, sizeof(order->pizza_ingredients));

        token = strtok(NULL, ",");
        strncpy(order->pizza_name, token, sizeof(order->pizza_name));

        (*size)++;
    }

    fclose(file);
    return orders;
}
