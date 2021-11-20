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

// 本番AC

const int N = (1<<20);

int main() {
	int q;
	cin >> q;
	set<int> holes;
	map<int, ll> avals;
	rep(i, N) holes.insert(i);
	rep(i, q) {
		int ti; ll xi;
		cin >> ti >> xi;
		if (ti == 1) {
			int h = (int)(xi % N);
			auto itr = holes.lower_bound(h);
			if (itr == holes.end()) itr = holes.begin();
			avals[*itr] = xi;
			holes.erase(itr);
		}
		else {
			int h = (int)(xi % N);
			if (avals.find(h) != avals.end()) cout << avals[h] << endl;
			else cout << -1 << endl;
		}
	}
	return 0;
}
