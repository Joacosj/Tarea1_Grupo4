#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metrics.h"

// Encuentra la pizza más vendida
char* pizza_mas_vendida(int size, Order *orders) {
    if (size == 0) return strdup("No hay datos disponibles.");

    int max_quantity = 0;
    char *most_sold_pizza = malloc(100);
    if (!most_sold_pizza) return strdup("Error de memoria");

    most_sold_pizza[0] = '\0';

    for (int i = 0; i < size; i++) {
        if (orders[i].quantity > max_quantity) {
            max_quantity = orders[i].quantity;
            strcpy(most_sold_pizza, orders[i].pizza_name);
        }
    }

    return most_sold_pizza;
}

// Encuentra la pizza menos vendida
char* pizza_menos_vendida(int size, Order *orders) {
    if (size == 0) return strdup("No hay datos disponibles.");

    int min_quantity = orders[0].quantity;
    char *least_sold_pizza = malloc(100);
    if (!least_sold_pizza) return strdup("Error de memoria");

    strcpy(least_sold_pizza, orders[0].pizza_name);

    for (int i = 1; i < size; i++) {
        if (orders[i].quantity < min_quantity) {
            min_quantity = orders[i].quantity;
            strcpy(least_sold_pizza, orders[i].pizza_name);
        }
    }

    return least_sold_pizza;
}

// Encuentra la fecha con más ventas en términos de dinero
char* fecha_mas_ventas_dinero(int size, Order *orders) {
    if (size == 0) return strdup("No hay datos disponibles.");

    float max_sales = 0;
    char *result = malloc(100);
    if (!result) return strdup("Error de memoria");

    for (int i = 0; i < size; i++) {
        if (orders[i].total_price > max_sales) {
            max_sales = orders[i].total_price;
            snprintf(result, 100, "Fecha: %s, Dinero: %.2f", orders[i].order_date, max_sales);
        }
    }

    return result;
}

// Encuentra la fecha con menos ventas en términos de dinero
char* fecha_menos_ventas_dinero(int size, Order *orders) {
    if (size == 0) return strdup("No hay datos disponibles.");

    float min_sales = orders[0].total_price;
    char *result = malloc(100);
    if (!result) return strdup("Error de memoria");

    snprintf(result, 100, "Fecha: %s, Dinero: %.2f", orders[0].order_date, min_sales);

    for (int i = 1; i < size; i++) {
        if (orders[i].total_price < min_sales) {
            min_sales = orders[i].total_price;
            snprintf(result, 100, "Fecha: %s, Dinero: %.2f", orders[i].order_date, min_sales);
        }
    }

    return result;
}

// Encuentra la fecha con más ventas en términos de cantidad de pizzas
char* fecha_mas_ventas_pizzas(int size, Order *orders) {
    if (size == 0) return strdup("No hay datos disponibles.");

    int max_pizzas = 0;
    char *result = malloc(100);
    if (!result) return strdup("Error de memoria");

    for (int i = 0; i < size; i++) {
        if (orders[i].quantity > max_pizzas) {
            max_pizzas = orders[i].quantity;
            snprintf(result, 100, "Fecha: %s, Pizzas: %d", orders[i].order_date, max_pizzas);
        }
    }

    return result;
}

// Encuentra la fecha con menos ventas en términos de cantidad de pizzas
char* fecha_menos_ventas_pizzas(int size, Order *orders) {
    if (size == 0) return strdup("No hay datos disponibles.");

    int min_pizzas = orders[0].quantity;
    char *result = malloc(100);
    if (!result) return strdup("Error de memoria");

    snprintf(result, 100, "Fecha: %s, Pizzas: %d", orders[0].order_date, min_pizzas);

    for (int i = 1; i < size; i++) {
        if (orders[i].quantity < min_pizzas) {
            min_pizzas = orders[i].quantity;
            snprintf(result, 100, "Fecha: %s, Pizzas: %d", orders[i].order_date, min_pizzas);
        }
    }

    return result;
}

// Calcula el promedio de pizzas por orden
char* promedio_pizzas_por_orden(int size, Order *orders) {
    if (size == 0) return strdup("No hay datos disponibles.");

    int total_pizzas = 0;
    for (int i = 0; i < size; i++) {
        total_pizzas += orders[i].quantity;
    }

    float average = (float)total_pizzas / size;
    char *result = malloc(50);
    if (!result) return strdup("Error de memoria");

    snprintf(result, 50, "Promedio de pizzas por orden: %.2f", average);

    return result;
}

// Calcula el promedio de pizzas por día
char* promedio_pizzas_por_dia(int size, Order *orders) {
    if (size == 0) return strdup("No hay datos disponibles.");

    int total_pizzas = 0;
    int unique_days = 0;
    char last_date[20] = "";

    for (int i = 0; i < size; i++) {
        total_pizzas += orders[i].quantity;
        if (strcmp(last_date, orders[i].order_date) != 0) {
            unique_days++;
            strcpy(last_date, orders[i].order_date);
        }
    }

    float average = (float)total_pizzas / unique_days;
    char *result = malloc(50);
    if (!result) return strdup("Error de memoria");

    snprintf(result, 50, "Promedio de pizzas por día: %.2f", average);

    return result;
}

// Encuentra el ingrediente más vendido
char* ingrediente_mas_vendido(int size, Order *orders) {
    if (size == 0) return strdup("No hay datos disponibles.");

    // Crear un mapa para contar los ingredientes
    typedef struct {
        char ingredient[50];
        int count;
    } IngredientCount;

    IngredientCount ingredient_counts[100];
    int ingredient_count_size = 0;

    for (int i = 0; i < size; i++) {
        char *ingredients = strdup(orders[i].pizza_ingredients); // Copiar la lista de ingredientes
        if (!ingredients) return strdup("Error de memoria");

        char *token = strtok(ingredients, ",");
        while (token) {
            // Buscar si el ingrediente ya está en el mapa
            int found = 0;
            for (int j = 0; j < ingredient_count_size; j++) {
                if (strcmp(ingredient_counts[j].ingredient, token) == 0) {
                    ingredient_counts[j].count++;
                    found = 1;
                    break;
                }
            }

            // Si no se encontró, agregarlo al mapa
            if (!found) {
                strcpy(ingredient_counts[ingredient_count_size].ingredient, token);
                ingredient_counts[ingredient_count_size].count = 1;
                ingredient_count_size++;
            }

            token = strtok(NULL, ",");
        }

        free(ingredients);
    }

    // Encontrar el ingrediente más vendido
    int max_count = 0;
    char most_sold_ingredient[50] = "";

    for (int i = 0; i < ingredient_count_size; i++) {
        if (ingredient_counts[i].count > max_count) {
            max_count = ingredient_counts[i].count;
            strcpy(most_sold_ingredient, ingredient_counts[i].ingredient);
        }
    }

    // Crear el resultado
    char *result = malloc(100);
    if (!result) return strdup("Error de memoria");

    snprintf(result, 100, "Ingrediente más vendido: %s, Veces: %d", most_sold_ingredient, max_count);

    return result;
}

// Calcula la cantidad de pizzas por categoría
char* pizzas_por_categoria(int size, Order *orders) {
    if (size == 0) return strdup("No hay datos disponibles.");

    // Crear un mapa para contar las categorías
    typedef struct {
        char category[50];
        int count;
    } CategoryCount;

    CategoryCount category_counts[100];
    int category_count_size = 0;

    for (int i = 0; i < size; i++) {
        // Buscar si la categoría ya está en el mapa
        int found = 0;
        for (int j = 0; j < category_count_size; j++) {
            if (strcmp(category_counts[j].category, orders[i].pizza_category) == 0) {
                category_counts[j].count += orders[i].quantity;
                found = 1;
                break;
            }
        }

        // Si no se encontró, agregarla al mapa
        if (!found) {
            strcpy(category_counts[category_count_size].category, orders[i].pizza_category);
            category_counts[category_count_size].count = orders[i].quantity;
            category_count_size++;
        }
    }

    // Crear el resultado
    char *result = malloc(500);
    if (!result) return strdup("Error de memoria");

    result[0] = '\0';
    strcat(result, "Categorías: ");

    for (int i = 0; i < category_count_size; i++) {
        char buffer[100];
        snprintf(buffer, 100, "%s: %d", category_counts[i].category, category_counts[i].count);
        strcat(result, buffer);
        if (i < category_count_size - 1) strcat(result, ", ");
    }

    return result;
}
