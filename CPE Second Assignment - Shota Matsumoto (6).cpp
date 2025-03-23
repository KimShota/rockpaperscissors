/*-------------------------------------------------------------------------------------------*/
/* Name: Shota Matsumoto, Student Number: sm11745*/
/* Date: March 20, 2024*/
/* Program: CPE Second Assignment - Shota Matsumoto.cpp*/
/* Description: This program executes a Rock Paper Scissors Game 5 times between a user and computer.*/
/* ------------------------------------------------------------------------------------------*/
#include <iostream>
#include <ctime>
using namespace std;

// declare function prototypes
int print_Menu();
void play_RPS(int player[], int computer[], int size);
void print_Summary(int player[], int computer[], int size);

//Define the main fuction
int main(){
    //Declare variables and initialize size to 5
    const int size = 5;
    //Declare the arrays
    int player[size], computer[size];
    
    //Sets the seed of the Random Number Generator
    srand(time(NULL));
    
    int choice;
    //Insert do/while Repetition structure to evaluate the condition at the end
    do {
        //Call the function, print_Menu, to get a user's selection
        choice = print_Menu();
        
        //Make if statement. Here on the top we deal with the case of choice 1.
        if (choice == 1){
            play_RPS(player, computer, size); //Call the function, play_RPS, to play the RPS game
            print_Summary(player, computer, size); //Call the function, print_Summary, to print a summary of the game
        }
        
        //Make else/if statement for the choice being 2. Print the information about the program and re-display main menu.
        else if (choice == 2){
            cout << "Help: Rock beats Scissors, Scissors beats Paper, Paper beats Rock." << endl;
        }
        
        //Make else/if statement for the choice being 3. This terminates the program.
        else if (choice == 3){
            cout << "Terminating ..." << endl;
        }
        
        //Make else statement for values other than 1, 2, or 3. Allow users to input the value again from main menu.
        else {
            cout << "Invalid input. Please enter 1, 2, or 3: " << endl;
        }
    } while (choice != 3); //Provide the condition for do/while Repepition structure
    
    return 0;
}

//Define the function
int print_Menu() {
    int choice;
    //Print Main Menu and three choices and Read choice
    cout << "Welcome to the Rock Paper Scissors game. You will play 5 times…" << endl;
    cout << "1) Play" << endl;
    cout << "2) Help" << endl;
    cout << "3) Exit" << endl;
    cout << "Please make a selection (1-3): ";
    cin >> choice;
    //Insert While Repitition structure to allow users to input a value again.
    while (choice < 1 || choice > 3) {
        cout << "Invalid choice. Please enter 1, 2, or 3: ";
        cin >> choice;
    }
    return choice; //Make sure to return to choice
}

//Define the void function
void play_RPS(int player[], int computer [], int size){
    cout << "Please select among 1) Rock, 2) Paper, or 3) Scissors: " << endl;
    //Insert for looping structure. Declare and Initialize i which is a counter. Provide conditions to the counter, and post-increment 1 every round
    for (int i=0; i < size; i++){
        cin >> player[i];
        //Insert While Repitition structure to allow users to input a value again.
        while (player[i] < 1 || player[i] > 3){
            cout << "Invalid input. Please enter 1, 2, or 3: " << endl;
            cin >> player[i];
        }
        //randomly generate the integer between 1 and 3
        computer[i] = rand () % 3 + 1;
        cout << "You: ";
        
        //Make if statements to print Rock for 1, Paper for 2, or Scissors for 3
        if (player[i] == 1){
            cout << "Rock";
        }
        else if (player[i] == 2){
            cout << "Paper";
        }
        else {
            cout << "Scissors";
        }
        cout << " Computer: ";
        if (computer[i] == 1){
            cout << "Rock";
        }
        else if (computer[i] == 2){
            cout << "Paper";
        }
        else {
            cout << "Scissors";
        }
        cout << endl;
    }
}

//Define the void function
void print_Summary(int player[], int computer[], int size){
    //Declare variables and Initialize them to 0
    int wins = 0, loses = 0, ties = 0;
    cout << "Summary: " << endl;
    //Insert for looping structure. Declare and Initialize i which is a counter. Provide conditions to the counter, and post-increment 1 every round
    for (int i = 0; i < size; i++){
        cout << "You: ";
        //Make if statements to print Rock for 1, Paper for 2, or Scissors for 3
        if (player[i] == 1){
            cout << "Rock";
        }
        else if (player[i] == 2){
            cout << "Paper";
        }
        else {
            cout << "Scissors";
        }
        cout << " Computer: ";
        if (computer[i] == 1){
            cout << "Rock";
        }
        else if (computer[i] == 2){
            cout << "Paper";
        }
        else {
            cout << "Scissors";
        }
        //Make if statements to print Win, Lose, or Tie based on the power relations in the RPS game and Post-increment a variable (wins, loses, or ties) by 1 if selected
        if (player[i] == 1 && computer [i] == 2){
            cout << " - Lose";
            loses++;
        }
        else if (player[i] == 2 && computer [i] == 3){
            cout << " - Lose";
            loses++;
        }
        else if (player[i] == 3 && computer [i] == 1){
            cout << " - Lose";
            loses++;
        }
        else if (player[i] == computer [i]){
            cout << " - Tie";
            ties++;
        }
        else {
            cout << " - Win";
            wins++;
        }
        cout << endl;
    }
    
    //Make if statements to print who wins and how many times an user wins, loses, and ties
    if (wins > loses){
        cout << "You win!" << " (win: " << wins << " , tie: " << ties << " , lose: " << loses << ")" << endl;
    }
    
    else if (wins < loses){
        cout << "You lose" << " (win: " << wins << " , tie: " << ties << " , lose: " << loses << ")" << endl;
    }
    
    else {
        cout << "You tie" << " (win: " << wins << " , tie: " << ties << " , lose: " << loses << ")" << endl;
    }
}
