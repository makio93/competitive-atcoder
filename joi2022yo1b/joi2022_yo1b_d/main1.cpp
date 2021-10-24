#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
    int ans = a[0];
    rep3(i, 1, n) {
        if (count(all(a), ans) > count(all(a), a[i])) ans = a[i];
        else if (count(all(a), ans) == count(all(a), a[i])) ans = min(ans, a[i]);
    }
    cout << ans << endl;
    return 0;
}
