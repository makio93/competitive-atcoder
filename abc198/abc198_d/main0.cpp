// 本番AC

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

int n;
vector<string> s;
map<char, int> cid;
vector<int> order;
vector<bool> used;
vector<ll> ans;
bool dfs(int d) {
    if (d == n) {
        vector<string> d = s;
        bool ok = true;
        rep(i, 3) {
            if (order[cid[s[i].front()]] == 0) return false;
            rep(j, (int)(s[i].length())) {
                d[i][j] = (char)(order[cid[s[i][j]]] + '0');
            }
        }
        if (ok) {
            if (stoll(d[0])+stoll(d[1]) == stoll(d[2])) {
                rep(i, 3) ans[i] = stoll(d[i]);
                return true;
            }
            else return false;
        }
        return false;
    }
    rep(i, 10) {
        if (used[i]) continue;
        used[i] = true;
        order[d] = i;
        if (dfs(d+1)) return true;
        used[i] = false;
    }
    return false;
}

int main(){
    s = vector<string>(3);
    rep(i, 3) cin >> s[i];
    set<char> ccnt;
    rep(i, 3) rep(j, (int)(s[i].length())) ccnt.insert(s[i][j]);
    if ((int)(ccnt.size()) > 10) {
        cout << "UNSOLVABLE" << endl;
        return 0;
    }
    int id = 0;
    cid = map<char, int>();
    for (auto itr=ccnt.begin(); itr!=ccnt.end(); ++itr) {
        cid[*itr] = id;
        ++id;
    }
    n = (int)(cid.size());
    order = vector<int>(n);
    used = vector<bool>(10);
    ans = vector<ll>(3);
    if (!dfs(0)) cout << "UNSOLVABLE" << endl;
    else {
        rep(i, 3) cout << ans[i] << endl;
    }
    return 0;
}
