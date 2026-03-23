# Práctica 4 (Ejercicio 1): Sistemas Operativos en Tiempo Real (RTOS)

## Objetivo
[cite_start]El objetivo de la práctica es comprender el funcionamiento de un sistema operativo en tiempo real (FreeRTOS)[cite: 4]. [cite_start]En este ejercicio se generan varias tareas para observar cómo se ejecutan dividiendo el tiempo de uso de la CPU del ESP32[cite: 5].

## Descripción del Funcionamiento
* [cite_start]**Creación de Tareas:** Se utiliza la función `xTaskCreate` para programar una tarea adicional (`anotherTask`)[cite: 20, 168].
* [cite_start]**Bucle Infinito:** La nueva tarea contiene un bucle `for(;;)` infinito[cite: 43, 182]. [cite_start]Para evitar que monopolice el procesador, se hace uso de pausas que ceden el control al planificador de FreeRTOS[cite: 46].
* [cite_start]**Salida por Puerto Serie:** El monitor serie muestra alternativamente los mensajes de la tarea principal gestionada por Arduino (`loopTask`) y la nueva tarea creada, demostrando la ejecución concurrente en el microcontrolador[cite: 176, 184].