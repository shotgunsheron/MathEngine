/*
Author: Srijith Chinthalapudi
language: C++
Program Description: A brain enrichment game with various cognitive activities.
#oflines: 739
Dev Log:
PVP tic tac toe is broken, possible memory leak/forever loop. 
*/
#include <iostream> //basic iostream library
#include <cstring>
#include <ctime>//ctime library for time-based functions
#include <random>//math library for random nums/positions
#include <fstream>//file management library
#include <cstdlib> // for exit function file management
#include <time.h>
using std::ofstream; //ofstream for file management
using std::cerr;//file management
using std::endl;//endl function
using namespace std;//use namespace for removing std
int game_count; //count games
int cpuMoveCount; //count the number of moves cpu made
int xMoveCount; //count the number of moves x made
string Username; //might use later
string Password;//might use later
int ability;
//main board array
char board[9] = {' ', ' ', ' ',' ',' ', ' ',' ', ' ', ' '}; //board array
//combo arrays
//horizontal combo arrays
char horizontal[3] = {board[0], board[1], board[2]};
char horizontal2[3] = {board[3], board[4], board[5]};
char horizontal3[3] = {board[6], board[7], board[8]};
//vertical combo arrays
char vertical[3] = {board[0], board[3], board[6]};
char vertical2[3] = {board[1], board[4], board[7]};
char vertical3[3] = {board[2], board[5], board[8]};
//diagonal combo arrays
char diagonal[3] = {board[1], board[4], board[8]};
char diagonal2[3] = {board[2], board[4], board[6]};
//functions
void list();
void wordMem();
void chooseGame(int num);
void wordUnscramble();
int numberGuessing();
int gameCounterGroup(); //group gamecounter file management systems
int gameCounter2();
int gameCounter();
int memSave(char data[]);//save memory
void show_board();//show board
void get_x_player_choice();//get x player's choice
void get_o_player_choice();//get o player's choice
void get_computer_choice(int bot);//get computer choice
int count_board(char symbol);//count the number of symbols in board
char check_winner();//check the winner
void computer_vs_player();//computer vs player mode
void player_vs_player();//player vs player mode
int layerOneBot();//Level 1 bot system
int layerTwoBot();//Level 2 bot system

using namespace std;//?
//below are the functions for the declarations above
void list() {
    int in;
    std::cout << "The list of activities is: 1 for Tic Tac Toe, 2 for Number Search, 3 for Unscrambling Words. Press the key of the activity you would like to do! To quit, press CTRL C!" << "\n";
    cin >> in;
    chooseGame(in); 

}

void wordMem() {
    std::cout << "I'll give you 10 words, each with its own assigned number! Your job is to memorize each word and its number. At the end, you will be given a number and asked to type in the word assigned to it. " << "\n";
    
}

void wordUnscramble() {
    std::cout << "You will get a scrambled word. Your job is to unscramble it: ";
    string words[] = {"Cat", "Dog", "Fog", "Log", "Cog", "Call", "Mall", "Doll"};
	srand(time(0)); //seed random number generator
	int index = rand() % 7 + 0; // random number between 1 and 100
    //std::cout << index << "\n";
    string word = words[index];
    string correctW = word;
    int len = correctW.length();
    for(int i = 0; i < len; ++i) 
    {
        int random_index = random() % len; 
        word[i] = word[i] + word[random_index] - (word[random_index] = word[i]); // we just swap two letters each time
    }
    int tries = 0;
    string guess;
    	do
	{
		cout << "The scrambled word is " + word << ": ";
		cin >> guess;
		tries++;

		if (guess !=  correctW)
			cout << "Incorrect!\n\n";
		else
			cout << "\nCorrect! You got it in " << tries << " guesses!\n";
	} while (guess != correctW);  
    list();
}

int numberGuessing() {
    std::cout << string(200, '\n');
	int num, guess, tries = 0;
	srand(time(0)); //seed random number generator
	num = rand() % 100 + 1; // random number between 1 and 100
	cout << "Guess A Number\n\n";
	do
	{
		cout << "Enter a guess between 1 and 100 : ";
		cin >> guess;
		tries++;

		if (guess > num)
			cout << "Too high!\n\n";
		else if (guess < num)
			cout << "Too low!\n\n";
		else
			cout << "\nCorrect! You got it in " << tries << " guesses!\n";
	} while (guess != num);                                                
    list();
    return 0;
    
}
int ticTacToe() { 
    int mode;
    std::cout << "1. Computer VS Player." << endl;
    std::cout << "2. Player VS Player.(in development. do not choose.)" << endl;
    std::cout << "Select Game Mode." << endl;
    cin >> mode;
    switch (mode) {
        case 1 :
            computer_vs_player();
            break;
        case 2 :
            //player_vs_player();    
            //std::cout << "Sorry, this mode is currently not available. It is a work in progress!" << endl;
            player_vs_player();
            break;
        default :
            std::cout << "Please Select Valid Game Mode." << endl;
            break;
    }
    return 0;
}
void chooseGame(int num) {


    switch(num) {
        case 1:
            ticTacToe();
        case 2:
            numberGuessing();   
        case 3:
            wordUnscramble(); 
    }
}




void exit() {
        std::cout << "Terminating program..." << "\n";
        std::cout << "Closing Tactic.." << "\n";
        std::cout << "Goodbye." << "\n";
}

int main() {
    int in;
    std::cout << "Welcome to Tactic, a brain-enriching app to improve logic, concentration, and creativity! Press any key to continue: " << "\n";
    std::cin.ignore();
    list();
    return 0;
}

int gameCounterGroup() {
        gameCounter();
        gameCounter2();
        std::cout << game_count << " games have been played against this bot in total!" << "\n";
        return 0;
}

int gameCounter2() {
   game_count = game_count + 1;
   int data = game_count;
   ofstream outdata; // outdata is like cin
   outdata.open("gameCount.txt"); // opens the file
   if( !outdata ) { // file couldn't be opened
      cerr << "Error: file could not be opened" << endl;
      exit(1);
   }
   outdata << data;
   outdata.close();
 
   return 0;
}
int gameCounter() {
    int x;
    ifstream inFile;
    inFile.open("gameCount.txt");
    if (!inFile) {
        cerr << "Unable to open file gameCount.txt";
        exit(1);   // call system to stop
    }
    while (inFile >> x) {
        game_count = x;
    }
    inFile.close();
    return 0;
}
int memSave(char data[])
{
   return 0;
}
void player_vs_player() {
    string x_player_name , o_player_name;
    std::cout << "Enter X Player Name: ";
    cin >> x_player_name;
    std::cout<< "Enter O Player Name: ";
    cin >> o_player_name;
    while(true) {
        std::cout << string(50, '\n');
        show_board();
        if(count_board('X') == count_board('O')) {
            std::cout << x_player_name << "'s Turn." << endl;
            get_x_player_choice();

        }
        else{
            std::cout << o_player_name << "'s Turn." << endl;
            get_o_player_choice;
        }
        char winner = check_winner();
        if(winner == 'X') {
            std::cout << string(50, '\n');
            show_board();
            std::cout<< x_player_name << " Won The Game." << endl;
            break;
        }
        else if(winner == 'O') {
            std::cout << string(50, '\n');
            show_board();
            std::cout << o_player_name << " Won The Game." << endl;
            break;
        }
        else if(winner == 'D') {
            std::cout << "Game is Draw." << endl;
            break;
        }
    }
}
int layerOneBot() {
    
    //opponent check

    //horizontal1 Check
    if (board[0] == 'X' and board[1] == 'X' and board[2] == ' ') {
        return 2;
    }
    if (board[0] == ' ' and board[1] == 'X' and board[2] == 'X') {
        return 0;
    }
    if (board[0] == 'X' and board[1] == ' ' and board[2] == 'X') {
        return 1;
    }
    
    //horizontal2 Check

    if (board[3] == 'X' and board[4] == 'X' and board[5] == ' ') {
        return 5;
    }
    if (board[3] == ' ' and board[4] == 'X' and board[5] == 'X') {
        return 3;
    }
    if (board[3] == 'X' and board[4] == ' ' and board[5] == 'X') {
        return 4;
    }

    //horizontal3 Check
    if (board[6] == 'X' and board[7] == 'X' and board[8] == ' ') {
        return 8;
    }
    if (board[6] == ' ' and board[7] == 'X' and board[8] == 'X') {
        return 6;
    }
    if (board[6] == 'X' and board[7] == ' ' and board[8] == 'X') {
        return 7;
    }    

    //vertical1 Check

    if (board[0] == 'X' and board[3] == 'X' and board[6] == ' ') {
        return 7-1;
    }
    if (board[0] == ' ' and board[3] == 'X' and board[6] == 'X') {
        return 1-1;
    }
    if (board[0] == 'X' and board[3] == ' ' and board[6] == 'X') {
        return 4-1;
    }    

    //vertical2 Check
    if (board[1] == 'X' and board[4] == 'X' and board[7] == ' ') {
        return 8-1;
    }
    if (board[1] == ' ' and board[4] == 'X' and board[7] == 'X') {
        return 2-1;
    }
    if (board[1] == 'X' and board[4] == ' ' and board[7] == 'X') {
        return 5-1;
    }        
    //vertical3 Check
   
    if (board[2] == 'X' and board[5] == 'X' and board[8] == ' ') {
        return 9-1;
    }
    if (board[2] == ' ' and board[5] == 'X' and board[8] == 'X') {
        return 3-1;
    }
    if (board[2] == 'X' and board[5] == ' ' and board[8] == 'X') {
        return 6-1;
    }            
    //diagonal1 Check
    if (board[0] == 'X' and board[4] == 'X' and board[8] == ' ') {
        return 9-1;
    }
    if (board[0] == ' ' and board[4] == 'X' and board[8] == 'X') {
        return 1-1;
    }
    if (board[0] == 'X' and board[4] == ' ' and board[8] == 'X') {
        return 5-1;
    }         
    //diagonal2 Check
    if (board[2] == 'X' and board[4] == 'X' and board[6] == ' ') {
        return 7-1;
    }
    if (board[2] == ' ' and board[4] == 'X' and board[6] == 'X') {
        return 3-1;
    }
    if (board[2] == 'X' and board[4] == ' ' and board[6] == 'X') {
        return 5-1;
    }                   
    else
    {
       return rand()%10;
    }

}
int layerTwoBot() {
    
    //winning move check
    if (board[0] == 'O' and board[1] == 'O' and board[2] == ' ') {
        return 2;
    }
    if (board[0] == ' ' and board[1] == 'O' and board[2] == 'O') {
        return 0;
    }
    if (board[0] == 'O' and board[1] == ' ' and board[2] == 'O') {
        return 1;
    }
    
    //winning horizontal2 Check

    if (board[3] == 'O' and board[4] == 'O' and board[5] == ' ') {
        return 5;
    }
    if (board[3] == ' ' and board[4] == 'O' and board[5] == 'O') {
        return 3;
    }
    if (board[3] == 'O' and board[4] == ' ' and board[5] == 'O') {
        return 4;
    }

    //winning horizontal3 Check
    if (board[6] == 'O' and board[7] == 'O' and board[8] == ' ') {
        return 8;
    }
    if (board[6] == ' ' and board[7] == 'O' and board[8] == 'O') {
        return 6;
    }
    if (board[6] == 'O' and board[7] == ' ' and board[8] == 'O') {
        return 7;
    }    

    //winning vertical1 Check

    if (board[0] == 'O' and board[3] == 'O' and board[6] == ' ') {
        return 7-1;
    }
    if (board[0] == ' ' and board[3] == 'O' and board[6] == 'O') {
        return 1-1;
    }
    if (board[0] == 'O' and board[3] == ' ' and board[6] == 'O') {
        return 4-1;
    }    

    //winning vertical2 Check
    if (board[1] == 'O' and board[4] == 'O' and board[7] == ' ') {
        return 8-1;
    }
    if (board[1] == ' ' and board[4] == 'O' and board[7] == 'O') {
        return 2-1;
    }
    if (board[1] == 'O' and board[4] == ' ' and board[7] == 'O') {
        return 5-1;
    }        
    //winning vertical3 Check
   
    if (board[2] == 'O' and board[5] == 'O' and board[8] == ' ') {
        return 9-1;
    }
    if (board[2] == ' ' and board[5] == 'O' and board[8] == 'O') {
        return 3-1;
    }
    if (board[2] == 'O' and board[5] == ' ' and board[8] == 'O') {
        return 6-1;
    }            
    //winning diagonal1 Check
    if (board[0] == 'O' and board[4] == 'O' and board[8] == ' ') {
        return 9-1;
    }
    if (board[0] == ' ' and board[4] == 'O' and board[8] == 'O') {
        return 1-1;
    }
    if (board[0] == 'O' and board[4] == ' ' and board[8] == 'O') {
        return 5-1;
    }         
    //winning diagonal2 Check
    if (board[2] == 'O' and board[4] == 'O' and board[6] == ' ') {
        return 7-1;
    }
    if (board[2] == ' ' and board[4] == 'O' and board[6] == 'O') {
        return 3-1;
    }
    if (board[2] == 'O' and board[4] == ' ' and board[6] == 'O') {
        return 5-1;
    }                   




    //opponent check

    //horizontal1 Check
    if (board[0] == 'X' and board[1] == 'X' and board[2] == ' ') {
        return 2;
    }
    if (board[0] == ' ' and board[1] == 'X' and board[2] == 'X') {
        return 0;
    }
    if (board[0] == 'X' and board[1] == ' ' and board[2] == 'X') {
        return 1;
    }
    
    //horizontal2 Check

    if (board[3] == 'X' and board[4] == 'X' and board[5] == ' ') {
        return 5;
    }
    if (board[3] == ' ' and board[4] == 'X' and board[5] == 'X') {
        return 3;
    }
    if (board[3] == 'X' and board[4] == ' ' and board[5] == 'X') {
        return 4;
    }

    //horizontal3 Check
    if (board[6] == 'X' and board[7] == 'X' and board[8] == ' ') {
        return 8;
    }
    if (board[6] == ' ' and board[7] == 'X' and board[8] == 'X') {
        return 6;
    }
    if (board[6] == 'X' and board[7] == ' ' and board[8] == 'X') {
        return 7;
    }    

    //vertical1 Check

    if (board[0] == 'X' and board[3] == 'X' and board[6] == ' ') {
        return 7-1;
    }
    if (board[0] == ' ' and board[3] == 'X' and board[6] == 'X') {
        return 1-1;
    }
    if (board[0] == 'X' and board[3] == ' ' and board[6] == 'X') {
        return 4-1;
    }    

    //vertical2 Check
    if (board[1] == 'X' and board[4] == 'X' and board[7] == ' ') {
        return 8-1;
    }
    if (board[1] == ' ' and board[4] == 'X' and board[7] == 'X') {
        return 2-1;
    }
    if (board[1] == 'X' and board[4] == ' ' and board[7] == 'X') {
        return 5-1;
    }        
    //vertical3 Check
   
    if (board[2] == 'X' and board[5] == 'X' and board[8] == ' ') {
        return 9-1;
    }
    if (board[2] == ' ' and board[5] == 'X' and board[8] == 'X') {
        return 3-1;
    }
    if (board[2] == 'X' and board[5] == ' ' and board[8] == 'X') {
        return 6-1;
    }            
    //diagonal1 Check
    if (board[0] == 'X' and board[4] == 'X' and board[8] == ' ') {
        return 9-1;
    }
    if (board[0] == ' ' and board[4] == 'X' and board[8] == 'X') {
        return 1-1;
    }
    if (board[0] == 'X' and board[4] == ' ' and board[8] == 'X') {
        return 5-1;
    }         
    //diagonal2 Check
    if (board[2] == 'X' and board[4] == 'X' and board[6] == ' ') {
        return 7-1;
    }
    if (board[2] == ' ' and board[4] == 'X' and board[6] == 'X') {
        return 3-1;
    }
    if (board[2] == 'X' and board[4] == ' ' and board[6] == 'X') {
        return 5-1;
    }                   
    else
    {
       return rand()%10;
    }    
}
void computer_vs_player() {
    cpuMoveCount = 0;
    xMoveCount = 0;
    string player_name;
    int bot;
    std::cout << "Enter Your Name: ";
    cin >> player_name;
    std::cout << "\n"<<" Choose a bot: 0. Random Moves, 1. One Layer, 2. Two Layer (The higher the layers, the more challenging.)" << endl;
    cin >> bot; 
    
    while(true) {
        std::cout << string(200, '\n');

        show_board();
        if(count_board('X') == count_board('O')) {
            std::cout << player_name << "'s Turn." << endl;
            get_x_player_choice();
        }
        else{
            get_computer_choice(bot);
        }
        char winner = check_winner();
        if (winner == 'X') {
            std::cout << string(50, '\n');
            gameCounterGroup();

            show_board();
            char fC;
            std::cout << player_name << " Won The Game. Play again? Y/N" << endl;
            cin >> fC;
            if (fC == 'Y' or fC == 'y') {
                for (int i = 0; i < 9; i++) {
                    board[i] = ' ';
                }
                computer_vs_player;
            }
            else{
                list();
                
            }
        }
        else if(winner == 'O') {
            std::cout << string(50, '\n');
            gameCounterGroup();

            show_board();
            std::cout << "Computer Won The Game. Play again? Y/N" << endl;
            char fC;
            cin >> fC;
            if (fC == 'Y' or fC == 'y') {
                for (int i = 0; i < 9; i++) {
                    board[i] = ' ';
                }                
                computer_vs_player;
            }
            else{
                list();
            }
        }
        else if(winner == 'D') {
            std::cout << "Game is Draw. Play again? Y/N" << endl;
            gameCounterGroup();

            char fC;
            cin >> fC;
            if (fC == 'Y' or fC == 'y') {
                for (int i = 0; i < 9; i++) {
                    board[i] = ' ';
                }                
                computer_vs_player;
            }
            else{
                list();
            }
        }
    }
}
void get_computer_choice(int bot) {
    //srand(time(0));
    int choice;
    do {
        if (bot == 1) {
            choice = layerOneBot();

        }
        if (bot == 2) {
            choice = layerTwoBot();

        }
        if (bot == 0) {
            choice = rand()%10;
        }

        std::cout << choice << endl;
        cpuMoveCount = cpuMoveCount + 1;
        memSave(board);
        
    }while(board[choice] != ' ');
    board[choice] ='O';
}
void get_x_player_choice() {
    while(true) {
        std::cout <<"Select Your Position (1-9): ";
        int choice;
        cin >> choice;

        choice--;

        if (choice < 0 || choice >8) {
            std::cout << "Please Select Your Choice From (1-9)." <<endl;

        }
        else if(board[choice] != ' ') {
            std::cout << "Please Select An Empty Postion." << endl;
        }
        else{
            board[choice] = 'X';
                xMoveCount = xMoveCount + 1;

            break;
        }
    }
}
void get_o_player_choice() {
    while(true) {
        std::cout <<"Select Your Position (1-9): ";
        int choice;
        cin >> choice;
        choice--;
        if (choice < 0 || choice >8) {
            std::cout << "Please Select Your Choice From (1-9)." <<endl;

        }
        else if(board[choice] != ' ') {
            std::cout << "Please Select An Empty Postion." << endl;
        }
        else{
            board[choice] = 'O';
            break;
        }
    }
}

int count_board(char symbol) {
    int total = 0;
    for (int i=0; i<9; i++) {
        if(board[i] == symbol) 
            total +=1;
        
    }
    return total;
}
char check_winner() {
    if(board[0] == board[1] && board[1] == board[2] && board[0] != ' ') 
        return board[0];
    if(board[3] == board[4] && board[4] == board[5] && board[3] != ' ') 
        return board[3];                    
    if(board[6] == board[7] && board[7] == board[8] && board[6] != ' ') 
        return board[6];       

        // checking winner in vertical/column format
    if (board[0] == board[3] && board [3] == board[6] && board[0] != ' ')
        return board[0];                        

    if (board[1] == board[4] && board [4] == board[7] && board[1] != ' ')
        return board[1];                        

    if (board[2] == board[5] && board [5] == board[8] && board[2] != ' ')
        return board[2];                           

        //checking winner in diagonal format
    if (board[0] == board[4] && board [4] == board[8] && board[0] != ' ')
        return board[0];         
                
    if (board[2] == board[4] && board [4] == board[6] && board[2] != ' ')
        return board[2];                       

    if (count_board('X') + count_board('O') < 9)

        return 'C';                    

    else 
        return 'D';                  

        
}
void show_board() {
    std::cout << "                                 " << "   |   " << "   |   "<< endl;
    std::cout << "                                 " << board[0] << "  |   " << board[1] << "  |  " << board[2] << endl;
    std::cout << "                              --------------------" << endl;
    std::cout << "                                 " << "   |   " << "   |   "<< endl;
    std::cout << "                                 " << board[3] << "  |   " << board[4] << "  |  " << board[5] << endl;
    std::cout << "                              --------------------" << endl;
    std::cout << "                                 " << "   |   " << "   |   "<< endl;
    std::cout << "                                 " << board[6] << "  |   " << board[7] << "  |  " << board[8] << endl;   
}

//739 lines of code