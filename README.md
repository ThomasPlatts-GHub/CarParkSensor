# Car Parking Sensor
<hr>
<p>This project was made with an Arduino Mega2560. I have linked 2 videos which i have had to split down due to file size restrictions from uploading directly through GitHub.</p>
# Project Summary
<hr>
<p>Here in this project, we use an Ultrasonic Distance Sensor (HC-SR04 to be exact) alongside a 16x2 LCD and a simple button to act as the exit "sensor". Alongside these components i used a servo which acted as the barrier to the car park (In later iterations i will add another sensor in place of the button and i will 3d print my own "barrier" with a mount to attach it to my servo for more realism). Looking at the code i used 2 libraries LiquidCrystal and Servo. These allow me to control the outputs to my LCD and Servo.</p>
# How To Run Yourself
<hr>
<p>The most difficult part in all of this is wiring up the circuity. If you have experience this won't be to bad but I soon will create an online blueprint for this circuitry which you can follow closely to wire all of this together. Then all you need is to download the libraries which are in the Platform.ini file within the CarParkSensor folder. Once you have these libraries sorted and have downloaded my code, change any pin numbers you need and all should be good. If not double check connections are correct and you can also use this link <a target="_blank">https://lastminuteengineers.com/arduino-1602-character-lcd-tutorial/</a> to see how to wire the 16x2 LCD. If there are any other problems feel free to comment in this repository.</p>
