#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string>
using namespace std;
void rules()
{
    system("cls");
    cout << "\t\t======CASINO NUMBER GUESSING RULES!======\n";
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner gets 10 times of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";
}
int main()
{
    int balance = 0;
    int dice;
    char choice;
    int bettingAmount;
    string playerName;
    int guess;
    srand(time(0));
    cout << "\n\t\t========WELCOME TO CASINO WORLD=======\n\n";
    cout << "\n\nWhat's your Name : ";cin >> playerName;
    cout << "\n\nEnter the starting balance to play game : $"; cin >> balance;
    do
    {
        system("cls");
        rules();
        cout << "Your current balance:" << balance;
        do
        {
            cout << "\n" << playerName << ", enter amount to bet : $";
            cin >> bettingAmount;
            if (bettingAmount > balance)
                cout << "Betting balance can't be more than current balance!\n"
                << "\nRe-enter balance\n ";
        } while (bettingAmount > balance);
        do
        {
            cout << "Guess any betting number between 1 and 10 :";cin >> guess;
            if (guess <= 0 || guess > 10)
                cout << "\nNumber should be between 1 to 10\n"
                << "Re-enter number:\n ";
        } while (guess <= 0 || guess > 10);
        dice = rand() % 10 + 1;
        if (dice == guess)
        {
            cout << playerName << ", you have won!" << "Your prize is $" << bettingAmount * 10;
            balance += bettingAmount * 10;
        }
        else
        {
            cout << playerName << ", you have losed!" << "Your lost is $" << bettingAmount << ". ";
            balance -= bettingAmount;
        }
        cout << "The winnig number was: " << dice;
        cout << "\n" << playerName << ", You have balance of $ " << balance << "\n";
        if (balance == 0)
        {
            string end;
            cout << "You have no money to play, press any buttom to end \n";
            cin >> end;
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
    cout << "\n\n\n";
    cout << "\n\nThanks for playing the game. Your balance is $ " << balance << "\n\n";
    return 0;
}

