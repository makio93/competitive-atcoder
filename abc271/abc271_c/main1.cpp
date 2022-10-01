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

const int INF = (int)(1e9);

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<bool> exists(n+1);
	int dval = 0;
	rep(i, n) {
		if (a[i]>n || exists[a[i]]) ++dval;
		else exists[a[i]] = true;
	}
	int li = 1, ri = n;
	while (li<=n && exists[li]) ++li;
	while (dval >= 2) {
		exists[li] = true;
		++li;
		while (exists[li]) ++li;
		dval -= 2;
	}
	while (ri>li && !exists[ri]) --ri;
	while (ri > li) {
		exists[ri] = false;
		++dval;
		--ri;
		while (!exists[ri]) --ri;
		if (dval >= 2) {
			exists[li] = true;
			++li;
			while (exists[li]) ++li;
			dval -= 2;
		}
	}
	--li;
	cout << li << endl;
	return 0;
}
