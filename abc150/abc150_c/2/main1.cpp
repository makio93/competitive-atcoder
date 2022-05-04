// 学習1,解説AC

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
	vector<int> p(n), q(n);
	rep(i, n) {
		cin >> p[i];
		p[i]--;
	}
	rep(i, n) {
		cin >> q[i];
		q[i]--;
	}
	int a = 1, b = 1;
	vector<int> x(n);
	iota(all(x), 0);
	while (x != p) {
		next_permutation(all(x));
		++a;
	}
	iota(all(x), 0);
	while (x != q) {
		next_permutation(all(x));
		++b;
	}
	cout << abs(a-b) << endl;
	return 0;
}
