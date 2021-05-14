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

// 本番中に作成、WA

int main() {
	int n;
	cin >> n;
	set<int> a, b;
	a.insert(1); b.insert(1);
	bool full = false;
	rep3(i, 2, 5001) {
		if (i == 1663) continue;
		if (i == 3) continue;
		bool prime = true;
		for (int j=2; j*j<=i; ++j) if (i%j == 0) prime = false;
		if (!prime) continue;
		auto a2 = a;
		for (auto itr=a.begin(); itr!=a.end(); ++itr) {
			int mi = i, ai = *itr;
			while (ai*mi <= 5000) {
				a2.insert(ai*mi);
				mi *= i;
				if ((int)(a2.size()) >= n/2) {
					full = true;
					break;
				}
			}
			if (full) break;
		}
		swap(a2, a);
		if (full) break;
	}
	{
		int asub = (n-1) - (int)(a.size());
		full = false;
		rep3(i, 2, 10000/6) {
			if (i == 1663) continue;
			if (i == 2) continue;
			bool prime = true;
			for (int j=2; j*j<=i; ++j) if (i%j == 0) prime = false;
			if (!prime) continue;
			auto b2 = b;
			for (auto itr=b.begin(); itr!=b.end(); ++itr) {
				int mi = i, bi = *itr;
				while (bi*mi <= 10000/6) {
					b2.insert(bi*mi);
					mi *= i;
					if ((int)(b2.size()) >= asub) {
						full = true;
						break;
					}
				}
				if (full) break;
			}
			swap(b2, b);
			if (full) break;
		}
	}
	vector<int> res;
	res.push_back(6*1663);
	for (auto itr=a.begin(); itr!=a.end(); ++itr) res.push_back(2*(*itr));
	for (auto itr=b.begin(); itr!=b.end(); ++itr) res.push_back(6*(*itr));
	rep(i, n) printf("%d%c", res[i], (i<n-1?' ':'\n'));
	return 0;
}
