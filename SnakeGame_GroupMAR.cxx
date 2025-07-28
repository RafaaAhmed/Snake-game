#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };

class SnakeGame {
private:
    bool gameOver;
    int width = 20, height = 10;
    int x, y, foodX, foodY, score;
    Direction dir;
    vector<pair<int, int>> tail;

public:
    SnakeGame() {
        gameOver = false;
        dir = STOP;
        x = width / 2;
        y = height / 2;
        srand(time(0));
        generateFood();
        score = 0;
    }

    void generateFood() {
        do {
            foodX = rand() % width;
            foodY = rand() % height;
        } while (isFoodOnSnake());
    }

    bool isFoodOnSnake() {
        if (foodX == x && foodY == y) return true;
        for (auto segment : tail) {
            if (segment.first == foodX && segment.second == foodY)
                return true;
        }
        return false;
    }

    void draw() {
        system("clear");
        cout << "----------------------" << endl;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (i == y && j == x)
                    cout << "O";
                else if (i == foodY && j == foodX)
                    cout << "F";
                else {
                    bool printed = false;
                    for (auto t : tail) {
                        if (t.first == j && t.second == i) {
                            cout << "o";
                            printed = true;
                            break;
                        }
                    }
                    if (!printed)
                        cout << " ";
                }
            }
            cout << endl;
        }
        cout << "----------------------" << endl;
        cout << "Score: " << score << endl;
        cout << "Use WASD to move, x to quit" << endl;
    }

    void input() {
        char ch;
        cout << "Move: ";
        cin >> ch;
        switch (ch) {
            case 'a': 
            case 'A': 
                if (dir != RIGHT) dir = LEFT; 
                break;
            case 'd': 
            case 'D': 
                if (dir != LEFT) dir = RIGHT; 
                break;
            case 'w': 
            case 'W': 
                if (dir != DOWN) dir = UP; 
                break;
            case 's': 
            case 'S': 
                if (dir != UP) dir = DOWN; 
                break;
            case 'x': 
            case 'X': 
                gameOver = true; 
                break;
        }
    }

    void logic() {
        if (dir == STOP) return;
        pair<int, int> prev = { x, y };
        switch (dir) {
            case LEFT: x--; break;
            case RIGHT: x++; break;
            case UP: y--; break;
            case DOWN: y++; break;
            default: break;
        }
        if (x < 0 || x >= width || y < 0 || y >= height) {
            gameOver = true;
            return;
        }
        for (auto segment : tail) {
            if (segment.first == x && segment.second == y) {
                gameOver = true;
                return;
            }
        }
        if (x == foodX && y == foodY) {
            score += 10;
            tail.push_back({ -1, -1 });
            generateFood();
        }
        if (!tail.empty()) {
            for (int i = tail.size() - 1; i > 0; i--) {
                tail[i] = tail[i - 1];
            }
            tail[0] = prev;
        }
    }

    void run() {
        while (!gameOver) {
            draw();
            input();
            logic();
            usleep(100000);
        }
        cout << "Game Over! Final Score: " << score << endl;
    }
};

int main() {
    cout << "Welcome to Snake Game!" << endl;
    cout << "Use WASD to move, x to quit" << endl;
    cout << "Press Enter to start...";
    cin.get();
    
    SnakeGame game;
    game.run();
    return 0;
}