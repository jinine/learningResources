#include <iostream>
#include <vector>

using namespace std;

class Board
{
public:
    std::vector<std::vector<std::pair<bool, char>>> board;
    Board()
    {
        board = {
            {
                {0, 'r'}, {0, 'k'}, {0, 'b'}, {0, 'x'}, {0, 'y'}, {0, 'b'}, {0, 'k'}, {0, 'r'},
            },
            {
                {0, 'p'}, {0, 'p'}, {0, 'p'}, {0, 'p'}, {0, 'p'}, {0, 'p'}, {0, 'p'}, {0, 'p'},
            },
            {
                {}, {}, {}, {}, {}, {}, {}, {},
            },
            {
                {}, {}, {}, {}, {}, {}, {}, {},
            },
            {
                {}, {}, {}, {}, {}, {}, {}, {},
            },
            {
                {}, {}, {}, {}, {}, {}, {}, {},
            },
            {
                {1, 'p'}, {1, 'p'}, {1, 'p'}, {1, 'p'}, {1, 'p'}, {1, 'p'}, {1, 'p'}, {1, 'p'},
            },
            {
                {1, 'r'}, {1, 'k'}, {1, 'b'}, {1, 'x'}, {1, 'y'}, {1, 'b'}, {1, 'k'}, {1, 'r'},
            },
        };
    };
    int checkWin()
    {
        return 0; // Placeholder for functionality
    };
};

class Player
{
public:
    bool colour; // 0 for white, 1 for black
    Player(bool colour)
    {
        this->colour = colour;
    }
    Board move(Board board)
    {
        bool occupied = false;
        char piece[2];

        while (!occupied)
        {
            std::cout << "Piece you'd like to move: " << std::endl;
            std::cin >> piece;
            int row = piece[1] - '0'; // Convert char to int
            int col = piece[0] - 'a'; // Assuming input uses chess-style columns (e.g., 'a'-'h')

            if (row >= 0 && row < 8 && col >= 0 && col < 8)
            {
                std::cout << board.board[col][row - 1].second << endl;
                occupied = true; // Placeholder, assumes move succeeds
            }
        }

        return board;
    }
};

class Game
{
public:
    Player white;
    Player black;
    Board board;
    bool currentMove; // true for white, false for black
    int winner;       // 0 for no winner, 1 for white, 2 for black
    Game(Player white, Player black)
        : white(white), black(black), board(Board()), currentMove(true), winner(0) {}

    void start()
    {
        while (winner == 0)
        {
            switch (currentMove)
            {
            case true:
                board = white.move(board);
                winner = board.checkWin();
                currentMove = !currentMove;
                break; 
            case false:
                board = black.move(board);
                winner = board.checkWin();
                currentMove = !currentMove;
                break; 
            }
        }

        switch (winner)
        {
        case 1:
            std::cout << "Winner is White!" << endl;
            break;
        case 2:
            std::cout << "Winner is Black!" << endl;
            break;
        }
    };
};

int main()
{
    Player white = Player(0);
    Player black = Player(1);
    Game game = Game(white, black);
    game.start();
    return 0;
}
