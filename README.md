# CHIP-8 Emulator

This project is a CHIP-8 emulator, implemented in C++ using the SDL library for graphical manipulation and input/output events. CHIP-8 is an interpreted programming language developed in the 1970s, originally used in microcomputers for teaching programming and games. This emulator recreates the experience of running CHIP-8 programs on modern hardware.

## Features

- Full CHIP-8 emulation.
- Support for all CHIP-8 opcodes.
- Simple graphical interface to view the state of graphical memory.
- Keyboard controls mapped for interaction with games and programs.

## Prerequisites

To compile and run this emulator, you will need:

- A C++ compiler that supports C++11 or higher.
- The SDL2 library installed on your system.

### Installing the C++ Compiler and SDL2

#### Linux (Ubuntu)

1. **Install GCC**:
   ```bash
   sudo apt install build-essential
   ```

2. **Install SDL2**:
   ```bash
   sudo apt install libsdl2-dev
   ```

#### Windows

1. **Install GCC via MinGW-w64**:
   - Download and install MSYS2 from the [official website](https://www.msys2.org/).
   - Open MSYS2 MSYS and execute:
     ```bash
     pacman -S mingw-w64-x86_64-toolchain
     ```
   - Add the MinGW-w64 binary path to your system's PATH.

2. **Install SDL2**:
   - Download SDL2 from the [official website](https://www.libsdl.org/download-2.0.php) and follow the instructions to set it up in your development environment.

#### macOS

1. **Install or update Clang**:
   - Run the following command to install or update the Xcode Command Line Tools, which includes Clang:
     ```bash
     xcode-select --install
     ```

2. **Install SDL2**:
   - Install SDL2 using Homebrew:
     ```bash
     brew install sdl2
     ```

## Compilation and Execution

With the environment set up, compile and run the emulator with the following commands:

