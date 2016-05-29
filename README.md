# gaming_console
Accelerometer based Gaming Console. Code for STM32F4 Discovery board.

We developed a standalone gaming device for a multiplayer Artillery Game. The
users/players are able to provide inputs to their player characters from the on
board accelerometer of the STM32F4Discovery microcontroller and the game is
played on an LCD interfaced with the board. 

This gaming device allows the user to connect with each other by communicating through 
GPIO ports as one of the board acting as the main controller and other as the child controller. 

LCD displays the movements of both the players in real time according to the accelerometer reading.
The players are represented by symbolic military tanks (square in shape) with the
capability to launch missiles. The accelerometer inputs allow the players to guide
their tanks and button press input guides the missiles in order to maximize the hit
on the opponent. The objective of the game is to destroy the opponent‟s tank.

