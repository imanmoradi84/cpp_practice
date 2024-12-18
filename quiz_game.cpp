#include <iostream>

int main()
{
// create the questions
std::string quiz[] = {"1_What is the capital city of France?",
                      "2_Which planet is known as the Red Planet?",
                      "3_What is the boiling point of water?",
                      "4_Who wrote the play “Romeo and Juliet”?"};
// create the possible answers
std::string options[][4] = {"A. Rome", "B. Madrid", "C. Paris", "D. Berlin",
                            "A. Earth", "B. Mars", "C. Venus", "D. Jupiter",
                            "A. 50°C" , "B. 100°C", "C. 150°C", "D. 200°C",
                            "A. Charles Dickens", "B. Jane Austen", "C. William Shakespeare", "D. Mark Twain"};
// create the correct answer
char answer[] ={'C', 'B', 'B', 'C'} ;
int size = sizeof(quiz)/sizeof(quiz[0]);
char guess;
int score = 0;
// make two for loops going thourgh the queiz and option
for(int i = 0; i < size; i++)
{
    std::cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
    std::cout << quiz[i] << '\n';
    std::cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";

    for(int j = 0; j < sizeof(options[i])/sizeof(options[i][0]); j++)
    {
        std::cout << options[i][j] << '\n';
    }

    std::cin >> guess;
    guess = toupper(guess);
     
    if(guess == answer[i])
    {
        std::cout << "CORRECT\n";
        score++;
    }
    else
    {
        std::cout << "WRONG\n";
        std::cout << "answer: " << answer[i] << '\n';
    }
}
std::cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
std::cout << "                  RESLUTS\n              \n";
std::cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
std::cout << "correct: " << score << '\n';

// print how many where correct and how many where wrong
return 0;
}