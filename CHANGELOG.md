# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Added

- Initial project setup with ESP32 support
- PlatformIO project configuration
- Basic MQTT client functionality
- Homie 3.0 compatibility

### Changed

- Migrated from ESP8266 to ESP32-only support for consistency with Pool Controller
- Updated dependencies to match Pool Controller standards
- Added comprehensive development tooling (clang-format, editorconfig, cpplint)

### Fixed

- Fixed dependency management (replaced Git URLs with package manager)

## [0.1.0] - 2024-01-01

### Features

- Initial release of Water Quality Monitor
- pH sensor monitoring
- Chloride monitoring
- Homie 3.0 compatible data exchange
- Basic display support

[Unreleased]: https://github.com/smart-swimmingpool/water-quality-monitor/compare/v0.1.0...HEAD
[0.1.0]: https://github.com/smart-swimmingpool/water-quality-monitor/releases/tag/v0.1.0
