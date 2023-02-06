// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT3L
// Names: KONG XIN YU | CHAN YENG HUI | WONG WAI YEE
// IDs: 1221303689 | 1221303663 | 1221303660
// Emails: 1221303689@student.mmu.edu.my | 1221303663@student.mmu.edu.my | 1221303660@student.mmu.edu.my
// Phones: 0162070751 | 0194759378 | 0129342913
// *********************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "pf/helper.cpp"
using namespace std;

const int MAX_ROWS = 100;
const int MAX_COLS = 100;
char board[MAX_ROWS][MAX_COLS];

// Alien and Zombie variables
int alienX, alienY;
int zombies[MAX_ROWS * MAX_COLS];
int numZombies;

// Game Board settings
int numRows, numCols;

void defaultGameSettings()
{
    int defRows = 5;
    int defCols = 5;
    int defZombies = 1;

    cout << "Default Game Settings" << endl;
    cout << "-----------------------" << endl;
    cout << "Board Rows    : " << defRows << endl;
    cout << "Board Colums  : " << defCols << endl;
    cout << "Zombie Count  : " << defZombies << endl;

    char gameSetChange;
    cout << "Do you wish to change the game settings (y/n)? => ";
    cin >> gameSetChange;

    if (gameSetChange == 'N' || gameSetChange == 'n')
    {
        numRows=defRows;
        numCols=defCols;
        numZombies=defZombies;
    }
    else
    {
        cout << "Enter the number of rows for the game board (odd number): ";
        cin >> numRows;
        while (numRows % 2 == 0)
        {
            cout << "Number of rows must be an odd number. Please enter again: ";
            cin >> numRows;
        }

        cout << "Enter the number of columns for the game board (odd number): ";
        cin >> numCols;
        while (numCols % 2 == 0)
        {
            cout << "Number of columns must be an odd number. Please enter again: ";
            cin >> numCols;
        }

        cout << "Enter the number of Zombies on the board: ";
        cin >> numZombies;
        while (numZombies > (numRows * numCols) - 1)
        {
            cout << "Too many Zombies for the board size. Please re-enter again: ";
            cin >> numZombies;
        }
    }
}

void initializeBoard()
{
    // Clear board
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            board[i][j] = ' ';
        }
    }
    // Place Alien at center of board
    alienX = numRows / 2;
    alienY = numCols / 2;
    board[alienX][alienY] = 'A';
    // Place Zombies randomly on board
    for (int i = 0; i < numZombies; i++)
    {
        int x, y;
        do
        {
            x = rand() % numRows;
            y = rand() % numCols;
        } while (board[x][y] != ' ');
        board[x][y] = 'Z';
    }
}

void displayBoard()
{
    cout << " . : Alien vs Zombie : ." << endl;
    // for each row
    for (int i = 0; i < numRows; ++i)
    {
        // display upper border of the row
        cout << "   ";
        for (int j = 0; j < numRows; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;

        // display row number
        cout << setw(2) << (i + 1) << " ";

        // display cell content and border of each column
        for (int j = 0; j < numRows; ++j)
        {
            cout << "|" << board[i][j];
        }
        cout << "|" << endl;
    }
    // display lower border of the last row
    cout << "   ";
    for (int j = 0; j < numRows; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;
    // display column number
    cout << "    ";
    for (int j = 0; j < numCols; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << "   ";
    for (int j = 0; j < numCols; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl;
}

void moveAlien(int x, int y)
{
    // make sure Alien always stay in game board
    if (x < 0 || x >= numRows || y < 0 || y >= numCols)
    {
        cout << "Invalid move." << endl;
        return;
    }

    if (board[x][y] == 'Z')
    {
        cout << "You defeated a Zombie!" << endl;
        for (int i = 0; i < numZombies; i++)
        {
            if (zombies[i] == x * numCols + y)
            {
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

void saveGame(string fileName)
{
    ofstream outFile(fileName);
    outFile << numRows << " " << numCols << endl;
    outFile << alienX << " " << alienY << endl;
    outFile << numZombies << " ";
    for (int i = 0; i < numZombies; i++)
    {
        outFile << zombies[i] << " ";
    }
    outFile << endl;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            outFile << board[i][j];
        }
        outFile << endl;
    }
    outFile.close();
    cout << "Game saved successfully." << endl;
}

void loadGame(string fileName)
{
    ifstream inFile(fileName);
    inFile >> numRows >> numCols;
    inFile >> alienX >> alienY;
    inFile >> numZombies;
    for (int i = 0; i < numZombies; i++)
    {
        inFile >> zombies[i];
    }
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            inFile >> board[i][j];
        }
    }
    inFile.close();
    cout << "Game loaded successfully." << endl;
}

void gamePause()
{
    cout << "Pausing Now" << endl;
    pf::Pause();
    cout << endl;
}

void gameClearScreen()
{
    cout << "Pausing and Clearing Screen Now" << endl;
    pf::Pause();
    pf::ClearScreen();
    cout << endl;
}

int main()
{
    srand(time(0));

    cout << "Welcome to Alien vs Zombie!" << endl;
    defaultGameSettings();
    initializeBoard();
    displayBoard();

    char choice;
    int x, y;
    while (true)
    {
        cout << "Enter move (W - up, A - left, S - down, D - right, Q - quit, V - save, L - load): ";
        cin >> choice;

        if (choice == 'W' || choice == 'w')
        {
            x = alienX - 1;
            y = alienY;
        }
        else if (choice == 'A' || choice == 'a')
        {
            x = alienX;
            y = alienY - 1;
        }
        else if (choice == 'S' || choice == 's')
        {
            x = alienX + 1;
            y = alienY;
        }
        else if (choice == 'D' || choice == 'd')
        {
            x = alienX;
            y = alienY + 1;
        }
        else if (choice == 'Q' || choice == 'q')
        {
            break;
        }
        else if (choice == 'V' || choice == 'v')
        {
            string fileName;
            cout << "Enter the file name to save the game: ";
            cin >> fileName;
            saveGame(fileName);
            continue;
        }
        else if (choice == 'L' || choice == 'l')
        {
            string fileName;
            cout << "Enter the file name to load the game: ";
            cin >> fileName;
            loadGame(fileName);
            continue;
        }
        else
        {
            cout << "Invalid choice." << endl;
            continue;
        }

        moveAlien(x, y);
        gameClearScreen();
        displayBoard();
    }

    cout << "Thank you for playing Alien vs Zombie!" << endl;

    return 0;
}
