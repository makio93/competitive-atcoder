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

int calc(string& s, vector<int>& perm, int d=0) {
	if (d == 4) {
		bool ok = true;
		rep(i, 10) {
			if (s[i] == 'o') {
				bool exist = false;
				rep(j, 4) if (perm[j] == i) exist = true;
				if (!exist) ok = false;
			}
			else if (s[i] == 'x') {
				bool exist = false;
				rep(j, 4) if (perm[j] == i) exist = true;
				if (exist) ok = false;
			}
			if (!ok) return 0;
		}
		return 1;
	}
	else {
		int res = 0;
		rep(i, 10) {
			perm[d] = i;
			res += calc(s, perm, d+1);
		}
		perm[d] = -1;
		return res;
	}
}

int main() {
	string s;
	cin >> s;
	vector<int> perm(4, -1);
	int res = calc(s, perm);
	cout << res << endl;
	return 0;
}
