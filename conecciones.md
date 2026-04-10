# Conexión ESP32 a Amplificador M562 (Estéreo)

| ESP32   | M562 Amplificador  |
|---------|--------------------|
| GPIO25  | INL (o L IN)       |
| GPIO26  | INR (o R IN)       |
| GND     | GND                |

**Notas:**
- GPIO25 y GPIO26 del ESP32 son las salidas DAC1 y DAC2 (izquierdo y derecho).
- No juntes ambos canales directamente.
- Usa GND común para ambos módulos.
