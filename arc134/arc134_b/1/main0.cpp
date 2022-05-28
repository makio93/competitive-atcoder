// 復習1回目,自力AC

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

pair<char, int> op(pair<char, int> a, pair<char, int> b) {
    if (a.first != b.first) return (a.first < b.first) ? a : b;
    else return (a.second >= b.second) ? a : b;
}

pair<char, int> e() { return make_pair((char)('z'+1), -1); }

int main() {
    int n;
    string s;
    cin >> n >> s;
    segtree<pair<char, int>, op, e> st(n);
    rep(i, n) st.set(i, make_pair(s[i], i));
    int rid = n-1;
    rep(i, n) {
        if (rid <= i) break;
        auto pi = st.prod(i+1, rid+1);
        if (s[i] <= s[pi.second]) continue;
        swap(s[i], s[pi.second]);
        rid = pi.second - 1;
    }
    cout << s << endl;
    return 0;
}
