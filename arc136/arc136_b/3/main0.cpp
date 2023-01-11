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

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }
    rep(i, n) {
        cin >> b[i];
        b[i]--;
    }
    int mval = max(*max_element(all(a)), *max_element(all(b)));
    vector<int> acnt(mval+1), bcnt(mval+1);
    rep(i, n) acnt[a[i]]++;
    rep(i, n) bcnt[b[i]]++;
    bool ok = true, same = false;
    rep(i, mval+1) {
        if (acnt[i] != bcnt[i]) {
            ok = false;
            break;
        }
        if (acnt[i] >= 2) same = true;
    }
    if (!ok) {
        cout << "No" << endl;
        return 0;
    }
    if (same) {
        cout << "Yes" << endl;
        return 0;
    }
    int arev = 0, brev = 0;
    rep(i, n) rep3(j, i+1, n) if (a[j] < a[i]) ++arev;
    rep(i, n) rep3(j, i+1, n) if (b[j] < b[i]) ++brev;
    if (arev%2 == brev%2) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
