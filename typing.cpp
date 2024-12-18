#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;
using namespace chrono;


// need this so i can have the number of mistakes and calculate the wpm
void result(const string& answer,const string& rand_sentence, int& wrong){
    for(size_t i = 0; i < rand_sentence.size(); i++){
        // so that if the answer is shorter than the sentence it count's that as a mistake
        if(i >= answer.size() || answer[i] != rand_sentence[i]){
            wrong += 1;
        };

    }
    

}

// so i can get a random sentence each time
string sentence_maker(const vector<string>& sentences){
    // do this to get diffrent number each time
    srand(time(0));
    // to make sure the random index is not bigger than the sentence
    int rand_i = rand() % sentences.size();
    return sentences[rand_i];

}


int main(){
    int ready;
    int wrong = 0;
    float wpm;
    string answer;
    string rand_sentence;
    // have some sentences ready so i can randomly choose from them for the test
    vector<string> sentences = {
        "The quick brown fox jumps over the lazy dog.",
        "A journey of a thousand miles begins with a single step.",
        "To be or not to be, that is the question.",
        "All that glitters is not gold.",
        "The early bird catches the worm.",
        "A rolling stone gathers no moss.",
        "Actions speak louder than words.",
        "Every cloud has a silver lining.",
        "Hope for the best, but prepare for the worst.",
        "Knowledge is power.",
        "Don't count your chickens before they hatch."
    };
    //  i need a timer for the start of the test
    steady_clock::time_point start_time;
    steady_clock::time_point end_time;
    // need to get a input and out put stream
    cout << "********************************\n"
         << "ARE YOU READY TO START? \n"
         << "1- yes\n"
         << "2- no\n"
         << "********************************\n";
    cin >> ready;
    // nedd this so i can give the user a way to close the program
    switch (ready)
    {
    case 1:{
        cout << "starting in\n";
        // to have a one second delay each time 
        this_thread::sleep_for(seconds(1));
        cout << "((3))\n";
        this_thread::sleep_for(seconds(1));
        cout << "((2))\n";
        this_thread::sleep_for(seconds(1));
        cout << "((1))\n";
        this_thread::sleep_for(seconds(1));
        // put the random sentence in variable so i can use it later
        rand_sentence = sentence_maker(sentences);
        // so i can measure the time fot the wpm
        start_time = steady_clock::now();

        cin.ignore();

        char ch;
        cout << "\033[34m" << rand_sentence << "\r";
        
        while((ch = cin.get()) != '\n'){
            answer += ch;
            cout << "\033[34m" << rand_sentence << "\r" << "\r\033[32m" << answer;
        }

        end_time = steady_clock::now();
        result(answer, rand_sentence, wrong);
        
        auto duration = duration_cast<seconds>(end_time - start_time);

        cout << "\n" << "you had " << wrong << " mistakes \n";
        wpm =  (answer.size() / 5.0) / duration.count() * 60;
        cout << "your word per minute is: " << wpm << " wpm\n";
        break;
        }
    case 2:
        cout << "see you later\n";
        break;
    
    default:
        cout << "wrong input\n";
        break;
    }


    return 0;
}