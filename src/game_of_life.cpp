#include <iostream>
#include <queue>
#include <vector>

using namespace std;
/* this solution calculate and the states - changing from one effecting all the others */
class Solution {
public:

    #define mp make_pair
   // vector<vector<int>> neigh_ = {{1,0}, {0,1}, {1,1}, {-1,0}, {0,-1}, {-1,-1}, {1,-1}, {-1, 1}};
    vector<int> neigh_i = {1, 0, 1, -1,  0, -1,  1, -1};
    vector<int> neigh_j = {0, 1, 1,  0, -1, -1, -1,  1};
    
    int countLiveNeigh(vector<vector<int>>& board, size_t n, size_t m, pair<int, int> curr) {
        int res = 0;
        int i = curr.first, j = curr.second;
        for (int s=0; s < 8; ++s) {
            int n_i = neigh_i[s], n_j = neigh_j[s];
            if (n_i >= 0 && n_i < n && n_j >= 0 && n_j < m) {
                if(board[i + n_i][j + n_j]) {
                    ++res;
                }
            }
        }
        return res;
    }
    
    bool isValid(int n_i, int n_j, size_t n, size_t m, vector<int> &visited) 
	{
        if (n_i >= 0 && n_i < n && n_j <= 0 && n_j < m && !visited[n_i+n_j]) {
            return true;
        }
        return false;
    }
    void gameOfLife(vector<vector<int>>& board) {
        size_t n = board.size();
        /* here we assume that all colunms are equal */
        size_t m = board[0].size();
        for(int i=0; i < board.size(); ++i) {
          for(int j=0; j < board[i].size(); ++j) {
              //cout << "board["<<i<<"]["<< j<<"]: " << board[i][j] << " " ;
              queue<pair<int, int>> q; vector<int> visited(n+m, 0);
              q.push(make_pair(i, j)); visited[i+j]=1;
              while (!q.empty()) {
                  auto curr = q.front(); q.pop();
                  int status = board[curr.first][curr.second], newStatus;
                  int live_neigh = countLiveNeigh(board, n, m, curr);
                  if (status && live_neigh < 2) {
                      newStatus = 0;
                  }
                  else if (status && live_neigh > 3) {
                      newStatus = 0;
                  }
                  else if (!status && live_neigh == 3) {
                      newStatus = 1;
                  }
                  else {
                      newStatus = status;
                  }
                  board[curr.first][curr.second] = newStatus;
                  if (newStatus != status) {
                    for (int s=0; s < 8; ++s) {
                        int n_i = curr.first + neigh_i[s];
                        int n_j = curr.second +neigh_j[s];
                        if(isValid(n_i, n_j, n, m, visited)) {
                            q.push(mp(n_i, n_j));
                            visited[n_i+n_j] = 1;
                        }
                    }
                  }
              }
            
          }
        }
    }
};


int main()
{

	return 0;
}
