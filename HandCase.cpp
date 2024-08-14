#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Welcome to the Automated Hand Case Machine!" << endl << "Please enter number of players:" << endl;
    int playerNumber = 0;
    cin >> playerNumber;
    //Enter number of players

    int scores[10][playerNumber+1];
    //Declare matrix for scoresheet (number of colums = number of players)

    for(int i = 0; i<10; i++){
        for(int j = 0; j<playerNumber+1; j++){
            scores[i][j]=0;
        }
    }
    //Zeros out scoresheet
    
    int winner = 0;
    int loss = 0;
    string winningWay;
    string results;
    
    for(int R=1; R<=9; R++){
        cout << endl << "Time to start Round " << R << "!" << endl << "How was it won? (Hand, Normal)" << endl;
        cin >> winningWay;
        //Inputs the winning way (either normal or Hand)

        if(winningWay == "Hand" || winningWay == "hand" || winningWay == "H" || winningWay == "h"){
            cout << "Who got hand? (enter player number)" << endl;
            cin >> winner;
            //Input winner player number

            scores[R][winner]= scores[R-1][winner]-60;
            //Subtracts 60 from their score

            for(int i = 1; i<=playerNumber; i++){
                if(winner == i){
                    continue; //doesnt count winner him/herself
                }
                cout << "How much did player " << i << " lose? (add)" << endl;
                cin >> loss;
                scores[R][i]= scores[R-1][i] + (loss*2);
                //Sum of cards held are multiplied by 2 and added to their scores
            }
            //End of Hand Win
        }
        
        if(winningWay == "Normal" || winningWay == "normal" || winningWay == "N" || winningWay == "n"){
            cout << "Who won? (enter player number)" << endl;
            cin >> winner;
            //Input winner player number

            scores[R][winner]=scores[R-1][winner]-30;
            //Subtracts 30 from their score

            for(int i = 1; i <= playerNumber; i++){
                if(winner == i){
                    continue; //doesnt count winner him/herself
                }
                cout << "How much did player " << i << " lose? (add)" << endl;
                cin >> loss;
                scores[R][i]=scores[R-1][i]+loss;
                //Sum of cards are added to their scores
            }
            //End of Normal
        }
        if(R!=9){
        cout << "Do you want to see results till now? (Y/N)" << endl;
        cin >> results;
        //Inputs either the user wants to see the results or not

        if(results == "Yes" || results == "yes" || results == "Y" || results == "y"){
            cout << endl;
            for(int i = 1; i <=R; i++){
                for(int j = 1; j <= playerNumber; j++){
                    cout << scores[i][j] << "  ";
                }
                cout << endl;
            }
            cout << endl << "These are the results." << endl << endl;
            //If yes, we output the matrix (scores)
        }
        }
    }
    
    cout << "These are your final results:-" << endl << endl;
    for(int i = 1; i <=9; i++){
        for(int j = 1; j <= playerNumber; j++){
            cout << scores[i][j] << "  ";
        }
        cout << endl;
    }
    //The scores are outputted after the game finishes
    
    cout << "Thank you for using the Hand Case Machine, Play again? (repeat the code!)";
    return 0;
}
