#  USB-Controlled Switchable Film for Experimental Applications

This is a simple Arduino-based application that allows USB serial control of a **switchable film** (also known as **smart film** or **PDLC film**). A switchable film is a special type of material that can switch between transparent and opaque states when an electrical signal is applied.

By using an **Arduino board** and a **relay module**, the smart film can be controlled from a computer via a serial connection. You can send simple commands from:

- Python scripts
- Experimental software like **OpenSesame**, **PsychoPy**, **E-Prime**
- MATLAB or other serial-enabled platforms

This setup is ideal for labs conducting **psychological**, **visual perception**, or **timing-sensitive** experiments, where automated control of visual stimuli is required.

---

## 🛠️ How it works

- The Arduino listens for serial commands via USB.
- When a command is received (e.g., `'o'` to turn the film on, `'c'` to turn it off), it activates a relay.
- The relay controls the AC power to the switchable film (typically 60–100V AC depending on the film).
- Commands can be triggered programmatically from experimental software.

---

## 🧪 Example Applications

- Temporarily obscure visual stimuli during an experiment.
- Control light transmission in timing-critical trials.
- Integrate smart glass control into behavioral tasks.

---

## 📡 Serial Command Reference

| Command      | Description                                                        |
|--------------|--------------------------------------------------------------------|
| `o`          | Activate the film (make it opaque)                                 |
| `c`          | Deactivate the film (make it transparent)                          |
| `O<time in ms>E`     | Activate, then deactivate, example: O2000E                 |
| `C<time in ms>E`     | Deactivate, then activate, example: C2400E                |


> `T` suffix = **timed trigger** command for automatic activation followed by deactivation.

These commands allow **precise control** over stimulus timing in behavioral experiments or visual exposure studies.

---

## ⚠️ Important Safety Notes

- The switchable film operates with **AC power** and must be handled with **extreme caution**.
- Always use a **relay module with proper galvanic isolation** between the Arduino (low-voltage side) and the high-voltage AC circuit connected to the film.
- Never connect high voltage directly to the Arduino or to your computer.
- The entire apparatus (relay module, AC driver, wiring, and switchable film) must be **adequately insulated and enclosed** to prevent accidental contact with live components.
- Ensure that all connections comply with **electrical safety standards**, and avoid handling the system when powered unless it is fully enclosed and safe.
- If you are not familiar with working with mains voltage (e.g., 220V AC), consult a qualified technician before proceeding.

⚠️ **High voltage can cause serious injury or death**. This project is intended for educational or laboratory use by individuals with adequate knowledge of electrical safety.


---

Feel free to fork the project and adapt it to your experimental setup. Contributions and suggestions are welcome!
