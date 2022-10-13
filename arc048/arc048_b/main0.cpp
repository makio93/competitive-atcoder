// バチャ本番AC

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
	vector<int> r(n), h(n);
	rep(i, n) {
		cin >> r[i] >> h[i];
		h[i]--;
	}
	int mval = *max_element(all(r));
	vector<vector<int>> rcnt(mval+1, vector<int>(3));
	rep(i, n) rcnt[r[i]][h[i]]++;
	vector<int> sum(mval+1);
	rep(i, mval) sum[i+1] = sum[i] + accumulate(all(rcnt[i+1]), 0);
	rep(i, n) {
		int win = sum[r[i]-1] + rcnt[r[i]][(h[i]+1)%3], lose = (sum[mval] - sum[r[i]]) + rcnt[r[i]][(h[i]+2)%3], draw = rcnt[r[i]][h[i]] - 1;
		cout << win << ' ' << lose << ' ' << draw << endl;
	}
	return 0;
}
