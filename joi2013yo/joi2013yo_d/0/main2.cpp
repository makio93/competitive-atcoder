// 学習0回目,解説AC2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main(){
    int d, n;
    cin >> d >> n;
    vector<int> t(d);
    rep(i, d) cin >> t[i];
    vector<int> a(n), b(n), c(n);
    rep(i, n) cin >> a[i] >> b[i] >> c[i];
    vector<int> mi(d), ma(d);
    rep(i, d) {
        int mit = INF, mat = -1;
        rep(j, n) if (t[i]>=a[j] && t[i]<=b[j]) {
             mit = min(mit, c[j]);
             mat = max(mat, c[j]);
        }
        mi[i] = mit; ma[i] = mat;
    }
    int sumi = 0, suma = 0;
    rep(i, d-1) {
        int psumi = sumi, psuma = suma;
        bool cmpi = psuma+abs(ma[i]-mi[i+1]) > psumi+abs(mi[i]-mi[i+1]);
        sumi = (cmpi?psuma+abs(ma[i]-mi[i+1]):psumi+abs(mi[i]-mi[i+1]));
        bool cmpa = psuma+abs(ma[i]-ma[i+1]) > psumi+abs(mi[i]-ma[i+1]);
        suma = (cmpa?psuma+abs(ma[i]-ma[i+1]):psumi+abs(mi[i]-ma[i+1]));
    }
    cout << max(sumi, suma) << endl;
    return 0;
}
