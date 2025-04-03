# Proyecto: Análisis de Ventas de Pizzas

## Integrantes del Grupo
- **Joaquin Salazr** - Correo: joaqusalazar@alumnos.uai.cl
- **Juan Pablo Aedo** - Correo: juaedo@alumnos.uai.cl
- **Matias Salinas** - Correo: matisalinas@alumnos.uai.cl
- **Pedro Hödar** - Correo: Phodar@alumnos.uai.cl

- **Sección**: LPP - Sección 1

## Descripción
Este proyecto analiza un archivo CSV con datos de ventas de pizzas y calcula métricas específicas como:
- Pizza más vendida (`pms`)
- Pizza menos vendida (`pls`)
- Fecha con más ventas en dinero (`dms`)
- Fecha con menos ventas en dinero (`dls`)
- Fecha con más ventas en cantidad de pizzas (`dmsp`)
- Fecha con menos ventas en cantidad de pizzas (`dlsp`)
- Promedio de pizzas por orden (`apo`)
- Promedio de pizzas por día (`apd`)
- Ingrediente más vendido (`ims`)
- Cantidad de pizzas por categoría (`hp`)

## Compilación
Para compilar el proyecto, asegúrate de tener instalado `gcc` y ejecuta el siguiente comando en la terminal: make  
Luego para ejecutar el programa se ejecuta el siguiente comando con este formato: ./app1 <archivo_csv> <métrica1> [<métrica2> ...]  
Ejemplo: ./app1 ventas.csv pms pls
