# Arduino PWM LED Control with Toggle and Momentary Buttons
# Overview
  This project involves controlling an LED's brightness using PWM (Pulse Width Modulation) based on the input from two different types of buttons connected to an Arduino board. One button is a toggle switch with    a latch (i.e., it remains in the last pressed state), while the other is a momentary switch (i.e., it only activates when pressed).

# Features
  PWM Control: The LED brightness is controlled using PWM signals, allowing for smooth transitions between different brightness levels.
  Button Functionality:
  Toggle Button: When pressed, the LED is set to a lower brightness level (40). When released, the LED remains on at this brightness.
  Momentary Button: When pressed, the LED brightens to maximum brightness (255). The LED returns to off when the button is released.
# Components Used:
  Arduino Board (e.g., Arduino Uno)
  LED
  Toggle Button (6 pins)
  Momentary Button (2 pins)
  Resistors (optional, but using internal pull-up resistors)
  Breadboard and Jumper Wires


# Button Configuration
# Toggle Button:
  The button is connected in such a way that pressing it connects the common pin to the normally open (NO) pin.
  Internal pull-up resistors are enabled in the code, meaning the button pin will read HIGH when not pressed and LOW when pressed.
# Momentary Button:
  Connected between the Arduino pin and ground.
  Also uses the internal pull-up resistor.
  Reads HIGH when not pressed and LOW when pressed.
# Code Explanation
  The code initializes the Arduino pins and sets up PWM for the LED. The internal pull-up resistors are enabled, allowing the buttons to work without external resistors.
