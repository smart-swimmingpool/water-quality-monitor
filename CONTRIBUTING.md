# Contributing to Water Quality Monitor

Thank you for your interest in contributing to the **Smart Swimming Pool Water Quality Monitor** project!

This document provides guidelines for contributing to the project. Please read it
carefully before submitting your first pull request.

## Table of Contents

- [Code of Conduct](#code-of-conduct)
- [How to Contribute](#how-to-contribute)
- [Getting Started](#getting-started)
- [Development Workflow](#development-workflow)
- [Coding Standards](#coding-standards)
- [Pull Request Process](#pull-request-process)
- [Commit Message Guidelines](#commit-message-guidelines)
- [Quality Gates](#quality-gates)

---

## 🤝 Code of Conduct

This project adheres to the
[Contributor Covenant](https://www.contributor-covenant.org/version/1/4/code-of-conduct.html).
By participating, you are expected to uphold this code. Please report unacceptable
behavior to
[project maintainers](https://github.com/smart-swimmingpool/water-quality-monitor/graphs/contributors).

See also: [CODE_OF_CONDUCT.md](CODE_OF_CONDUCT.md)

---

## How to Contribute

### Reporting Bugs

- **Check existing issues**: Search
  [GitHub Issues](https://github.com/smart-swimmingpool/water-quality-monitor/issues)
  before creating a new one
- **Use the issue template**: Provide detailed information about the bug
- **Include**:
  - Firmware version (from serial monitor)
  - Hardware setup (ESP32 model, sensors)
  - Steps to reproduce
  - Serial monitor output (if applicable)
  - Screenshots (if UI-related)

### Suggesting Enhancements

- **Check the roadmap**: See [README.md](README.md) for planned features
- **Discuss first**: Open a
  [GitHub Discussion](https://github.com/smart-swimmingpool/smart-swimmingpool.github.io/discussions)
  to discuss your idea
- **Check for duplicates**: Search existing issues and PRs

### Submitting Pull Requests

- **Fork the repository**: Create your own fork
- **Create a feature branch**: Use descriptive branch names
  (e.g., `feat/add-ph-sensor-support`)
- **Follow coding standards**: See below
- **Test your changes**: Ensure all tests pass
- **Update documentation**: Keep docs in sync with code changes

---

## Getting Started

### Prerequisites

- [PlatformIO](https://platformio.org/) installed
- [Git](https://git-scm.com/) installed
- Basic knowledge of C++ and ESP32 development
- Understanding of MQTT protocol (for Home Assistant integration)

### Setting Up the Development Environment

```bash
# Clone the repository
git clone https://github.com/smart-swimmingpool/water-quality-monitor.git
cd water-quality-monitor

# Install dependencies (handled by PlatformIO)
pio run -e esp32dev

# Run local linting
make lint-fix && make lint

# Build the project
make build
```text

---

## Project Structure

```text
water-quality-monitor/
├── src/                    # Main source code
│   └── main.cpp            # Main application entry point
│   └── Version.h           # Version information (auto-managed)
├── lib/                    # External libraries
├── .github/                # GitHub configuration
│   ├── workflows/          # GitHub Actions workflows
│   └── release-please-config.json
├── .editorconfig           # Editor configuration
├── .clang-format           # C++ code formatting rules
├── CPPLINT.cfg             # C++ linting configuration
├── Makefile                # Local development tasks
├── platformio.ini          # PlatformIO project configuration
├── README.md               # Project documentation
├── CONTRIBUTING.md         # This file
├── CODE_OF_CONDUCT.md      # Code of conduct
├── CHANGELOG.md            # Release history
└── LICENSE                 # License information
```text

---

## Coding Standards

This project follows the same coding standards as the Pool Controller project.

### Key Guidelines

1. **Code Formatting**: Use `clang-format` with the provided configuration
2. **Line Length**: Maximum 130 characters
3. **Indentation**: 2 spaces (no tabs)
4. **Pointer Alignment**: Right (`int* ptr`)
5. **Naming Conventions**: Use descriptive names, follow existing patterns
6. **Error Handling**: Always handle errors gracefully
7. **Memory Management**: Be mindful of memory usage (ESP32 constraints)

### Before Committing

```bash
# Format and lint your code
make lint-fix && make lint

# Build to ensure it compiles
make build
```text

---

## Pull Request Process

1. **Fork the repository** and create your branch from `master`
2. **Make your changes** following the coding standards
3. **Test your changes** thoroughly
4. **Update documentation** if applicable
5. **Run quality checks**: `make lint-fix && make lint`
6. **Commit your changes** with clear, descriptive messages
7. **Push to your fork** and submit a pull request

### Pull Request Requirements

- ✅ All CI checks pass (Super-Linter, PlatformIO CI)
- ✅ Code follows project standards
- ✅ Documentation is updated
- ✅ No breaking changes (unless discussed)
- ✅ Clear commit messages

---

## Commit Message Guidelines

### Format

```text
type(scope): subject

body

footer
```text

### Types
- `feat`: New feature
- `fix`: Bug fix
- `docs`: Documentation changes
- `style`: Code formatting (no functional changes)
- `refactor`: Code refactoring
- `test`: Adding or fixing tests
- `chore`: Maintenance tasks

### Example
```text
feat(sensors): add pH sensor support

- Add pH sensor reading functionality
- Update MQTT topics for pH data
- Add configuration options for pH calibration

Closes #123
```text

---

## Quality Gates

All contributions must pass the following quality checks:

1. **Super-Linter**: Code quality and style checks
2. **PlatformIO CI**: Build verification
3. **Manual Review**: Code review by maintainers

### Local Quality Checks

```bash
# Run all quality checks
make lint

# Auto-fix common issues
make lint-fix

# Build the project
make build
```text

---

## Thank You!

Your contributions help make this project better for everyone. We appreciate your
time and effort in improving the Smart Swimming Pool Water Quality Monitor!

---

## Additional Resources

- [Pool Controller Documentation](https://github.com/smart-swimmingpool/pool-controller)
- [Smart Swimming Pool Website](https://smart-swimmingpool.com)
- [GitHub Discussions](https://github.com/smart-swimmingpool/smart-swimmingpool.github.io/discussions)
