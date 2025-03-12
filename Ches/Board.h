//
// Created by Adminchik on 06.03.2025.
//

#ifndef BOARD_H
#define BOARD_H
#include "Piece.h"

class Board : public Piece
{
private:

public:
    Board(){};
    static void EnableANSI()
    {
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD dwMode = 0;
        GetConsoleMode(hOut, &dwMode);
        SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    }

    void table()
    {
        const int size = 8;

        std::cout <<" " << " " << "A " << "B " << "C " << "D " << "E " << "F " << "G " << "H " << std::endl;

        for (int row = 1; row <= size; row++)
        {
            std::cout << row << " ";
            for (int col = 1; col <= size; col++)
            {
                printPiece(row,col);
                // if (row == 1 && col == 1)
                //     King();
                // else if (row == 1 && col == 2)
                //     Bishop();
                // if (row > 1 && row < size)
                // {
                //     if ((row + col) % 2 == 0)
                //     {
                //         std::cout << "\033[47m  \033[0m";
                //     }
                //     else
                //     {
                //         std::cout << "\033[40m  \033[0m";
                //     }
                // }
            }
            std::cout << std::endl;
        }
    }

    void addPieceOnTable()
    {
        const int size = 8;
        int index = 1;
        for (int col = 1; col <= size; col++)
        {
            addPiece(index++,1,1,5);
            addPiece(index++,1,8,4);

            addPiece(index++,2,1,4);
            addPiece(index++,2,8,5);

            if (col == 3 || col == 6)
            {
                addPiece(index++, 3,1,col);
                addPiece(index++, 3,8,col);
            }
            else if (col == 2 || col == 7)
            {
                addPiece(index++, 4,1,col);
                addPiece(index++, 4,8,col);
            }
            else if (col == 1 || col == 8)
            {
                addPiece(index++, 5,1,col);
                addPiece(index++, 5,8,col);
            }

            addPiece(index++, 6,2,col);
            addPiece(index++, 6,7,col);
        }
    }
};



#endif //BOARD_H
