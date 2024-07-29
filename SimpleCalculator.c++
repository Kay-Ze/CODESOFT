#include <iostream>
using namespace std;

void add(){
    int a,b;
    cout << "\n\t Enter The Digits(Separate Them Using Space) :: ";
    cin >> a >> b;
    int ans = a+b;
    cout << "\t Answer is :: " << ans << endl;
}

void sub(){
    int a,b;
    cout << "\n\t Enter The Digits(Separate Them Using Space) :: ";
    cin >> a >> b;
    int ans = a - b;
    cout << "\t Answer is :: " << ans << endl;
}

void multiply(){
    int a,b;
    cout << "\n\t Enter The Digits(Separate Them Using Space) :: ";
    cin >> a >> b;
    int ans = a * b;
    cout << "\t Answer is :: " << ans << endl;
}

void divide(){
    float a,b;
    cout << "\n\t Enter The Digits(Separate Them Using Space) :: ";
    cin >> a >> b;
    if(b == 0){
        cout << "\n|| Error: Division by ZERO ||" << endl;
    }
    float ans = (float)a / b;
    cout << "\t Answer is :: " << ans << endl;
}

void remainder(){
    int a,b;
    cout << "\n\t Enter The Digits(Separate Them Using Space) :: ";
    cin >> a >> b;
    if(b == 0){
        cout << "\n|| Error: Division by ZERO ||" << endl;
    }
    int ans = a % b;
    cout << "\t Answer is :: " << ans << endl;
}

int main(){

    cout << "*This is the 'Simple Calculator' use for simple calculations Like Addition, Multiplication, Subtraction, Division and to find Remainder * " << endl;
    cout << "\n\tSelect the Operation By Entering the Number assigned for that OPERATION:-" << endl;
    cout << "\t\t 1.) Addition \n\t\t 2.) Subtraction \n\t\t 3.) Division \n\t\t 4.) Multiplication \n\t\t 5.) Remainder" << endl;
    
    int choice;
    cout << "\t Select The Operation :: ";
    cin >> choice;

    switch (choice){
        case 1:
        add();
        break;

        case 2:
        sub();
        break;

        case 3:
        divide();
        break;

        case 4:
        multiply();
        break;

        case 5:
        remainder();
        break;

        default:
        cout << " INVALID INPUT" << endl;
        break;
    }
    
    cout << "\n\t Thank You For Using This :)\n" << endl;
    return 0;
}