# Alien vs. Zombie

On a planet far far away from earth, a young alien is fighthing unknown zombies that invade his home planet. Help this young alien to protect his home.

You as a player will help this alien to navigate his way to defeat the zombies and keep his home save.

Alien vs. Zombie is a text-based game where player are able to input simple command to control the character which is the alien. The alien will be able to defeat the zombies by attacking the zombie.

The player will use simple command such as up(^), down(v), left(<) and right(>) to move around the game board and attack the zombies.

There will be multiple game object where player will be able to interact with to make the game even more fun. XD
![Game Board Generation](https://github.com/Kong-fish/Assignment/blob/main/Screenshot/Screenshot%20(84).png)
![Display Help](https://github.com/Kong-fish/Assignment/blob/main/Screenshot/Screenshot%20(85).png)


Please provide the YouTube link to your [Video Demo](https://youtu.be/x4x--XBjtP4).

## Compilation Instructions

1. Download file into local machine
First, Player is advice to download the whole program as a zip file into local machine.
2. Unzip the zip file.
3. Right click on the main.cpp application file.
4. Choose the option copy as path. Then player will get the path directed to the program.
Player may use their choice of command shell to open up the application.
5. Paste the copied path and enjoy!

```
g++ main.cpp folder1\code.cpp folder2\code.cpp ......
```

## User Manual

1. Generation of game board
User will be choose between three set of default difficulity with different rows and and coloums for game board size. There is also different numbers of zombies that user need to defeat for each difficulity. 
User can choose between three default which is 
:Easy (Rows = 5, Colums = 9, Zombies = 1)
:Normal (Rows = 9, Colums = 11, Zombies = 2) 
:Hard (Rows = 13, Colums = 15, Zombies = 3). 
User is able to change the default settings of the game board too. 
Player are able to move around the generated game board. Invalid input will shown if the player move the Alien out of bounds. Zombie will also move randomly in the game board.

2. Game Character and Game Objects
Alien (A) is the character that player able to control.
Zombie (Z) will be the non-player character that player need to defeat by passing around the zombies.
Rock (r) is an obstacle object that will block the Alien path. It will turn into another game object after Alien bumping into the rock.
Arrow (^,v,<,>) is game objects that that allow Alien to change its path.

3. Player Input
Player able to input lower or uppercase of the alphabet symbolize each input.
W key will be moving Alien up.
A key will be moving Alien to the left
D key will be moving Alien to the right.
S key will be moving Alien to the bottom
Q key will let player to end the game.
V key will let the player to save it game.
L key will let player load previous game file.
H key will display the Player Input explaination.

## Progress Log

- [Part 1](PART1.md)
- [Part 2](PART2.md)

## Contributors

- Kong Xin Yu
- Chan Yeng Hui
- Wong Wai Yee


