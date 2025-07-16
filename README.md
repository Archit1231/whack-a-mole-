# Whack-a-mole

## ⚡ Introduction

The Whack-a-Mole game is a popular arcade-style game that has been entertaining players for decades. The premise is simple yet fun: moles (or in modern versions, animated
creatures) pop up randomly from holes, and the player needs to hit them with a mallet
or a hammer to score points. When translated into the world of electronics and DIY
projects, this classic game can be recreated using a microcontroller such as the Arduino
Nano.

## 🔍 Component Selection

 - **Arduino Nano** - Acts as the brain of the system.
 
 - **LEDs (Light Emitting Diodes)** - Used to visually represent the ”moles” that pop up.
 
 - **Push Buttons** - Each LED has a corresponding push button positioned in front of it.
 
 - **16x2 LCD with I2C Module (Optional)** - Displays real-time score and game messages.
 
 - **Resistors** - 220–330Ω resistors are used in series with LEDs to prevent overcurrent.
 
 - **Breadboard and Jumper Wires** - Used for quick prototyping and connecting all components
 
 - **Power Supply** - The Arduino Nano can be powered via USB from a computer or using an externa l5V adapter.
 

 ## ⚙️ Working

 The software running on the Arduino Nano handles random mole activation, player input
detection, scoring logic, and optional output through a buzzer or display. The modular
and structured code allows easy enhancements such as difficulty adjustment and timebased challenges. The Arduino IDE provides a robust platform for writing, compiling,
and uploading the game code efficiently.

The Arduino IDE is used to program the microcontroller. The code includes:

1) Initialization of pins.

2) Game loop controlling mole activation and timing.

3) Random selection of mole to light.

4) Detection of button presses and scoring.

5) Audio feedback through buzzer.

## 🚀 Testing and Evaluation

The testing and evaluation phase is essential to ensure the reliability and functionality
of the Whack-a-Mole Game using Arduino Nano. This phase involved checking hardware
connections, verifying software logic, and conducting gameplay tests under different scenarios. The goal was to ensure that the system responded correctly to inputs, scored
accurately, and provided consistent feedback to the user.


The testing process was carried out in the following stages:
1. Power and Connectivity Check: The Arduino Nano was powered via USB,
and all connections on the breadboard were visually inspected for correctness and
continuity.

2. LED Functionality Test: Each LED was tested using a simple blink sketch to
confirm proper wiring and resistor values.

3. Button Response Test: The digital input pins were monitored using serial output
to verify that each button press was correctly detected.

4. LCD Output Test : The I2C LCD was tested to ensure correct address
configuration and real-time display of score and status messages.

5. Full Game Simulation: The complete game logic was uploaded, and multiple
gameplay sessions were conducted to verify randomness, responsiveness, and scoring
logic.

## 🤖 Code Structure

The code is divided into the following key sections:

**• Initialization**: Pin modes and variables are set.

**• Random LED Activation**: An LED is turned on randomly using the random()
function.

**• Input Monitoring**: Button states are continuously checked using digitalRead().

**• Scoring Logic**: When the correct button is pressed while the corresponding LED
is on, the score is incremented.

**• Feedback**: A tone is played on the buzzer, and score is optionally updated on the LCD.

## ⚡Result Summary

The Whack-a-Mole game built using the Arduino Nano microcontroller was thoroughly
tested to evaluate its functional performance and user experience. The system successfully
demonstrated the core game mechanics by randomly lighting up LEDs to represent moles
and accurately detecting button presses corresponding to these LEDs. Real-time feedback
was delivered through a buzzer and an optional LCD screen displaying the player’s score.
The response time window of 1.5 seconds per mole provided a suitable challenge, encouraging quick reactions while maintaining playability. Testing under continuous operation
revealed consistent, reliable performance without hardware malfunctions or software errors.

## 🔌 References

The development of the Arduino Nano-based Whack-a-Mole game was greatly supported
by several online resources, tutorials, and open-source community contributions. A key
reference that provided the foundation for the overall game logic and hardware setup was
the Instructables tutorial titled Simon/Whack-a-Mole Game Using Arduino [1]. This
tutorial offered a step-by-step guide for interfacing LEDs and push buttons with an
Arduino, and for programming a reaction-time game using simple C code.
Further simplification and adaptation of the logic were based on the project documented by 101 Computing, titled Arduino Whack-a-Mole Game [2]. This source explained the implementation of the Whack-a-Mole concept using minimal components,
making it particularly helpful for adapting the project to the Arduino Nano’s pin constraints and size.

![WhatsApp Image 2025-07-16 at 15 15 14_69a06d7c](https://github.com/user-attachments/assets/d80abf44-4601-4ab0-aa6d-3371eb6b02e2)

![WhatsApp Image 2025-07-16 at 15 18 18_b516f732](https://github.com/user-attachments/assets/c10d4dff-6e4d-4c14-8d68-923c133ca3b6)








