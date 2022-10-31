#include <iostream>
#include "application.h"
#include "board.h"
#include "chess_board_square.h"
#include <string>

using namespace std;
using std::string;

const int CON_H=8;
const int CON_W=8;
const int LETTER=8;

application::application() {

  
};

application::~application(){
  cout <<"Thank you for playing\n";
};

void application::run(){



    char checkmate='G';
    bool coutput;
    int x=1;
    int column, row;
    int player=1;
    bool illegal;
    int chess[CON_H][CON_W];
    char convert_letter;
    
    char letter[LETTER];
    
    application::set_letter(letter, LETTER);
    application::start_board(chess, CON_H);
    
    application::print_board(chess, letter, CON_H);
    
    cout<< "\n" << "player "<< player << " starts." << "\n";

    board *myboa=new board;

    while(checkmate!='F'){
        if(x>1){
            cout<< "\n" << "player "<<player<< "'s turn"<<"\n";
        }
        illegal=false;
        cout << "Select piece." << "\n";
        cout << "row: ";
        cin>> row;
        row=row-1;
        
        cout<< "column: ";
        cin>>convert_letter;
        column = application::letter_to_number(convert_letter, illegal);
        column=column-1;
        
        application::within_array(row, player, illegal);
            if(illegal!=true){
                coutput=true;
                myboa -> move_making(chess, illegal, coutput, column, row, player, CON_H);
            }
            myboa -> pawn_change(chess, player, CON_H);
            
            if(illegal!=true){
                if(player==1){
                    player=2;
                }
                
                else if(player==2){
                    player= 1;
                    
                }
                
            }
        
        cout<< "\n";
        application::print_board(chess, letter, CON_H);
        x=x+1;
        cout << "Entre \"F\" to forfit.\n";
        cin>> checkmate;
        if(checkmate=='F'){
          if(player==1){
            cout << "Player 2 wins.\n";
          }
          else if(player==2){
            cout << "Player 1 wins.\n";
          }
        }
        
    }
}



void application::start_board(int chess[][8],const int hieght){
    
    for(int i=0; i<hieght;i++){
        for(int j=0; j<CON_W; j++){
            if(i==1){
               chess[i][j] =12; 
            }
            else if(i==6){
                chess[i][j] =11;
            }
            else{
                chess[i][j] = 00;
            }
            if(j==0 || j==7){
               chess[0][j]= 22;
               chess[7][j]= 21;
            }
            if(j==1||j==6){
                chess[0][j]=32;
                chess[7][j]=31;
            }
            if(j==2 || j==5){
                chess[0][j]=42;
                chess[7][j]=41;
            }
            if(i==0|| i==7){
                chess[0][3]=52;
                chess[7][3]=51;
            }
            if(i==0|| i==7){
                chess[0][4]=62;
                chess[7][4]=61;
            }
        }
    }
}

 void application::set_letter(char letter[], const int num_letter){
     for(int i=0;i<num_letter;i++){
        if(i==0){
            letter[i]='A';
        }
        else if(i==1){
            letter[i]='B';
        }
        else if(i==2){
            letter[i]='C';
        }
        else if(i==3){
            letter[i]='D';
        }
        else if(i==4){
            letter[i]='E';
        }
        else if(i==5){
            letter[i]='F';
        }
        else if(i==6){
            letter[i]='G';
        }
        else if(i==7){
            letter[i]='H';
        }
    }
 }

 void application::print_board(int chess[][8],char letter[], const int hieght){
    cout << " ";
    for(int k=0;k<8;k++){
        cout<< letter[k] <<"  ";
    }
    cout << "\n";

    string new_chess[CON_H][CON_W];

    for(int i=0;i<hieght;i++){
        
        for(int j=0;j<CON_W;j++){
            if(chess[i][j]==00){
              new_chess[i][j]="  ";
            }
            else if(chess[i][j]==11){
              new_chess[i][j]="P1";
            }
            else if(chess[i][j]==12){
              new_chess[i][j]="P2";
            }
            else if(chess[i][j]==21){
              new_chess[i][j]="R1";
            }
            else if(chess[i][j]==22){
              new_chess[i][j]="R2";
            }
            else if(chess[i][j]==31){
              new_chess[i][j]="N1";
            }
            else if(chess[i][j]==32){
              new_chess[i][j]="N2";
            }
            else if(chess[i][j]==41){
              new_chess[i][j]="B1";
            }
            else if(chess[i][j]==42){
              new_chess[i][j]="B2";
            }
            else if(chess[i][j]==51){
              new_chess[i][j]="Q1";
            }
            else if(chess[i][j]==52){
              new_chess[i][j]="Q2";
            }
            else if(chess[i][j]==61){
              new_chess[i][j]="K1";
            }
            else if(chess[i][j]==62){
              new_chess[i][j]="K2";
            }
        }
        
    }

    for(int i=0;i<hieght;i++){
        
        for(int j=0;j<CON_W;j++){
            cout<< "|"<< new_chess[i][j];
        }
        cout << "|  "<<i+1<<"\n";
    }
 }

 int application::letter_to_number(char convert_letter, bool& illegal){
    if(convert_letter=='A'){
        return 1;
    }
    else if(convert_letter=='B'){
        return 2;
    }
    else if(convert_letter=='C'){
        return 3;
    }
    else if(convert_letter=='D'){
        return 4;
    }
    else if(convert_letter=='E'){
        return 5;
    }
    else if(convert_letter=='F'){
        return 6;
    }
    else if(convert_letter=='G'){
        return 7;
    }
    else if(convert_letter=='H'){
        return 8;
    }
    else{
        illegal=true;
        cout<<"Not a column"<< "\n";
        return 0;
    }
}

void application::within_array(int row, int player, bool& illegal){
    if(row<1 && row>7 ){
        illegal=true;
        cout<<"Not a row"<< "\n"; 
    }
    
}

void application::test(){
}