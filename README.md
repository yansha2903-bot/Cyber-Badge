# Cyber-Badge
An electronic E-Ink badge with an e-ink display that is designed to be worn around the neck as an alternative to ordinary badges.

This is my project for an electronic badge featuring an E-Ink display. It can show your name, current status (like "Coding"), and contact info.

## Components Used

* **Seeed Studio XIAO ESP32-C3** — The microcontroller that controls everything.
* **E-Ink Display (1.54")** — An electronic paper screen. It's awesome because the image stays on the screen even when the power is disconnected!
* **Push Button** — Switches between screens when pressed.
* **JST Battery Connector** — For running the badge portably without any cables.

## Repository Structure

* `Firmware/code/code.ino` — Main Arduino code for the badge.
* `KiCad/` — Project files for KiCad 10:
* `Cyber-Badge.kicad_sch` — Schematic design.
* `Cyber-Badge.kicad_pcb` — PCB layout design.
* `BOM.csv` — Bill of Materials.
* `gerbers.zip` & `drill.zip` — Manufacturing files.
* `Images/` — Photos of my project.

## How to Flash the Code

1. Open `Firmware/code/code.ino` in Arduino IDE.
2. Install the `GxEPD2` and `Adafruit GFX` libraries via the Library Manager.
3. Select **XIAO ESP32-C3** as your board in the settings.
4. Upload the code and enjoy!
