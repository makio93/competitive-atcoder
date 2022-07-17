// 終了後,自力0-4,AC

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

int main() {
    int n;
    cin >> n;
    string res;
    vector<int> lvals;
    auto mten = [&]() -> void {
        int len = lvals.size();
        rep(i, len) lvals[i] = lvals[i] * 10 % 7;
    };
    auto madd = [&]() -> int {
        vector<bool> check(7, true);
        int len = lvals.size();
        repr(i, len) rep3(j, 1, 7) if ((lvals[i]*10+j)%7 == 0) check[j] = false;
        int sval = 0;
        rep3(i, 1, 7) if (check[i]) {
            sval = i;
            break;
        }
        repr(i, len) lvals[i] = (lvals[i] * 10 + sval) % 7;
        lvals.push_back(sval);
        return sval;
    };
    while (n) {
        int cnt = 1;
        while (n-cnt >= 0) {
            res.push_back('7');
            n -= cnt;
            ++cnt;
            mten();
        }
        if (n > 0) {
            int sval = madd();
            res.push_back((char)('0'+sval));
        }
    }
    cout << res << endl;
    return 0;
}
