#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstdbool>
using namespace std;

struct grid {
  int r;
  int c;
};
typedef struct grid GRID ;

GRID coordinates(int input){
  GRID p;
  switch (input) {
    case 1:
      p.r = 0;
      p.c = 0;
      break;
    case 2:
      p.r = 0;
      p.c = 1;
      break;
    case 3:
        p.r = 0;
        p.c = 2;
        break;
    case 4:
        p.r = 1;
        p.c = 0;
        break;
    case 5:
        p.r = 1;
        p.c = 1;
        break;
    case 6:
        p.r = 1;
        p.c = 2;
      break;
    case 7:
        p.r = 2;
        p.c = 0;
        break;
    case 8:
        p.r = 2;
        p.c = 1;
        break;
    case 9:
        p.r = 2;
        p.c = 2;
        break;
    default:
    cout << "Out of grid" << endl;
  }
  return p;
}

void printboard(int board[3][3]){
  int i;
  for(i=0;i<3;i++){
    cout << " " << (board[i][0] == 0 ? " " : (board[i][0] == 1 ? "X" : "O"))  << " " << "|" << " " << (board[i][1] == 0 ? " " : (board[i][1] == 1 ? "X" : "O")) << " " <<  "|" << " " << (board[i][2] == 0 ? " " : (board[i][2] == 1 ? "X" : "O")) <<endl;
    if (i<2) {
      cout << "___________" << endl;
    }
  }
}
int isfull(int board[3][3]){
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      if (board[i][j] == 0) {
        return 0 ;
      }
    }
  }
  return 1;
}

int iswin(int p ,int board[3][3]){
  int i ;
  for (i = 0; i < 3; i++) {
    if (board[i][0] == p && board[i][1] == p && board[i][2] == p) {
      return 1;
    }
    if (board[0][i] == p && board[1][i] == p && board[2][i] == p) {
      return 1;
    }
  }
  if (board[0][0] == p && board[1][1] == p && board[2][2] == p ) {
    return 1;
  }
  if (board[0][2] == p && board[1][1] == p && board[2][0] == p ) {
    return 1;
  }
  return 0;
}

int score(int board[3][3]){
  int i ;
  for (i = 0; i < 3; i++) {
    if (board[i][0] == 2 && board[i][1] == 2 && board[i][2] == 2) {
      return 10;
    }else if (board[i][0] == 1 && board[i][1] == 1 && board[i][2] == 1) {
      return -10;
    }
    if (board[0][i] == 2 && board[1][i] == 2 && board[2][i] == 2) {
      return 10;
    }else if (board[0][i] == 1 && board[1][i] == 1 && board[2][i] == 1) {
      return -10;
    }
  }
  if (board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 2 ) {
    return 10;
  }else if (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1 ) {
    return -10;
  }
  if (board[0][2] == 2 && board[1][1] == 2 && board[2][0] == 2 ) {
    return 10;
  }else if (board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1 ) {
    return -10;
  }
  return 0;
}

int minimax(int board[3][3], int depth, bool ismax){
  int scoreval = score(board);
  if (scoreval == 10) {
    return scoreval;
  }
  if (scoreval == -10) {
    return scoreval;
  }
  if (isfull(board)) {
    return 0;
  }
  if(ismax){
    int best = -1000;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if(board[i][j] == 0){
          board[i][j] = 2;
          best = max(best , minimax(board , depth+1 , !ismax));
          board[i][j] = 0;
        }
      }
    }
    return best;
  }else{
    int best = 1000;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if(board[i][j] == 0){
          board[i][j] = 1;
          int value = minimax(board , depth+1 , !ismax);
          best = min(best , value);
          board[i][j] = 0;
        }
      }
    }
    return best;
  }
}

GRID findbest(int board[3][3]){
  int bestmove = -1000;
  GRID currbest;
  currbest.r = -1;
  currbest.c = -1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == 0) {
        board[i][j] = 2;
        int curr = minimax(board , 0 , false);
        board[i][j] = 0;
        if(curr > bestmove){
          bestmove = curr;
          currbest.r = i;
          currbest.c = j;
        }
      }
    }
  }
  return currbest;
}


int main(int argc, char const *argv[]) {
    int i , res , moves=0 , input;
    GRID p1 , p2;
    char reset;
    int board[3][3];
    start:
    for(i=0;i<3;i++){
      board[i][0] = board[i][1] = board[i][2] = 0;
    }
    system("clear");
    cout << "\t\tTic Tac Toe" << endl;
    cout << "\t1/PLAY AGAINST A FRIEND" << endl << "\t2/PLAY AGAINST COMPUTER" << endl<< "\t3/READ THE RULES" << endl << "\t4/EXIT" << endl;
    cin >> res;
    switch (res) {
      case 1:
        while (!isfull(board)) {

          if (moves % 2 == 0 ) {
            do {
              cout << "Player 1 , Enter the coordinate of your move:";
              cin >>  input;
              p1 = coordinates(input);
            } while(board[p1.r][p1.c] != 0);
            board[p1.r][p1.c] = 1 ;
            moves++;
            system("clear");
            printboard(board);
            if(iswin(1 , board)){
              cout << "Player 1 won !" << endl;
              cout << "restart ? (y or n)";
              cin >> reset;
              if (reset == 'y') {
                goto start;
              }
              return 0;
            }

          }
          else {
            do {
              cout << "Player 2 , Enter the coordinate of your move:";
              cin >>  input;
              p2 = coordinates(input);
            } while(board[p2.r][p2.c] != 0);
            moves++;
            board[p2.r][p2.c] = 2 ;
            system("clear");
            printboard(board);
            if(iswin(2 , board)){
              cout << "Player 2 won !" << endl;
              cout << "restart ? (y or n)";
              cin >> reset;
              if (reset == 'y') {
                goto start;
              }
              return 0;
            }
          }
        }
        break;
      case 2:
      while (!isfull(board)) {
        if (moves % 2 == 0 ) {
          do {
            cout << "Player 1 , Enter the coordinate of your move:";
            cin >>  input;
            p1 = coordinates(input);
          } while(board[p1.r][p1.c] != 0);
          board[p1.r][p1.c] = 1 ;
          moves++;
          system("clear");
          printboard(board);
          if(iswin(1 , board)){
            cout << "Player 1 won !" << endl;
            cout << "restart ? (y or n)";
            cin >> reset;
            if (reset == 'y') {
              goto start;
            }
            return 0;
          }
        }else {
          p2.r = findbest(board).r;
          p2.c = findbest(board).c;
          board[p2.r][p2.c] = 2 ;
          moves++;
          system("clear");
          printboard(board);
          if(iswin(2 , board)){
            cout << "Player 2 won !" << endl;
            cout << "restart ? (y or n)";
            cin >> reset;
            if (reset == 'y') {
              goto start;
            }
            return 0;
          }
        }
      }
        break;
      case 3 :
        system("clear");
        std::cout << "1. The game is played on a grid that's 3 squares by 3 squares." << endl << endl;
        std::cout << "2. You are X, your friend (or the computer in this case) is O." << endl << " Players take turns putting their marks in empty squares." << endl << endl;
        std::cout << "3. The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner." << endl << endl;
        std::cout << "4. When all 9 squares are full, the game is over." << endl << " If no player has 3 marks in a row, the game ends in a tie." << endl << endl;
        cout << "Start playing ? (y or n) ";
        cin >> reset;
        if (reset == 'y') {
          goto start;
        }else{
          return 0;
        }
        break;
      case 4 :
        system("clear");
        return 0;
        break;

    }
    system("clear");
    printboard(board);
    cout << "Tie" << endl;
    cout << "restart ? (y or n)";
    cin >> reset;
    if (reset == 'y') {
      goto start;
    }
    return 0;

}
