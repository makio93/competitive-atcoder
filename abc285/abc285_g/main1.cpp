// 解説AC

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
    int h, w;
    cin >> h >> w;
    vector<string> c(h);
    rep(i, h) cin >> c[i];
    set<tuple<int, int, int>> eids;
    mf_graph<int> g(h*w+4);
    rep(i, h) rep(j, w) {
        if (c[i][j] == '1') continue;
        if (c[i][j] != '2') {
            if ((i+j)%2 == 0) {
                g.add_edge(h*w, i*w+j, 1);
                eids.emplace(h*w, i*w+j, eids.size());
            }
            else {
                g.add_edge(i*w+j, h*w+1, 1);
                eids.emplace(i*w+j, h*w+1, eids.size());
            }
        }
        else {
            if ((i+j)%2 == 0) {
                g.add_edge(h*w+2, i*w+j, 1);
                eids.emplace(h*w+2, i*w+j, eids.size());
                g.add_edge(h*w, h*w+3, 1);
                eids.emplace(h*w, h*w+3, eids.size());
            }
            else {
                g.add_edge(h*w+2, h*w+1, 1);
                eids.emplace(h*w+2, h*w+1, eids.size());
                g.add_edge(i*w+j, h*w+3, 1);
                eids.emplace(i*w+j, h*w+3, eids.size());
            }
        }
        if (i+1 < h && c[i+1][j] != '1') {
            int ui = i * w + j, di = (i+1) * w + j;
            if ((i+j)%2 != 0) swap(ui, di);
            g.add_edge(ui, di, 1);
            eids.emplace(ui, di, eids.size());
        }
        if (j+1 < w && c[i][j+1] != '1') {
            int li = i * w + j, ri = i * w + j + 1;
            if ((i+j)%2 != 0) swap(li, ri);
            g.add_edge(li, ri, 1);
            eids.emplace(li, ri, eids.size());
        }
    }
    g.add_edge(h*w+1, h*w, INF);
    eids.emplace(h*w+1, h*w, eids.size());
    g.flow(h*w+2, h*w+3);
    bool ok = true;
    for (const auto& [fr, to, id] : eids) if ((fr >= h*w+2 || to >= h*w+2) && g.get_edge(id).flow < 1) ok = false;
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
