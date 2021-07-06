#include <iostream>
#include <vector>

using namespace std;

enum PIECE {B_ROOK =1, B_KING, B_BISHOP, B_QUEEN, B_KNIGHT, B_PAWN,
        W_ROOK, W_KING, W_BISHOP, W_QUEEN, W_KINGHT, W_PAWN};

class ChessBoard{
public:
    ChessBoard(){
        board[0]= {B_ROOK, B_KNIGHT, B_BISHOP, B_QUEEN, B_KING, B_BISHOP, B_KNIGHT, B_ROOK};
        board[7] = {W_ROOK, W_KINGHT, W_BISHOP, W_QUEEN, W_KING, W_BISHOP, W_KINGHT, W_ROOK};
        fill(board[1].begin(), board[1].end(), B_PAWN);
        fill(board[6].begin(), board[6].end(), W_PAWN);
    }
    friend ostream& operator<<(ostream& os, const ChessBoard& chess);

private:
    vector<vector<int>> board = vector<vector<int>>(8, vector<int>(8));
};

ostream& operator<<(ostream& os, const ChessBoard& chess)
{
    for(const auto i : chess.board)
    {
        for(const auto j : i)
        {
            cout << j << " ";
        }
        cout<<endl;
    }
    return os;
}

int main(void)
{
    ChessBoard c;
    std::cout << c << std::endl;
    return 0;
}