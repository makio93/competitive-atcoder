// 学習2回目,自力AC2

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
    int lval = 0, rval = n + 1;
    while (rval-lval > 1) {
        int cval = rval - (rval-lval) / 2;
        if ((ll)cval*(cval+1)/2 >= (ll)n) rval = cval;
        else lval = cval;
    }
    cout << rval << endl;
    return 0;
}
