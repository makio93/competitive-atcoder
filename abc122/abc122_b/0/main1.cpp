// 学習0回目,解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const string T = "ACGT";

int main(){
    string s;
    cin >> s;
    int ans = 0, now = 0;
    for (char c : s) {
        bool isT = false;
        for (char c2 : T) {
            if (c == c2) isT = true;
        }
        if (isT) {
            ++now;
            ans = max(now, ans);
        }
        else now = 0;
    }
    cout << ans << endl;
    return 0;
}

