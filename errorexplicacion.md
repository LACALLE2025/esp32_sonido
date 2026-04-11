Esquema de conexión recomendado:
Audio Izquierdo (L): Pin GPIO 25 del ESP32 → Entrada INL del M562.
Audio Derecho (R): Pin GPIO 26 del ESP32 → Entrada INR del M562.
Tierra de Audio: Pin GND del ESP32 → Entrada GND (al lado de las entradas de audio) del M562.
Alimentación: 12V-24V directo a los terminales VCC/GND de fuerza del M562. 
¿Cómo estás alimentando actualmente el amplificador M562? Si lo tienes a la misma fuente que el ESP32 sin un buen filtrado, esa es la razón exacta de la caída.





undefined
undefined
undefined
8 sitios
DIY ESP32 Based Audio Player - Circuit Digest
24 mar. 2021 — » Power Wiring: Connect your LM386 module VCC to the ESP32 VIN pin (5V) and GND to the ESP32 GND pin. » Audio Connection: Connect ...

Circuit Digest

XH-M562 TPA3116D2 TPA3116 Mini Digital Audio Amplifier D ...
Top highlights. Voltage. 12 Volts, 24 Volts. Manufacturer. Rakstore. Brand. Rakstore. Number of Channels. 2. UPC. 717981930591. Po...

Amazon.com

Integrado Modulo Mini Amplificador Tpa3116d2 Xh-m562 50+ ...
Descripción. TPA3116D2 XH-M562 amplificador de potencia 50W + 50 W 2 canales Audio estéreo digital para potencia de audio DC 12V-2...

Mercado Libre

Mostrar todo
ets Jul 29 2019 12:21:46

rst:0x1 (POWERON_RESET),boot:0x13 (SE (69598) task_wdt: Task watchdog got triggered. The following tasks/users did not reset the watchdog in time:
E (69598) task_wdt:  - IDLE0 (CPU 0)
E (69598) task_wdt: Tasks currently running:
E (69598) task_wdt: CPU 0: BTC_TASK
E (69598) task_wdt: CPU 1: loopTask
E (69598) task_wdt: Aborting.
Ese error BTC_TASK y el Task Watchdog Timer (WDT) disparándose confirman exactamente lo que sospechábamos: el procesador del ESP32 se está "congelando" porque el Bluetooth Classic (que corre en la tarea BTC_TASK) está saturado o sufriendo por falta de recursos.
Cuando el audio empieza a fluir, el consumo de CPU y de energía sube tanto que el sistema no puede completar las tareas a tiempo y el "perro guardián" (Watchdog) reinicia el chip para protegerlo.
Para solucionar este error específico de Watchdog y la caída de conexión, aplica estos 3 cambios en tu configuración:
1. Cambia la Partición a "Huge APP" (Obligatorio)
El stack de Bluetooth con A2DP es enorme. Si no lo has hecho, este error es típico de falta de espacio en la memoria flash para las librerías de audio:
En Arduino IDE: Herramientas > Partition Scheme > Huge APP (3MB No OTA).
2. Código Optimizado (Prioridad y Brownout)
Vamos a añadir una línea para darle un "respiro" al procesador y desactivar el detector de voltaje que suele causar estos reinicios en cadena:
