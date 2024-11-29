# My Hunter Game

## Overview

My Hunter is a simple and engaging video game inspired by the classic Duck Hunt. The game is developed in C using the CSFML library, focusing on user input, animated sprites, and scalable gameplay design.

The goal of the game is to shoot ducks while avoiding letting them escape. If three ducks reach the edges of the screen, the player loses the game.

## Features

    Duck Shooting Gameplay: Click on ducks to shoot them and score points.
    Escape Mechanic: Lose the game if three ducks escape.
    Interactive Menu: Access and exit the menu with the ESC key or button.
    Game Dynamics:
        Animated duck sprites move across the screen.
        Real-time user input with mouse clicks.
    Score Tracking: Keep track of your performance with an in-game score counter.

## Requirements

**Lib :**
- CSFML library

## Installation

- Download the .zip in **download** branch, unzip and execute the my_hunter file:

      ./my_hunter

**OR**

- Clone this repository to your local machine:

      git clone <repository_url>
      cd my_hunter

  Compile the game using the provided **Makefile**:

      make

    This will generate the my_hunter executable.

## How to Play

    Run the game:
        Start gameplay: ./my_hunter
        View help: ./my_hunter -h

    Controls:
        Menu Navigation:
            Press ESC to access the menu or quit the game.
            Press the Play button to resume gameplay.
        Gameplay:
            Click on ducks to score points.
            Avoid letting ducks escape—if three ducks reach the screen's border, the game ends.

    Objective:
        Shoot as many ducks as possible to maximize your score.

## Development Notes

    Programming Language: C
    Graphics Library: CSFML
    Compilation Rules:
        Use make to compile the project.
        Cleaning commands:

        make clean     # Remove object files
        make fclean    # Remove object files and binaries

    Error Handling:
        Errors are written to the standard error output.
        Exits with error code 84 for failures, and 0 for successful runs.

## Credits

    Developed By: ThePepidev
    Inspired by the classic Duck Hunt.
    For more information, refer to Duck Hunt Wiki.

## License

This project is OpenSource and totally free to use !
