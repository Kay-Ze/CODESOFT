#include <iostream>
#include <ctime>
using namespace std;

void display(char *spaces){
    cout << "\n\t\t     |     |     \n\t\t  "<<spaces[0]<<"  |  "<<spaces[1]<<"  |  "<<spaces[2]<<"  \n\t\t_____|_____|_____" << endl;
    cout << "\t\t     |     |     \n\t\t  "<<spaces[3]<<"  |  "<<spaces[4]<<"  |  "<<spaces[5]<<"  \n\t\t_____|_____|_____" << endl;
    cout << "\t\t     |     |     \n\t\t  "<<spaces[6]<<"  |  "<<spaces[7]<<"  |  "<<spaces[8]<<"  \n\t\t     |     |     \n" << endl;
}

void PlayerMove(char *spaces, char player){
    int number;
    do{
        cout << "Enter a spot to place a marker (1-9): ";
        cin >> number;
        number--;
        if(spaces[number] == ' '){
            spaces[number] = player;
            break; 
        }
    }while(!number > 0 || !number < 8);
}

void ComputerMove(char *spaces, char computer){
    int number;
    srand(time(0));
    do{
        number = (rand()%9);
        if(spaces[number] == ' '){
            spaces[number] = computer;
            break; 
        }
    }while(!number > 0 || !number < 8);
}

bool CheckWinner(char *spaces, char player, char computer){
    if((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])){
        spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])){
        spaces[3] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])){
        spaces[6] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])){
        spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])){
        spaces[1] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])){
        spaces[2] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])){
        spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])){
        spaces[2] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else{
        return false;
    }

    return true;
}

bool CheckTie(char *spaces){
    for(int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
            return false;
        }
    }
    cout << "IT'S A TIE!\n";
    return true;
}

int main() {

    cout << "======> WELCOME TO 'TIC TAC TOE' GAME <=======\n\n\t **Here You'll be Playing Against Computer**\n" << endl;
    cout << "\t Player Obtained 'X'   &   Computer Obtained 'O'\n" << endl;
    cout << "\t This is the Board on which you will be Playing" << endl;

    char spaces[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool run = true;

    display(spaces);

    while (run) {
        PlayerMove(spaces, player);

        if(CheckWinner(spaces, player, computer)){
            display(spaces);
            run = false;
            break;
        }
        else if(CheckTie(spaces)){
            run = false;
            break;
        }

        ComputerMove(spaces, computer);

        display(spaces);

        if(CheckWinner(spaces, player, computer)){
            run = false;
            break;
        }
        else if(CheckTie(spaces)){
            run = false;
            break;
        }
    }
    cout << "Thank you for Playing!!.." << endl;
    return 0;
}