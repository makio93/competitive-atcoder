// 本番WA

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;
#define v(t) vector<t>
#define p(t) pair<t, t>
#define p2(t, s) pair<t, s>
#define vp(t) v(p(t))

#define rep(i, n) for (int i=0,i##_len=((int)(n)); i<i##_len; ++i)
#define rep2(i, a, n) for (int i=((int)(a)),i##_len=((int)(n)); i<=i##_len; ++i)
#define repr(i, n) for (int i=((int)(n)-1); i>=0; --i)
#define rep2r(i, a, n) for (int i=((int)(n)),i##_len=((int)(a)); i>=i##_len; --i)

#define repi(itr, c) for (__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); ++itr)
#define repir(itr, c) for (__typeof((c).rbegin()) itr=(c).rbegin(); itr!=(c).rend(); ++itr)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define eb emplace_back

#define INF (1e9)
#define LINF (1e18)
#define PI (acos(-1))
#define EPS (1e-7)
#define DEPS (1e-10)

int main(){
    int n;
    cin >> n;
    v(int) vi(n*2);
    rep(i, n*2) cin >> vi[i];
    set<p(int)> vil, vir;
    multiset<pair<int,int>> vall, valr;
    rep(i, n) {
        vil.emplace(i, vi[i]);
        vall.emplace(vi[i], i);
    }
    rep(i, n) {
        vir.emplace(i, vi[2*n-1-i]);
        valr.emplace(vi[2*n-1-i], i);
    }
    ll sum = 0;
    rep(i, n) {
        int li = vil.rbegin()->second, ri = vir.rbegin()->second;
        pair<int,int> lmax = *vall.rbegin(), rmax = *valr.rbegin();
        int choose = -1;
        if (lmax.first-ri > rmax.first-li) choose = 0;
        else if (lmax.first-ri < rmax.first-li) choose = 1;
        else if (ri < li) choose = 0;
        else choose = 1;
        if (choose == 0) {
            sum += lmax.first;
            vil.erase(p(int){lmax.second,lmax.first});
            vall.erase(lmax);
            p(int) rtmp = *vir.rbegin();
            vir.erase(rtmp);
            valr.erase(p(int){rtmp.second,rtmp.first});
        }
        else {
            sum += rmax.first;
            vir.erase(p(int){rmax.second,rmax.first});
            valr.erase(rmax);
            p(int) ltmp = *vil.rbegin();
            vil.erase(ltmp);
            vall.erase(p(int){ltmp.second,ltmp.first});
        }
    }
    cout << sum << endl;
    return 0;
}
