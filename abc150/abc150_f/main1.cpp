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

struct MP {
	int n;
	vector<int> t, a;
	MP(vector<int>& t_) : t(t_) {
		n = t_.size(); a.resize(t_.size()+1, 0);
		int j = -1;
		a[0] = j;
		rep(i, n) {
			while (j!=-1 && t[i]!=t[j]) j = a[j];
			++j;
			a[i+1] = j;
		}
	}
	vector<int> search(vector<int>& s) {
		int m = s.size();
		vector<int> res;
		int j = 0;
		rep(i, m) {
			while (j!=-1 && s[i]!=t[j]) j = a[j];
			++j;
			if (j == n) {
				res.push_back(i-j+1);
				j = a[j];
			}
		}
		return res;
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	auto f = [&](vector<int>& vec) -> vector<int> {
		vector<int> rvec(n);
		rep(i, n) rvec[i] = vec[i] ^ vec[(i+1)%n];
		return rvec;
	};
	vector<int> xa = f(a), xb = f(b);
	MP mp(xb);
	xa.insert(xa.end(), xa.begin(), xa.end()-1);
	vector<pair<int, int>> res;
	auto rlst = mp.search(xa);
	for (int vi : rlst) {
		int xi = a[vi] ^ b[0];
		res.emplace_back(vi, xi);
	}
	int m = res.size();
	rep(i, m) cout << res[i].first << ' ' << res[i].second << endl;
	return 0;
}
