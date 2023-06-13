# Maze Game

This is a simple maze game implemented in C++. The player navigates through a maze, collects treasures, avoids monsters, and tries to achieve the highest score.

## Features

- Move the player character in four directions: up, down, left, and right.
- Shoot in the direction the player is facing to eliminate monsters.
- Collect treasures to increase the score.
- Avoid monsters to prevent score penalties.
- The game ends when the player decides to quit.

## Getting Started

### Prerequisites

- C++ compiler (e.g., GCC or Visual Studio)

### Installation

1. Clone the repository:

   ```shell
   git clone https://github.com/steepcloud/Maze-Game.git
   ```
2. Navigate to the project directory:
   ```shell
   cd Maze-Game/Maze
   ```
3. Compile for the source code:
   - For GCC:
   ```shell
   g++ Maze.cpp -o Maze
   ```
   - For Visual Studio (via Developer Command Prompt):
   ```shell
   cl Maze.cpp
   ```
4. Run the executable:
   - For GCC:
   ```shell
   ./Maze
   ```
   - For Visual Studio:
   ```shell
   Maze.exe
   ```

## How to play
Use the following controls to navigate through the maze:

i: Move up
j: Move left
k: Move down
l: Move right
s: Shoot in the direction the player is facing
q: Quit the game
The maze is represented by a grid, and each cell has a specific symbol representing its content:

1: Wall
0: Clear path
^, v, <, >: Player character facing up, down, left, and right, respectively
T: Treasure
M: Monster
The objective is to collect treasures, avoid monsters, and achieve the highest score possible.

## Contributing
Contributions are welcome! If you have any ideas, improvements, or bug fixes, please open an issue or submit a pull request.

## License
This project is licensed under the [MIT](https://choosealicense.com/licenses/mit/) license.
