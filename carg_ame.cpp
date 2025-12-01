#include <iostream>
#include <string>
using namespace std;

const int WIDTH = 30;
const int HEIGHT = 20;

void showMenu() {
    cout << "========================\n";
    cout << "     CAR RACING GAME    \n";
    cout << "========================\n";
    cout << "1. Start Game\n";
    cout << "2. Game Rules\n";
    cout << "3. Quit\n";
    cout << "Enter your choice: ";
}

void showRules() {
    cout << "\n=== GAME RULES ===\n";
    cout << "- Control the car using keys:\n";
    cout << "  w = up, s = down, a = left, d = right\n";
    cout << "- Avoid the falling obstacles (xxx)\n";
    cout << "- Score increases when you successfully avoid an obstacle\n";
    cout << "- The game ends if you collide with an obstacle\n\n";
    cout << "Press Enter to return to menu...";
    cin.ignore();
    cin.get();
}

void startGame() {
    int leftBorder = 8;
    int rightBorder = 21;
    int carPos = (leftBorder + rightBorder) / 2;
    int carRow = HEIGHT - 1;
    int score = 0;

    int obsPos = leftBorder + 1;
    int obsRow = 0;

    while (true) {
        for (int i = 0; i < HEIGHT; i++) {
            string row(WIDTH, ' ');
            row[leftBorder] = '|';
            row[rightBorder] = '|';

            if (i == obsRow) {
                row[obsPos] = 'x';
                row[obsPos + 1] = 'x';
                row[obsPos + 2] = 'x';
            }

            if (i == carRow) {
                if (i == obsRow && carPos >= obsPos && carPos <= obsPos + 2) {
                    cout << row << endl;
                    cout << "\n\n*** GAME OVER ***\n";
                    cout << "Final Score: " << score << endl;
                    return;
                }
                row[carPos] = 'A';
            }

            cout << row << endl;
        }

        cout << "\nScore: " << score;
        cout << "\nMove (w = up, s = down, a = left, d = right, q = quit): ";

        char mv;
        cin >> mv;

        if (mv == 'a' && carPos > leftBorder + 1) carPos--;
        if (mv == 'd' && carPos < rightBorder - 1) carPos++;
        if (mv == 'w' && carRow > 0) carRow--;
        if (mv == 's' && carRow < HEIGHT - 1) carRow++;
        if (mv == 'q') break;

        obsRow++;

        if (obsRow >= HEIGHT) {
            obsRow = 0;
            obsPos += 3;
            if (obsPos + 2 >= rightBorder) obsPos = leftBorder + 1;
            score++;
        }

        cout << string(40, '\n');
    }
}

int main() {
    while (true) {
        showMenu();
        int choice;
        cin >> choice;

        if (choice == 1) {
            startGame();
        } else if (choice == 2) {
            showRules();
        } else if (choice == 3) {
            cout << "Thank you for playing!\n";
            break;
        } else {
            cout << "Invalid choice! Try again.\n";
        }

        cout << string(40, '\n'); 
    }

    return 0;
}