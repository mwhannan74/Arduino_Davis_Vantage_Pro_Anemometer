10/1/2023

# Getting Started with Arduino

All items in section 1 are available at the following link:
<https://www.arduino.cc/en/Guide>

## Installing

Select the proper install directions depending on which OS you are
using: Windows or Linux.

## Learning

There are a few things you should read up on before beginning.

- Introduction to Arduino

- IDE

- Libraires

- Adding a new board

# Overview of Arduino

## What is Arduino and why use it?

Arduino is an open-source electronics platform based on easy-to-use
hardware and software. It's designed to make electronics more accessible
to artists, designers, hobbyists, and anyone interested in creating
interactive objects or environments.

Why use Arduino?

- **Simplicity**: Arduino boards are designed for beginners. The
  programming environment is user-friendly, and there are plenty of
  resources available for learning.

- **Flexibility**: It can be used for a wide range of projects, from
  simple tasks like turning on an LED to complex robotics.

- **Community**: There's a vast community of Arduino enthusiasts
  worldwide, which means a lot of shared projects, tutorials, and
  support.

## Family of Arduino Microcontrollers

The Arduino family is vast, with various boards designed for different
applications. Here's a brief overview:

- **Arduino Uno**: This is the most popular board and serves as the
  standard model. It's based on the ATmega328P microcontroller and is
  great for beginners.

- **Arduino Mega**: Offers more I/O pins and memory, making it suitable
  for larger projects.

- **Arduino Nano**: A compact board, ideal for projects where space is a
  constraint.

- **Arduino Leonardo**: Similar to the Uno but uses the ATmega32U4,
  allowing it to emulate a computer mouse or keyboard.

- **Adafruit Boards**: Adafruit Industries offers a range of
  microcontroller boards that are compatible with the Arduino IDE. Some
  popular ones include the Feather series, Trinket, and the more
  powerful Metro.

- **Teensy**: Developed by PJRC, Teensy boards are known for their small
  size and high performance. They're compatible with the Arduino
  software but offer advanced features and better processing power.

## Unique Features of Arduino Microcontrollers

Compared to a standard PC, Arduino microcontrollers:

- **Interact Directly with the Physical World**: Arduinos can read
  inputs from sensors (like light or temperature) and turn it into an
  output (like activating a motor or turning on an LED).

- **Real-time Operation**: They can operate in real-time, responding
  immediately to environmental changes, which PCs aren't typically
  designed to do.

- **Low Power Consumption**: Arduinos consume much less power than PCs,
  making them ideal for battery-operated projects.

- **Compact Size**: Their small size allows them to be integrated into
  all sorts of devices and projects.

## How is Arduino Different from Other Microcontrollers?

- **Open-Source**: Both the hardware design and the software are
  open-source. This means anyone can modify, distribute, and use it.

- **Community Support**: The vast Arduino community means a plethora of
  shared knowledge, tutorials, and libraries.

- **Cross-Platform IDE**: The Arduino Integrated Development Environment
  (IDE) works on Windows, Mac OS X, and Linux.

- **Modularity**: Arduino boards are modular, allowing for easy
  replacement of components or integration with other boards.

- **Variety**: With the vast family of Arduino and compatible boards,
  there's likely a board tailored to almost any project's needs.

Other microcontrollers might not have the same level of community
support, open-source ethos, or ease of use that Arduino offers, making
Arduino a preferred choice for many beginners and educators.

## Pros and Cons of Using Arduino

Arduino is a powerful ecosystem. However, it has it limitations. Here
are some of the pros and cons of using the Arduino platform. When
choosing between Arduino and more powerful alternatives, it's essential
to consider the project's requirements, the desired learning curve,
budget, and the importance of community support.

### Pros:

- **Beginner-Friendly**: Arduino is designed with beginners in mind. The
  programming environment is straightforward, and the syntax is simpler
  than many other platforms.

- **Open-Source**: Both the hardware and software of Arduino are
  open-source. This means users can modify and tailor them to their
  specific needs.

- **Strong Community Support**: The Arduino community is vast. This
  means a plethora of shared projects, tutorials, forums, and libraries
  are available, making troubleshooting and learning easier.

- **Cross-Platform IDE**: The Arduino Integrated Development Environment
  (IDE) is available for Windows, Mac OS X, and Linux.

- **Modular Design**: Arduino boards are designed to be modular,
  allowing for easy integration with sensors, actuators, and other
  components.

- **Cost-Effective**: Arduino boards are generally affordable, making
  them a popular choice for hobbyists and educators.

- **Standardized Connectors**: Many Arduino boards use standardized
  headers, making it easy to connect a wide variety of "shields" (add-on
  boards) to extend their capabilities.

### Cons:

- **Limited Processing Power**: While suitable for many tasks, Arduino
  boards (especially the basic ones) might not handle complex
  computations or multitasking as efficiently as some other
  microcontrollers.

- **Memory Constraints**: Basic Arduino boards have limited memory,
  which can be a constraint for larger projects.

- **Overhead of Abstraction**: The simplicity of the Arduino platform
  comes at the cost of some overhead. For projects that require precise
  timing or optimization, this can be a limitation.

- **Not Suitable for Commercial Products**: While great for prototyping,
  Arduino boards are often not optimized for commercial product
  integration in terms of size, power consumption, and cost.

- **Limited Networking Capabilities**: Basic Arduino boards don't come
  with built-in advanced networking features like Wi-Fi or Bluetooth,
  though they can be added via shields or modules.

### More Powerful Alternatives to Arduino:

- **Raspberry Pi**: A mini-computer that runs a full OS and has digital
  IO. It's more powerful than Arduino and can handle tasks like web
  browsing, word processing, and even video streaming. It also supports
  “HATs” that allow the RPi to be expand with microcontroller like
  capability. However, it's not as real-time as Arduino, consumes more
  power, and does not have the “simplicity” of the Arduino development
  process.

- **BeagleBone**: Similar to Raspberry Pi but with more focus on
  interfacing with the physical world.

# Arduino Code Development Process

The Arduino code development process differs a bit from the traditional
process. The Arduino development process is tailored for ease of use and
rapid prototyping, especially for those new to programming or
electronics. In contrast, traditional C++ development offers more
flexibility and control but comes with a steeper learning curve.

## Arduino C++ Development Process”

- **Sketches**: In the Arduino world, programs are often referred to as
  "sketches." A sketch is a set of instructions written in the Arduino
  programming language.

- **Arduino IDE**: The Arduino Integrated Development Environment (IDE)
  is a simple, user-friendly platform where users write, compile, and
  upload their sketches to an Arduino board.

- **Predefined Functions**:

  - **setup()**: This function is called once when the Arduino board
    starts up. It's used for initial setup tasks, like setting pin modes
    or initializing serial communication.

  - **loop()**: After the setup() function runs, the loop() function
    runs repeatedly, allowing the board to change and respond. It's the
    heart of most Arduino sketches.

- **Compilation and Uploading**: Once the sketch is written, the user
  clicks the "Upload" button in the Arduino IDE. The IDE then
  automatically compiles the sketch and uploads it to the Arduino board.

- **Libraries**: The Arduino platform provides a rich set of libraries
  that simplify the task of interfacing with various sensors, actuators,
  and modules. These can be easily included in the sketch.

## Traditional C++ Development Process

- **Source Code**: In traditional C++ development, programs are written
  in source files, typically with .cpp extensions.

- **IDEs**: Developers use Integrated Development Environments like
  Visual Studio, Code::Blocks, or Eclipse. These IDEs offer advanced
  features like code suggestions, debugging tools, and more.

- **Compilation**:

  - **Preprocessing**: The preprocessor handles directives like
    \#include and \#define.

  - **Compilation**: The compiler translates the C++ source code into
    assembly code or object code (.obj or .o files).

- **Linking**: The linker takes one or more object files and combines
  them with necessary library files to produce an executable file.

- **Execution**: The produced executable can be run on the target
  platform.

- **Libraries**: In traditional C++ development, libraries need to be
  explicitly linked, and their headers included in the source code.

## Contrast and Comparison

- **Simplicity vs. Complexity**: Arduino's development process is
  streamlined for simplicity. The IDE takes care of many tasks behind
  the scenes, making it beginner-friendly. Traditional C++ development
  offers more control but requires a deeper understanding of the
  process.

- **Sketch vs. Source Code**: Arduino uses the term "sketch" for its
  programs, emphasizing the idea of quickly drafting ideas. Traditional
  C++ development uses terms like "source code" or "program."

- **Automatic vs. Manual Steps**: In the Arduino IDE, compilation and
  uploading are combined into a single step. In traditional C++
  development, compiling, linking, and executing are distinct steps.

- **Predefined Functions**: Arduino sketches have a standard structure
  with setup() and loop() functions. Traditional C++ programs have a
  main() function as their entry point, but beyond that, the structure
  can vary widely.

- **Platform-Specific vs. General-Purpose**: Arduino sketches are
  written with a specific board and its capabilities in mind.
  Traditional C++ development is more general-purpose and can target a
  wide range of platforms.

- **Libraries**: While both offer libraries to extend functionality,
  Arduino's libraries are often more high-level, abstracting away much
  of the complexity. In traditional C++ development, libraries might
  require more configuration and understanding of their inner workings.

# Arduino Inputs and Outputs Overview

Arduino boards are versatile platforms that can interact with the
external world through various inputs and outputs. These interfaces
allow the board to sense, process, and act upon a wide range of signals.
This section covers the core types of inputs and outputs available on an
Arduino board, their subfunctionalities, and some illustrative examples.
By understanding these core functionalities of an Arduino board, users
can design and implement a wide range of projects, from simple LED
displays to complex robotic systems.

## Digital Inputs/Outputs

Digital pins on an Arduino board can read or produce only two states:
HIGH (usually 5V or 3.3V) or LOW (0V).

- **Digital Input**: Read the state of a button, switch, or any binary
  sensor.

  - *Example*: Detecting if a button is pressed or not.

- **Digital Output**: Drive LEDs, relays, or any binary actuator.

  - *Example*: Turning an LED on or off.

## Analog Inputs

Analog pins can read a range of voltages, allowing them to interpret
more than just binary states.

- **Analog-to-Digital Conversion (ADC)**: Convert a varying voltage
  level into a digital value.

  - *Example*: Reading the value from a potentiometer or a temperature
    sensor.

## Analog Outputs (PWM)

While Arduino doesn't have true analog output capabilities, it can
simulate them using Pulse Width Modulation (PWM).

- **Pulse Width Modulation (PWM)**: Vary the duty cycle of a digital
  signal to simulate an analog output.

  - *Example*: Adjusting the brightness of an LED or controlling the
    speed of a motor.

## Communication Interfaces

Arduino boards come equipped with various communication interfaces to
interact with other devices, sensors, or even other microcontrollers.

- **Serial Communication (UART)**: Transmit and receive data serially.

  - *Example*: Sending data to a computer or receiving commands from it.

- **I2C (Inter-Integrated Circuit)**: A bus system for multi-device
  communication.

  - *Example*: Communicating with an OLED display or a digital sensor.

- **SPI (Serial Peripheral Interface)**: A synchronous serial data
  protocol.

  - *Example*: Interfacing with an SD card or a shift register.

- **CAN (Controller Area Network)**: A robust communication protocol
  mainly used in automotive applications.

  - *Example*: Interfacing with car sensors or actuators in DIY
    automotive projects.

## 5. Specialized I/O

Beyond the standard digital and analog pins, Arduino boards often
feature specialized pins for specific functions.

- **Interrupt Pins**: Respond to external events or changes in pin
  states instantly.

  - *Example*: Detecting a motion sensor's trigger without continuously
    polling its state.

- **External Oscillator Pins**: For connecting an external clock source.

  - *Example*: Achieving more accurate time-based operations.
