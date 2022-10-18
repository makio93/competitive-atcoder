// 学習1回目,自力AC

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

template<typename T>
struct MP {
    int n;
    T t;
    vector<int> a;
    MP() {}
    MP(const T& t): t(t) {
        n = t.size();
        a = vector<int>(n+1);
        a[0] = -1;
        int j = -1;
        for (int i=0; i<n; ++i) {
            while (j!=-1 && t[j]!=t[i]) j = a[j];
            j++;
            a[i+1] = j;
        }
    }
    int operator[](int i) { return a[i]; }
    vector<int> findAll(const T& s) {
        vector<int> res;
        int j = 0;
        for (int i=0; i<(int)(s.size()); ++i) {
            while (j!=-1 && t[j]!=s[i]) j = a[j];
            j++;
            if (j == n) {
                res.push_back(i-j+1);
                j = a[j];
            }
        }
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    vector<pair<int, int>> res;
    if (a==vector<int>(n,a.front()) && b==vector<int>(n,b.front())) rep(i, n) res.emplace_back(i, a.front()^b.front());
    else {
        vector<int> xa(n*2), xb(n);
        rep(i, n*2) xa[i] = a[i%n] ^ a[(i+1)%n];
        rep(i, n) xb[i] = b[i] ^ b[(i+1)%n];
        MP<vector<int>> amp(xb);
        auto mlst = amp.findAll(xa);
        int mlen = mlst.size();
        rep(i, mlen) if (mlst[i] < n) res.emplace_back(mlst[i], a[mlst[i]]^b.front());
        sort(all(res));
    }
    if (res.empty()) cout << endl;
    else for (const auto& pi : res) cout << pi.first << ' ' << pi.second << endl;
    return 0;
}
