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

# Water Quality Monitor | \ud83c\udfca Smart Swimming Pool

The **Water Quality Monitor** is an **ESP8266-based device** designed to monitor the chemical quality of your swimming pool water in real-time. This module provides continuous monitoring of key water parameters to ensure safe, comfortable, and properly sanitized swimming conditions.

> **\u26a0\ufe0f Status: Under Development** \u2014 This module is currently in the planning and early development phase. Contributions are welcome!

## \u2728 Key Features

### \u2705 Planned Monitoring Capabilities

| Parameter | Range | Importance |
|-----------|-------|------------|
| **pH** | 0-14 | Affects chlorine effectiveness and swimmer comfort |
| **Chlorine** | 0-10 ppm | Primary sanitizer for killing bacteria and algae |
| **Temperature** | 0-60\u00b0C | Affects chemical reactions and swimmer comfort |

### \u26a1 Integration with Smart Swimming Pool Ecosystem

- **Homie 3.0 MQTT** \u2014 Standard messaging protocol for consistency
- **Home Assistant compatible** \u2014 Future support for MQTT Discovery
- **Grafana-ready** \u2014 Data can be visualized in Grafana dashboards
- **openHAB compatible** \u2014 Works with openHAB MQTT binding

## \u26a1 Why Monitor Water Quality?

### \u26a1 Health & Safety

- **Prevent waterborne illnesses** \u2014 Proper sanitization kills harmful bacteria and viruses
- **Avoid chemical irritation** \u2014 Maintain proper pH to prevent skin and eye irritation
- **Ensure safe swimming conditions** \u2014 Meet health department regulations

### \u26a1 Equipment Protection

- **Prevent corrosion** \u2014 Low pH can damage metal parts and pool surfaces
- **Avoid scaling** \u2014 High pH and calcium hardness can cause scale buildup
- **Extend equipment life** \u2014 Proper water chemistry protects pumps, filters, and heaters

### \u26a1 Cost Savings

- **Optimize chemical usage** \u2014 Add only what's needed, when it's needed
- **Reduce water waste** \u2014 Maintain proper chemistry to minimize water replacement
- **Prevent costly repairs** \u2014 Avoid damage from improper water chemistry

### \u26a1 Convenience

- **Continuous monitoring** \u2014 No more manual testing with test strips
- **Remote access** \u2014 Check water quality from anywhere via smart home system
- **Automatic alerts** \u2014 Get notified when parameters are out of range
- **Historical data** \u2014 Track trends and identify patterns over time

## \u26a1 Current Status

This module is currently in the **planning and early development phase**. The following work has been completed or is in progress:

### \u2705 Completed

- **Project structure** \u2014 Repository set up with PlatformIO
- **License** \u2014 MIT License for open source development
- **Initial documentation** \u2014 README and basic guides
- **Sensor research** \u2014 Identified compatible pH and chlorine sensors

### \u26a1 In Progress

- **Sensor selection** \u2014 Evaluating pH and chlorine sensor options
- **Circuit design** \u2014 Planning sensor interfacing with ESP8266
- **Firmware planning** \u2014 Designing MQTT integration and sensor reading

### \u26a1 Planned

- **Prototype development** \u2014 Breadboard testing of sensors and circuit
- **Firmware implementation** \u2014 Sensor reading, calibration, MQTT publishing
- **PCB design** \u2014 Custom PCB for production-ready device
- **Enclosure design** \u2014 Waterproof housing for outdoor installation
- **Field testing** \u2014 Real-world validation in pool environments
- **Documentation** \u2014 Complete user guides and troubleshooting

## \u26a1 How You Can Help

This module offers many opportunities for community contributions:

### \u26a1 Development

- **Sensor testing** \u2014 Test different pH and chlorine sensors with ESP8266
- **Circuit design** \u2014 Create schematic and PCB layout
- **Firmware development** \u2014 Implement sensor reading and MQTT integration
- **Calibration routines** \u2014 Develop automatic calibration procedures

### \u26a1 Testing

- **Lab testing** \u2014 Validate sensor accuracy in controlled conditions
- **Field testing** \u2014 Test in actual pool environments
- **Comparison testing** \u2014 Compare readings with commercial test kits

### \u26a1 Documentation

- **User guides** \u2014 Setup, calibration, and maintenance instructions
- **Troubleshooting** \u2014 Common issues and solutions
- **Best practices** \u2014 Water quality management guidelines

### \u26a1 Design

- **Enclosure design** \u2014 Waterproof housing for outdoor use
- **Mounting solutions** \u2014 Sensor placement and installation methods
- **User interface** \u2014 Local display and control options

## \u26a1 Getting Started with Development

If you want to contribute to the development of this module:

### \u26a1 Prerequisites

- **Basic electronics knowledge** \u2014 Circuit design, soldering, troubleshooting
- **ESP8266 development experience** \u2014 PlatformIO, Arduino IDE, or similar
- **MQTT understanding** \u2014 Homie convention, topics, payloads
- **Sensor knowledge** \u2014 Analog sensors, calibration, signal conditioning

### \u26a1 Development Environment Setup

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

### \u26a1 Recommended Development Board

For development and testing, we recommend:

- **WeMos D1 Mini** \u2014 Compact, breadboard-friendly, good for prototyping
- **NodeMCU** \u2014 Widely available, good documentation, more GPIO
- **ESP-12E/12F** \u2014 More GPIO, better RF performance, requires breakout board

## \u26a1 Sensor Information

### \u26a1 pH Sensors

We're evaluating several pH sensor options:

| Sensor | Type | Interface | Pros | Cons |
|--------|------|-----------|------|------|
| **14core pH Sensor** | Electrochemical | Analog | Affordable, BNC connector | Requires calibration |
| **Atlas Scientific pH** | Electrochemical | I2C/UART | High accuracy, robust | Expensive |
| **DFRobot pH** | Electrochemical | Analog | Good documentation | Moderate accuracy |
| **Gravitech pH** | Electrochemical | Analog | Industrial grade | Higher cost |

**Recommended:** [14core pH Sensor with BNC Probe](https://14core.com/wiring-the-ph-power-of-hydrogen-ion-concentration-sensor-with-bnc-electrode-probe/)

### \u26a1 Chlorine Sensors

Chlorine sensor options under evaluation:

| Sensor | Type | Interface | Range | Pros | Cons |
|--------|------|-----------|-------|------|------|
| **Electrochemical** | Amperometric | Analog | 0-10 ppm | Direct measurement | Requires calibration, limited lifespan |
| **Optical** | Absorbance | I2C/UART | 0-10 ppm | No calibration needed | Expensive, complex |
| **DPD Colorimetric** | Chemical | Analog | 0-10 ppm | Standard method | Requires reagents, manual process |

**Note:** Chlorine sensor selection depends on budget, accuracy requirements, and maintenance preferences.

## \u26a1 MQTT Integration Plan

The Water Quality Monitor will integrate with the Smart Swimming Pool ecosystem via MQTT:

### \u26a1 Topic Structure (Homie 3.0)

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

### \u26a1 Example Messages

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

## \u26a1 Water Quality Guidelines

### \u26a1 Ideal Ranges for Swimming Pools

| Parameter | Ideal Range | Acceptable Range | Notes |
|-----------|-------------|------------------|-------|
| **pH** | 7.2-7.6 | 7.0-8.0 | Most important parameter |
| **Free Chlorine** | 1.0-3.0 ppm | 0.5-5.0 ppm | Primary sanitizer |
| **Total Chlorine** | 1.0-3.0 ppm | 0.5-5.0 ppm | Includes combined chlorine |
| **Alkalinity** | 80-120 ppm | 60-180 ppm | pH buffer |
| **Calcium Hardness** | 200-400 ppm | 150-1000 ppm | Prevents corrosion/scaling |
| **Cyanuric Acid** | 30-50 ppm | 0-100 ppm | Chlorine stabilizer |

### \u26a1 pH Management

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

### \u26a1 Chlorine Management

**Why Chlorine is Important:**
- **Sanitization:** Kills bacteria, viruses, and algae
- **Oxidation:** Breaks down organic contaminants
- **Residual protection:** Maintains sanitization between additions

**Chlorine Types:**
- **Liquid chlorine** (Sodium hypochlorite) \u2014 Fast acting, no cyanuric acid
- **Chlorine tablets** (Trichloroisocyanuric acid) \u2014 Slow dissolving, contains cyanuric acid
- **Chlorine granules** (Calcium hypochlorite) \u2014 Fast dissolving, adds calcium
- **Salt water generator** \u2014 Produces chlorine from salt (sodium chloride)

## \u26a1 Resources

### \u26a1 Documentation

- [Hardware Guide](hardware-guide.md) \u2014 Parts list and circuit information
- [pH Sensor Datasheet](14core.com-Wiring%20The%20pH%20Power%20of%20Hydrogen%20Ion%20Concentration%20Sensor%20with%20BNC%20Electrode%20Probe.pdf) \u2014 Technical specifications

### \u26a1 External Resources

- [CDC Healthy Swimming](https://www.cdc.gov/healthywater/swimming/index.html) \u2014 Pool water quality guidelines
- [WHO Water Quality Guidelines](https://www.who.int/water_sanitation_health/dwq/en/) \u2014 International standards
- [EPA Pool Water Quality](https://www.epa.gov/ground-water-and-drinking-water/national-primary-drinking-water-regulations) \u2014 Regulations and guidelines
- [pH Calibration Guide](https://www.phionics.com/ph-calibration/) \u2014 Calibration procedures

### \u26a1 Community

- [GitHub Discussions](https://github.com/smart-swimmingpool/smart-swimmingpool.github.io/discussions) \u2014 Ask questions and share ideas
- [Smart Swimming Pool Website](https://smart-swimmingpool.com) \u2014 Project documentation

## \u26a1 Contributing

We welcome contributions to this module! Please see the [main README](https://github.com/smart-swimmingpool/water-quality-monitor#contributing) for information on how to contribute.

### \u26a1 Current Contribution Opportunities

1. **Sensor research and testing** \u2014 Help evaluate different pH and chlorine sensors
2. **Circuit design** \u2014 Create schematic and PCB layout
3. **Firmware development** \u2014 Implement sensor reading and MQTT integration
4. **Documentation** \u2014 Write user guides and troubleshooting
5. **Testing** \u2014 Validate performance in real pool environments

---

<p align="center">
  Help us make pool water monitoring smarter! \u2764\ufe0f
</p>
