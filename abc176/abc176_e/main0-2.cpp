// 終了後,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main(){
    int h, w, m;
    cin >> h >> w >> m;
    map<pair<int, int>, bool> bomb;
    vector<int> hcnt(h), wcnt(w);
    rep(i, m) {
        int hi, wi;
        cin >> hi >> wi;
        --hi; --wi;
        bomb[{hi, wi}] = true;
        hcnt[hi]++;
        wcnt[wi]++;
    }
    int hmx = 0, wmx = 0;
    vector<int> hlis, wlis;
    rep(i, h) hmx = max(hmx, hcnt[i]);
    rep(i, h) if (hcnt[i] == hmx) hlis.push_back(i);
    rep(i, w) wmx = max(wmx, wcnt[i]);
    rep(i, w) if (wcnt[i] == wmx) wlis.push_back(i);
    bool exist = true;
    int cnt = 0;
    rep(i, (int)(hlis.size())) rep(j, (int)(wlis.size())) {
        if (!bomb[{hlis[i], wlis[j]}]) exist = false;
        if (cnt > 3e5) {
            cout << (hmx+wmx) << endl;
            return 0;
        }
        ++cnt;
    }
    if (exist) cout << (hmx+wmx-1) << endl;
    else cout << (hmx+wmx) << endl;
    return 0;
}
