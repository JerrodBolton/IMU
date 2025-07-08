# M5Core2 and ThingSpeak Integration  

This project demonstrates how to prepare the M5Core2 for communication with ThingSpeak and create applications that utilize the ThingSpeak API for data logging and visualization.  

## Setup Instructions  

### 1. Install Required Libraries  
- Open the Arduino IDE.  
- Navigate to `Sketch > Include Library > Manage Libraries`.  
- Search for **ThingSpeak by MATLAB** and install the library.  

### 2. Download Example Code  
- Visit the [ThingSpeak ESP Examples GitHub repository](https://github.com/nothans/thingspeak-esp-examples).  
- Download the repository as a `.zip` file.  
- Add the library to your Arduino libraries folder.  

### 3. Create a ThingSpeak Channel  
- Go to [ThingSpeak](https://www.thingspeak.com) and create a free account.  
- Create a new channel named **CSC320**.  
- Add a field named **WiFi Strength**.  
- After creating the channel, note the **Channel ID** and **Write API Key** from the Channel Settings page.  

### 4. Configure `secrets.h`  
- Open the `secrets.h` file in the `thingspeak-esp-examples` directory.  
- Update the file with the following information:  
    - **WiFi SSID** and **Password**.  
    - **Channel ID** and **Write API Key**.  

### 5. Record Data from M5Core2  
- Use the sample code from the GitHub repository to create a program that records a number from the M5Core2 every minute.  
- Display the recorded number on the M5Core2 screen.  
- Add the following lines to your code to initialize the M5Core2 display:  
    ```cpp  
    #include <M5Core2>  
    M5.begin();  
    ```  

### 6. Create a Custom Application  
- Develop a new application that uses ThingSpeak and the M5Core2 in a unique way.  
- You can explore ThingSpeak apps (available in the topic menu bar on the ThingSpeak website) or use a different sensor for your project.  

## Additional Resources  
- Refer to the tutorial in the GitHub repository's `README.md` for further guidance.  
- Experiment with ThingSpeak's features to enhance your project.  

This project provides a foundation for integrating IoT devices with cloud-based data logging and visualization platforms.  