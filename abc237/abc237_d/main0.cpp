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

int main() {
	int n;
	string s;
	cin >> n >> s;
	vector<int> tol(n+1, -1), tor(n+1, -1);
	rep(i, n) {
		if (s[i] == 'L') {
			tol[i+1] = tol[i];
			if (tol[i+1] != -1) tor[tol[i+1]] = i+1;
			tol[i] = i+1;
			tor[i+1] = i;
		}
		else {
			tor[i+1] = tor[i];
			if (tor[i+1] != -1) tol[tor[i+1]] = i+1;
			tor[i] = i+1;
			tol[i+1] = i;
		}
	}
	vector<int> a;
	int id = -1;
	rep(i, n+1) if (tol[i] == -1) {
		id = i;
		break;
	}
	rep(i, n+1) {
		a.push_back(id);
		id = tor[id];
	}
	rep(i, n+1) printf("%d%c", a[i], (i<n?' ':'\n'));
	return 0;
}
