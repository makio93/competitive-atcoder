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
	vector<int> cnt(7);
	rep(i, 3) {
		int ai;
		cin >> ai;
		cnt[ai]++;
	}
	int res = 0;
	bool three = false, two = false;
	rep3(i, 1, 7) {
		if (cnt[i] == 3) {
			three = true;
			res = i;
			break;
		}
		else if (cnt[i] == 2) {
			two = true;
			break;
		}
	}
	if (two) {
		rep3(i, 1, 7) if (cnt[i] == 1) {
			res = i;
			break;
		}
	}
	cout << res << endl;
	return 0;
}
