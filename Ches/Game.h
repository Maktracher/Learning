//
// Created by Adminchik on 06.03.2025.
//

#ifndef GAME_H
#define GAME_H

class Game : public Player
{
private:
public:
    void startGame()
    {
        addPieceOnTable();
        EnableANSI();
        while (true) // Гра в нескінченному циклі (в майбутньому можна додати вихід)
        {
            table();  // Відображаємо шахівницю
            playerMove();  // Гравець робить хід
        }
    }
};



#endif //GAME_H
