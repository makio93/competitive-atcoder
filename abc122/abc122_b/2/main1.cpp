// 復習2回目,解説AC

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const string tar = "ACGT";

int main() {
    string s;
    cin >> s;
    int n = s.length(), res = 0;
    rep(i, n) rep3(j, i, n) {
        if (tar.find(s[j]) == string::npos) break;
        res = max(res, j-i+1);
    }
    cout << res << endl;
    return 0;
}
