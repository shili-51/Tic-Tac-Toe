#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

char curr_marker;
int curr_player;

void drawboard()
{
    cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
    cout<<"-----------\n";
    cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
    cout<<"-----------\n";
    cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;
}
bool placeMarker(int slot)  /*if board is stored in linear array we will find row no and column no
                            with this function*/
{
    int row = slot/3;
    int col;
    if(slot%3 == 0)
    {
        row = row - 1;
        col = 2;
    }
     else
     {
         col = (slot%3) - 1;
     }
    //  cout<< row << ',' <<col;

    if(board[row][col]!='X' && board[row][col]!='O')
    {
        board[row][col] = curr_marker;
        return true;
    }
    else return false;
}

char winner()
{
    for(int i=0;i<3;i++)
    {
        if(board[i][0] == board[i][1] && board[i][1]==board[i][2]) return curr_player; /*one row is occupied*/
       if(board[0][i] == board[1][i] && board[1][i]==board[2][i]) return curr_player; /*one column is occupied*/
    }
    if(board[0][0] == board[1][1] && board[1][1]==board[2][2]) return curr_player; /*elements along diagonal*/
    if(board[0][2] == board[1][1] && board[1][1]==board[2][0]) return curr_player;

    return 0;
}
void swap_player_and_marker()
{
    if(curr_marker=='X') curr_marker = 'O';
    else curr_marker = 'X';

    if(curr_player==1) curr_player = 2;
    else curr_player = 1;
}
void game()
{
    cout<<"Player one,choose your marker : ";
    char marker_pl;
    cin>> marker_pl;

    curr_player = 1;
    curr_marker = marker_pl;
    int player_won;
    for(int i=0;i<9/2;i++) //another player is computer
    {
         cout<<"It's player"<<curr_player<<"'s turn. Enter your slot : ";
         int slot;
         cin>>slot;

         if(slot < 1 || slot > 9)
         {
             cout<<"That slot is invalid! Try another slot!";
             i--;
             continue;
         }
         if(!placeMarker(slot))
         {
             cout<<"That slot is occupied! Try another slot!";
             i--;
             continue;
         }
         drawboard();

         player_won = winner();

           if(player_won==1)
          {
              cout<<"Player one won! Congratulations!";
              break;
          }
            if(player_won==2)
          {
             cout<<"Player two won! Congratulations!";
             break;
          }
         swap_player_and_marker();
    }
    if(player_won==0)
    {
        cout<<"That is a tie game!";
    }

}
int main()
{
    // game();
    srand(time(NULL));
    cout<< (rand() % (10 - 1 + 1)) + 1;

    // [l,u] = (rand() % (U - l + 1)) + L     //to generate random numbers between a range

    //  [l,u] = (rand() % (10 - 1 + 1)) + 1

}

