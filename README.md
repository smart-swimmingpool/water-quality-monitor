# Water Quality Monitor | 🏊 Smart Swimmingpool

[![Smart Swimmingpool](https://img.shields.io/badge/%F0%9F%8F%8A%20-Smart%20Swimmingpool-blue.svg)](https://github.com/smart-swimmingpool)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

**Discussions:** <https://github.com/smart-swimmingpool/smart-swimmingpool.github.io/discussions>

---

## ⚠️ **WICHTIGER HINWEIS: MODUL IN ENTWICKLUNG**

> **⚠️ Dieses Modul befindet sich derzeit in der Entwicklungsphase und ist noch nicht funktionsfähig!**
> - Die **pH- und Chlorid-Sensoren** sind **noch nicht implementiert**. 
> - Die **Hardware** (ESP8266) und **Firmware** sind **nicht getestet**.
> - **Nicht für den Produktiveinsatz geeignet!**
>
> **🔧 Falls du an der Entwicklung mitwirken möchtest, sieh dir die [Contributing Guidelines](https://github.com/smart-swimmingpool/pool-controller/blob/main/.github/CONTRIBUTING.md) an oder erstelle ein [Issue](https://github.com/smart-swimmingpool/water-quality-monitor/issues).**

---

## 📌 Übersicht

Der **Water Quality Monitor** ist ein **ESP8266-basiertes Modul** zur Überwachung der Wasserqualität in Swimmingpools. 
Das Modul soll folgende Parameter messen:

- **pH-Wert** (Säuregrad des Wassers)
- **Chlorid** (Desinfektionsmittel)
- **Temperatur** (optional, über DS18B20)

Das Modul kommuniziert über **MQTT (Homie 3.0)** mit dem **Smart Swimmingpool Controller** oder anderen Smart-Home-Systemen (z. B. Home Assistant, openHAB).

---

## 🎯 Aktueller Status

| **Feature**               | **Status**       | **Hinweise**                                                                                     |
|--------------------------|------------------|-------------------------------------------------------------------------------------------------|
| pH-Wert messen           | ❌ Nicht implementiert | **Sensor noch nicht ausgewählt** (z. B. Atlas Scientific pH-Sensor).                     |
| Chlorid messen           | ❌ Nicht implementiert | **Sensor noch nicht ausgewählt** (z. B. Atlas Scientific ORP-Sensor).                    |
| Temperatur messen         | ⚠️ Teilweise implementiert | **DS18B20-Unterstützung** vorhanden (wie im Pool Controller).                               |
| Homie 3.0 MQTT            | ⚠️ Teilweise implementiert | **MQTT-Integration** vorhanden, aber **keine echten Sensordaten**.                     |

---

## 🛠️ Geplante Hardware

### **Empfohlene Sensoren**

| **Parameter**  | **Empfohlener Sensor**                     | **Preis (ca.)** | **Anschluss**       | **Hinweise**                                                                                     |
|---------------|-------------------------------------------|------------------|--------------------|-------------------------------------------------------------------------------------------------|
| pH-Wert       | [Atlas Scientific pH Kit](https://atlas-scientific.com/probes/ph-probe/) | 50–150€          | I2C/Analog       | **Präzise Messung, kalibrierbar.**                                                             |
| Chlorid       | [Atlas Scientific ORP Kit](https://atlas-scientific.com/probes/orp-probe/) | 50–150€          | I2C/Analog       | **Misst Redoxpotential (Chlorid-Äquivalent).**                                                  |
| Temperatur    | DS18B20 (wasserdicht)                      | 5–10€            | OneWire          | **Wie im Pool Controller.**                                                                   |

---

## 🔗 Integration in den Pool Controller

Falls du **kein separates ESP8266-Modul** verwenden möchtest, kannst du die **pH- und Chlorid-Sensoren direkt an den Pool Controller (ESP32) anschließen**.

### **Anschlussmöglichkeiten:**

| **Sensortyp**       | **Empfohlene Pins (ESP32)** | **Bibliothek**               | **Hinweise**                                                                                     |
|--------------------|-------------------------------|-----------------------------|-------------------------------------------------------------------------------------------------|
| Analoger pH-Sensor | GPIO34, GPIO35 (ADC1)          | `AnalogRead`                | **0–5V Ausgang, Skalierung erforderlich.**                                                      |
| I2C pH-Sensor      | GPIO21 (SDA), GPIO22 (SCL)    | `Wire`, `pH-Sensor-Lib`     | **I2C-Adresse prüfen!**                                                                         |
| DS18B20            | GPIO32, GPIO33                | `OneWire`, `DallasTemperature` | **Wie im Pool Controller.**                                                                   |

---

## 📊 MQTT-Integration (geplant)

Das Modul soll über **MQTT (Homie 3.0)** mit Smart-Home-Systemen kommunizieren. 
Geplante MQTT-Topics:

```
homie/water-quality-monitor/$homie → {"name": "Water Quality Monitor", "fw_version": "1.0.0", ...}
homie/water-quality-monitor/ph → 7.2
homie/water-quality-monitor/chlorine → 1.5
homie/water-quality-monitor/temperature → 25.5
```

---

## 🤝 Mitwirken

Dieses Modul **benötigt deine Hilfe**! Falls du Erfahrung mit **pH- oder Chlorid-Sensoren** hast, trage gerne bei:

1. **Implementiere die Sensor-Anbindung** (z. B. Atlas Scientific).
2. **Teste die Hardware & Firmware**.
3. **Dokumentiere die Kalibrierung der Sensoren**.

Sieh dir die [Contributing Guidelines](https://github.com/smart-swimmingpool/pool-controller/blob/main/.github/CONTRIBUTING.md) an.

---

## 📜 Lizenz

[MIT License](LICENSE) – Freie Nutzung, Modifikation und Weitergabe.