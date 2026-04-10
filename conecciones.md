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


**Nota sobre alimentación y tierra (GND):**

Si el ESP32 y el amplificador M562 se alimentan con voltajes distintos (por ejemplo, 3.3V y 5V/12V), **debes conectar las GNDs de ambas fuentes de alimentación** para asegurar que haya una referencia común de señal.
- No conectes las líneas positivas (VCC) entre sí; solo comparte la GND.
- Compartir la GND asegura que la señal de audio se transmita correctamente y evita ruidos o posibles daños.
- Si usas baterías completamente independientes y aisladas, NO conectes las GND.
