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
	int lg = 0, tmp = 1;
	while (tmp*2 <= n) {
		++lg;
		tmp *= 2;
	}
	int m = n * (lg + 1);
	cout << m << endl;
	cout.flush();
	vector<int> twos(lg+1);
	rep(i, lg+1) twos[i] = 1 << i;
	map<pair<int, int>, int> ptoid;
	int id = 1;
	rep3(i, 1, n+1) rep(j, lg+1) {
		int li = i, ri = min(n, i+(1<<j)-1);
		cout << li << ' ' << ri << endl;
		cout.flush();
		ptoid[{li, j}] = id;
		++id;
	}
	int q;
	cin >> q;
	rep(i, q) {
		int li, ri;
		cin >> li >> ri;
		int tid = upper_bound(all(twos), ri-li+1) - twos.begin() - 1;
		int ai = ptoid[{li, tid}], bi = ptoid[{ri-(1<<tid)+1, tid}];
		cout << ai << ' ' << bi << endl;
		cout.flush();
	}
	return 0;
}
