# M5Core2 IMU Sensors Project

## Part 1: Understanding the Axes

1. Load the **mpu6886** sample sketch, found under `File -> Examples -> M5Core2 -> Basics`.
2. Use the sample code to determine the directions of the x, y, and z axes.
3. In your lab report:
    - Create a simple sketch of the M5Core2 device.
    - Label the axes appropriately.
    - Note that the axes are centered on the MPU unit, not specifically on the Core2.
4. You may need to remove the back casing to locate the MPU's position.

---

## Part 2: Tracking Maximum Accelerometer Values

1. Create variables `maxX`, `maxY`, and `maxZ` to store the maximum values observed by the accelerometer for each axis.
2. Implement a `maxTotalVector` variable to calculate the magnitude of the acceleration vector:
    - Use the formula: `sqrt(Xsq + Ysq + Zsq)` where `Xsq`, `Ysq`, and `Zsq` are the squared values of the respective axes.
3. Display all these values with labels on the screen.
4. Add functionality to reset the maximum vectors:
    - Use the left button to reset all `maxX`, `maxY`, `maxZ`, and `maxTotalVector` values to zero.

---

## Part 3: Detecting Drops and Triggering Alerts

1. Combine the IMU sample sketch with the blink sketch from the introduction lab.
2. Add an `if` statement to detect when the accelerometer senses a drop of **10 cm or more**.
3. When a drop is detected:
    - Make the screen blink **5 times** alternating between red and white.
    - Set the blink rate to **500 milliseconds** (2 Hz).

---

### Notes

- Ensure proper testing and calibration of the accelerometer values.
- Refer to class lectures for additional guidance on vector calculations.
- Handle edge cases to avoid false positives in drop detection.

Happy coding!