

repository: https://github.com/labdipsco/film-switchable-controller/tree/main

This is a simple Arduino-based application that allows USB serial control of a **switchable film** (also known as **smart film** or **PDLC film**). A switchable film is a special type of material that can switch between transparent and opaque states when an electrical signal is applied.

By using an **Arduino board** and a **relay module**, the smart film can be controlled from a computer via a serial connection. You can send simple commands from:

- Python scripts
- Experimental software like **OpenSesame**, **PsychoPy**, **E-Prime**
- MATLAB or other serial-enabled platforms

This setup is ideal for labs conducting **psychological**, **visual perception**, or **timing-sensitive** experiments, where automated control of visual stimuli is required.

---

## 🛠️ How it works

- The Arduino listens for serial commands via USB.
- When a command is received (e.g., `'o'` to turn the film on, `'c'` to turn it off), it activates a relay. Timed control is also possible.
- The relay controls the AC power to the switchable film (typically 45/60V AC depending on the film).
- Commands can be triggered programmatically from experimental software.

<img src="https://github.com/user-attachments/assets/6057584a-f228-4490-a199-25440742b28f" alt="Alt Text" style="width:70%; height:auto;">

---

## 🔧 Hardware Requirements

To build this system, you'll need the following components:

### 1. Arduino UNO R4 Minima
- **USB Interface**: USB-C connector
For more details, refer to the [Arduino UNO R4 Minima Documentation](https://docs.arduino.cc/hardware/uno-r4-minima/).

### 2. Relay Shield for Arduino UNO or an Arduino compatible relay
This shield allows the Arduino to control high-power loads up to 120V AC/3A. The relay connected to the switchable film is controlled from arduino pin 7 at 5V.
For more information, see the [Arduino 4 Relays Shield Basics](https://docs.arduino.cc/tutorials/4-relays-shield/4-relay-shield-basics/).

### 3. Switchable Film (Smart Film)

The switchable film used in this project was kindly provided by [Innoptec](https://www.innoptec.com). This film changes its transparency state when an electrical voltage is applied, making it ideal for applications requiring controlled light transmission.
*Note*: The film requires an appropriate AC power supply (typically 45 or 60V/50Hz AC) and should be handled with care, ensuring all safety precautions are followed.

---

Ensure all components are properly connected and insulated to maintain safety and functionality. Always consult the respective datasheets and user manuals for detailed information and guidelines.

---

## 📡 Install

Download [controller.ino](https://github.com/labdipsco/film-switchable-controller/blob/main/controller.ino),compile and upload to Arduino Uno with [Arduino IDE](https://www.arduino.cc/en/software/)

---

## 📡 Serial Command Reference

The values listed in the table are sent to Arduino to control the switchable film.

| Command      | Description                                                        |
|--------------|--------------------------------------------------------------------|
| `o`          | Activate the film (make it opaque)                                 |
| `c`          | Deactivate the film (make it transparent)                          |
| `O<time in ms>E`     | Activate, then deactivate after delay (e.g., `O2000E`)     |
| `C<time in ms>E`     | Deactivate, then activate after delay (e.g., `C2400E`)     |


## 📡 Simple code for Send command to Arduino with Python and Matlab

```python
import serial
import time
# Define the command to send
command = "O60000E"
# Check which COM port is correct for your device on your system (e.g., COM3, COM4, etc.)
ser = serial.Serial('COM3', baudrate=115200, timeout=1)
ser.write(command.encode('utf-8'))
ser.close()
```

Matlab
```matlab
% Define the command to send
command = 'O15000E';
% Check which COM port is correct for your device on your system (e.g., COM3, COM4, etc.)
s = serialport("COM3", 115200);  % Adjust port name and baud rate as needed
write(s, command, "string");
clear s;
```
---
## ⚠️ Important Safety Notes

- The switchable film operates with **AC power** and must be handled with **extreme caution**.
- Always use a **relay module with proper galvanic isolation** between the Arduino (low-voltage side) and the high-voltage AC circuit connected to the film.
- Never connect high voltage directly to the Arduino or to your computer.
- The entire apparatus (relay module, AC driver, wiring, and switchable film) must be **adequately insulated and enclosed** to prevent accidental contact with live components.
- Ensure that all connections comply with **electrical safety standards**, and avoid handling the system when powered unless it is fully enclosed and safe.
- If you are not familiar with working with mains voltage (e.g., 220V AC), consult a qualified technician before proceeding.

⚠️ **High voltage can cause serious injury or death**. This project is intended for educational or laboratory use by individuals with adequate knowledge of electrical safety.


## 📢 Disclaimer

This project is provided “as is” without warranty of any kind. By using or building this system, you acknowledge and agree that you do so at your own risk. The creators of this project are not responsible for any injury, damage, or legal issues that may arise from improper use, installation, or handling of high-voltage equipment. Always follow local safety regulations and consult a professional if unsure.

---

## 📢 Some Image from the project
<table>
  <tr>
    <td><img src="https://github.com/user-attachments/assets/e72ec4d6-dd25-4c1c-862d-3d7ec89eb1a2" width="75%"></td>
    <td><img src="https://github.com/user-attachments/assets/3ce1f4d4-bde2-49d8-bf43-a0c3364776c4" width="50%"></td>
  </tr>
  <tr>
    <td><img src="https://github.com/user-attachments/assets/d1e4c71d-dabd-413e-8ad6-07c0fcf0b0fd" height="50%"></td>
    <td><img src="https://github.com/user-attachments/assets/875c6860-1171-4157-9eb8-ab311ed982ce" height="50%"></td>
  </tr>
</table>


---

Feel free to fork the project and adapt it to your experimental setup. Contributions and suggestions are welcome!
