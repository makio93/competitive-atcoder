#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> xy(m);
    rep(i, m) cin >> xy[i].first >> xy[i].second;
    sort(all(xy));
    set<int> s;
    s.insert(n);
    int l = 0;
    while (l < m) {
        int r = l, xi = xy[l].first;
        while (r < m) {
            if (xi == xy[r].first) ++r;
            else break;
        }
        set<int> a, e;
        rep3(i, l, r) {
            int yi = xy[i].second;
            if ((s.find(yi-1)!=s.end()||s.find(yi+1)!=s.end()) && s.find(yi)==s.end()) a.insert(yi);
            if ((s.find(yi-1)==s.end()&&s.find(yi+1)==s.end()) && s.find(yi)!=s.end()) e.insert(yi);
        }
        for (int ai : a) s.insert(ai);
        for (int ei : e) s.erase(ei);
        l = r;
    }
    cout << (int)(s.size()) << endl;
    return 0;
}
