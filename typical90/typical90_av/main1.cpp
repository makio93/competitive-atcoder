#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
    vector<int> ab;
    rep(i, n) ab.push_back(b[i]);
    rep(i, n) ab.push_back(a[i]-b[i]);
    sort(ab.rbegin(), ab.rend());
    ll res = 0;
    rep(i, k) res += ab[i];
    cout << res << endl;
    return 0;
}
