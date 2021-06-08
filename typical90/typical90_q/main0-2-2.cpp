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

// ACLなし、AC

template<typename T>
struct BIT {
	int n;
	vector<T> d;
	BIT(int n=0):n(n),d(n+1) {}
	void add(int i, T x=1) {
		for (i++; i <= n; i += i&-i) {
			d[i] += x;
		}
	}
	T sum(int i) {
		T x = 0;
		for (i++; i; i -= i&-i) {
			x += d[i];
		}
		return x;
	}
	T sum(int l, int r) {
		return sum(r-1) - sum(l-1);
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	map<int, vector<int>> rl;
	rep(i, m) {
		int li, ri;
		cin >> li >> ri;
		--li; --ri;
		rl[ri].push_back(li);
	}
	ll res = 0;
	BIT<ll> b(n);
	for (auto itr=rl.rbegin(); itr!=rl.rend(); ++itr) {
		int ri = itr->first; auto la = itr->second;
		rep(i, (int)(la.size())) res += b.sum(la[i]+2, ri+1);
		rep(i, (int)(la.size())) b.add(la[i]+1);
	}
	cout << res << endl;
	return 0;
}
