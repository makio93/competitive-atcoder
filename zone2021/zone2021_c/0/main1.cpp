// 解説を読んでから実装、AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(5));
    rep(i, n) rep(j, 5) cin >> a[i][j];
    auto check = [&](int c) -> bool {
        set<int> st;
        for (auto& ai : a) {
            int sbit = 0;
            for (int& aj : ai) {
                sbit <<= 1;
                sbit |= (aj >= c);
            }
            st.insert(sbit);
        }
        for (int i1 : st) for (int i2 : st) for (int i3 : st) {
            if ((i1|i2|i3) == ((1<<5)-1)) return true;
        }
        return false;
    };
    int l = 0, r = (int)(1e9)+1;
    while (r-l > 1) {
        int c = (l+r) / 2;
        (check(c) ? l : r) = c;
    }
    cout << l << endl;
    return 0;
}
