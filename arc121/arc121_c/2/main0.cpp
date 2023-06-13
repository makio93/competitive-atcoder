// 学習2回目,自力AC

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
        if (n == 2) {
            if (p[0] != 0) {
                res.push_back(1);
                swap(p[0], p[1]);
            }
        }
        else {
            rep3r(i, 4, n) {
                int ti = i;
                rep(j, i) if (p[j] == i) ti = j;
                if (ti == i) continue;
                if (ti%2 != (int)(res.size())%2) {
                    int si = (int)(res.size()) % 2;
                    while (si==ti || si+1==ti) si += 2;
                    res.push_back(si+1);
                    swap(p[si], p[si+1]);
                }
                rep3(j, ti, i) {
                    res.push_back(j+1);
                    swap(p[j], p[j+1]);
                }
            }
            if (n >= 4 && p[3] != 3) {
                if (p[0] == 3) {
                    if ((int)(res.size())%2 == 1) {
                        res.push_back(2);
                        swap(p[1], p[2]);
                    }
                    rep(i, 3) {
                        res.push_back(i+1);
                        swap(p[i], p[i+1]);
                    }
                }
                else if (p[1] == 3) {
                    if ((int)(res.size())%2 == 0) {
                        res.push_back(3);
                        swap(p[2], p[3]);
                    }
                    res.push_back(2);
                    res.push_back(3);
                    swap(p[1], p[2]);
                    swap(p[2], p[3]);
                }
                else if (p[2] == 3) {
                    if ((int)(res.size())%2 == 0) {
                        res.push_back(3);
                        swap(p[2], p[3]);
                    }
                    else {
                        rep(i2, 2) {
                            res.push_back(2);
                            res.push_back(3);
                            swap(p[1], p[2]);
                            swap(p[2], p[3]);
                        }
                    }
                }
            }
            while (n >= 3 && (p[0] != 0 || p[1] != 1 || p[2] != 2)) {
                if ((int)(res.size())%2 == 0) {
                    res.push_back(1);
                    swap(p[0], p[1]);
                }
                else {
                    res.push_back(2);
                    swap(p[1], p[2]);
                }
            }
        }
        int m = res.size();
        cout << m << endl;
        if (m > 0) rep(i, m) cout << res[i] << (i<m-1?' ':'\n');
        else cout << endl;
    }
    return 0;
}
