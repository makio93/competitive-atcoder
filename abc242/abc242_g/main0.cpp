// 本番WA

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
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<int> acnt(n), sum(n+1);
	rep(i, n) {
		acnt[a[i]-1]++;
		if (acnt[a[i]-1]%2 == 0) {
			sum[i+1] = sum[i] + 1;
		}
	}
	int q;
	cin >> q;
	rep(i, q) {
		int li, ri;
		cin >> li >> ri;
		--li;
		cout << (sum[ri]-sum[li]) << endl;
	}
	return 0;
}
