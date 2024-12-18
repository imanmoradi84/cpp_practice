#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    // rock = 1 -- paper = 2 -- scissors = 3
    int choice;
    int player_score = 0;
    int opponent_score = 0;

    srand(time(0));
    cout << "make a choice: \n"
         << "rock --> 1\n"
         << "paper --> 2\n"
         << "scissors --> 3\n"
         << "exit --> 4\n";
    cin >> choice;

    while(true){
        cin >> choice;
        if(choice == 4){
        cout << "***************";
        cout << "see you later!";
        cout << "***************";
        break;
        }
        int randnum = rand() % 3 + 1;
        switch(choice){
            case 1 :
                if(randnum == 1){
                    cout << "***************\n";
                    cout << "it a tie\n";
                    cout << "your score: " << player_score << endl;
                    cout << "opponent score: " << opponent_score << endl;
                    cout << "***************\n";
                }
                else if(randnum == 2){
                    cout << "***************\n";
                    cout << "you lose\n";
                    opponent_score += 1;
                    cout << "your score: " << player_score << endl;
                    cout << "opponent score: " << opponent_score << endl;
                    cout << "***************\n";
                }
                else
                    cout << "***************\n";
                    cout << "you win\n";
                    player_score += 1;
                    cout << "your score: " << player_score << endl;
                    cout << "opponent score: " << opponent_score << endl;
                    cout << "***************\n";
                break;
            case 2 :
                if(randnum == 1){
                    cout << "***************\n";
                    cout << "you win\n";
                    player_score += 1;
                    cout << "your score: " << player_score << endl;
                    cout << "opponent score: " << opponent_score << endl;
                    cout << "***************\n";
                }
                else if(randnum == 2){
                    cout << "***************\n";
                    cout << "its a tie\n";
                    cout << "your score: " << player_score << endl;
                    cout << "opponent score: " << opponent_score << endl;
                    cout << "***************\n";
                }
                else
                    cout << "***************\n";
                    cout << "you lose\n";
                    opponent_score += 1;
                    cout << "your score: " << player_score << endl;
                    cout << "opponent score: " << opponent_score << endl;
                    cout << "***************\n";
                break;
            case 3 :
                if(randnum == 1){
                    cout << "***************\n";
                    cout << "you lose\n";
                    opponent_score += 1;
                    cout << "your score: " << player_score << endl;
                    cout << "opponent score: " << opponent_score << endl;
                    cout << "***************\n";
                }
                else if(randnum == 2){
                    cout << "***************\n";
                    cout << "you win\n";
                    player_score += 1;
                    cout << "your score: " << player_score << endl;
                    cout << "opponent score: " << opponent_score << endl;
                    cout << "***************\n";
                }
                else
                    cout << "***************\n";
                    cout << "its a tie\n";
                    cout << "your score: " << player_score << endl;
                    cout << "opponent score: " << opponent_score << endl;
                    cout << "***************\n";
                break;
                default:
                    cout << "***************\n";
                    cout << "invalid input";
                    cout << "***************\n";
                    break;
                
        }
    }


    return 0;
}