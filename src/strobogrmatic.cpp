//
// leet solution c++ strobogrammatic-number-ii
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
    vector<string> findStroboRec(int n, int m)
    {
        vector<string> res;
        if(n == 0) { res.emplace_back(""); return res;}
        if(n == 1) {
            res.emplace_back("0");
            res.emplace_back("1");
            res.emplace_back("8");
            return res;
        }
        res = findStroboRec(n-2, m);
        
        vector<string> new_res;
        
        for (auto &s : res) {
            if (n != m) {
                new_res.emplace_back('0' + s + '0');
            }
            new_res.emplace_back('1' + s + '1');
            new_res.emplace_back('6' + s + '9');
            new_res.emplace_back('8' + s + '8');
            new_res.emplace_back('9' +s + '6');
        }
        
        return new_res;
    }
    vector<string> findStrobogrammatic(int n) {
        vector<string> res;
        res = findStroboRec(n,n);
        return res;
    }
};



int main()
{
    Solution sol;
    vector<string> res = sol.findStrobogrammatic(4);
    for (auto &i : res) {
        cout << i << endl;
    }
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
