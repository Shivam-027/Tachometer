# Tachometer

## Description

Tachometer is an Arduino-based project designed to measure the revolutions per minute (RPM) of a rotating object, such as a ceiling fan. This project utilizes an IR sensor module to detect rotations and a 16x2 LCD to display the RPM. The system uses an interrupt to count revolutions and calculate the RPM based on the time interval between updates. The LCD provides real-time feedback, showing both RPM and revolutions per second.


## Language Used

- **C++**: The project is implemented using the Arduino programming language, which is a subset of C/C++. The code leverages the LiquidCrystal library to interface with the LCD.

## Arduino Board Used

- **Arduino UNO**

## Components Used

- **Arduino Board**: The central microcontroller used for processing and control.
- **LiquidCrystal LCD**: A 16x2 LCD for displaying the RPM and other information.
- **IR Sensor Module**: Contains both transmitter and receiver for detecting rotations.
- **Breadboard**: For prototyping and connecting components.

- **LiquidCrystal Library**: For interfacing with the LCD.

## Working

1. **Initialization**: 
   - The LCD is initialized to display 16 columns and 2 rows.
   - An interrupt is attached to pin 2 to count the number of revolutions. The interrupt service routine (`countRevolutions()`) increments the revolution count each time a rising edge is detected.

2. **Revolution Counting**:
   - The `loop()` function runs continuously. It delays for 1 second, during which it detaches the interrupt to stop counting.
   - It then calculates the RPM based on the number of revolutions counted and the elapsed time. The formula used is `rpm = (revolutionCount / elapsedTime) * 60000`.

3. **Display Update**:
   - The LCD is cleared, and the current RPM and revolutions per second (calculated as `rpm / 60`) are displayed.

4. **Reattach Interrupt**: 
   - The interrupt is reattached to continue counting revolutions for the next interval.

## Setup

1. Connect the LCD to the defined pins: RS to pin 12, E to pin 11, D4 to pin 6, D5 to pin 5, D6 to pin 4, and D7 to pin 3.
2. Connect the sensor to pin 2 for revolution counting.
3. Power the Arduino and the LCD.
