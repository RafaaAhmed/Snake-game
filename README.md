# Snake-game
Snake game created with C++ for OOP project
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
Gets user input (WASD) and updates movement direction.
# logic()
- Moves snake head
- Checks collisions (walls, self)
- Handles food eating
- Moves tail segments
# run()
Main game loop: draw → input → logic → wait.
# Game control
  Flow:
1. Initialize game
2. Loop: display → get input → update. game → delay.
3. End when collision occurs.
# Game loop
```
while (!gameOver) {
    draw();     // Show current state
    input();    // Get player move
    logic();    // Update positions
    usleep();   // Wait 100ms
}
```
# Movement
- Head moves based on direction.
- Each tail segment follows the one in front.
- New segment added when food is eaten.
