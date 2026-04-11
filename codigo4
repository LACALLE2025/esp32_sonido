#include "BluetoothA2DPSink.h"
#include "soc/soc.h"           // Necesario para registros internos
#include "soc/rtc_cntl_reg.h"  // Necesario para desactivar Brownout

BluetoothA2DPSink a2dp_sink;

void setup() {
    // 1. Desactivamos el Brownout para que micro-caídas de tensión no reinicien el chip
    WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0); 

    Serial.begin(115200);

    // 2. Iniciamos el Bluetooth con el DAC interno (pines 25 y 26)
    a2dp_sink.start("ESP32_Audio", true);

    Serial.println("Bluetooth listo. Si se cae al sonar, revisa la fuente de 12V.");
}

void loop() {
    // 3. Añadimos un delay mínimo para que el Watchdog del sistema (IDLE task)
    // tenga tiempo de "alimentarse" y no reinicie el ESP32.
    delay(10); 
}
