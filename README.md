# Water Quality Monitor | 🏊 Smart Swimming Pool

[![Smart Swimmingpool](https://img.shields.io/badge/%F0%9F%8F%8A%20-Smart%20Swimmingpool-blue.svg)](https://github.com/smart-swimmingpool)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

---

> **⚠️ WARNING: This project involves water chemistry and electrical measurements!**
>
> - **Handle chemical sensors with care** — Some sensors may require calibration with chemical solutions
> - **Follow sensor manufacturer instructions** for proper handling and maintenance
> - **Keep electronics away from water** — Use waterproof enclosures for outdoor installation
> - **This project is NOT certified for commercial use. For personal use only!**

---

## ✨ Overview

The **Water Quality Monitor** is an **ESP8266-based circuit** designed to monitor the chemical quality of your swimming pool water. It provides real-time measurements of key water parameters to ensure safe and comfortable swimming conditions.

**Current Status:** 👢 **Under Development** — This module is in the planning and early development phase.

---

## ✨ Features

### ✅ Planned Features

| Feature | Description | Status |
|---------|-------------|--------|
| **pH Monitoring** | Measure water pH level (0-14 scale) | 📰 Planned |
| **Chlorine Monitoring** | Measure chlorine concentration | 📰 Planned |
| **Homie 3.0 Compatibility** | Standard MQTT messaging protocol | 📰 Planned |
| **Display Integration** | Local display for readings | 📰 Planned |

### ⚡ Future Enhancements

- [ ] **Temperature compensation** for pH readings
- [ ] **Automatic calibration** routines
- [ ] **Alert thresholds** for abnormal values
- [ ] **Data logging** and historical trends
- [ ] **Multiple sensor support** (pH, chlorine, ORP, etc.)
- [ ] **Home Assistant MQTT Discovery** integration
- [ ] **Battery-powered operation** with deep sleep
- [ ] **Solar-powered option** for autonomous operation

---

## ⚡ Hardware Overview

### 💻 Required Parts (BOM)

| # | Component | Qty | Approx. Cost | Notes | Recommended Links |
|---|-----------|:---:|:------------:|-------|------------------|
| 1 | ESP8266 Development Board | 1 | 5–10€ | NodeMCU or WeMos D1 Mini | [Amazon](https://amzn.to/2DPf0LJ), [AliExpress](https://www.aliexpress.com/) |
| 2 | pH Sensor with BNC Probe | 1 | 20–50€ | 0-14 pH range, BNC connector | [AliExpress](https://www.aliexpress.com/item/32797327021.html), [14core](https://14core.com/) |
| 3 | Chlorine Sensor | 1 | 30–80€ | Optional, for chlorine monitoring | Various suppliers |
| 4 | ADC Module (optional) | 1 | 2–5€ | For higher precision analog readings | [AliExpress](https://www.aliexpress.com/) |
| 5 | Waterproof Enclosure | 1 | 10–20€ | IP65+ for outdoor use | [Amazon](https://www.amazon.de/s?k=IP65+Gehäuse) |
| 6 | Calibration Solutions | 2 | 10–20€ | pH 4.0 and pH 7.0 for calibration | [Amazon](https://www.amazon.de/s?k=pH+calibration+solution) |
| **Total** | | | **~80–180€** | Without chlorine sensor | |

### ⚡ ESP8266 Board Options

| Board | Pros | Cons | Recommended |
|-------|------|------|-------------|
| **NodeMCU** | Widely available, good documentation | Larger size | ✅ Yes |
| **WeMos D1 Mini** | Compact, breadboard-friendly | Limited GPIO | ✅ Yes |
| **ESP-12E/12F** | More GPIO, better RF performance | Requires breakout board | ✅ Yes |

**Pinout References:**
- [NodeMCU Pinout](https://nodemcu.readthedocs.io/en/release/pinout/)
- [WeMos D1 Mini Pinout](https://wiki.wemos.cc/products:d1:d1_mini)
- [ESP8266 Pinout Diagram](docs/ESP8266-ESP-12E-chip-pinout-gpio-pin.png)
- [WeMos D1 Mini Pinout](docs/ESP8266-WeMos-D1-Mini-pinout-gpio-pin.png)

---

## ⚡ Sensor Information

### 🌐 pH Sensor

**Specifications:**
- **Range:** 0-14 pH
- **Resolution:** 0.01 pH
- **Accuracy:** ±0.1 pH
- **Response Time:** < 1 minute
- **Temperature Range:** 0-60°C
- **Connector:** BNC
- **Output:** Analog voltage (0-3.3V or 0-5V depending on module)

**Recommended Sensor:**
- **14core pH Sensor Board** with BNC Electrode Probe
- Includes: pH electrode, BNC connector, signal conditioning circuit
- [Product Page](https://14core.com/wiring-the-ph-power-of-hydrogen-ion-concentration-sensor-with-bnc-electrode-probe/)
- [Datasheet](docs/14core.com-Wiring%20The%20pH%20Power%20of%20Hydrogen%20Ion%20Concentration%20Sensor%20with%20BNC%20Electrode%20Probe.pdf)

**Wiring:**
```text
ESP8266 (3.3V)  pH Sensor VCC
ESP8266 GND  pH Sensor GND
ESP8266 A0  pH Sensor Output (analog)
```

**Calibration:**
- Use **pH 4.0** and **pH 7.0** calibration solutions
- Calibrate before first use and periodically (every 1-2 months)
- Follow manufacturer calibration procedure

**Maintenance:**
- **Store electrode wet** when not in use (use storage solution)
- **Clean electrode** regularly with storage solution
- **Replace electrode** every 1-2 years (depending on usage)
- **Avoid touching** the glass membrane

### ⚡ Chlorine Sensor (Optional)

**Specifications (typical):**
- **Range:** 0-10 ppm (free chlorine)
- **Resolution:** 0.1 ppm
- **Accuracy:** ±0.5 ppm
- **Response Time:** < 2 minutes
- **Output:** Analog voltage or digital (I2C/UART)

**Sensor Types:**
1. **Electrochemical sensors** — Most common, require regular calibration
2. **Optical sensors** — More expensive, less maintenance
3. **DPD colorimetric** — Chemical test method, manual or automated

**Note:** Chlorine sensor selection depends on your specific requirements and budget. Research compatible sensors for ESP8266.

---

## ⚡ Circuit Design

### ⚡ Basic Circuit (pH Only)

```text
ESP8266 Development Board
   
   3.3V [ pH Sensor VCC ]
   GND [ pH Sensor GND ]
   A0  [ pH Sensor Output ]
   
   pH Sensor Board
   
   BNC Connector [ pH Electrode Probe ]
```

### ⚡ Advanced Circuit (pH + Chlorine)

```text
ESP8266 Development Board
   
   3.3V [ pH Sensor VCC ]
   3.3V [ Chlorine Sensor VCC ]
   GND [ pH Sensor GND ]
   GND [ Chlorine Sensor GND ]
   A0  [ pH Sensor Output ]
   D2  [ Chlorine Sensor SDA ] (if I2C)
   D1  [ Chlorine Sensor SCL ] (if I2C)
   
   Optional: External ADC Module
   
   3.3V [ ADC VCC ]
   GND [ ADC GND ]
   A0  [ ADC Input 0 ]  pH Sensor
   D1  [ ADC SDA ]
   D2  [ ADC SCL ]
```

### ⚡ Pin Assignment (WeMos D1 Mini)

| Sensor | ESP8266 Pin | WeMos D1 Pin | Notes |
|--------|-------------|--------------|-------|
| pH Sensor VCC | 3.3V | 3V3 | Power |
| pH Sensor GND | GND | G | Ground |
| pH Sensor Output | A0 | A0 | Analog input |
| Chlorine Sensor SDA | GPIO4 | D2 | I2C Data (if I2C) |
| Chlorine Sensor SCL | GPIO5 | D1 | I2C Clock (if I2C) |
| Chlorine Sensor Output | A0 | A0 | Analog (if analog) |

**Note:** If using both pH and chlorine sensors with analog output, consider using an **external ADC module** (e.g., ADS1115) for better precision and to avoid ESP8266 ADC limitations.

---

## ⚡ MQTT Integration

### ⚡ Homie 3.0 Convention

The Water Quality Monitor will follow the **Homie 3.0** MQTT convention for consistency with other Smart Swimming Pool modules.

**Base Topic:** `homie/water-quality-monitor/`

**Device Information:**
```text
homie/water-quality-monitor/$homie
homie/water-quality-monitor/$name
homie/water-quality-monitor/$state
homie/water-quality-monitor/$nodes
```

**Node Structure:**
```text
homie/water-quality-monitor/ph/$type
homie/water-quality-monitor/ph/$name
homie/water-quality-monitor/ph/$properties

homie/water-quality-monitor/ph/value

homie/water-quality-monitor/chlorine/$type
homie/water-quality-monitor/chlorine/$name
homie/water-quality-monitor/chlorine/$properties

homie/water-quality-monitor/chlorine/value
```

### ⚡ MQTT Topics

**State Topics:**
```text
# Device State
homie/water-quality-monitor/$state

# pH Sensor
homie/water-quality-monitor/ph/value

# Chlorine Sensor (if installed)
homie/water-quality-monitor/chlorine/value

# Status
homie/water-quality-monitor/status
```

**Example Messages:**
```text
# pH reading
homie/water-quality-monitor/ph/value [0m7.42

# Chlorine reading
homie/water-quality-monitor/chlorine/value [0m3.5

# Device state
homie/water-quality-monitor/$state [0mready

# Status message
homie/water-quality-monitor/status [0m{"pH":7.42,"chlorine":3.5,"temperature":25.5}
```

---

## ⚡ Software Development

### ⚡ PlatformIO Setup

```bash
# Clone the repository
git clone https://github.com/smart-swimmingpool/water-quality-monitor.git
cd water-quality-monitor

# Build the firmware
pio run

# Flash to device
pio run --target upload

# Monitor serial output
pio run --target monitor
```

**Platform:** ESP8266 (WeMos D1 Mini or NodeMCU)

### ⚡ Required Libraries

| Library | Purpose | Install Command |
|---------|---------|-----------------|
| Homie for ESP8266 | MQTT framework | `pio lib install homieiot` |
| OneWire | Sensor communication | `pio lib install OneWire` |
| DallasTemperature | Temperature sensors | `pio lib install DallasTemperature` |
| ArduinoJson | JSON processing | `pio lib install ArduinoJson` |
| ESP8266WiFi | WiFi connectivity | Built-in |
| PubSubClient | MQTT client | `pio lib install PubSubClient` |

### ⚡ Project Structure

```text
water-quality-monitor/
 src/
    main.cpp              # Main firmware
    config.h              # Configuration and pin definitions
    sensors.cpp           # Sensor reading functions
    mqtt.cpp              # MQTT handling
    calibration.cpp       # Sensor calibration routines
    
 lib/                      # External libraries
 platformio.ini          # Build configuration
 README.md               # This file
 LICENSE                 # License information
```

---

## ⚡ Calibration Procedures

### ⚡ pH Sensor Calibration

**Required Materials:**
- pH 4.0 calibration solution
- pH 7.0 calibration solution
- Distilled water for rinsing
- Clean containers

**Calibration Steps:**

1. **Prepare sensor:**
   - Remove protective cap from pH electrode
   - Rinse electrode with distilled water
   - Place in pH 7.0 solution

2. **First calibration point (pH 7.0):**
   - Wait 1-2 minutes for stable reading
   - Send calibration command: `CALIBRATE,7.0` via serial or MQTT
   - Confirm calibration successful

3. **Rinse and dry:**
   - Rinse electrode with distilled water
   - Blot dry with clean tissue (don't rub)

4. **Second calibration point (pH 4.0):**
   - Place electrode in pH 4.0 solution
   - Wait 1-2 minutes for stable reading
   - Send calibration command: `CALIBRATE,4.0` via serial or MQTT
   - Confirm calibration successful

5. **Finalize calibration:**
   - Rinse electrode with distilled water
   - Store electrode in storage solution or pH 7.0 buffer

**Calibration Frequency:**
- **Before first use** — Mandatory
- **Every 1-2 months** — Regular maintenance
- **After long storage** — If stored dry for > 1 week
- **If readings seem inaccurate** — Troubleshooting

### ⚡ Chlorine Sensor Calibration (if applicable)

**Calibration depends on sensor type:**

1. **Electrochemical sensors:**
   - Use **0 ppm** and **10 ppm** calibration solutions
   - Follow manufacturer procedure
   - Typically requires 2-point calibration

2. **Optical sensors:**
   - Usually factory calibrated
   - May require periodic verification

3. **DPD colorimetric:**
   - Calibrate with known chlorine standards
   - Follow chemical test procedure

---

## ⚡ Installation & Deployment

### ⚡ Enclosure Requirements

**For outdoor installation:**
- **IP65+ rating** — Protection from water and dust
- **Ventilation** — Prevent condensation buildup
- **Cable glands** — For waterproof cable entry
- **Mounting options** — Wall or pole mounting

**Recommended enclosures:**
- **ABS plastic** — Good chemical resistance
- **Polycarbonate** — Impact resistant, UV stable
- **Stainless steel** — Most durable, expensive

### ⚡ Sensor Placement

**pH Sensor:**
- **Location:** In pool water, away from returns and skimmers
- **Depth:** 30-50 cm below surface
- **Mounting:** Use sensor holder or weighted base
- **Cable:** Waterproof cable to enclosure

**Chlorine Sensor (if installed):**
- **Location:** Similar to pH sensor
- **Considerations:** May need separate enclosure if using DPD method

**General Tips:**
- **Avoid direct sunlight** on sensors
- **Keep sensors submerged** at all times
- **Protect from physical damage**
- **Ensure good water circulation** around sensors

### ⚡ Wiring Tips

1. **Use waterproof connectors** for all outdoor connections
2. **Label all wires** for easy maintenance
3. **Use shielded cable** for analog sensor signals
4. **Keep cable runs short** to minimize signal interference
5. **Avoid running sensor cables** parallel to power cables

---

## ⚡ Maintenance

### ⚡ Regular Maintenance Schedule

| Task | Frequency | Notes |
|------|-----------|-------|
| **Clean pH electrode** | Weekly | Rinse with storage solution |
| **Calibrate pH sensor** | Monthly | Use pH 4.0 and 7.0 solutions |
| **Check chlorine sensor** | Monthly | Verify readings with test strips |
| **Inspect enclosure** | Monthly | Check for water ingress, condensation |
| **Test MQTT connection** | Monthly | Verify data is being published |
| **Replace pH electrode** | Annually | Or when readings become unreliable |
| **Replace calibration solutions** | Every 3-6 months | Or when contaminated |

### ⚡ Troubleshooting

| Issue | Possible Cause | Solution |
|-------|---------------|----------|
| **pH readings unstable** | Dirty electrode | Clean electrode with storage solution |
| **pH readings inaccurate** | Needs calibration | Recalibrate with pH 4.0 and 7.0 |
| **pH readings drift** | Old electrode | Replace electrode |
| **No MQTT messages** | WiFi connection issue | Check WiFi credentials and signal |
| **MQTT connected but no data** | Sensor wiring issue | Check sensor connections |
| **Sensor not responding** | Power issue | Check power supply to sensor |
| **Condensation in enclosure** | Poor ventilation | Add ventilation or desiccant |

### ⚡ Storage

**Short-term storage (days to weeks):**
- Store pH electrode **wet** in storage solution or pH 7.0 buffer
- Keep chlorine sensor **dry** (if applicable)
- Store in **cool, dry place**

**Long-term storage (months):**
- Clean and calibrate pH electrode before storage
- Store pH electrode **wet** in storage solution
- Remove batteries if applicable
- Store in **sealed container** with desiccant

---

## ⚡ Safety Considerations

### ⚠️ Electrical Safety

- **Use low voltage (3.3V/5V)** for all electronics
- **Keep electronics dry** — Use waterproof enclosures
- **Use waterproof connectors** for all outdoor connections
- **Ground all metal parts** if possible
- **Use RCD/FI protection** for any mains-powered components

### ⚠️ Chemical Safety

- **Handle calibration solutions with care** — Some may be corrosive
- **Wear gloves** when handling sensors and solutions
- **Avoid skin contact** with calibration solutions
- **Rinse with water** if solution contacts skin
- **Dispose of old solutions properly** — Follow local regulations

### ⚠️ Pool Safety

- **Do not rely solely on this monitor** for pool safety
- **Regularly test water manually** with test strips or kits
- **Follow local health department guidelines** for pool water quality
- **Keep pool chemicals properly stored** and labeled
- **Never mix chemicals** — Can cause dangerous reactions

---

## ⚡ Water Quality Guidelines

### ⚡ Recommended Ranges

| Parameter | Ideal Range | Acceptable Range | Notes |
|-----------|-------------|------------------|-------|
| **pH** | 7.2-7.6 | 7.0-8.0 | Affects chlorine effectiveness |
| **Free Chlorine** | 1.0-3.0 ppm | 0.5-5.0 ppm | Sanitization |
| **Total Chlorine** | 1.0-3.0 ppm | 0.5-5.0 ppm | Includes combined chlorine |
| **Bromine** | 2.0-4.0 ppm | 1.0-6.0 ppm | Alternative to chlorine |
| **Alkalinity** | 80-120 ppm | 60-180 ppm | pH buffer |
| **Calcium Hardness** | 200-400 ppm | 150-1000 ppm | Prevents corrosion/scaling |
| **Cyanuric Acid** | 30-50 ppm | 0-100 ppm | Chlorine stabilizer |
| **Total Dissolved Solids (TDS)** | < 2000 ppm | < 5000 ppm | Water replacement indicator |

### ⚡ pH Importance

**Why pH matters:**
- **Chlorine effectiveness:** Chlorine is most effective at pH 7.2-7.6
- **Swimmer comfort:** pH outside 7.2-7.8 can cause skin/eye irritation
- **Equipment protection:** Low pH (acidic) can corrode metal parts
- **Water clarity:** Proper pH helps maintain clear water

**pH Adjustment:**
- **To raise pH:** Add soda ash (sodium carbonate)
- **To lower pH:** Add muriatic acid or sodium bisulfate
- **Always add chemicals slowly** and retest frequently

### ⚡ Chlorine Importance

**Why chlorine matters:**
- **Sanitization:** Kills bacteria, algae, and other contaminants
- **Oxidation:** Breaks down organic matter
- **Residual effect:** Maintains protection between additions

**Chlorine Types:**
- **Liquid chlorine** — Sodium hypochlorite, fast acting
- **Chlorine tablets** — Slow dissolving, stabilized
- **Chlorine granules** — Fast dissolving, unstabilized
- **Salt water generator** — Produces chlorine from salt

---

## 🤝 Contributing

We welcome contributions! This module is currently in the **planning and early development phase**, so there are many opportunities to help.

### ⚡ How You Can Help

1. **Research sensors** — Find compatible pH and chlorine sensors
2. **Test sensor accuracy** — Compare readings with commercial test kits
3. **Develop calibration routines** — Implement automatic calibration
4. **Design circuit** — Create schematic and PCB layout
5. **Write firmware** — Implement sensor reading and MQTT publishing
6. **Test in real conditions** — Validate performance in actual pool environments
7. **Improve documentation** — Help create guides and tutorials

### ⚡ Development Roadmap

| Phase | Tasks | Status |
|-------|-------|--------|
| **Phase 1: Research** | Sensor selection, compatibility testing | 👢 In Progress |
| **Phase 2: Prototyping** | Breadboard testing, basic firmware | 📰 Planned |
| **Phase 3: Circuit Design** | Schematic, PCB design | 📰 Planned |
| **Phase 4: Firmware** | Sensor reading, MQTT integration | 📰 Planned |
| **Phase 5: Testing** | Lab testing, field testing | 📰 Planned |
| **Phase 6: Documentation** | User guides, troubleshooting | 📰 Planned |

---

## 📜 License

[MIT License](LICENSE) – Free to use, modify, and share.

---

## 🌐 Community & Support

- **Discussions:** [GitHub Discussions](https://github.com/smart-swimmingpool/smart-swimmingpool.github.io/discussions)
- **Website:** [smart-swimmingpool.com](https://smart-swimmingpool.com)

**Need Help?**
1. Check this README for information
2. Search [GitHub Discussions](https://github.com/smart-swimmingpool/smart-swimmingpool.github.io/discussions)
3. Open a [new issue](https://github.com/smart-swimmingpool/water-quality-monitor/issues/new)

---

## 📢 Related Projects

| Project | Description |
|---------|-------------|
| [Pool Controller](https://github.com/smart-swimmingpool/pool-controller) | Main control unit with MQTT integration |
| [Pool Monitor](https://github.com/smart-swimmingpool/monitor) | Solar-powered wireless temperature display |
| [Grafana Dashboard](https://github.com/smart-swimmingpool/grafana-dashboard) | Visualization dashboard |
| [openHAB Config](https://github.com/smart-swimmingpool/openhab-config) | openHAB configuration files |
| [Website](https://github.com/smart-swimmingpool/website) | Project documentation website |

---

## 💻 Additional Resources

### Sensors
- [14core pH Sensor](https://14core.com/wiring-the-ph-power-of-hydrogen-ion-concentration-sensor-with-bnc-electrode-probe/) — Recommended pH sensor
- [Atlas Scientific](https://www.atlas-scientific.com/) — High-quality water quality sensors
- [DFRobot](https://www.dfrobot.com/) — Various water quality sensors
- [Gravitech](https://www.gravitech.us/) — pH and ORP sensors

### ESP8266
- [ESP8266 Documentation](https://www.espressif.com/en/products/hardware/esp8266ex/overview) — Official docs
- [NodeMCU Documentation](https://nodemcu.readthedocs.io/) — NodeMCU firmware
- [WeMos D1 Mini](https://wiki.wemos.cc/products:d1:d1_mini) — Board information

### MQTT
- [MQTT Protocol](https://mqtt.org/) — MQTT specification
- [Homie for ESP8266](https://github.com/homieiot/homie-esp8266) — MQTT framework
- [PubSubClient](https://pubsubclient.knolleary.net/) — MQTT client library

### Water Quality
- [CDC Healthy Swimming](https://www.cdc.gov/healthywater/swimming/index.html) — Pool water quality guidelines
- [WHO Water Quality Guidelines](https://www.who.int/water_sanitation_health/dwq/en/) — Water quality standards
- [EPA Pool Water Quality](https://www.epa.gov/ground-water-and-drinking-water/national-primary-drinking-water-regulations) — Regulations and guidelines

### Calibration
- [pH Calibration Guide](https://www.phionics.com/ph-calibration/) — pH sensor calibration
- [Calibration Solutions](https://www.thermofisher.com/us/en/home/life-science/lab-chemicals/ph-buffers-ph-electrodes/ph-buffers.html) — pH buffer solutions

---

<p align="center">
  Made with ❤️ by the Smart Swimming Pool community
</p>
