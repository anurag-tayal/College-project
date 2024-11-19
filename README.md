# ESP32 Firebase IoT Monitoring Project

This project demonstrates how to use an ESP32 microcontroller to generate random sensor data and send it to a Firebase Realtime Database. The project is ideal for understanding the integration of IoT devices with cloud-based databases for real-time monitoring.

## Project Overview

The ESP32 generates six distinct random values, mimicking sensor data for temperature, voltage, and current parameters. These values are sent to a Firebase Realtime Database, where they can be monitored and visualized in real time through a web interface.

### Features
- **Random Data Generation**: Simulates sensor readings (temperature, voltage, current, etc.).
- **Firebase Integration**: Sends data to a Firebase Realtime Database.
- **Real-Time Updates**: Data is updated in real time and can be accessed via a web dashboard.
- **Wi-Fi Connectivity**: Uses the ESP32’s built-in Wi-Fi module to connect to the internet.

---

## Hardware Requirements
- ESP32 Development Board
- USB Cable (for programming and power)
- Access to a Wi-Fi network

---

## Software Requirements
- Arduino IDE
- Firebase Realtime Database
- Firebase ESP32 Library

---

## Firebase Setup
1. **Create a Firebase Project**:
   - Go to the [Firebase Console](https://console.firebase.google.com/).
   - Create a new project and enable the Realtime Database.

2. **Get the Database URL and API Key**:
   - Note down the database URL (e.g., `https://your-project.firebaseio.com/`).
   - Generate an API key for the project from the settings.

3. **Set Up Rules**:
   - Update the database rules to allow read and write access:
     ```json
     {
       "rules": {
         ".read": true,
         ".write": true
       }
     }
     ```

4. **Add Firebase Library**:
   - Install the Firebase ESP32 Client Library from the Arduino Library Manager.

---

## Code Explanation

### Configuration
- Replace the placeholders in the code with your Firebase URL, API key, Wi-Fi SSID, and password.

### Random Data Simulation
The ESP32 generates random values for the following parameters:
- **Temperature**: Random value between 0 and 100
- **vmax**: Random value between 125 and 200
- **vmin**: Random value between 0 and 124
- **imax**: Random value between 50 and 80
- **imin**: Random value between 0 and 79
- **six**: Random value between 0 and 1023

### Firebase Data Upload
The data is structured into JSON format and sent to the `/Weight` node in the Firebase Realtime Database.

---

## How to Run the Project
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/firebase-iot-monitoring.git
   ```

2. **Open the Arduino Code**:
   - Open the `.ino` file in Arduino IDE.

3. **Install Dependencies**:
   - Install the required libraries: Firebase ESP32, WiFi, etc.

4. **Upload the Code**:
   - Connect the ESP32 to your computer and upload the code.

5. **Monitor the Output**:
   - Use the Serial Monitor to observe the ESP32's connection status and data generation.
   - Check the Firebase Realtime Database to view the uploaded data.

---

## Web Interface
The web interface allows users to visualize the data in real time. It is built using HTML, CSS, and JavaScript, and integrates Firebase's Realtime Database for dynamic updates.

### Hosting Options
- **GitHub Pages**
- **Firebase Hosting**
- **Netlify**

---

## Folder Structure
```
.
├── firebase_iot.ino   # Main Arduino code
├── index.html         # Web dashboard (for visualization)
├── style.css          # Styling for the web dashboard
├── script.js          # JavaScript for Firebase interaction
└── README.md          # Project documentation
```

---

## Future Improvements
- Replace random values with actual sensor readings.
- Add data visualization charts in the web dashboard.
- Implement user authentication for database security.
- Extend the project to include additional sensors or actuators.

---

## License
This project is licensed under the MIT License. Feel free to modify and distribute it as needed.

---

## Acknowledgments
- Firebase ESP32 Client Library by Mobizt.
- Arduino IDE for development.

---
Start contributing and enjoy exploring IoT with Firebase!
