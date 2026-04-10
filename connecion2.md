Para alimentar tu ESP32 mientras lo usas con el amplificador XH-M562, tienes dos caminos principales. Todo depende de si quieres usar una sola fuente de energía para ambos o fuentes separadas.
Aquí te explico las mejores opciones:
## 1. La opción profesional: Fuente única (12V - 24V)
Como el amplificador M562 necesita obligatoriamente entre 12V y 24V, lo ideal es usar una sola fuente potente y "bajar" el voltaje para el ESP32.

* Necesitas: Un convertidor de voltaje Step-Down (Buck Converter) como el LM2596.
* Conexión:
1. Conecta la fuente (ej. 12V) a la entrada del amplificador y a la entrada del convertidor.
   2. Ajusta el convertidor para que salgan exactamente 5V.
   3. Conecta esos 5V al pin VIN (o 5V) del ESP32 y el GND al GND del ESP32.

## 2. La opción rápida: Fuentes separadas
Si no quieres complicarte con convertidores, puedes alimentar cada cosa por su lado:

* Amplificador M562: Conéctalo a una fuente de pared o batería de 12V a 24V.
* ESP32: Aliméntalo mediante el puerto Micro-USB / USB-C conectado a un cargador de celular o a tu PC.
* ¡Muy Importante!: Debes unir el pin GND del ESP32 con el pin GND de la entrada de audio del amplificador para que la señal de audio sea limpia.

## 3. Alimentación directa (Solo si tu fuente es de 5V)
No recomendada para este amplificador específico, ya que el chip TPA3116D2 del M562 rinde muy poco a 5V (casi no suena). Si intentaras esto, conectarías los 5V al pin VIN del ESP32.
------------------------------
## Resumen de Pines de Alimentación en el ESP32:

* Pin VIN (o 5V): Recibe entre 4.5V y 5V (el ESP32 tiene su propio regulador interno para bajarlo a 3.3V).
* Pin 3V3: ¡Cuidado! Este es de salida. Solo se usa como entrada si tienes una fuente de 3.3V regulada y muy estable. No le metas 5V aquí o quemarás la placa.
* Puerto USB: La forma más segura y fácil para programar y hacer pruebas iniciales.

¿Qué fuente de voltaje tienes a mano ahora mismo para alimentar el amplificador? (Ejemplo: una fuente de 12V de un router o una batería de 18V).

