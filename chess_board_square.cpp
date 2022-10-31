#include <iostream>
#include "application.h"
#include "board.h"
#include "chess_board_square.h"
#include <string>

using namespace std;

const int CON_H=8;
const int CON_W=8;
const int LETTER=8;

chess_board_square::chess_board_square() {
  
};

chess_board_square::~chess_board_square(){
  
};

void chess_board_square::pawn_move_check(int chess[][8], bool& illegal, bool coutput, int column,int move_column, int row, int move_row, int player, const int hieght){
    int n;
    int x;
    if(player==1){
        if(move_row==(row-2) && move_column==column && chess[move_row][move_column]==00&& chess[move_row+1][move_column]==00){
            if(row==6){
                x=chess[move_row][move_column];
                chess[move_row][move_column]=11;
                
                chess[row][column]=00;
                chess_board_square::search_king(chess, illegal, coutput, player, hieght);
                if(illegal==true){
                    chess[move_row][move_column]=x;
                    chess[row][column]=11;    
                }
                
            }
            else{
                illegal=true;
                cout << "Cannot be done. try again." << "\n"; 
            }
        }
        else if(move_row==(row-1) && move_column==column && chess[move_row][move_column]==00){
            x=chess[move_row][move_column];
            chess[move_row][move_column]=11;
            chess[row][column]=00;
            chess_board_square::search_king(chess, illegal, coutput, player, hieght);
                if(illegal==true){
                    chess[move_row][move_column]=x;
                    chess[row][column]=11;    
                }
        }
        else if(move_row==(row-1) && move_column==(column+1) && chess[move_row][move_column]!=00 &&chess[move_row][move_column]!=11 &&chess[move_row][move_column]!=21 &&chess[move_row][move_column]!=61 &&chess[move_row][move_column]!=41&&chess[move_row][move_column]!=51 &&chess[move_row][move_column]!=31){
            x=chess[move_row][move_column];
            chess[move_row][move_column]=11;
            chess[row][column]=00;
            chess_board_square::search_king(chess, illegal, coutput, player, hieght);
                if(illegal==true){
                    chess[move_row][move_column]=x;
                    chess[row][column]=11;    
                }
        }
        else if(move_row==(row-1) && move_column==(column-1) && chess[move_row][move_column]!=00 &&chess[move_row][move_column]!=11 &&chess[move_row][move_column]!=21 &&chess[move_row][move_column]!=61 &&chess[move_row][move_column]!=41&&chess[move_row][move_column]!=51&&chess[move_row][move_column]!=31){
            x=chess[move_row][move_column];
            chess[move_row][move_column]=11;
            chess[row][column]=00;
            chess_board_square::search_king(chess, illegal, coutput, player, hieght);
                if(illegal==true){
                    chess[move_row][move_column]=x;
                    chess[row][column]=11;    
                }
        }
        else{
            illegal=true;
            cout << "Cannot be done. try again." << "\n";
        }
    }

    else if(player==2){
        if(move_row==(row+2) && move_column==column && chess[move_row][move_column]==00&& chess[move_row-1][move_column]==00){
            if(row==1){
                x=chess[move_row][move_column];
                chess[move_row][move_column]=12;
                
                chess[row][column]=00;
                chess_board_square::search_king(chess, illegal, coutput, player, hieght);
                if(illegal==true){
                    chess[move_row][move_column]=x;
                    chess[row][column]=12;    
                }
                
            }
            else{
                illegal=true;
                cout << "Cannot be done. try again." << "\n"; 
            }
        }
        else if(move_row==(row+1) && move_column==column && chess[move_row][move_column]==00){
            x=chess[move_row][move_column];
            chess[move_row][move_column]=12;
            chess[row][column]=00;
            chess_board_square::search_king(chess, illegal, coutput, player, hieght);
                if(illegal==true){
                    chess[move_row][move_column]=x;
                    chess[row][column]=12;    
                }
        }
        else if(move_row==(row+1) && move_column==(column+1) && chess[move_row][move_column]!=00 &&chess[move_row][move_column]!=12 &&chess[move_row][move_column]!=22 &&chess[move_row][move_column]!=62 &&chess[move_row][move_column]!=42&&chess[move_row][move_column]!=52 &&chess[move_row][move_column]!=32){
            x=chess[move_row][move_column];
            chess[move_row][move_column]=12;
            chess[row][column]=00;
            chess_board_square::search_king(chess, illegal, coutput, player, hieght);
                if(illegal==true){
                    chess[move_row][move_column]=x;
                    chess[row][column]=12;    
                }
        }
        else if(move_row==(row+1) && move_column==(column-1) && chess[move_row][move_column]!=00 &&chess[move_row][move_column]!=12 &&chess[move_row][move_column]!=22 &&chess[move_row][move_column]!=62 &&chess[move_row][move_column]!=42&&chess[move_row][move_column]!=52&&chess[move_row][move_column]!=32){
            x=chess[move_row][move_column];
            chess[move_row][move_column]=12;
            chess[row][column]=00;
            chess_board_square::search_king(chess, illegal, coutput, player, hieght);
                if(illegal==true){
                    chess[move_row][move_column]=x;
                    chess[row][column]=12;    
                }
        }
        else{
            illegal=true;
            cout << "Cannot be done. try again c." << "\n";
        }
    }
}
void chess_board_square::rook_move_check(int chess[][8], bool& illegal, bool coutput, int column,int move_column, int row, int move_row, int player, const int hieght){
    int n=0;
    int x,y;
    double direaction;
    if(player==1){
        if(move_row==row){
            direaction=move_column-column;
            if(direaction<0){
                for(int i=(move_column+1);i<column;i++){
                    if(chess[row][i]!=00){
                        n=n+1; 
                    }
                } 
            }
            else if(direaction>0){
                for(int i=(move_column-1);i>column;i--){
                    if(chess[row][i]!=00){
                        n=n+1;
                    }
                }
            }
      
            if(n!=0){
                illegal=true;
                cout << "Cannot be done. try again." << "\n"; 
            }
            else{
                if(chess[move_row][move_column]!=11 && chess[move_row][move_column]!=21 && chess[move_row][move_column]!=61 && chess[move_row][move_column]!=41&&chess[move_row][move_column]!=51 &&chess[move_row][move_column]!=31){
                    x=chess[move_row][move_column];
                    y=chess[row][column];
                    chess[move_row][move_column]=21;
                    chess[row][column]=00;
                    chess_board_square::search_king(chess, illegal, coutput, player, hieght);
                    if(illegal==true){
                        chess[move_row][move_column]=x;
                        chess[row][column]=y;    
                }   
                }
                else{
                    illegal=true;
                    cout << "Cannot be done. try again." << "\n";
                }
            }
        }
        else if(move_column==column){
            direaction=move_row-row;
            if(direaction<0){
                for(int i=(move_row+1);i<row;i++){
                    if(chess[i][column]!=00){
                        n=n+1; 
                    }
                } 
            }
            else if(direaction>0){
                    for(int i=(move_row-1);i>row;i--){
                        if(chess[i][column]!=00){
                            n=n+1; 
                        }
                    }
                }
            if(n!=0) {
                cout <<n<<"\n";
                illegal=true;
                cout << "Cannot be done. try again." << "\n"; 
            }
            else{
                if(chess[move_row][move_column]!=11 &&chess[move_row][move_column]!=21 && chess[move_row][move_column]!=61 && chess[move_row][move_column]!=41&&chess[move_row][move_column]!=51 &&chess[move_row][move_column]!=31){
                    x=chess[move_row][move_column];
                    y=chess[row][column];
                    chess[move_row][move_column]=21;
                    chess[row][column]=00;
                    chess_board_square::search_king(chess, illegal, coutput, player, hieght);
                    if(illegal==true){
                        chess[move_row][move_column]=x;
                        chess[row][column]=y;    
                    }
                }
                else{
                    illegal=true;
                    cout << "Cannot be done. try again." << "\n";
                }
            }  
        }
        else{
            illegal=true;
            cout << "Cannot be done. try again." << "\n";  
        }
    } 
    else if(player==2){
        if(move_row==row){
            direaction=move_column-column;
            if(direaction<0){
                for(int i=(move_column+1);i<column;i++){
                    if(chess[row][i]!=00){
                        n=n+1; 
                    }
                } 
            }
            else if(direaction>0){
                for(int i=(move_column-1);i>column;i--){
                    if(chess[row][i]!=00){
                        n=n+1; 
                    }
                }
            }
            if(n!=0) {
                illegal=true;
                cout << "Cannot be done. try again." << "\n"; 
            }
            else{
                if(chess[move_row][move_column]!=12 &&chess[move_row][move_column]!=22 && chess[move_row][move_column]!=62 && chess[move_row][move_column]!=42&&chess[move_row][move_column]!=52 &&chess[move_row][move_column]!=32){
                    x=chess[move_row][move_column];
                    y=chess[row][column];
                    chess[move_row][move_column]=22;
                    chess[row][column]=00;
                    chess_board_square::search_king(chess, illegal, coutput, player, hieght);
                    if(illegal==true){
                        chess[move_row][move_column]=x;
                        chess[row][column]=y;    
                    }
                }
                else{
                    illegal=true;
                    cout << "Cannot be done. try again." << "\n";
                }
            }
        }
        else if(move_column==column){
            direaction=move_row-row;
            if(direaction<0){
                for(int i=(move_row+1);i<row;i++){
                    if(chess[i][column]!=00){
                         n=n+1; 
                    }
                } 
            }
            else if(direaction>0){
                    for(int i=(move_row-1);i>row;i--){
                        if(chess[i][column]!=00){
                            n=n+1; 
                        }
                    }
                }
            if(n!=0) {
                illegal=true;
                cout << "Cannot be done. try again." << "\n"; 
            }
            else{
                if(chess[move_row][move_column]!=12 &&chess[move_row][move_column]!=22 && chess[move_row][move_column]!=61 && chess[move_row][move_column]!=42&&chess[move_row][move_column]!=52 &&chess[move_row][move_column]!=31){
                    x=chess[move_row][move_column];
                    y=chess[row][column];
                    chess[move_row][move_column]=22;
                    chess[row][column]=00;
                    chess_board_square::search_king(chess, illegal, coutput, player, hieght);
                    if(illegal==true){
                            chess[move_row][move_column]=x;
                            chess[row][column]=y;    
                    }
                }
                else{
                    illegal=true;
                    cout << "Cannot be done. try again." << "\n";
                }
            }  
        }
        else{
            illegal=true;
            cout << "Cannot be done. try again." << "\n";  
        }
        
    } 
}
void chess_board_square::knight_move_check(int chess[][8], bool& illegal, bool coutput, int column,int move_column, int row, int move_row, int player, const int hieght){
    int n=0;
    int x;
    if(player==1){ 
        if(move_row==(row+2) && move_column==(column+1)){
           n=1;
        }
        else if(move_row==(row+2) && move_column==(column-1)){
                n=1;
        }
        else if(move_row==(row+1) && move_column==(column+2)){
                n=1;
        }
        else if(move_row==(row+1) && move_column==(column-2)){
                n=1; 
        }
        else if(move_row==(row-2) && move_column==(column+1)){
                n=1;
        }
        else if(move_row==(row-2) && move_column==(column-1)){
                n=1; 
        }
        else if(move_row==(row-1) && move_column==(column+2)){
                n=1;
        }
        else if(move_row==(row-1) && move_column==(column-2)){
                n=1; 
        }
        
        if(n==0){
            illegal=true;
            cout<< "Cannot be done. try again." << "\n"; 
        }
        else if(n==1){
            if(chess[move_row][move_column]==11 || chess[move_row][move_column]==21 || chess[move_row][move_column]==61 || chess[move_row][move_column]==41||chess[move_row][move_column]==51 || chess[move_row][move_column]==31){
                illegal=true;
                cout<< "Cannot be done. try again." << "\n";
            }
            else{
                x=chess[move_row][move_column];
                chess[move_row][move_column]=31;
                chess[row][column]=00;
                chess_board_square::search_king(chess, illegal, coutput, player, hieght);
                if(illegal==true){
                        chess[move_row][move_column]=x;
                        chess[row][column]=31;    
                }
            }
        }
    }
    else if(player==2){ 
        if(move_row==(row+2) && move_column==(column+1)){
           n=1;
        }
        else if(move_row==(row+2) && move_column==(column-1)){
                n=1;
        }
        else if(move_row==(row+1) && move_column==(column+2)){
                n=1;
        }
        else if(move_row==(row+1) && move_column==(column-2)){
                n=1; 
        }
        else if(move_row==(row-2) && move_column==(column+1)){
                n=1;
        }
        else if(move_row==(row-2) && move_column==(column-1)){
                n=1; 
        }
        else if(move_row==(row-1) && move_column==(column+2)){
                n=1;
        }
        else if(move_row==(row-1) && move_column==(column-2)){
                n=1; 
        }
        
        if(n==0){
            illegal=true;
            cout<< "Cannot be done. try again." << "\n"; 
            
        }
        else if(n==1){
            if(chess[move_row][move_column]==12 || chess[move_row][move_column]==22 || chess[move_row][move_column]==62 || chess[move_row][move_column]==42||chess[move_row][move_column]==52 || chess[move_row][move_column]==32){
                illegal=true;
                cout<< "Cannot be done. try again." << "\n";
            }
            else{
                x=chess[move_row][move_column];
                chess[move_row][move_column]=32;
                chess[row][column]=00;
                chess_board_square::search_king(chess, illegal, coutput, player, hieght);
                if(illegal==true){
                        chess[move_row][move_column]=x;
                        chess[row][column]=32;    
                }
            }
        }
    }
}
void chess_board_square::bishop_move_check(int chess[][8], bool& illegal, bool coutput, int column,int move_column, int row, int move_row, int player, const int hieght){
    int n=0;
    int z=0;
    int i, j;
    int x,y;
    if(player==1){
        if((move_row-row)==(move_column-column)){
            n=1;
        }
        else if((move_row-row)==(-(move_column-column))){
            n=2;
        }
    
        if(n==0){
            illegal=true;
            cout<< "Cannot be done. try again." << "\n"; 
        }
        else{
            if(n==1){
                if((move_row-row)>0){
                    for(i=(move_row-1);i>row;i--){
                        for(j=(move_column-1);j>column;j--){
                            if(chess[i][j]!=00){
                                z=z+1;
                            }
                        } 
                    } 
                }
                else if((move_row-row)<0){
                    for(i=(move_row+1);i<row;i++){
                        for(j=(move_column+1);j<column;j++){
                            if(chess[i][j]!=00){
                                z=z+1;    
                            }
                        }
                    }
                }
                
                if(z!=0){
                    illegal=true;
                    cout<< "Cannot be done. try again." << "\n"; 
                }
                else{
                    if(chess[move_row][move_column]!=11 && chess[move_row][move_column]!=21 && chess[move_row][move_column]!=61&&chess[move_row][move_column]!=51 &&chess[move_row][move_column]!=41 &&chess[move_row][move_column]!=31){
                        x=chess[move_row][move_column];
                        y=chess[row][column];
                        chess[move_row][move_column]=41;
                        chess[row][column]=00;
                        chess_board_square::search_king(chess, illegal, coutput, player, hieght);
                        if(illegal==true){
                            chess[move_row][move_column]=x;
                            chess[row][column]=y;    
                        }
                    }
                    else{
                        illegal=true;
                        cout<< "Cannot be done. try again." << "\n";    
                    }
                }
            }
            else if(n==2){
                if((move_row-row)>0){
                    for(i=(move_row-1);i>row;i--){
                        for(j=(move_column+1);j<column;j++){
                            if(chess[i][j]!=00){
                                z=z+1;
                            }
                        } 
                    }
                }
                else if((move_row-row)<0){
                    for(i=(move_row+1);i<row;i++){
                        for(j=(move_column-1);j>column;j--){
                            if(chess[i][j]!=00){
                                z=z+1;
                            }
                        } 
                    }
                }
                
                if(z!=0){
                    illegal=true;
                    cout<< "Cannot be done. try again." << "\n"; 
                }
                else{
                    if(chess[move_row][move_column]!=11 && chess[move_row][move_column]!=21 && chess[move_row][move_column]!=61&&chess[move_row][move_column]!=51 &&chess[move_row][move_column]!=41 &&chess[move_row][move_column]!=31){
                        x=chess[move_row][move_column];
                        y=chess[row][column];
                        chess[move_row][move_column]=41;
                        chess[row][column]=00;
                        chess_board_square::search_king(chess, illegal, coutput, player, hieght);
                        if(illegal==true){
                            chess[move_row][move_column]=x;
                            chess[row][column]=y;    
                        }
                    }
                    else{
                        illegal=true;
                        cout<< "Cannot be done. try again." << "\n";    
                    }
                }
            }
        }
    }
    if(player==2){
        if((move_row-row)==(move_column-column)){
            n=1;
        }
        else if((move_row-row)==(-(move_column-column))){
            n=2;
        }
    
        if(n==0){
            illegal=true;
            cout<< "Cannot be done. try again." << "\n"; 
        }
        else{
                if(n==1){
                    if((move_row-row)>0){
                        for(i=(move_row-1);i>row;i--){
                            for(j=(move_column-1);j>column;j--){
                                if(chess[i][j]!=00){
                                    z=z+1;
                                }
                            } 
                        } 
                    }
                    else if((move_row-row)<0){
                        for(i=(move_row+1);i<row;i++){
                            for(j=(move_column+1);j<column;j++){
                                if(chess[i][j]!=00){
                                    z=z+1;    
                                }
                            }
                        }
                    }
                    if(z!=0){
                        illegal=true;
                        cout<< "Cannot be done. try again." << "\n"; 
                    }
                    else{
                        if(chess[move_row][move_column]!=12 && chess[move_row][move_column]!=22 && chess[move_row][move_column]!=62&&chess[move_row][move_column]!=52 &&chess[move_row][move_column]!=42&&chess[move_row][move_column]!=32){
                            x=chess[move_row][move_column];
                            y=chess[row][column];
                            chess[move_row][move_column]=42;
                            chess[row][column]=00;
                            chess_board_square::search_king(chess, illegal, coutput, player, hieght);
                            if(illegal==true){
                                chess[move_row][move_column]=x;
                                chess[row][column]=y;    
                            }
                        }
                        else{
                            illegal=true;
                            cout<< "Cannot be done. try again." << "\n";    
                        }
                    }
            }
            else if(n==2){
                if((move_row-row>0)){
                    for(i=(move_row-1);i>row;i--){
                        for(j=(move_column+1);j<column;j++){
                            if(chess[i][j]!=00){
                                z=z+1;
                            }
                        } 
                    }
                }
                else if((move_row-row)<0){
                    for(i=(move_row+1);i<row;i++){
                        for(j=(move_column-1);j>column;j--){
                            if(chess[i][j]!=00){
                                z=z+1;
                            }
                        } 
                    }
                }
                if(z!=0){
                    illegal=true;
                    cout<< "Cannot be done. try again." << "\n"; 
                }
                else{
                    if(chess[move_row][move_column]!=12 && chess[move_row][move_column]!=22 && chess[move_row][move_column]!=62&&chess[move_row][move_column]!=52 &&chess[move_row][move_column]!=32 &&chess[move_row][move_column]!=42){
                        x=chess[move_row][move_column];
                        y=chess[row][column];
                        chess[move_row][move_column]=42;
                        chess[row][column]=00;
                        chess_board_square::search_king(chess, illegal, coutput, player, hieght);
                        if(illegal==true){
                            chess[move_row][move_column]=x;
                            chess[row][column]=42;    
                        }
                    }
                    else{
                        illegal=true;
                        cout<< "Cannot be done. try again." << "\n";    
                    }
                }
            }
        }
    }
}
void chess_board_square::queen_move_check(int chess[][8], bool& illegal, bool coutput, int column,int move_column, int row, int move_row, int player, const int hieght){
    if(player==1){   
        if(move_row==row || move_column==column){
            chess_board_square::rook_move_check(chess, illegal, coutput, column,move_column, row, move_row, player, hieght);
            if(chess[move_row][move_column]==21){
                chess[move_row][move_column]=51; 
            }
        }
        else{
            chess_board_square::bishop_move_check(chess, illegal, coutput, column,move_column, row, move_row, player, hieght);
            if(chess[move_row][move_column]==41){
                chess[move_row][move_column]=51; 
            }
        }
    }
    else if(player==2){   
        if(move_row==row || move_column==column){
            chess_board_square::rook_move_check(chess, illegal, coutput, column,move_column, row, move_row, player, hieght);
            if(chess[move_row][move_column]==22){
                chess[move_row][move_column]=52; 
            }
        }
        else{
            chess_board_square::bishop_move_check(chess, illegal, coutput, column,move_column, row, move_row, player, hieght);
            if(chess[move_row][move_column]==42){
                chess[move_row][move_column]=52; 
            }
        }
    }
}
void chess_board_square::king_move_check(int chess[][8], bool& illegal, bool coutput,  int column,int move_column, int row, int move_row, int player, const int hieght){
    if(player==1){
        if(move_row==row && move_column==(column+2)&& chess[7][4]==61 && chess[7][7]==21&& chess[7][6]==00 &&chess[7][5]==00){
            
            chess_board_square::check_checker(chess, illegal, coutput, move_row, move_column, player, hieght);
            if(illegal==false){
                chess[7][6]=61;
                chess[7][5]=21;
                chess[7][4]=00;
                chess[7][7]=00;
            }
        }
        else if(move_row>(row+1)||move_row<(row-1)||move_column>(column+1)||move_column<(column-1)){
            illegal=true;
            cout<< "Cannot be done. try again." << "\n";     
        }
        else{
            
            if(chess[move_row][move_column]!=11&&chess[move_row][move_column]!=21&&chess[move_row][move_column]!=31&&chess[move_row][move_column]!=41&&chess[move_row][move_column]!=51){
                    
                chess_board_square::check_checker(chess, illegal, coutput, move_row, move_column, player, hieght);
                if(illegal==false){  
                    chess[move_row][move_column]=61;
                    chess[row][column]=00;
                }
            }
            else{
                illegal=true;
                cout<< "Cannot be done. try again." << "\n";    
            }
            
        }
    }    
    
    if(player==2){
        if(move_row==row && move_column==(column+2)&& chess[0][4]==62 && chess[0][7]==22&& chess[0][6]==00 &&chess[0][5]==00){
            
            chess_board_square::check_checker(chess, illegal, coutput, move_row, move_column, player, hieght);
            if(illegal==false){
                chess[0][6]=62;
                chess[0][5]=22;
                chess[0][4]=00;
                chess[0][7]=00;
            }
        }
        else if(move_row>(row+1)&&move_row<(row-1)&&move_column>(column+1) &&move_column<(column-1)){
            illegal=true;
            cout<< "Cannot be done. try again." << "\n";     
            
        }
        else{
            
            if(chess[move_row][move_column]!=12&&chess[move_row][move_column]!=22&&chess[move_row][move_column]!=32&&chess[move_row][move_column]!=42&&chess[move_row][move_column]!=52){
                    
                chess_board_square::check_checker(chess, illegal, coutput, move_row, move_column, player, hieght);
                if(illegal==false){  
                    chess[move_row][move_column]=62;
                    chess[row][column]=00;   
                }
            }
            else{
                illegal=true;
                cout<< "Cannot be done. try again." << "\n";    
            }
        }
    }       
}

void chess_board_square::search_king(int chess[][8], bool& illegal, bool coutput, int player, const int hieght){
    int king_row, king_column;
    if(player==1){
        for(int i=0; i<hieght;i++){
            for(int j=0; j<CON_W; j++){
                if(chess[i][j]==61){
                    king_row=i;
                    king_column=j;
                    chess_board_square::check_checker(chess, illegal, coutput, king_row, king_column, player, hieght);
                }
            }
        }
    }
    if(player==2){
        for(int i=0; i<hieght;i++){
            for(int j=0; j<CON_W; j++){
                if(chess[i][j]==62){
                    king_row=i;
                    king_column=j;
                    chess_board_square::check_checker(chess, illegal, coutput, king_row, king_column, player, hieght);
                }
            }
        }
    }
}

void chess_board_square::check_checker(int chess[][8], bool& illegal, bool coutput, int move_row, int move_column, int player, const int hieght){
    
chess_board_square::pawn_in_check(chess, illegal, coutput, move_row, move_column, player, hieght);

    if(illegal==false){
        chess_board_square::rook_in_check(chess, illegal, coutput, move_row, move_column, player, hieght);
    }
    if(illegal==false){
        chess_board_square::knight_in_check(chess, illegal, coutput, move_row, move_column, player, hieght);
    }
    if(illegal==false){
        chess_board_square::bishop_in_check(chess, illegal, coutput, move_row, move_column, player, hieght);
    }

    if(illegal==false){
        chess_board_square::king_in_check(chess, illegal, coutput, move_row, move_column, player, hieght);
    }
}
void chess_board_square::pawn_in_check(int chess[][8], bool& illegal,bool coutput, int move_row, int move_column, int player, const int hieght){
    if(player==1){
        if((move_column+1)<=7 && (move_column-1)>=0 && (move_row-1)>=0){
            if(chess[move_row-1][move_column+1]==12 ||chess[move_row-1][move_column-1]==12 ){
                illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }
            }
        }
    }
    else if(player==2){
        if((move_column+1)<=7 && (move_column-1)>=0 && (move_row+1)<=7){
            if(chess[move_row+1][move_column+1]==11 ||chess[move_row+1][move_column-1]==11 ){
                illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }
            }
        }
    }
}
void chess_board_square::rook_in_check(int chess[][8], bool& illegal, bool coutput, int move_row, int move_column, int player, const int hieght){
    int row, column;
    if(player==1){
        
        row=move_row-1;
        while(row>=0 && illegal!=true){
            if(chess[row][move_column]==00||chess[row][move_column]==61){
               row=row-1;
            }
            else{
                if(chess[row][move_column]==22 ||chess[row][move_column]==52){
                illegal=true;
                    if(coutput==true){
                        cout << "Your king would be in check on your own turn. Try again." << "\n";
                    }
                }
                else{
                    row =-999;
                }
            }
        }
        row=move_row+1;
        while(row<8 && illegal!=true){
            if(chess[row][move_column]==00||chess[row][move_column]==61){
               row=row+1;
            }
            else{
                if(chess[row][move_column]==22 ||chess[row][move_column]==52){
                illegal=true;
                    if(coutput==true){
                        cout << "Your king would be in check on your own turn. Try again." << "\n";
                    }
                }
                else{
                    row =999;
                }
            }
        }
        
        column=move_column-1;
        while((column>-1) && illegal!=true){
            if(chess[move_row][column]==00||chess[move_row][column]==61){
               column=column-1;
            }
            else{
                if(chess[move_row][column]==22 ||chess[move_row][column]==52){
                illegal=true;
                    if(coutput==true){
                        cout << "Your king would be in check on your own turn. Try again." << "\n";
                    }
                }
                else{
                    column =-999;
                }
            }
        }
        column=move_column+1;
        while(column<=7 && illegal!=true){
            if(chess[move_row][column]==00||chess[move_row][column]==61){
               column=column+1;
            }
            else{
                if(chess[move_row][column]==22||chess[move_row][column]==52){
                illegal=true;
                    if(coutput==true){
                        cout << "Your king would be in check on your own turn. Try again." << "\n";
                    }
                }
                else{
                    column =+999;
                }
            }
        }
    }
    if(player==2){
        
        row=move_row-1;
        while(row>=0 && illegal!=true){
            if(chess[row][move_column]==00||chess[row][move_column]==62){
               row=row-1;
            }
            else{
                if(chess[row][move_column]==21 ||chess[row][move_column]==51){
                illegal=true;
                    if(coutput==true){
                        cout << "Your king would be in check on your own turn. Try again." << "\n";
                    }
                }
                else{
                    row =-999;
                }
            }
        }
        row=move_row+1;
        while(row<8 && illegal!=true){
            if(chess[row][move_column]==00||chess[row][move_column]==62){
               row=row+1;
            }
            else{
                if(chess[row][move_column]==21 ||chess[row][move_column]==51){
                illegal=true;
                    if(coutput==true){
                        cout << "Your king would be in check on your own turn. Try again." << "\n";
                    }
                }
                else{
                    row =999;
                }
            }
        }
        
        column=move_column-1;
        while((column>-1) && illegal!=true){
            if(chess[move_row][column]==00||chess[move_row][column]==62){
               column=column-1;
            }
            else{
                if(chess[move_row][column]==21 ||chess[move_row][column]==51){
                illegal=true;
                    if(coutput==true){
                        cout << "Your king would be in check on your own turn. Try again." << "\n";
                    }}
                else{
                    column =-999;
                }
            }
        }
        column=move_column+1;
        while(column<=7 && illegal!=true){
            if(chess[move_row][column]==00||chess[move_row][column]==62){
               column=column+1;
            }
            else{
                if(chess[move_row][column]==21||chess[move_row][column]==51){
                illegal=true;
                    if(coutput==true){
                        cout << "Your king would be in check on your own turn. Try again." << "\n";
                    }
                }
                else{
                    column =+999;
                }
            }
        }
    } 
}

void chess_board_square::knight_in_check(int chess[][8], bool& illegal,bool coutput, int move_row, int move_column, int player, const int hieght){
    if(player==1){
        if((move_column+1)<8 && (move_row+2)<8){
            if(chess[move_row+2][move_column+1]==32){
                illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }
            }
        }
        if((move_column-1)>-1 && (move_row+2)<8){
            if(chess[move_row+2][move_column-1]==32){
                illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }
            }
        }
        if((move_column+2)<8 && (move_row+1)<8){
            if(chess[move_row+1][move_column+2]==32){
                illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }    
            }
        }
        if((move_column-2)>-1 && (move_row+1)<8){
            if(chess[move_row+1][move_column-2]==32){
            illegal=true;
            if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }
            }
        }
        if((move_column+1)<8 && (move_row-2)>-1){
            if(chess[move_row-2][move_column+1]==32){
                illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }    
            }
        }
        if((move_column-1)>-1 && (move_row-2)>-1){
            if(chess[move_row-2][move_column-1]==32){
                illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }    
            }
        }
        if((move_column+2)<8 && (move_row-1)>-1){
            if(chess[move_row-1][move_column+2]==32){
                illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }    
            }
        }
        if((move_column-2)>-1 && (move_row-1)>-1){
            if(chess[move_row-1][move_column-2]==32){
                illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }        
            }
        }
    }
    else if(player==2){
        if((move_column+1)<8 && (move_row+2)<8){
            if(chess[move_row+2][move_column+1]==31){
                illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }
            }
        }
        if((move_column-1)>-1 && (move_row+2)<8){
            if(chess[move_row+2][move_column-1]==31){
                illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }
            }
        }
        if((move_column+2)<8 && (move_row+1)<8){
            if(chess[move_row+1][move_column+2]==31){
                illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }    
            }
        }
        if((move_column-2)>-1 && (move_row+1)<8){
            if(chess[move_row+1][move_column-2]==31){
            illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }
            }
        }
        if((move_column+1)<8 && (move_row-2)>-1){
            if(chess[move_row-2][move_column+1]==31){
                illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }    
            }
        }
        if((move_column-1)>-1 && (move_row-2)>-1){
            if(chess[move_row-2][move_column-1]==31){
                illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }    
            }
        }
        if((move_column+2)<8 && (move_row-1)>-1){
            if(chess[move_row-1][move_column+2]==31){
                illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }    
            }
        }
        if((move_column-2)>-1 && (move_row-1)>-1){
            if(chess[move_row-1][move_column-2]==31){
                illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }        
            }
        }
    }
}

void chess_board_square::bishop_in_check(int chess[][8], bool& illegal,bool coutput, int move_row, int move_column, int player, const int hieght){
    int row, column;
    if(player==1){
        row=move_row+1;
        column=move_column+1;
        while(row<=7 && column<=7 && illegal==false){
            if(chess[row][column]==00||chess[row][column]==61){
                row=row+1;
                column=column+1;
            }
            else{
                if(chess[row][column]==42||chess[row][column]==52){
                    illegal=true;
                    if(coutput==true){
                        cout << "Your king would be in check on your own turn. Try again." << "\n";
                    }     
                }
                else{
                    row=999;
                }
            }
        }
        row=move_row+1;
        column=move_column-1;
        while(row<=7 && column>=0 && illegal==false){
            if(chess[row][column]==00||chess[row][column]==61){
                row=row+1;
                column=column-1;
            }
            else{
                if(chess[row][column]==42 ||chess[row][column]==52){
                    illegal=true;
                    if(coutput==true){
                        cout << "Your king would be in check on your own turn. Try again." << "\n";
                    }     
                }
                else{
                    row=999;
                }
            }
        }
        row=move_row-1;
        column=move_column+1;
        while(row>=0 && column<=7 && illegal==false){
            if(chess[row][column]==00||chess[row][column]==61){
                row=row-1;
                column=column+1;
            }
            else{
                if(chess[row][column]==42 ||chess[row][column]==52){
                illegal=true;
                    if(coutput==true){
                        cout << "Your king would be in check on your own turn. Try again." << "\n";
                    }     
                }
                else{
                    row=-999;
                }
            }
        }
        row=move_row-1;
        column=move_column-1;
        while(row>=0 && column>=0 && illegal==false){
            if(chess[row][column]==00||chess[row][column]==61){
                row=row-1;
                column=column-1;
            }
            else{
                if(chess[row][column]==42 ||chess[row][column]==52){
                    illegal=true;
                    if(coutput==true){
                        cout << "Your king would be in check on your own turn. Try again." << "\n";
                    }    
                }
                else{
                    row=-999;
                }
            }
        }
    }    
    else if(player==2){
        row=move_row+1;
        column=move_column+1;
        while(row<=7 && column<=7 && illegal==false){
            if(chess[row][column]==00||chess[row][column]==62){
                row=row+1;
                column=column+1;
            }
            else{
                if(chess[row][column]==41||chess[row][column]==51){
                    illegal=true;
                    if(coutput==true){
                        cout << "Your king would be in check on your own turn. Try again." << "\n";
                    }     
                }
                else{
                    row=999;
                }
            }
        }
        row=move_row+1;
        column=move_column-1;
        while(row<=7 && column>=0 && illegal==false){
            if(chess[row][column]==00||chess[row][column]==62){
                row=row+1;
                column=column-1;
            }
            else{
                if(chess[row][column]==41 ||chess[row][column]==51){
                    illegal=true;
                    if(coutput==true){
                        cout << "Your king would be in check on your own turn. Try again." << "\n";
                    }     
                }
                else{
                    row=999;
                }
            }
        }
        row=move_row-1;
        column=move_column+1;
        while(row>=0 && column<=7 && illegal==false){
            if(chess[row][column]==00||chess[row][column]==62){
                row=row-1;
                column=column+1;
            }
            else{
                if(chess[row][column]==41 ||chess[row][column]==51){
                illegal=true;
                    if(coutput==true){
                        cout << "Your king would be in check on your own turn. Try again." << "\n";
                    }     
                }
                else{
                    row=-999;
                }
            }
        }
        row=move_row-1;
        column=move_column-1;
        while(row>=0 && column>=0 && illegal==false){
            if(chess[row][column]==00||chess[row][column]==62){
                row=row-1;
                column=column-1;
            }
            else{
                if(chess[row][column]==41 ||chess[row][column]==51){
                    illegal=true;
                    if(coutput==true){
                        cout << "Your king would be in check on your own turn. Try again." << "\n";
                    }     
                }
                else{
                    row=-999;
                }
            }
        }
    }
}

void chess_board_square::king_in_check(int chess[][8], bool& illegal, bool coutput, int move_row, int move_column, int player, const int hieght){
    if(player==1)    {
        if(move_row+1<=7){
            if(chess[move_row+1][move_column]==62){
                illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }
            }
        }
        if(move_row+1<=7&&move_column+1<=7){
            if(chess[move_row+1][move_column+1]==62){
                illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }
            }
        }
        if(move_column+1<=7){
            if(chess[move_row][move_column+1]==62){
                illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }    
            }
        }
        if(move_row-1>=0&&move_column+1<=7){
            if(chess[move_row-1][move_column+1]==62){
                illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }
            }
        }
        if(move_row-1>=0){
            if(chess[move_row-1][move_column]==62){
                illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }    
            }
        }
        if(move_row-1>=0&&move_column-1>=0){
            if(chess[move_row-1][move_column-1]==62){
                illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }    
            }
        }
        if(move_column-1>=0){
            if(chess[move_row][move_column-1]==62){
                illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }    
            }
        }
        if(move_column-1>=0&&move_row+1<=7){
            if(chess[move_row+1][move_column-1]==62){
                illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }        
            }  
        }
    }
    else if(player==2)    {
        if(move_row+1<=7){
            if(chess[move_row+1][move_column]==61){
                illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }
            }
        }
        if(move_row+1<=7&&move_column+1<=7){
            if(chess[move_row+1][move_column+1]==61){
                illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }
            }
        }
        if(move_column+1<=7){
            if(chess[move_row][move_column+1]==61){
                illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }    
            }
        }
        if(move_row-1>=0&&move_column+1<=7){
            if(chess[move_row-1][move_column+1]==61){
                illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }
            }
        }
        if(move_row-1>=0){
            if(chess[move_row-1][move_column]==61){
                illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }    
            }
        }
        if(move_row-1>=0&&move_column-1>=0){
            if(chess[move_row-1][move_column-1]==61){
                illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }    
            }
        }
        if(move_column-1>=0){
            if(chess[move_row][move_column-1]==61){
                illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }    
            }
        }
        if(move_column-1>=0&&move_row+1<=7){
            if(chess[move_row+1][move_column-1]==61){
                illegal=true;
                if(coutput==true){
                    cout << "Your king would be in check on your own turn. Try again." << "\n";
                }        
            }  
        }
    }
}