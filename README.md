# Snake-game
Snake game written in C++ for OOP project
# Variables
```cpp
- bool gameOver;                    // Flag to indicate game state
- int width = 20, height = 10;      // Game board dimensions
- int x, y;                         // Snake head coordinates
- int foodX, foodY;                 // Food coordinates
- int score;                        // Player score
- Direction dir;                    // Current movement direction
- vector<pair<int, int>> tail;      // Coordinates of tail segments
```
# Functions
- main
- SnakeGame
- generateFood
- isFoodOnSnake
- draw
- input
- logic
- run
# main()
Program entry point, creates game and starts it.
# SnakeGame()
Initializes game variables and places first food.
# generateFood()
Places food at random position that's not on snake.
# isFoodOnSnake()
Checks if food overlaps with snake body.
# draw()
Clears screen and displays game board with snake, food, and score.
# input()
Gets user input (WASD or X) and updates movement direction.
# logic()
- Moves snake head
- Checks collisions (walls, self)
- Handles food eating
- Moves tail segments
# run()
Main game loop: draw → input → logic → wait.
# Game control
# Key Action
- W: Move Up.
- A: Move Left
- S: Move Down.
- A: Move Right.
- X: Quit game.
# Flow
 1. Initialize game state.
 2. Repeat:
  - Draw current state.
  -  Get input from player.
  -  Update game logic.
  -  Delay 100ms.
 3. End when collision occurs.
# Game loop
```cpp
while (!gameOver) {
    draw();     // Render the board
    input();    // Handle user input
    logic();    // Update positions, check collisions
    usleep(100000); // Delay
}
```
# Movement
- Head moves based on direction.
- Each tail segment follows the one in front.
- New segment added when food is eaten.
