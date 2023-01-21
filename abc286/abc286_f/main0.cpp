// 自力AC

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
const vector<ll> mlst = { 4, 9, 5, 7, 11, 13, 17, 19, 23 };

int main() {
	int m = (int)accumulate(all(mlst), 0LL), mlen = mlst.size();
	cout << m << endl;
	cout.flush();
	vector<ll> msum(mlen+1);
	rep(i, mlen) msum[i+1] = msum[i] + mlst[i];
	vector<int> a(m);
	iota(all(a), 2);
	int mid = 0;
	rep(i, m-1) {
		if (a[i] == msum[mid+1]) {
			a[i+1] -= mlst[mid];
			++mid;
		}
	}
	rep(i, m) cout << a[i] << (i<m-1?' ':'\n');
	cout.flush();
	vector<int> b(m);
	rep(i, m) cin >> b[i];
	vector<ll> rlst(mlen);
	rep(i, mlen) rlst[i] = b[msum[i]] - (msum[i] + 1);
	auto pvals = crt(rlst, mlst);
	if (pvals.first == 0) pvals.first += pvals.second;
	cout << pvals.first << endl;
	cout.flush();
	return 0;
}
