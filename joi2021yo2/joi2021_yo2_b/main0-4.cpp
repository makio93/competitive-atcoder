#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 終了後,自力WA2

int main(){
    int n, q;
    cin >> n >> q;
    vector<string> s(q);
    rep(i, q) cin >> s[i];
    rep(i, q) {
        vector<pair<char, int>> len;
        len.emplace_back(s[i][0], 1);
        rep3(j, 1, n) {
            if (s[i][j] == len.back().first) len.back().second++;
            else len.emplace_back(s[i][j], 1);
        }
        int cnt = 0;
        while ((int)(len.size()) > 3) {
            vector<pair<char, int>> nlen, nlen2, rlen = len;
            int l = 0, r = len.size()-1, tcnt = 0, tcnt2 = 1;
            while (l < r) {
                if (len[l].first == len[r].first) {
                    nlen.emplace_back(len[l].first, 1);
                    ++l; --r;
                }
                else {
                    nlen.emplace_back(len[r].first, 1);
                    --r;
                    if (r == l) nlen.emplace_back(len[l].first, 1);
                }
                ++tcnt;
            }
            reverse(all(rlen));
            l = 0, r = len.size()-1;
            while (l < r) {
                if (rlen[l].first == rlen[r].first) {
                    nlen2.emplace_back(rlen[l].first, 1);
                    ++l; --r;
                }
                else {
                    nlen2.emplace_back(rlen[r].first, 1);
                    --r;
                    if (r == l) nlen2.emplace_back(rlen[l].first, 1);
                }
                ++tcnt2;
            }
            if (tcnt < tcnt2) {
                cnt += tcnt;
                len = nlen;
            }
            else {
                cnt += tcnt2;
                len = nlen2;
            }
        }
        if ((int)(len.size()) == 3) {
            const vector<string> tar = { "ABC", "BAC", "CBA", "BCA", "CAB", "ACB" };
            string lstr;
            rep(j, 3) lstr += len[j].first;
            rep(j, (int)(tar.size())) if (lstr == tar[j]) cnt += (j+1)/2;
        }
        else if ((int)(len.size()) == 2) {
            if (len[0].first > len[1].first) ++cnt;
        }
        cout << cnt << endl;
    }
    return 0;
}
