#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC

int sdigit(string s) {
    int n = s.length(), res = 0;
    repr(i, n) res = res * 3 + (s[i]-'A');
    return res;
}

int main(){
    int n, q;
    cin >> n >> q;
    unordered_map<int, int> dist;
    queue<int> que;
    rep(ai, n+1) rep(bi, n-ai+1) {
        int ci = n - ai - bi, sval = sdigit(string(ai,'A')+string(bi,'B')+string(ci,'C'));
        dist[sval] = 0;
        que.push(sval);
    }
    while (!que.empty()) {
        int val = que.front(); que.pop();
        int di = dist[val], ndi = di + 1;
        rep3(i, 2, n+1) {
            int lval = 0, pval = 1;
            rep(j, i) {
                lval = lval * 3 + val / pval % 3;
                pval *= 3;
            }
            int nval = val / pval * pval + lval;
            if (dist.find(nval) != dist.end()) continue;
            dist[nval] = ndi;
            que.push(nval);
        }
    }
    vector<string> s(q);
    rep(i, q) cin >> s[i];
    rep(i, q) cout << dist[sdigit(s[i])] << endl;
    return 0;
}
