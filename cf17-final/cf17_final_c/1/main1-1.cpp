// 学習1回目,解説AC1

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
    int n;
    cin >> n;
    vector<int> d(n);
    rep(i, n) cin >> d[i];
    vector<int> dcnt(13);
    dcnt[0]++;
    rep(i, n) dcnt[d[i]]++;
    if (dcnt[0]>=2 || dcnt[12]>=2 || *max_element(dcnt.begin()+1,dcnt.begin()+12)>=3) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> bids, dids;
    rep3(i, 1, 12) {
        if (dcnt[i] == 1) bids.push_back(i);
        else if (dcnt[i] == 2) dids.push_back(i);
    }
    int m = bids.size(), res = 0;
    rep(i, 1<<m) {
        vector<int> lst;
        lst.push_back(0);
        lst.push_back(24);
        if (dcnt[12] == 1) lst.push_back(12);
        for (const int& id : dids) {
            lst.push_back(id);
            lst.push_back(24-id);
        }
        rep(j, m) {
            if (i&(1<<j)) lst.push_back(24-bids[j]);
            else lst.push_back(bids[j]);
        }
        sort(all(lst));
        int mval = INF, len = lst.size();
        rep(j, len-1) mval = min(mval, lst[j+1]-lst[j]);
        res = max(res, mval);
    }
    cout << res << endl;
    return 0;
}
