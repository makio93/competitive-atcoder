// 

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main(){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> l(q), r(q);
    rep(i, q) cin >> l[i] >> r[i];
    vector<int> sum(n+1);
    rep3(i, 1, n) {
        if (s[i-1]=='A' && s[i]=='C') sum[i+1] = sum[i] + 1;
        else sum[i+1] = sum[i];
    }
    rep(i, q) {
        cout << (sum[r[i]]-sum[l[i]]) << endl;
    }
    return 0;
}
