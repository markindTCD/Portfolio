class chess_board_square{
public:

chess_board_square();// default constructor
~chess_board_square();// default destructor

void move_making(int chess[][8], bool& illegal, bool coutput, int column,int row,int player, const int hieght);

void pawn_move_check(int chess[][8], bool& illegal, bool coutput, int column,int move_column, int row, int move_row, int player, const int hieght);

void rook_move_check(int chess[][8], bool& illegal, bool coutput, int column,int move_column, int row, int move_row, int player, const int hieght);
void knight_move_check(int chess[][8], bool& illegal, bool coutput, int column,int move_column, int row, int move_row, int player, const int hieght);
void bishop_move_check(int chess[][8], bool& illegal, bool coutput, int column,int move_column, int row, int move_row, int player, const int hieght);
void queen_move_check(int chess[][8], bool& illegal, bool coutput, int column,int move_column, int row, int move_row, int player, const int hieght);
void king_move_check(int chess[][8], bool& illegal, bool coutput, int column,int move_column, int row, int move_row, int player, const int hieght);

void search_king(int chess[][8], bool& illegal, bool coutput, int player, const int hieght);
void check_checker(int chess[][8], bool& illegal, bool coutput, int move_row, int move_column, int player, const int hieght);

void pawn_in_check(int chess[][8], bool& illegal, bool coutput, int move_row, int move_column, int player, const int hieght);
void rook_in_check(int chess[][8], bool& illegal, bool coutput, int move_row, int move_column, int player, const int hieght);
void knight_in_check(int chess[][8], bool& illegal, bool coutput, int move_row, int move_column, int player, const int hieght);
void bishop_in_check(int chess[][8], bool& illegal, bool coutput, int move_row, int move_column, int player, const int hieght);
void king_in_check(int chess[][8], bool& illegal, bool coutput, int move_row, int move_column, int player, const int hieght);


};