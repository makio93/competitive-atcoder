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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> p(n, vector<int>(3));
    rep(i, n) rep(j, 3) cin >> p[i][j];
    vector<int> psum(n);
    rep(i, n) psum[i] = accumulate(all(p[i]), 0);
    vector<int> pcnt(901);
    rep(i, n) pcnt[psum[i]]++;
    repr(i, 900) pcnt[i] += pcnt[i+1];
    rep(i, n) {
        if (psum[i]+301>900 || pcnt[psum[i]+300+1]<k) cout << "Yes" << endl;
        else cout << "No" << endl; 
    }
    return 0;
}
