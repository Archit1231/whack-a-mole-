# whack-a-mole

## Introduction

The Whack-a-Mole game is a popular arcade-style game that has been entertaining players for decades. The premise is simple yet fun: moles (or in modern versions, animated
creatures) pop up randomly from holes, and the player needs to hit them with a mallet
or a hammer to score points. When translated into the world of electronics and DIY
projects, this classic game can be recreated using a microcontroller such as the Arduino
Nano.

##  Component Selection

 - **Arduino Nano** - Acts as the brain of the system.
 
 - **LEDs (Light Emitting Diodes)** - Used to visually represent the ”moles” that pop up.
 
 - **Push Buttons** - Each LED has a corresponding push button positioned in front of it.
 
 - **16x2 LCD with I2C Module (Optional)** - Displays real-time score and game messages.
 
 - **Resistors** - 220–330Ω resistors are used in series with LEDs to prevent overcurrent.
 
 - **Breadboard and Jumper Wires** - Used for quick prototyping and connecting all components
 
 - **Power Supply** - The Arduino Nano can be powered via USB from a computer or using an externa l5V adapter.
 

 ## working

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

## Testing and Evaluation

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

## Code Structure

The code is divided into the following key sections:

• Initialization: Pin modes and variables are set.

• Random LED Activation: An LED is turned on randomly using the random()
function.

• Input Monitoring: Button states are continuously checked using digitalRead().

• Scoring Logic: When the correct button is pressed while the corresponding LED
is on, the score is incremented.

• Feedback: A tone is played on the buzzer, and score is optionally updated on the
LCD.



