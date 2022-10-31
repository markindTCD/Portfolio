class board{
public:


board();// default constructor
~board();// default destructor

void move_making(int chess[][8], bool& illegal, bool coutput, int column,int row,int player, const int hieght);

void pawn_check(int chess[][8], bool& illegal, bool coutput, int column,int row,int player, const int hieght);
void rook_check(int chess[][8], bool& illegal, bool coutput, int column,int row,int player, const int hieght);
void knight_check(int chess[][8], bool& illegal, bool coutput, int column,int row,int player, const int hieght);
void bishop_check(int chess[][8], bool& illegal, bool coutput, int column,int row,int player, const int hieght);
void queen_check(int chess[][8], bool& illegal, bool coutput, int column,int row,int player, const int hieght);
void king_check(int chess[][8], bool& illegal, bool coutput, int column,int row,int player, const int hieght);


void pawn_change(int chess[][8], int player, const int hieght);
void change_to(int chess[][8], int player, int i);


int letter_to_numbers(char convert_letter, bool& illegal);
void within_array(int row, int player, bool& illegal);
};