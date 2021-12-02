#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 終了後,自力WA1

int main(){
    int n, q;
    cin >> n >> q;
    vector<string> s(q);
    rep(i, q) cin >> s[i];
    rep(i, q) {
        vector<pair<char, int>> len;
        len.emplace_back(s[i][0], 1);
        rep3(j, 1, n+1) {
            if (s[i][j] == len.back().first) len.back().second++;
            else len.emplace_back(s[i][j], 1);
        }
        int cnt = 0;
        if ((int)(len.size()) > 2) {
            char left = len.front().first;
            rep3(j, 1, len.size()-1) {
                if (len[j+1].first == left) {
                    ++cnt;
                    left = len[j].first;
                }
                else if (j+2 < (int)(len.size())) {
                    if (len[j].first == len[j+2].first) {
                        ++cnt;
                        left = len[j].first;
                    }
                }
            }
            string last = { len[(int)(len.size())-2].first, len.back().first };
            const vector<string> score = { "AC", "BC", "CA", "BA", "CB", "AB" };
            rep(j, (int)(score.size())) if (last == score[j]) cnt += (j+1) / 2;
        }
        else if ((int)(len.size()) == 2) {
            if (len[0].first > len[1].first) cnt = 1;
        }
        cout << cnt << endl;
    }
    return 0;
}
