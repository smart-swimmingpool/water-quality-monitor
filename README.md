# Water Quality Monitor | Smart Swimmingpool

[![Smart Swimmingpool](https://img.shields.io/badge/Smart%20Swimmingpool-blue.svg)](https://github.com/smart-swimmingpool)

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/J3J33A8DT)

Discussions: <https://github.com/smart-swimmingpool/smart-swimmingpool.github.io/discussions>

ESP32-based circuit to monitor quality of water in your swimming pool.

## ✨ Features

- 🔬 **pH Value Monitoring** - Track water acidity/alkalinity
- 🧪 **Chloride Monitoring** - Measure chlorine levels
- 📡 **Homie 3.0 Compatible** - Standardized MQTT data exchange
- 📺 **Display Support** - Local display of water quality data
- 🌐 **MQTT Integration** - Seamless integration with Home Assistant and other MQTT clients

## 🚀 Quick Start

### Prerequisites

- ESP32 development board
- pH sensor (e.g., Atlas Scientific pH probe)
- Chloride sensor
- MQTT broker (e.g., Mosquitto, Home Assistant)
- PlatformIO installed

### Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/smart-swimmingpool/water-quality-monitor.git
   cd water-quality-monitor
   ```

2. **Install dependencies:**
   ```bash
   pio run -e esp32dev
   ```

3. **Configure your settings:**
   - Update WiFi credentials in `platformio.ini` or via serial monitor
   - Configure MQTT broker settings
   - Calibrate your sensors

4. **Upload to your ESP32:**
   ```bash
   pio run -e esp32dev -t upload
   ```

5. **Monitor via serial console:**
   ```bash
   pio run -e esp32dev -t monitor
   ```

## 📚 Documentation

- [Hardware Guide](docs/hardware-guide.md) - Assembly and wiring instructions
- [Contributing Guide](CONTRIBUTING.md) - How to contribute to the project
- [Code of Conduct](CODE_OF_CONDUCT.md) - Expected behavior guidelines
- [Changelog](CHANGELOG.md) - Release history and changes

## 🤝 Contributing

We welcome contributions! Please read our [Contributing Guide](CONTRIBUTING.md) before submitting pull requests.

### Development Workflow

```bash
# Clone and setup
git clone https://github.com/smart-swimmingpool/water-quality-monitor.git
cd water-quality-monitor

# Run quality checks before committing
make lint-fix && make lint

# Build the project
make build
```text

## Dependencies

This project uses the following main dependencies:

- **NTPClient @ 3.2.1** - Time synchronization
- **TimeZone @ 1.2.6** - Timezone handling
- **ArduinoJson @ 7.3.2** - JSON parsing for MQTT messages

See [platformio.ini](platformio.ini) for complete dependency list.

## Configuration

### PlatformIO Environments

- **esp32dev** - Standard ESP32 development board (default)

### Build Flags

- `SERIAL_SPEED=74880` - Serial communication speed
- `PIO_FRAMEWORK_ARDUINO_LWIP2_LOW_MEMORY` - Reliable OTA updates

## MQTT Topics

The Water Quality Monitor publishes data to the following MQTT topics:

```text
smart-swimmingpool/water-quality/pH
smart-swimmingpool/water-quality/chloride
smart-swimmingpool/water-quality/temperature
smart-swimmingpool/water-quality/status
```text

## Quality Checks

This project enforces strict quality standards:

- ✅ **Super-Linter** - Code quality and style checking
- ✅ **PlatformIO CI** - Build verification
- ✅ **Release Please** - Automated version management
- ✅ **EditorConfig** - Consistent editor settings
- ✅ **Clang-Format** - Automatic code formatting
- ✅ **CPPLint** - C++ style checking

Run quality checks locally:
```bash
make lint      # Check code quality
make lint-fix  # Auto-fix issues
make build     # Build project
```text

## License

[MIT License](LICENSE) – Free to use, modify, and share.

---

## Community

- **Discussions:** [GitHub Discussions](https://github.com/smart-swimmingpool/smart-swimmingpool.github.io/discussions)
- **Website:** [smart-swimmingpool.com](https://smart-swimmingpool.com)
- **Home Assistant Community:** [community.home-assistant.io](https://community.home-assistant.io/)

## Credits

- All [contributors](https://github.com/smart-swimmingpool/water-quality-monitor/graphs/contributors) for their valuable input!
- Inspired by the [Pool Controller](https://github.com/smart-swimmingpool/pool-controller) project

---

<p align="center">
  Made with ❤️ by the Smart Swimming Pool community
</p>
