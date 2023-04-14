// 学習3回目,自力AC

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

const int INF = (int)(1e9);

int main() {
    int n;
    cin >> n;
    string s;
    while (n != 0) {
        if (abs(n)%2 == 0) s.push_back('0');
        else {
            --n;
            s.push_back('1');
        }
        n /= -2;
    }
    if (s.empty()) s.push_back('0');
    reverse(all(s));
    cout << s << endl;
    return 0;
}
