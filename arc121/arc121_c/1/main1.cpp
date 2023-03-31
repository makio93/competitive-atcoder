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

const int INF = (int)(1e9);

int main() {
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int n;
        cin >> n;
        vector<int> p(n);
        rep(i, n) {
            cin >> p[i];
            p[i]--;
        }
        vector<int> res;
        if (n >= 3) {
            rep3r(i, 4, n) {
                int id = find(all(p), i) - p.begin();
                if (i == id) continue;
                if ((int)(res.size())%2 != id%2) {
                    int tid = 0;
                    while ((int)(res.size())%2!=tid%2 || tid==id || tid+1==id) ++tid;
                    res.push_back(tid);
                    swap(p[tid], p[tid+1]);
                }
                rep3(j, id, i) {
                    res.push_back(j);
                    swap(p[j], p[j+1]);
                }
            }
            if (n >= 4) {
                int id = find(all(p), 3) - p.begin();
                if (id < 3) {
                    if (id==2 && (int)(res.size())%2!=id%2) {
                        res.push_back(1);
                        swap(p[1], p[2]);
                        --id;
                    }
                    if ((int)(res.size())%2 != id%2) {
                        int tid = 0;
                        while ((int)(res.size())%2!=tid%2 || tid==id || tid+1==id) ++tid;
                        res.push_back(tid);
                        swap(p[tid], p[tid+1]);
                    }
                    rep3(i, id, 3) {
                        res.push_back(i);
                        swap(p[i], p[i+1]);
                    }
                }
            }
            while (p[0]!=0 || p[1]!=1 || p[2]!=2) {
                int tid = (int)(res.size()) % 2;
                res.push_back(tid);
                swap(p[tid], p[tid+1]);
            }
        }
        else {
            if (p[0] != 0) {
                res.push_back(0);
                swap(p[0], p[1]);
            }
        }
        int m = res.size();
        cout << m << endl;
        if (m > 0) rep(i, m) cout << (res[i]+1) << (i<m-1?' ':'\n');
        else cout << endl;
    }
    return 0;
}
