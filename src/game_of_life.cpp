#include <iostream>
#include <queue>
#include <vector>

using namespace std;
/* this solution calculate and the states - changing from one effecting all the others */

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
    int m = board.size(), n = m ? board[0].size() : 0;
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            int count = 0;
            for (int I=max(i-1, 0); I<=min(i+1, m-1); ++I)
                for (int J=max(j-1, 0); J<=min(j+1, n-1); ++J)
                    count += board[I][J] & 1;
            
            count -= board[i][j] & 1;
            
            if (board[i][j] == 1 && count >= 2 && count <= 3) {
                board[i][j] = 3;
            }
            if (board[i][j] == 0 && count ==3) {
                board[i][j] = 2;
            }
        }
    }
    for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
            board[i][j] >>= 1;
    }

};


int main()
{

	return 0;
}
