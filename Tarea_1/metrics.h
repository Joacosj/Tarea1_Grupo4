#ifndef METRICS_H
#define METRICS_H

#include "utils.h" // Para usar la estructura Order

// Tipo de puntero a función para las métricas
typedef char* (*MetricFunction)(int size, Order *orders);

// Declaraciones de las funciones de métricas
char* pizza_mas_vendida(int size, Order *orders);
char* pizza_menos_vendida(int size, Order *orders);
char* fecha_mas_ventas_dinero(int size, Order *orders);
char* fecha_menos_ventas_dinero(int size, Order *orders);
char* fecha_mas_ventas_pizzas(int size, Order *orders);
char* fecha_menos_ventas_pizzas(int size, Order *orders);
char* promedio_pizzas_por_orden(int size, Order *orders);
char* promedio_pizzas_por_dia(int size, Order *orders);
char* ingrediente_mas_vendido(int size, Order *orders);
char* pizzas_por_categoria(int size, Order *orders);

#endif