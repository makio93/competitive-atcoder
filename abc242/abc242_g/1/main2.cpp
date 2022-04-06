// 復習1,解説2

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

struct query {
    int l, r, id;
    void set(int l_, int r_, int id_){ l = l_, r = r_, id = id_; }
};

int main() {
    int n, q;
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }
    cin >> q;
    vector<query> qlst(q);
    rep(i, q) {
        int l, r;
        cin >> l >> r;
        qlst[i].set(l-1, r, i);
    }
    int blen = (int)(max(1, (int)round(sqrt((double)q))));
    sort(all(qlst), [&](query& a, query& b){
        int alb = a.l / blen, blb = b.l / blen;
        if (alb != blb) return alb < blb;
        else if (alb%2 == 0) return a.r < b.r;
        else return !(a.r < b.r);
    });
    vector<int> cnt(n);
    int val = 0, l = 0, r = 0;
    auto add = [&](int id) -> void {
        cnt[a[id]]++;
        if (cnt[a[id]]%2 == 0) ++val;
    };
    auto rem = [&](int id) -> void {
        if (cnt[a[id]]%2 == 0) --val;
        cnt[a[id]]--;
    };
    auto to_move = [&](int tl, int tr) -> void {
        while (r < tr) add(r), ++r;
        while (l > tl) --l, add(l);
        while (r > tr) --r, rem(r);
        while (l < tl) rem(l), ++l;
    };
    vector<int> res(q);
    rep(i, q) {
        to_move(qlst[i].l, qlst[i].r);
        res[qlst[i].id] = val;
    }
    rep(i, q) cout << res[i] << endl;
    return 0;
}
