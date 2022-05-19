// 本番,TLE

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
    vector<int> hi(m), wi(m);
    vector<vector<int>> htow(h);
    rep(i, m) {
        cin >> hi[i] >> wi[i];
        hi[i]--; wi[i]--;
        htow[hi[i]].push_back(wi[i]);
    }
    vector<int> cnt(w);
    rep(i, m) cnt[wi[i]]++;
    pair<int, int> mwi = {0, -1};
    rep(i, w) mwi = max(mwi, {cnt[i], i});
    vector<int> wm;
    rep(i, w) if (cnt[i]==mwi.first) wm.push_back(i);
    vector<int> hcnt(h);
    rep(i, m) hcnt[hi[i]]++;
    int hmx = 0;
    rep(i, h) hmx = max(hmx, hcnt[i]);
    int ans = hmx + mwi.first -1;
    rep(i, h) {
        if (hcnt[i] == hmx) {
            rep(j, (int)(wm.size())) {
                if (find(all(htow[i]), wm[j])==htow[i].end()) {
                    ans = max(ans, hmx + mwi.first);
                    cout << ans << endl;
                    return 0;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
