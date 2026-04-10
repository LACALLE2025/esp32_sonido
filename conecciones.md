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
Perfecto, aquí tienes un esquema y resumen de cómo conectar el ESP32, el amplificador y asegurar la tierra (GND) en ambos casos: con fuente externa y con USB.

---

### 1. **Conexión con USB**

- ESP32 recibe energía por el cable USB.
- USB conecta automáticamente la GND del ESP32 con la GND del PC.
- Solo conectas el amplificador a las salidas indicadas (GPIO25—INL, GPIO26—INR, GND—GND).
- Bluetooth funciona sin problemas, porque todo tiene referencia común de tierra.

---

### 2. **Conexión con Fuente Externa**

#### **Posibles problemas**
- Si SOLO usas la fuente externa y no unes su GND con la GND del PC/USB, el ESP32 y el ordenador no comparten referencia y el Bluetooth falla o no aparece.

#### **Solución**
- **¡Debes unir las tierras!**

#### **Opción 1:** Fuente externa + USB conectado (solo para tierra)
- Alimenta el ESP32 por VIN/3.3V y GND desde tu fuente externa.
- Conecta el USB al PC (no importa que el ESP32 no reciba energía del USB, lo importante es que une la GND del PC y del ESP32).
- Así, el Bluetooth funciona y puedes programar o comunicarte.

#### **Opción 2:** Fuente externa + manualmente unir tierras
- Alimenta el ESP32 por VIN/3.3V y GND.
- Sin USB conectado, conecta un cable desde el GND de la fuente externa (del ESP32) a la GND del PC (puedes usar el chasis metálico del PC o el blindaje del conector USB).
- Así creas una referencia común.

---

### **Esquema visual simple**

```
(Fuente Externa)              (PC)
   +-----+                      |
   |  VCC|----- ESP32 VIN       |
   |     |                      |
   |  GND|-----+------ ESP32 GND|--- USB GND (si tienes USB conectado)
   +-----+     |                |
               |                |
               +--- Amplificador GND

ESP32 GPIO25 --> Amplificador INL
ESP32 GPIO26 --> Amplificador INR
```

---

**Recuerda:**
- Solo UNE las tierras (GND), nunca conectes el +V de la fuente al USB.
- Si usas solo una fuente externa bien conectada y las tierras están unidas, el Bluetooth será visible.
- Si usas fuentes TOTALMENTE aisladas (ej. baterías independientes), entonces NO debes unir tierras y a veces Bluetooth no funcionará sin referencia común.

---

¿Quieres un diagrama gráfico, más detalles sobre la conexión, o explicación de algo específico del archivo [conecciones.md](https://github.com/LACALLE2025/esp32_sonido/blob/main/conecciones.md)?
