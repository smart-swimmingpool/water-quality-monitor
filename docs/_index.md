---
linktitle: Water Quality Monitor
summary: ESP8266-based water quality monitoring for pH and chlorine levels in swimming pools

title: Water Quality Monitor
date: "2020-05-28"
lastmod: "2026-06-28"
draft: false
toc: true
type: docs
featured: true

menu:
  docs:
    parent: Water Quality Monitor
    name: Overview
    weight: 10

tags: ["docs", "esp8266", "sensor", "water-quality", "pH", "chlorine"]
---

<span style="text-shadow: none;">
<a class="github-button" href="https://github.com/smart-swimmingpool/water-quality-monitor/subscription" data-size="large" data-show-count="true" aria-label="Watch smart-swimmingpool/water-quality-monitor on GitHub">Watch</a>
<a class="github-button" href="https://github.com/smart-swimmingpool/water-quality-monitor" data-icon="octicon-star" data-size="large" data-show-count="true" aria-label="Star this on GitHub">Star</a><script async defer src="https://buttons.github.io/buttons.js"></script>
</span>

# Water Quality Monitor | 🏊 Smart Swimming Pool

The **Water Quality Monitor** is an **ESP8266-based device** designed to monitor the chemical quality of your swimming pool water in real-time. This module provides continuous monitoring of key water parameters to ensure safe, comfortable, and properly sanitized swimming conditions.

> **⚠️ Status: Under Development** — This module is currently in the planning and early development phase. Contributions are welcome!

## ✨ Key Features

### ✅ Planned Monitoring Capabilities

| Parameter | Range | Importance |
|-----------|-------|------------|
| **pH** | 0-14 | Affects chlorine effectiveness and swimmer comfort |
| **Chlorine** | 0-10 ppm | Primary sanitizer for killing bacteria and algae |
| **Temperature** | 0-60°C | Affects chemical reactions and swimmer comfort |

### ⚡ Integration with Smart Swimming Pool Ecosystem

- **Homie 3.0 MQTT** — Standard messaging protocol for consistency
- **Home Assistant compatible** — Future support for MQTT Discovery
- **Grafana-ready** — Data can be visualized in Grafana dashboards
- **openHAB compatible** — Works with openHAB MQTT binding

## ⚡ Why Monitor Water Quality?

### ⚡ Health & Safety

- **Prevent waterborne illnesses** — Proper sanitization kills harmful bacteria and viruses
- **Avoid chemical irritation** — Maintain proper pH to prevent skin and eye irritation
- **Ensure safe swimming conditions** — Meet health department regulations

### ⚡ Equipment Protection

- **Prevent corrosion** — Low pH can damage metal parts and pool surfaces
- **Avoid scaling** — High pH and calcium hardness can cause scale buildup
- **Extend equipment life** — Proper water chemistry protects pumps, filters, and heaters

### ⚡ Cost Savings

- **Optimize chemical usage** — Add only what's needed, when it's needed
- **Reduce water waste** — Maintain proper chemistry to minimize water replacement
- **Prevent costly repairs** — Avoid damage from improper water chemistry

### ⚡ Convenience

- **Continuous monitoring** — No more manual testing with test strips
- **Remote access** — Check water quality from anywhere via smart home system
- **Automatic alerts** — Get notified when parameters are out of range
- **Historical data** — Track trends and identify patterns over time

## ⚡ Current Status

This module is currently in the **planning and early development phase**. The following work has been completed or is in progress:

### ✅ Completed

- **Project structure** — Repository set up with PlatformIO
- **License** — MIT License for open source development
- **Initial documentation** — README and basic guides
- **Sensor research** — Identified compatible pH and chlorine sensors

### ⚡ In Progress

- **Sensor selection** — Evaluating pH and chlorine sensor options
- **Circuit design** — Planning sensor interfacing with ESP8266
- **Firmware planning** — Designing MQTT integration and sensor reading

### ⚡ Planned

- **Prototype development** — Breadboard testing of sensors and circuit
- **Firmware implementation** — Sensor reading, calibration, MQTT publishing
- **PCB design** — Custom PCB for production-ready device
- **Enclosure design** — Waterproof housing for outdoor installation
- **Field testing** — Real-world validation in pool environments
- **Documentation** — Complete user guides and troubleshooting

## ⚡ How You Can Help

This module offers many opportunities for community contributions:

### ⚡ Development

- **Sensor testing** — Test different pH and chlorine sensors with ESP8266
- **Circuit design** — Create schematic and PCB layout
- **Firmware development** — Implement sensor reading and MQTT integration
- **Calibration routines** — Develop automatic calibration procedures

### ⚡ Testing

- **Lab testing** — Validate sensor accuracy in controlled conditions
- **Field testing** — Test in actual pool environments
- **Comparison testing** — Compare readings with commercial test kits

### ⚡ Documentation

- **User guides** — Setup, calibration, and maintenance instructions
- **Troubleshooting** — Common issues and solutions
- **Best practices** — Water quality management guidelines

### ⚡ Design

- **Enclosure design** — Waterproof housing for outdoor use
- **Mounting solutions** — Sensor placement and installation methods
- **User interface** — Local display and control options

## ⚡ Getting Started with Development

If you want to contribute to the development of this module:

### ⚡ Prerequisites

- **Basic electronics knowledge** — Circuit design, soldering, troubleshooting
- **ESP8266 development experience** — PlatformIO, Arduino IDE, or similar
- **MQTT understanding** — Homie convention, topics, payloads
- **Sensor knowledge** — Analog sensors, calibration, signal conditioning

### ⚡ Development Environment Setup

```bash
# Clone the repository
git clone https://github.com/smart-swimmingpool/water-quality-monitor.git
cd water-quality-monitor

# Install PlatformIO
pip install platformio

# Install project dependencies
pio lib install

# Build the firmware
pio run
```

### ⚡ Recommended Development Board

For development and testing, we recommend:

- **WeMos D1 Mini** — Compact, breadboard-friendly, good for prototyping
- **NodeMCU** — Widely available, good documentation, more GPIO
- **ESP-12E/12F** — More GPIO, better RF performance, requires breakout board

## ⚡ Sensor Information

### ⚡ pH Sensors

We're evaluating several pH sensor options:

| Sensor | Type | Interface | Pros | Cons |
|--------|------|-----------|------|------|
| **14core pH Sensor** | Electrochemical | Analog | Affordable, BNC connector | Requires calibration |
| **Atlas Scientific pH** | Electrochemical | I2C/UART | High accuracy, robust | Expensive |
| **DFRobot pH** | Electrochemical | Analog | Good documentation | Moderate accuracy |
| **Gravitech pH** | Electrochemical | Analog | Industrial grade | Higher cost |

**Recommended:** [14core pH Sensor with BNC Probe](https://14core.com/wiring-the-ph-power-of-hydrogen-ion-concentration-sensor-with-bnc-electrode-probe/)

### ⚡ Chlorine Sensors

Chlorine sensor options under evaluation:

| Sensor | Type | Interface | Range | Pros | Cons |
|--------|------|-----------|-------|------|------|
| **Electrochemical** | Amperometric | Analog | 0-10 ppm | Direct measurement | Requires calibration, limited lifespan |
| **Optical** | Absorbance | I2C/UART | 0-10 ppm | No calibration needed | Expensive, complex |
| **DPD Colorimetric** | Chemical | Analog | 0-10 ppm | Standard method | Requires reagents, manual process |

**Note:** Chlorine sensor selection depends on budget, accuracy requirements, and maintenance preferences.

## ⚡ MQTT Integration Plan

The Water Quality Monitor will integrate with the Smart Swimming Pool ecosystem via MQTT:

### ⚡ Topic Structure (Homie 3.0)

```text
homie/water-quality-monitor/$homie
homie/water-quality-monitor/$name
homie/water-quality-monitor/$state
homie/water-quality-monitor/$nodes

homie/water-quality-monitor/ph/$type
homie/water-quality-monitor/ph/value

homie/water-quality-monitor/chlorine/$type
homie/water-quality-monitor/chlorine/value

homie/water-quality-monitor/temperature/$type
homie/water-quality-monitor/temperature/value
```

### ⚡ Example Messages

```text
# pH reading
homie/water-quality-monitor/ph/value [0m7.42

# Chlorine reading
homie/water-quality-monitor/chlorine/value [0m3.5

# Temperature reading
homie/water-quality-monitor/temperature/value [0m25.5

# Device state
homie/water-quality-monitor/$state [0mready
```

## ⚡ Water Quality Guidelines

### ⚡ Ideal Ranges for Swimming Pools

| Parameter | Ideal Range | Acceptable Range | Notes |
|-----------|-------------|------------------|-------|
| **pH** | 7.2-7.6 | 7.0-8.0 | Most important parameter |
| **Free Chlorine** | 1.0-3.0 ppm | 0.5-5.0 ppm | Primary sanitizer |
| **Total Chlorine** | 1.0-3.0 ppm | 0.5-5.0 ppm | Includes combined chlorine |
| **Alkalinity** | 80-120 ppm | 60-180 ppm | pH buffer |
| **Calcium Hardness** | 200-400 ppm | 150-1000 ppm | Prevents corrosion/scaling |
| **Cyanuric Acid** | 30-50 ppm | 0-100 ppm | Chlorine stabilizer |

### ⚡ pH Management

**Why pH is Important:**
- **Chlorine effectiveness:** Chlorine is 50% effective at pH 7.5, only 10% at pH 8.5
- **Swimmer comfort:** pH < 7.0 or > 8.0 can cause skin and eye irritation
- **Equipment protection:** Low pH can corrode metal parts, high pH can cause scaling
- **Water clarity:** Proper pH helps maintain clear, sparkling water

**Adjusting pH:**
- **To raise pH:** Add **soda ash** (sodium carbonate)
- **To lower pH:** Add **muriatic acid** or **sodium bisulfate**
- **Always add chemicals slowly** and retest frequently
- **Wait 4-6 hours** between adjustments

### ⚡ Chlorine Management

**Why Chlorine is Important:**
- **Sanitization:** Kills bacteria, viruses, and algae
- **Oxidation:** Breaks down organic contaminants
- **Residual protection:** Maintains sanitization between additions

**Chlorine Types:**
- **Liquid chlorine** (Sodium hypochlorite) — Fast acting, no cyanuric acid
- **Chlorine tablets** (Trichloroisocyanuric acid) — Slow dissolving, contains cyanuric acid
- **Chlorine granules** (Calcium hypochlorite) — Fast dissolving, adds calcium
- **Salt water generator** — Produces chlorine from salt (sodium chloride)

## ⚡ Resources

### ⚡ Documentation

- [Hardware Guide](hardware-guide.md) — Parts list and circuit information
- [pH Sensor Datasheet](14core.com-Wiring%20The%20pH%20Power%20of%20Hydrogen%20Ion%20Concentration%20Sensor%20with%20BNC%20Electrode%20Probe.pdf) — Technical specifications

### ⚡ External Resources

- [CDC Healthy Swimming](https://www.cdc.gov/healthywater/swimming/index.html) — Pool water quality guidelines
- [WHO Water Quality Guidelines](https://www.who.int/water_sanitation_health/dwq/en/) — International standards
- [EPA Pool Water Quality](https://www.epa.gov/ground-water-and-drinking-water/national-primary-drinking-water-regulations) — Regulations and guidelines
- [pH Calibration Guide](https://www.phionics.com/ph-calibration/) — Calibration procedures

### ⚡ Community

- [GitHub Discussions](https://github.com/smart-swimmingpool/smart-swimmingpool.github.io/discussions) — Ask questions and share ideas
- [Smart Swimming Pool Website](https://smart-swimmingpool.com) — Project documentation

## ⚡ Contributing

We welcome contributions to this module! Please see the [main README](https://github.com/smart-swimmingpool/water-quality-monitor#contributing) for information on how to contribute.

### ⚡ Current Contribution Opportunities

1. **Sensor research and testing** — Help evaluate different pH and chlorine sensors
2. **Circuit design** — Create schematic and PCB layout
3. **Firmware development** — Implement sensor reading and MQTT integration
4. **Documentation** — Write user guides and troubleshooting
5. **Testing** — Validate performance in real pool environments

---

<p align="center">
  Help us make pool water monitoring smarter! ❤️
</p>
