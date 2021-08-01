#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	int q;
	cin >> q;
	ll bias = 0;
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	rep(i, q) {
		int pi;
		cin >> pi;
		if (pi == 1) {
			int xi;
			cin >> xi;
			pq.push((ll)xi-bias);
		}
		else if (pi == 2) {
			int xi;
			cin >> xi;
			bias += xi;
		}
		else {
			ll pval = pq.top(); pq.pop();
			cout << (pval+bias) << endl;
		}
	}
	return 0;
}
