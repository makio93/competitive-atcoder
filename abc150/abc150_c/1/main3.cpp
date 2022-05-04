// 

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

map<vector<int>, int> perm;
void dfs(int t, int d=0, vector<int> v={}, set<int> p={})
{
    if ((int)(v.size()) == t) {
        perm[v] = perm.size();
        return;
    }
    rep3(j, 1, t+1) {
        if (p.find(j)==p.end()) {
            vector<int> pv = v; set<int> pp = p;
            pv.push_back(j);
            pp.insert(j);
            dfs(t, d+1, pv, pp);
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> q[i];
    dfs(n);
    cout << abs(perm[p]-perm[q]) << endl;
    return 0;
}
