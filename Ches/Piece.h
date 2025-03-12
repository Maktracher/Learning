#ifndef PIECE_H
#define PIECE_H

#include <iostream>

class Piece
{
private:
    struct Figure {
        int index;
        int type;
        int row;
        int col;

        Figure(int index, int type, int row, int col) : index(index), type(type), row(row), col(col) {};
    };

    std::vector<Figure> figures;

public:
    void addPiece(int index, int type, int row, int col) {
        figures.push_back(Figure(index, type, row, col));
    }

    void printPiece(int row, int col)
    {
        bool found = false;
        for (const auto& figure : figures)
            {
            if (figure.row == row && figure.col == col)
                {
                switch (figure.type)
                {
                    case 1: std::cout << "K "; break; // King
                    case 2: std::cout << "Q "; break; // Queen
                    case 3: std::cout << "B "; break; // Bishop
                    case 4: std::cout << "N "; break; // Knight
                    case 5: std::cout << "R "; break; // Rook
                    case 6: std::cout << "P "; break; // Pawn
                    default: std::cout << ". "; break;
                }
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << ". ";
        }
    }

    void pieceMove(int index, int row, int col)
    {
        for (auto& figure : figures)
        {
            if (figure.index == index)
            {
                for (auto& other : figures)
                {
                    if (other.row == row && other.col == col)
                    {
                        other.row = -1;
                        other.col = -1;
                    }
                }
                figure.row = row;
                figure.col = col;
                return;
            }
        }
    }
};



#endif //PIECE_H
