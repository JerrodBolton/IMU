# Lab 7.1: Using Thingspeak API  

## Overview  
This project involves using a thermistor to measure temperature and display the results on the M5Core2 device. The thermistor is a temperature-dependent resistor, meaning its resistance changes with temperature. By utilizing a voltage divider circuit and a reference resistor, we can calculate the thermistor's resistance and subsequently determine the temperature.  

## Part 1: Thermistor Circuit  
### Key Concepts  
- **Thermistor**: A resistor whose resistance varies with temperature.  
- **Voltage Divider**: A circuit used to measure voltage at a specific point, enabling resistance calculation.  
- **Reference Resistor**: A resistor with a known value, chosen to minimize error (±20% of thermistor resistance at room temperature).  

### Steps  
1. **Determine Thermistor Resistance**:  
    - Use a multimeter to measure the thermistor's resistance at room temperature.  
    - Record this value in your lab report.  

2. **Calculate Reference Resistor Value**:  
    - Use the formula:  
      `Reference Resistor = 3.4 Ohms for every 1 Ohm of thermistor resistance`.  
    - Record the calculated value in your lab report.  

3. **Build the Circuit**:  
    - Connect the thermistor, reference resistor, and M5Core2 as shown in the circuit diagram (`image.png`).  
    - Take a picture of the completed circuit as the deliverable for Part 1.  

## Part 2: Temperature Calculation  
### Equation  
Use the provided equation (EQ2) to calculate the thermistor's resistance and determine its temperature.  

### Programming Task  
1. Write a program for the M5Core2 that:  
    - Reads the thermistor temperature.  
    - Displays the temperature in Celsius on the screen.  

2. Test the program by recording three different temperatures.  

## Deliverables  
- **Part 1**:  
  - Picture of the thermistor circuit.  
  - Thermistor resistance and reference resistor values.  

- **Part 2**:  
  - Program displaying thermistor temperature in Celsius.  
  - Demonstration of three recorded temperatures.  

## Notes  
- The circuit and programming concepts will be discussed in class.  
- Ensure all measurements and calculations are documented in your lab report.  
