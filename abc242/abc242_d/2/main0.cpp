// 復習2回目,自力AC

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
    string s;
    int q;
    cin >> s >> q;
    auto calc = [&](auto calc, ll ti, ll ki) -> char {
        if (ti == 0) return s[ki];
        else if (ki == 0) return (char)('A'+((s[0]-'A')+(ti%3))%3);
        else {
            int rval = calc(calc, ti-1, ki/2) - 'A';
            if (ki%2 == 1) rval = (rval + 2) % 3;
            else rval = (rval + 1) % 3;
            return (char)('A'+rval);
        }
    };
    rep(i, q) {
        ll ti, ki;
        cin >> ti >> ki;
        --ki;
        cout << calc(calc, ti, ki) << endl;
    }
    return 0;
}
