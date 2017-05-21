//
//
//  Created by Nathaniel Kohn on 11 M 2017.
//  Copyright © 2017 Nathaniel Kohn. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <sstream>
#include <memory>
#include <algorithm>
#include <memory>
#include <iomanip>
#include <cmath>

/* My Templates for convenience */
#define INF 0x3f3f3f3f
#define rep(i, j, k) for(int i = (int)j; i < (int)k; ++i)
#define sz(x) ( (int) x.size())
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define zero(x) memset((x), 0, sizeof((x)))
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int ,int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using seii = set<ii>;
using stii = stack<ii>;
using StrSet = set<string>;
using vs = vector<string>;



class Solution {
public:
    Solution() {}
    bool isValid (vector<vector<char>> &image, int x, int y) {
        if( x <0 || y < 0 || x > image.size()-1 || y > image[0].size()-1 || image[x][y] != '1') {
            return false;
        }
        return true;
    }
    
    int minArea(vector<vector<char>>& image, int x, int y) {
        static vector<int> neighY = {1, 0, -1,  0 };
        static vector<int> neighX = {0, 1,  0, -1 };
        
        int minY = (int)image[0].size()-1, minX = (int)image.size()-1;
        int maxY = 0, maxX = 0;
        if(!isValid(image, x, y)) {
            return 0;
        }
        stack<pair<int,int>> st;
        st.push(make_pair(x,y));
        image[x][y] = '2';
        while (!st.empty()) {
            auto curr = st.top(); st.pop();
            int nx = curr.first, ny = curr.second;
            minY = min(minY, ny); minX = min(minX, nx);
            maxY = max(maxY, ny); maxX = max(maxX, nx);
           
            for(int i=0; i < 4; ++i) {
                if(isValid(image, curr.first+neighX[i], curr.second + neighY[i])) {
                    st.push(make_pair(curr.first+neighX[i], curr.second+neighY[i]));
                    image[curr.first+neighX[i]][curr.second+neighY[i]] = '2';
                }
            }
        }

        
        return (maxY-minY+1)*(maxX-minX+1);
    }
};

int main()

{
	//while(scanf("%d%d%d%d",&A,&B,&E,&P)!=EOF) {
    
	//}
//    ["0010","0110","0100"]
//    0
//    2
    vector<vector<char>> image = { {'0','0','1','0'}, {'0','1','1', '0'} , {'0','1','0', '0'} };
    Solution s;
    cout << s.minArea(image, 0, 2) << endl;
    
    return 0;
}








#ifdef DEGBUG
    /*
    int N; int T;
    cin >> T;
    rep(i, 0, T) {
        vii v;
        cin >> N;
       int M;
        cin >> M; set<string> fs;
        for (int i = 0; i < N; ++i) {
            string name;
//            while(getline(cin, name) && name.empty());
           //        reverseStr(s) ;
        }
//        printFs(fs);
        
        rep(i, 0, M) {
            string dir;
            while(getline(cin, dir) && dir.empty());
//            ll num = getCommNum(fs, dir);
//            cout << "Case #" << i+1 << ": " << num << endl;
        }
    }
    
    //    cout << "the sum: " << sum << endl;
    // cout << "the sum: " << sum << endl;
   */

#endif
