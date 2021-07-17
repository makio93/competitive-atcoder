#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC

const vector<string> name = { "Draw", "Takahashi", "Aoki" };

int char_to_int(char c) {
    if (isupper(c)) return (int)(c - 'A');
    else if (islower(c)) return (int)(c - 'a' + 26);
    else return -1;
}

int str_to_int(string str) {
    if ((int)(str.length()) != 3) return -1;
    int res = 0;
    rep(i, 3) {
        res *= 52;
        int cval = char_to_int((char)str[i]);
        if (cval == -1) return -1;
        res += cval;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    int vsum = 1;
    rep(i, 3) vsum *= 52;
    vector<int> deg(vsum), sfrom(n), sto(n);
    vector<vector<int>> rg(vsum);
    rep(i, n) {
        int rfrom = str_to_int(s[i].substr((int)(s[i].length())-3,3)), rto = str_to_int(s[i].substr(0,3));
        rg[rfrom].push_back(rto);
        deg[rto]++;
        sfrom[i] = rto;
        sto[i] = rfrom;
    }
    queue<int> que;
    vector<int> dist(vsum, -1);
    rep(i, vsum) if (deg[i] == 0) {
        que.push(i);
        dist[i] = 0;
    }
    while (!que.empty()) {
        int v = que.front(); que.pop();
        int d = dist[v];
        for (int t : rg[v]) if (dist[t] == -1) {
            deg[t]--;
            if (d == 0) {
                que.push(t);
                dist[t] = 1;
            }
            else if (deg[t] == 0) {
                que.push(t);
                dist[t] = 0;
            }
        }
    }
    vector<int> ans(n);
    rep(i, n) ans[i] = dist[sto[i]] + 1;
    rep(i, n) cout << name[ans[i]] << endl;
    return 0;
}
