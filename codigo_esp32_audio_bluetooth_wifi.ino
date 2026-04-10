/*
 * Ejemplo: Salida de audio por Bluetooth con ESP32 y conexión WiFi activa
 * Requisitos:
 *   - Placa ESP32 (configurada en Arduino IDE)
 *   - Librería "ESP32-A2DP" de schreibfaul1 para audio bluetooth (instálala desde el Gestor de Librerías)
 *   - Librería "WiFi.h" (ya incluida en ESP32)
 * 
 * Hardware:
 *   - El ESP32 envía audio digital por Bluetooth como A2DP Sink (altavoz/receptor)
 */

#include <BluetoothA2DPSink.h>    // Para recepción de audio Bluetooth
#include <WiFi.h>                 // Para WiFi

// Configura tus credenciales WiFi
const char* ssid     = "TU_SSID";       // Cambia por el nombre de tu red WiFi
const char* password = "TU_PASSWORD";   // Cambia por la contraseña

BluetoothA2DPSink a2dp_sink;   // Crea un receptor Bluetooth para audio

// Esta función se llama cuando se recibe audio por Bluetooth
void audio_data_callback(const uint8_t *data, uint32_t length){
    // Aquí puedes enviar el audio a salida I2S, PWM, o a un amplificador externo
    // En este ejemplo, la librería se encarga automáticamente si tienes un DAC/I2S
    // Si quieres usar el DAC interno, no necesitas modificar esto
}

void setup() {
  Serial.begin(115200);

  // 1. Conectar a la red WiFi para mantener acceso a Internet
  Serial.println("Conectando a WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConectado a WiFi. Dirección IP: ");
  Serial.println(WiFi.localIP());

  // 2. Inicializa Bluetooth para recibir audio
  Serial.println("Iniciando Bluetooth A2DP Sink (altavoz Bluetooth)...");
  a2dp_sink.set_stream_reader(audio_data_callback);
  a2dp_sink.start("ESP32_Audio"); // El nombre que verás al emparejar como altavoz bluetooth
}

void loop() {
  // El loop puede quedar vacío.
  // Todo el procesamiento es por interrupciones del sistema y librerías.
}