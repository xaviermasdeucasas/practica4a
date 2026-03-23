#include <Arduino.h>

/* Declaración previa de la función de la tarea para evitar errores en PlatformIO */
void anotherTask(void * parameter);

void setup() {
  Serial.begin(115200); // Corregido: La velocidad estándar es 115200, no 112500
  
  // Damos un poco de tiempo para abrir el monitor serie
  delay(1000);
  Serial.println("--- Inicio del programa ---");

  /* Creamos una nueva tarea aquí */
  xTaskCreate(
    anotherTask,      /* Función de la tarea. */
    "another Task",   /* Nombre de la tarea (para debug). */
    10000,            /* Tamaño de la pila (Stack size) en bytes. */
    NULL,             /* Parámetro que se pasa a la tarea (ninguno). */
    1,                /* Prioridad de la tarea (1). */
    NULL              /* Manejador de la tarea (Task handle), no lo guardamos. */
  ); 
}

/* La función loop() tradicional es ejecutada por la tarea "loopTask" del ESP32/Arduino */
void loop() {
  Serial.println("this is ESP32 Task");
  delay(1000);
}

/* Esta función será ejecutada por la nueva tarea que hemos creado */
void anotherTask(void * parameter) {
  /* Bucle infinito, necesario en las tareas de FreeRTOS que no terminan */
  for(;;) {
    Serial.println("this is another Task");
    delay(1000);
  }
  
  /* Eliminar la tarea cuando termine, 
     esto nunca sucederá porque está en un bucle infinito */
  vTaskDelete(NULL); 
}