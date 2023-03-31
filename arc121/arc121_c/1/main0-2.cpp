// 学習1回目,ヒント有,自力AC

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
                res.push_back(0);
                swap(p[0], p[1]);
            }
        }
        else {
            rep(i, n-3) {
                int id = i-1;
                while (id+1<n && p[id+1]!=i) ++id;
                if (id < i) continue;
                if ((int)(res.size())%2 != id%2) {
                    int tid = -1;
                    rep3(j, i, n-1) if (j%2 == (int)(res.size())%2) {
                        if (p[j]==i || p[j+1]==i) continue;
                        tid = j;
                        break;
                    }
                    if (tid == -1) {
                        res.push_back(id+1);
                        swap(p[id+1], p[id+2]);
                        res.push_back(i);
                        swap(p[i], p[i+1]);
                        ++id;
                    }
                    else {
                        res.push_back(tid);
                        swap(p[tid], p[tid+1]);
                    }
                }
                rep3r(j, i, id+1) {
                    res.push_back(j);
                    swap(p[j], p[j+1]);
                }
            }
            if (p[n-3]==n-3 && (int)(res.size())%2!=(n-2)%2 && p[n-2]!=n-2) {
                res.push_back(n-3);
                swap(p[n-3], p[n-2]);
            }
            if (p[n-2] == n-3) {
                if ((int)(res.size())%2 != (n-3)%2) {
                    res.push_back(n-2);
                    swap(p[n-2], p[n-1]);
                    res.push_back(n-3);
                    swap(p[n-3], p[n-2]);
                }
                else {
                    res.push_back(n-3);
                    swap(p[n-3], p[n-2]);
                }
            }
            if (p[n-1] == n-3) {
                if ((int)(res.size())%2 != (n-2)%2) {
                    res.push_back(n-3);
                    swap(p[n-3], p[n-2]);
                }
                res.push_back(n-2);
                swap(p[n-2], p[n-1]);
                res.push_back(n-3);
                swap(p[n-3], p[n-2]);
            }
            if (p[n-2] != n-2) {
                res.push_back(n-2);
                swap(p[n-2], p[n-1]);
            }
        }
        int m = res.size();
        cout << m << endl;
        if (m > 0) rep(i, m) cout << (res[i]+1) << (i<m-1?' ':'\n');
        else cout << endl;
    }
    return 0;
}
