#include <iostream>
#include <time.h> 
using namespace std;

int random10(){
    srand(time(0));
    int rn = (rand()%10)+1;
    return rn;
}

int random100(){
    srand(time(0));
    int rn = (rand()%100)+1;
    return rn;
}

int game1(){
    int x = random10(); // Generated random number
    int lp = 1;
    cout << "** Congratulations, Now You Have To Guess The Number Between 1 to 10 **" << endl;
    cout << "\t*NOTE :: TO QUIT Feel Free To ENTER '0' Anytime" << endl;

    while(lp > 0){
        int guess;
        cout << "==>Now Enter The Number :: " ;
        cin >> guess;

        if (guess == 0) break;

        else if(guess > x && guess <= 10){
            cout << "Entered Number Is Bigger, Try again" << endl;
            continue;
        }

        else if(guess < x && guess >=1){
            cout << "Entered Number Is Smaller, Try again" << endl;
            continue;
        }

        else if(guess == x){
            cout << "Congratulations!!! You Won The Game" << endl;
            lp = 0;
        }

        else{
            cout << "Invalid Input" << endl;
            continue;
        }
    }

    return 0;
}

int game2(){
    int x = random100(); // Generated random number
    int lp = 1;
    cout << "** Congratulations, Now You Have To Guess The Number Between 1 to 100 **" << endl;
    cout << "\t*NOTE :: TO QUIT Feel Free To ENTER '0' Anytime" << endl;

    while(lp > 0){
        int guess;
        cout << "==>Now Enter The Number :: " ;
        cin >> guess;

        if (guess == 0) break;

        else if(guess > x && guess <= 100){
            if(guess - x >= 50){
                cout << "Entered Number Is Much Bigger, Try again" << endl;
                continue;
            }
            else if (guess - x < 50 && guess - x >= 10){
                cout << "Entered Number Is Bigger, Try again" << endl;
                continue;
            }
            else cout << "Entered Number Is Slightly Bigger, Try again" << endl;
        }

        else if(guess < x && guess >=1){
            if(x - guess >= 50){
                cout << "Entered Number Is Much Smaller, Try again" << endl;
                continue;
            }
            else if (x - guess < 50 && guess - x >= 10){
                cout << "Entered Number Is Smaller, Try again" << endl;
                continue;
            }
            else cout << "Entered Number Is Slightly Smaller, Try again" << endl;
        }

        else if(guess == x){
            cout << "Congratulations!!! You Won The Game" << endl;
            lp = 0;
        }

        else{
            cout << "Invalid Input" << endl;
            continue;
        }
    }
    return 0;
}

int main() {
    int choice;
    cout << "=========__Welcome To Our Number Guessing Game__=========\n\t If You Have To Guess The Number Between 1-10, Press 1\n\t If You Have To Guess The Number Between 1-100, Press 2" << endl;
    cin >> choice;

    switch (choice) {
    case 1:
        game1();
        break;
    case 2:
        game2();
        break;
    default:
    cout << "Invalid Choice";
    break;
    }
    cout << "Thank You Far Playing" << endl;

    return 0;
}
