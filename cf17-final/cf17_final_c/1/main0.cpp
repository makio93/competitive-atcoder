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
    vector<int> dlst;
    int am = true;
    rep(i, 13) {
        if (i>=1 && i<=11) {
            if (dcnt[i] == 2) {
                dlst.push_back(i);
                dlst.push_back(24-i);
            }
            else if (dcnt[i] == 1) {
                if (am) dlst.push_back(i);
                else dlst.push_back(24-i);
                am = !am;
            }
        }
        else {
            if (dcnt[i] == 1) dlst.push_back(i);
        }
    }
    dlst.push_back(24);
    sort(all(dlst));
    int res = INF, m = dlst.size();
    rep(i, m-1) res = min(res, dlst[i+1]-dlst[i]);
    cout << res << endl;
    return 0;
}
