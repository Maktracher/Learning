//
// Created by Adminchik on 06.03.2025.
//

#ifndef PLAYER_H
#define PLAYER_H

class Player : public Board
{
public:
    void playerMove()
    {
        int figure;
        int row;
        int col;

        std::cout << "Select figure" << std::endl;
        std::cin >> figure;
        std::cout << "Select row" << std::endl;
        std::cin >> row;
        std::cout << "Select col" << std::endl;
        std::cin >> col;

        pieceMove(figure, row, col);

    }
};



#endif //PLAYER_H
