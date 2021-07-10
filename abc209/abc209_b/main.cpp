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
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		if ((i+1)%2 == 0) a[i]--;
	}
	int sum = 0;
	rep(i, n) sum += a[i];
	if (sum <= x) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
