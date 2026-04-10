/*
 * Ejemplo: Salida de audio por Bluetooth con ESP32 (SIN WiFi)
 * Requisitos:
 *   - Placa ESP32 (configurada en Arduino IDE)
 *   - Librería "ESP32-A2DP" de schreibfaul1 para audio bluetooth (instálala desde el Gestor de Librerías)
 * 
 * Hardware:
 *   - El ESP32 envía audio digital por Bluetooth como A2DP Sink (altavoz/receptor)
 */

#include <BluetoothA2DPSink.h>    // Para recepción de audio Bluetooth

BluetoothA2DPSink a2dp_sink;   // Crea un receptor Bluetooth para audio

// Esta función se llama cuando se recibe audio por Bluetooth
void audio_data_callback(const uint8_t *data, uint32_t length){
    // Aquí puedes enviar el audio a salida I2S, PWM, o a un amplificador externo
    // En este ejemplo, la librería se encarga automáticamente si tienes un DAC/I2S
    // Si quieres usar el DAC interno, no necesitas modificar esto
}

void setup() {
  Serial.begin(115200);

  // Inicializa Bluetooth para recibir audio
  Serial.println("Iniciando Bluetooth A2DP Sink (altavoz Bluetooth)...");
  a2dp_sink.set_stream_reader(audio_data_callback);
  a2dp_sink.start("ESP32_Audio"); // El nombre que verás al emparejar como altavoz bluetooth
}

void loop() {
  // El loop puede quedar vacío.
  // Todo el procesamiento es por interrupciones del sistema y librerías.
}