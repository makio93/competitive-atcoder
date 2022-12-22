// 学習1回目,解説AC

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
    vector<int> a(n*2);
    rep(i, n*2) cin >> a[i];
    vector<pair<int, int>> aids(2*n);
    rep(i, n*2) aids[i] = { a[i], i };
    sort(all(aids));
    vector<bool> cols(2*n);
    rep(i, n*2) if (i < n) cols[aids[i].second] = true;
    string res(2*n, '(');
    stack<int> st;
    rep(i, n*2) {
        if (!st.empty() && cols[st.top()]!=cols[i]) {
            res[i] = ')';
            st.pop();
        }
        else st.push(i);
    }
    cout << res << endl;
    return 0;
}
