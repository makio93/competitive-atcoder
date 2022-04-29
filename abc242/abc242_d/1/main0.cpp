// 復習1,自力AC

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
    cin >> s;
    auto calc = [&](auto calc, ll ti, ll ki) -> char {
        if (ti == 0) return s[(int)ki];
        else if (ki == 0) {
            int id = ((s[0]-'A') + (int)(ti%3)) % 3;
            return (char)('A'+id);
        }
        else {
            char pch = calc(calc, ti-1, ki/2);
            if (ki%2 == 0) pch++;
            else pch += 2;
            if (pch-'A' >= 3) pch -= 3;
            return pch;
        }
    };
    int q;
    cin >> q;
    rep(i, q) {
        ll ti, ki;
        cin >> ti >> ki;
        ki--;
        cout << calc(calc, ti, ki) << endl;
    }
    return 0;
}
