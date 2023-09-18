# Smart-Home-System
The focus of this project is on creating a smart home system.

Used Drivers:

1-DIO

2-Keypad

3-LCD

4-Timer 0

5-Timer 1

6-UART

7-ADC


Used Components :

-2 Microcontroller (Atmega32)

-Temperature Sensor(LM35)

-Light Sensor (LDR)

-Speaker

-Servo Motor 

-DC Motor

-Keypad

-2 LCD

-4 LEDS

-6 Buttons


Now, let me guide you through the intriguing features and functionalities of the project:

1. Password Protection: The system employs password protection to ensure security. The user is prompted to enter a password, and they have three attempts to input the correct password. If the password is still incorrect after three tries, the system activates visual and auditory indicators to alert the user, such as toggling the LED and activating the buzzer until the system is turned off.

2. Door Opening: The first microcontroller is responsible for controlling the door's opening and closing mechanism. It utilizes a servo motor to physically indicate the door's movements. When the correct password is entered, the servo motor rotates to simulate the door opening.

3. Temperature Sensing and Fan Control: The second microcontroller incorporates a temperature sensor to monitor the ambient temperature. The temperature is displayed on the LCD screen once the correct password is entered. Depending on the temperature reading, the system controls a DC motor that represents a fan. If the temperature is below 30 degrees, the fan remains off. Between 30 and 45 degrees, the fan rotates at a certain speed, and if the temperature exceeds 45 degrees, the fan operates at a higher speed.

4. Light Sensing and LED Control: The second microcontroller also includes a light sensor to detect the level of ambient light. When the environment becomes too dark, the light sensor triggers the activation of LEDs to provide lighting.

5. Manual and Auto Modes: The system offers both manual and auto modes. In the manual mode, the user can control the fan speed using buttons. Separate buttons are also provided to manually turn on the LEDs for lighting purposes.

Overall, the smart home system integrates multiple components, including microcontrollers, LCDs, buzzers, LEDs, servo motors, temperature sensors, light sensors, and DC motors, to create a secure and automated environment. It offers password protection, door control, temperature monitoring, fan control, lighting control, and user interaction through manual and auto modes.
