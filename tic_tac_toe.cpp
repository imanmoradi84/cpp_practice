#include <iostream>
#include <ctime>
#include <cstdlib>

// call the functions
void drawboard(char *space);
void player_move(char *space, char player);
void computer_move(char *space, char computer);
bool check_winner(char *space, char player, char computer);
bool check_tie(char *space);

// main funtion
int main()
{
    char space[9] ={' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawboard(space);
    
    while(running)
    {
    player_move(space, player);
    drawboard(space);
    
    if(check_winner(space, player, computer))
    {
        running = false;
        break;
    }
    else if(check_tie(space))
    {
        running = false;
        break;
    }

    computer_move(space, computer);
    drawboard(space);
    if(check_winner(space, player, computer))
    {
        running = false;
        break;
    }
    else if(check_tie(space))
    {
        running = false;
        break;
    }

    }
    return 0;
}

// define the funtions
void drawboard(char *space)
{
    std::cout << "      |      |      \n";
    std::cout << "  " << space[0] << "   |  " << space[1] << "   |  " << space[2] << "   \n";
    std::cout << "______|______|______\n";
    std::cout << "      |      |      \n";
    std::cout << "  " << space[3] << "   |  " << space[4] << "   |  " << space[5] << "   \n";
    std::cout << "______|______|______\n";
    std::cout << "      |      |      \n";
    std::cout << "  " << space[6] << "   |  " << space[7] << "   |  " << space[8] << "   \n";
    std::cout << "      |      |      \n";
    std::cout << "************************\n";
}
void player_move(char *space, char player) 
{
    int number;
    do {
        std::cout << "Enter a spot to place a marker (1-9): ";
        std::cin >> number;
        if (number >= 1 && number <= 9 && space[number - 1] == ' ') 
        {
            space[number - 1] = player;
            break;
        } else {
            std::cout << "Invalid move. Try again." << std::endl;
        }
    } while (true);
}
void computer_move(char *space, char computer)
{
    int number;
    srand(time(0));

    while(true)
    {
        number = rand() % 9;
        if(space[number] == ' ')
        {
            space[number] = computer;
            break;
        }
    }
    

}
bool check_winner(char *space, char player, char computer)
{
    // horizontal
    if((space[0] != ' ') && (space[0] == space[1]) && (space[1] == space[2]))
    {
        space[0] == player ? std::cout << "YOU WON\n" : std::cout << "YOU LOSE\n";
    }

    else if((space[3] != ' ') && (space[3] == space[4]) && (space[4] == space[5]))
    {
        space[3] == player ? std::cout << "YOU WON\n" : std::cout << "YOU LOSE\n";
    }
    
    else if((space[6] != ' ') && (space[6] == space[7]) && (space[7] == space[8]))
    {
        space[6] == player ? std::cout << "YOU WON\n" : std::cout << "YOU LOSE\n";
    }
    // perpendicular
    else if((space[0] != ' ') && (space[0] == space[3]) && (space[3] == space[6]))
    {
        space[0] == player ? std::cout << "YOU WON\n" : std::cout << "YOU LOSE\n";
    }

    else if((space[1] != ' ') && (space[1] == space[4]) && (space[4] == space[7]))
    {
        space[1] == player ? std::cout << "YOU WON\n" : std::cout << "YOU LOSE\n";
    }

    else if((space[2] != ' ') && (space[2] == space[5]) && (space[5] == space[8]))
    {
        space[2] == player ? std::cout << "YOU WON\n" : std::cout << "YOU LOSE\n";
    }
    // diagonal
    else if((space[0] != ' ') && (space[0] == space[4]) && (space[4] == space[8]))
    {
        space[0] == player ? std::cout << "YOU WON\n" : std::cout << "YOU LOSE\n";
    }

    else if((space[2] != ' ') && (space[2] == space[4]) && (space[4] == space[6]))
    {
        space[2] == player ? std::cout << "YOU WON\n" : std::cout << "YOU LOSE\n";
    }
    else
    {
        return false;
    }
    return true;
}
bool check_tie(char *space)
{
    for(int i = 0; i < 9; i++)
    {
        if(space[i] = ' ')
        {
            return false;
        }
    }
    std::cout << "IT'S A TIE";
    return true;
}