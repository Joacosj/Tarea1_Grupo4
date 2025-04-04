#ifndef UTILS_H
#define UTILS_H

// Estructura para representar una orden
typedef struct {
    int pizza_id;
    int order_id;
    char pizza_name_id[50];
    int quantity;
    char order_date[20];
    char order_time[20];
    float unit_price;
    float total_price;
    char pizza_size[5];
    char pizza_category[20];
    char pizza_ingredients[200];
    char pizza_name[50];
} Order;

// Declaración de la función para leer el archivo CSV
Order* read_csv(const char *filename, int *size);

#endif