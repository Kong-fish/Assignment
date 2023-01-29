//This will be the main code we will edit 
//Please familliar with Github cause it shares code and easy to work with more than sharing on googele doc
// let fight for three days no sleep 

#include <iostream>
#include <fstream>
using namespace std;

const int MAX_ROWS = 100;
const int MAX_COLS = 100;
char board[MAX_ROWS][MAX_COLS];

// Alien and Zombie variables
int alienX, alienY;
int zombies[MAX_ROWS * MAX_COLS];
int numZombies;

// Game settings
int numRows, numCols;

void initializeBoard() {
   // Clear board
   for (int i = 0; i < numRows; i++) {
       for (int j = 0; j < numCols; j++) {
           board[i][j] = '.';
       }
   }
   // Place Alien at center of board
   alienX = numRows / 2;
   alienY = numCols / 2;
   board[alienX][alienY] = 'A';
   // Place Zombies randomly on board
   for (int i = 0; i < numZombies; i++) {
       int x, y;
       do {
           x = rand() % numRows;
           y = rand() % numCols;
       } while (board[x][y] != '.');
       board[x][y] = 'Z';
       zombies[i] = x * numCols + y;
   }
}

void displayBoard() {
   // Display column numbers
   if (numCols >= 10) {
       cout << " ";
       for (int i = 0; i < numCols; i++) {
           cout << i % 10;
       }
       cout << endl;
   }


   for (int i = 0; i < numRows; i++) {
       // Display row number
       if (numRows >= 10) {
           cout << i % 10 << " ";
       }

       for (int j = 0; j < numCols; j++) {
           cout << board[i][j];
       }
       cout << endl;
   }
}

void moveAlien(int x, int y) {
   if (x < 0 || x >= numRows || y < 0 || y >= numCols) {
       cout << "Invalid move." << endl;
       return;
   }

   if (board[x][y] == 'Z') {
       cout << "You defeated a Zombie!" << endl;
       for (int i = 0; i < numZombies; i++) {
           if (zombies[i] == x * numCols + y) {
               zombies[i] = -1;
               break;
           }
       }
   }

   board[alienX][alienY] = '.';
   alienX = x;
   alienY = y;
   board[alienX][alienY] = 'A';
}


void saveGame(string fileName) {
   ofstream outFile(fileName);
   outFile << numRows << " " << numCols << endl;
   outFile << alienX << " " << alienY << endl;
   outFile << numZombies << " ";
   for (int i = 0; i < numZombies; i++) {
       outFile << zombies[i] << " ";
   }
   outFile << endl;
   for (int i = 0; i < numRows; i++) {
       for (int j = 0; j < numCols; j++) {
           outFile << board[i][j];
       }
       outFile << endl;
   }
   outFile.close();
   cout << "Game saved successfully." << endl;
}

void loadGame(string fileName) {
   ifstream inFile(fileName);
   inFile >> numRows >> numCols;
   inFile >> alienX >> alienY;
   inFile >> numZombies;
   for (int i = 0; i < numZombies; i++) {
       inFile >> zombies[i];
   }
   for (int i = 0; i < numRows; i++) {
       for (int j = 0; j < numCols; j++) {
           inFile >> board[i][j];
       }
   }
   inFile.close();
   cout << "Game loaded successfully." << endl;
}

int main() {
   srand(time(0));

   cout << "Welcome to Alien vs Zombie!" << endl;
   cout << "Enter the number of rows for the game board (odd number): ";
   cin >> numRows;
   while (numRows % 2 == 0) {
       cout << "Number of rows must be an odd number. Please enter again: ";
       cin >> numRows;
   }

   cout << "Enter the number of columns for the game board (odd number): ";
   cin >> numCols;
   while (numCols % 2 == 0) {
       cout << "Number of columns must be an odd number. Please enter again: ";
       cin >> numCols;
   }

   cout << "Enter the number of Zombies on the board: ";
   cin >> numZombies;
   while (numZombies > (numRows * numCols) - 1) {
       cout << "Too many Zombies for the board size. Please re-enter again: ";
       cin >> numZombies;
   }

   initializeBoard();
   displayBoard();

   char choice;
   int x, y;
   while (true) {
       cout << "Enter move (W - up, A - left, S - down, D - right, Q - quit, S - save, L - load): ";
       cin >> choice;

       if (choice == 'W') {
           x = alienX - 1;
           y = alienY;
       }
       else if (choice == 'A') {
           x = alienX;
           y = alienY - 1;
       }
       else if (choice == 'S') {
           x = alienX + 1;
           y = alienY;
       }
       else if (choice == 'D') {
           x = alienX;
           y = alienY + 1;
       }
       else if (choice == 'Q') {
           break;
       }
       else if (choice == 'S') {
           string fileName;
           cout << "Enter the file name to save the game: ";
           cin >> fileName;
           saveGame(fileName);
           continue;
       }
       else if (choice == 'L') {
           string fileName;
           cout << "Enter the file name to load the game: ";
           cin >> fileName;
           loadGame(fileName);
           continue;
       }
       else {
           cout << "Invalid choice." << endl;
           continue;
       }

       moveAlien(x, y);
       displayBoard();
   }


   cout << "Thank you for playing Alien vs Zombie!" << endl;

   return 0;
}
