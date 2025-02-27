### Für David
Hallo David, ich hoffe du hast etwas Spaß mit meinem Spiel :). 
Die .exe Dateien befinden sich in SnakeGame-master/x64/Debug bzw. SnakeGame-master/x64/Release. 
Warum diese beiden Dateien unterschiedlich sind, habe ich weiter unten erklärt. 
Im Ordner SnakeGame-master/SnakeGame gibt es auch einen x64-Ordner mit den beiden Unterordnern Debug und Release.
Darin sind allerdings nicht die richtigen Builds, sondern nur die .exe-recipes.
Um die Builds auszuführen musst du noch in den Eigenschaften unter Allgemein unter Sicherheit den Haken setzen.

Du kannst zur Not das Repository (https://github.com/FloJCodes/SnakeGame.git) auch in Visual Studio klonen und es dort ausführen. Die Projekteinstellungen sollten alle stimmen.

Viel Spaß :)

Flo


# SnakeGame

This game is a version of the classical Snake-Game. It was written in C++ with the SFML-Library.
You can control the snake to eat random spawning food to get bigger. You die if you hit a wall or yourself.


## Requirements
- **Visual Studio**: Version 2022 or higher.
- **Operating System**: Windows (tested on Windows 10).

The Repository already contains all necessary builds (Debug and Release) and project properties. The Project can be immediately opened and executed after cloning it to VS.


## Instructions
Due to a problem with SFML (Explained in ## Known Problems) there are two different builds in x64/Debug and x64/Release. 
The Debug build contains a bug which causes the snake to completely turn around if two inputs are pressed fast enough after each other. 
This turn is forbidden and causes a loss of the game. To prevent that and have more fun with the game I recommend playing the Release build. 
It only contains the "endGame condition" for wall collisions. This build allows the snake to pass through itself (which is much more snake-like if you ask me :) )
In either of the builds you control the snake with WASD or the Arrow-Keys.


## Project structure
- main.cpp calls the Game class and runs the main loop
- the Game class acts as the Game engine
  - it initializes, updates and renders the Window and the necessary Variables
  - it also handles all incoming events
- the Snake class contains the "parts" vector which represents the snake and all functions related to it
- the Food class contains the coordinates of the current food as well as the spawn function for new food


## Known Problems
The direct counter movement to a direction is forbidden by Code. The programm will not set the direction of the snake to "LEFT" if the former direction was "RIGHT".
But if the inputs "UP","LEFT" oder "DOWN","LEFT" are pressed fast enough after another the program will recognize the former direction as not "RIGHT" so the new direction "LEFT" is allowed
before the snake had made the first move in the "UP" or "DOWN" direction. The interval of the two inputs is 0.1 seconds.


## Third Party Services
The basic structure of main.cpp and Game class is from a Tutorial series by https://www.youtube.com/@SurajSharmaFourKnob.
The complete rebuilt tutorial game is in my GitHub aswell: https://github.com/FloJCodes/DefendGame.git.
I rebuilt the tutorial game to snake with a bit of help from AI for problem solving.

## Contact
You can contact me via email: flojcodes@gmail.com
