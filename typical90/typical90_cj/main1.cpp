#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC

int n;
vector<int> a;
vector<vector<int>> g;
unordered_map<int, vector<vector<int>>> res;
vector<int> qcnt;
vector<vector<int>> ans;

int calc(vector<int>& lst) {
    int sum = 0;
    for (int id : lst) sum += a[id];
    return sum;
}

bool add(vector<int>& lst, int val) {
    res[val].push_back(lst);
    if ((int)(res[val].size()) >= 2) {
        ans = res[val];
        return true;
    }
    return false;
}

bool dfs(vector<int>& lst, int v=0) {
    if (v == n) { return add(lst, calc(lst)); }
    if (dfs(lst, v+1)) return true;
    if (qcnt[v] == 0) {
        lst.push_back(v);
        for (int t : g[v]) qcnt[t]++;
        if (dfs(lst, v+1)) return true;
        for (int t : g[v]) qcnt[t]--;
        lst.pop_back();
    }
    return false;
}

int main() {
    int q;
    cin >> n >> q;
    a = vector<int>(n);
    rep(i, n) cin >> a[i];
    g = vector<vector<int>>(n);
    rep(i, q) {
        int xi, yi;
        cin >> xi >> yi;
        --xi; --yi;
        g[xi].push_back(yi);
    }
    qcnt = vector<int>(n);
    vector<int> lst;
    dfs(lst);
    rep(i, 2) {
        int len = ans[i].size();
        cout << len << endl;
        rep(j, len) printf("%d%c", ans[i][j]+1, (j<len-1?' ':'\n'));
    }
    return 0;
}
