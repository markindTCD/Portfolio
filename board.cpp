#include <iostream>
#include "application.h"
#include "board.h"
#include "chess_board_square.h"
#include <string>

using namespace std;

const int CON_H=8;
const int CON_W=8;
const int LETTER=8;

board::board() {
  
};

board::~board(){
  
};

void board::move_making(int chess[][8], bool& illegal, bool coutput, int column, int row, int player, const int hieght){
    
  cout << "\n";
    if(chess[row][column]==11||chess[row][column]==12){
        cout << "Move pawn to," <<"\n";
        board::pawn_check(chess, illegal, coutput, column, row, player, hieght); 
    }
    else if(chess[row][column]==21||chess[row][column]==22){
        cout << "Move rook to," <<"\n";
        board::rook_check(chess, illegal, coutput, column, row, player, hieght);
    }
    else if(chess[row][column]==31||chess[row][column]==32){
        cout << "Move knight to," <<"\n";
        board::knight_check(chess, illegal, coutput, column, row, player, hieght);
    }
    else if(chess[row][column]==41||chess[row][column]==42){
        cout << "Move bishop to," <<"\n";
        board::bishop_check(chess, illegal, coutput, column, row, player, hieght);
    }
    else if(chess[row][column]==51||chess[row][column]==52){
        cout << "Move queen to," <<"\n";
        board::queen_check(chess, illegal, coutput, column, row, player, hieght);
    }
    else if(chess[row][column]==61||chess[row][column]==62){
        cout << "Move king to," <<"\n";
        board::king_check(chess, illegal, coutput, column, row, player, hieght);
    }
    else{
        illegal=true;
        cout<<"No pieces selected, try again"<< "\n";
    }
}

void board::pawn_check(int chess[][8], bool& illegal, bool coutput, int column,int row,int player, const int hieght){
    int move_column, move_row;
    if(chess[row][column]==11 && player==2){
        illegal=true;
        cout<< "Selected opponites pieces."<< "\n";
    }  

    else if(chess[row][column]==12&&player==1){
        illegal=true;
        cout<< "Selected opponites pieces."<< "\n";
    }   
    else{
        cout << "row: ";
        cin>> move_row;
        move_row=move_row-1;
        board::within_array(row, player, illegal);
        char convert_letter;
    
        cout << "column: ";
        cin>>convert_letter;
        
        move_column = board::letter_to_numbers(convert_letter, illegal);
        move_column=move_column-1;

        if(illegal==false){
        chess_board_square *mycbs=new chess_board_square;
    
         mycbs -> pawn_move_check(chess, illegal, coutput, column,move_column, row, move_row, player, hieght);
      }
    } 
}
void board::rook_check(int chess[][8], bool& illegal, bool coutput, int column,int row,int player, const int hieght){
    int move_column, move_row;
    if(chess[row][column]==21 && player==2){
        illegal=true;
        cout<< "Selected opponites pieces."<< "\n";
    }  

    else if(chess[row][column]==22&&player==1){
        illegal=true;
        cout<< "Selected opponites pieces."<< "\n";
    }   
    else{
        cout << "row: ";
        cin>> move_row;
        move_row=move_row-1;
        board::within_array(row, player, illegal);
        char convert_letter;
    
        cout << "column: ";
        cin>>convert_letter;
        move_column = board::letter_to_numbers(convert_letter, illegal);
        move_column=move_column-1;

        if(illegal==false){
          chess_board_square *mycbs=new chess_board_square;

        mycbs -> rook_move_check(chess, illegal, coutput, column,move_column, row, move_row, player, hieght);
      }
    }
}
void board::knight_check(int chess[][8], bool& illegal, bool coutput, int column,int row,int player, const int hieght){
    int move_column, move_row;
    if(chess[row][column]==31 && player==2){
        illegal=true;
        cout<< "Selected opponites pieces."<< "\n";
    }  

    else if(chess[row][column]==32 && player==1){
        illegal=true;
        cout<< "Selected opponites pieces."<< "\n";
        }   
    else{
        cout << "row: ";
        cin>> move_row;
        move_row=move_row-1;
        board::within_array(row, player, illegal);
        char convert_letter;
    
        cout << "column: ";
        cin>>convert_letter;
        move_column = board::letter_to_numbers(convert_letter, illegal);
        move_column=move_column-1;

        if(illegal==false){
          chess_board_square *mycbs=new chess_board_square;

        mycbs -> knight_move_check(chess, illegal, coutput, column,move_column, row, move_row, player, hieght);
      }
    }
}
void board::bishop_check(int chess[][8], bool& illegal, bool coutput, int column,int row,int player, const int hieght){
    int move_column, move_row;
    if(chess[row][column]==41 && player==2){
        illegal=true;
        cout<< "Selected opponites pieces."<< "\n";
    }  
    else if(chess[row][column]==42 && player==1){
        illegal=true;
        cout<< "Selected opponites pieces."<< "\n";
    }   
    else{
        cout << "row: ";
        cin>> move_row;
        move_row=move_row-1;
        board::within_array(row, player, illegal);
        char convert_letter;
    
        cout << "column: ";
        cin>>convert_letter;
        move_column = board::letter_to_numbers(convert_letter,illegal);
        move_column=move_column-1;
    
        if(illegal==false){
          chess_board_square *mycbs=new chess_board_square;

        mycbs -> bishop_move_check(chess, illegal, coutput, column,move_column, row, move_row, player, hieght);
      }
    }
}
void board::queen_check(int chess[][8], bool& illegal, bool coutput, int column,int row,int player, const int hieght){

    int move_column, move_row;
    if(chess[row][column]==51 && player==2){
        illegal=true;
        cout<< "Selected opponites pieces."<< "\n";
        }  

    else if(chess[row][column]==52&&player==1){
        illegal=true;
        cout<< "Selected opponites pieces."<< "\n";
    }   
    else{
        cout << "row: ";
        cin>> move_row;
        move_row=move_row-1;
        board::within_array(row, player, illegal);
        char convert_letter;
    
        cout << "column: ";
        cin>>convert_letter;
        move_column = board::letter_to_numbers(convert_letter, illegal);
        move_column=move_column-1;
    
        if(illegal==false){
          chess_board_square *mycbs=new chess_board_square;

        mycbs -> queen_move_check(chess, illegal, coutput, column,move_column, row, move_row, player, hieght);
        }
    }
}
void board::king_check(int chess[][8], bool& illegal, bool coutput, int column,int row,int player, const int hieght){

    int move_column, move_row;
    if(chess[row][column]==61 && player==2){
        illegal=true;
        cout<< "Selected opponites pieces."<< "\n";
        }  

    else if(chess[row][column]==62&&player==1){
        illegal=true;
        cout<< "Selected opponites pieces."<< "\n";
    }   
    else{
        cout << "row: ";
        cin>> move_row;
        move_row=move_row-1;
        board::within_array(row, player, illegal);
        char convert_letter;
    
        cout << "column: ";
        cin>>convert_letter;
        move_column = board::letter_to_numbers(convert_letter, illegal);
        move_column=move_column-1;
    
        if(illegal==false){
          chess_board_square *mycbs=new chess_board_square;

         mycbs -> king_move_check(chess, illegal, coutput, column,move_column, row, move_row, player, hieght);
        }
    }
}


int board::letter_to_numbers(char convert_letter, bool& illegal){
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
void board::within_array(int row, int player, bool& illegal){
    if(row<1 && row>7 ){
        illegal=true;
        cout<<"Not a row"<< "\n"; 
    }
    
}

void board::pawn_change(int chess[][8], int player, const int hieght){
    for(int i=0; i<hieght; i++){
        if(chess[0][i]==11){
            board::change_to(chess, player, i);    
        }
        else if(chess[7][i]==12){
            board::change_to(chess, player, i);    
        }
    }
}
void board::change_to(int chess[][8],int player, int i){
    int x;
    cout << "Change pawn to: ";
    if(player==1){
        while(chess[0][i]==11){   
            cin >> x;
            if(x==1){
                chess[0][i]=21;  
            }
            else if(x==2){
                chess[0][i]=31;  
            }
            else if(x==3){
                chess[0][i]=41;  
            }
            else if(x==4){
                chess[0][i]=51;  
            }
            else{
                cout<<"Not possible. Try to change again:";
            }
        }
    }
    else if(player==2){
        while(chess[7][i]==12){   
            cin >> x;
            if(x==1){
                chess[7][i]=22;  
            }
            else if(x==2){
                chess[7][i]=32;  
            }
            else if(x==3){
                chess[7][i]=42;  
            }
            else if(x==4){
                chess[7][i]=52;  
            }
            else{
                cout<<"Not possible. Try to change again:";
            }
        }
    }
}

