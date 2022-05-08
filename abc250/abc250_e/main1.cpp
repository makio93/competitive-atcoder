// 解説AC

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

int main() {
    int n, q;
    cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
    vector<int> acnt(n), bcnt(n);
    vector<pair<int, int>> alst, blst;
    unordered_set<int> st;
    rep(i, n) {
        if (st.find(a[i]) == st.end()) alst.emplace_back(i, a[i]);
        st.insert(a[i]);
        acnt[i] = st.size();
    }
    st.clear();
    rep(i, n) {
        if (st.find(b[i]) == st.end()) blst.emplace_back(i, b[i]);
        st.insert(b[i]);
        bcnt[i] = st.size();
    }
    alst.emplace_back(n, -1);
    blst.emplace_back(n, -1);
    int klen = min(alst.size(), blst.size());
    vector<bool> aok(n), bok(n);
    st.clear();
    rep(i, klen-1) {
        if (st.find(alst[i].second) != st.end()) st.erase(alst[i].second);
        else st.insert(alst[i].second);
        if (st.find(blst[i].second) != st.end()) st.erase(blst[i].second);
        else st.insert(blst[i].second);
        bool bval = (st.empty());
        for (int j=alst[i].first; j<alst[i+1].first; ++j) aok[j] = bval;
        for (int j=blst[i].first; j<blst[i+1].first; ++j) bok[j] = bval;
    }
	cin >> q;
    rep(i, q) {
        int xi, yi;
        cin >> xi >> yi;
        --xi; --yi;
        if (acnt[xi]==bcnt[yi] && aok[xi] && bok[yi]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
