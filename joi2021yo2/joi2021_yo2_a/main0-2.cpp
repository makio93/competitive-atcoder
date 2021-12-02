#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

int main(){
    int n, a;
    cin >> n >> a;
    string s;
    cin >> s;
    vector<int> llst, rlst;
    rep(i, n) if (s[i] == '#') {
        if (i+1 < a) llst.push_back(i+1);
        else rlst.push_back(i+1);
    }
    bool right = true;
    if (llst.size() >= rlst.size()) {
        int num = llst.size() - rlst.size();
        rep(i, num) rlst.push_back(n+1);
        right = false;
    }
    else {
        int num = rlst.size() - llst.size() - 1;
        rep(i, num) llst.push_back(0);
    }
    sort(all(rlst));
    sort(llst.rbegin(), llst.rend());
    ll ans = 0;
    rep(i, (int)(rlst.size())) ans += abs(a - rlst[i]) * 2;
    rep(i, (int)(llst.size())) ans += abs(a - llst[i]) * 2;
    if (right) ans -= abs(a - rlst.back());
    else ans -= abs(a - llst.back());
    cout << ans << endl;
    return 0;
}
