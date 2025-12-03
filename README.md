## 🚗 Car Game

A simple console-based driving game implemented in C++.

-----

### 📝 Description

This is a basic terminal-based game where the player controls a **car** (`<^^>`) and must avoid a falling **obstacle** (`[**]`). The game board is a 3-lane road displayed in the console. The objective is to survive as long as possible by dodging the obstacle as it moves down the screen.

-----

### ⚙️ How to Play

1.  **Compile and Run:** Compile the C++ code using a standard C++ compiler (like g++):
    ```bash
    g++ car_game.cpp -o car_game
    ./car_game
    ```
    *(Note: The name `car_game.cpp` is an assumption for the source file.)*
2.  **Controls:** Use the following keys to move your car:
      * **`a`**: Move **Left** (Change lane to the left)
      * **`d`**: Move **Right** (Change lane to the right)
      * **`w`**: Move **Up** (Move car up the road)
      * **`s`**: Move **Down** (Move car down the road)
3.  **Objective:**
      * Avoid colliding with the obstacle (`[**]`).
      * Each time the obstacle successfully passes the car's vertical position and resets, your **Score** increases.
4.  **Game Over:** The game ends (`gameover = 1`) when your car (`<^^>`) occupies the same lane (`x`) and row (`y`) as the obstacle (`[**]`).

-----

### 🧱 Core Logic

  * **Player Car:** Represented by `x` (lane: 1-3) and `y` (row: 0-20). Displayed as `<^^>`.
  * **Obstacle:** Represented by `ex` (lane) and `ey` (row). Displayed as `[**]`.
  * **Movement:** The car's position changes based on the user's input (`w/a/s/d`).
  * **Obstacle Movement:** The obstacle moves one row down in each game loop iteration (`ey++`).
  * **Scoring/Reset:** When the obstacle reaches the bottom of the road (`ey > 20`), the `score` increments, and the obstacle resets to the top (`ey = 0`) in a different lane (`ex`) following a cycle (1 -\> 2 -\> 3 -\> 1).
  * **Screen Clear:** The loop includes a temporary screen-clear method using 100 newline characters (`\n`).
