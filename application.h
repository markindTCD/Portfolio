class application{
public:


application();// default constructor
~application();// default destructor
void test();
void run();

void start_board(int chess[][8], const int hieght);
void set_letter(char letter[],const int num_letter);
void print_board(int chess[][8],char letter[], const int hieght);
int letter_to_number(char convert_letter, bool& illegal);
void within_array(int row, int player, bool& illegal);


};