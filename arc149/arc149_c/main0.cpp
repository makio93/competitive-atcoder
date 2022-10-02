// 本番AC

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

bool is_prime(int val) {
	if (val <= 3) return true;
	for (int i=2; i<val; ++i) if (val%i == 0) return false;
	return true;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> res(n, vector<int>(n));
	if (n == 3) {
		vector<int> ord(9);
		iota(all(ord), 1);
		do {
			rep(i, 9) res[i/3][i%3] = ord[i];
			bool ok = true;
			rep(i, 3) {
				rep(j, 3) {
					if (i+1 < 3) if (is_prime(res[i][j]+res[i+1][j])) ok = false;
					if (j+1 < 3) if (is_prime(res[i][j]+res[i][j+1])) ok = false;
					if (!ok) break;
				}
				if (!ok) break;
			}
			if (ok) break;
		} while (next_permutation(all(ord)));
		rep(i, 3) rep(j, 3) cout << res[i][j] << (j<2?' ':'\n');
		return 0;
	}
	vector<set<int>> odd(3), even(3);
	rep3(i, 1, n*n+1) {
		if (i%2 == 0) even[i%3].insert(i);
		else odd[i%3].insert(i);
	}
	if (n%2 == 0) {
		int cid = n / 2, ri = 0, id = 0;
		while (ri < n) {
			int tid = (3 - id) % 3;
			if (odd[id].empty() || even[tid].empty()) {
				id = (id + 1) % 3;
				continue;
			}
			res[ri][cid] = *odd[id].rbegin();
			odd[id].erase(res[ri][cid]);
			res[ri][cid-1] = *even[tid].rbegin();
			even[tid].erase(res[ri][cid-1]);
			++ri;
		}
		--cid;
		id = 0;
		rep(i, cid) rep(j, n) {
			while (even[id].empty()) id = (id + 1) % 3;
			res[j][i] = *even[id].rbegin();
			even[id].erase(res[j][i]);
		}
		id = 0;
		rep3(i, cid+2, n) rep(j, n) {
			while (odd[id].empty()) id = (id + 1) % 3;
			res[j][i] = *odd[id].rbegin();
			odd[id].erase(res[j][i]);
		}
	}
	else {
		int cid = n / 2;
		res[cid][cid] = *odd[2].rbegin();
		odd[2].erase(res[cid][cid]);
		res[cid+1][cid+1] = *odd[2].rbegin();
		odd[2].erase(res[cid+1][cid+1]);
		res[cid][cid-1] = *even[1].rbegin();
		even[1].erase(res[cid][cid-1]);
		res[cid+1][cid] = *even[1].rbegin();
		even[1].erase(res[cid+1][cid]);
		int id = 0;
		rep(i, cid) {
			while (odd[id].empty()) id = (id + 1) % 3;
			res[i][cid] = *odd[id].rbegin();
			odd[id].erase(res[i][cid]);
		}
		rep(i, cid) {
			int tid = (3 - (res[i][cid]%3)) % 3;
			res[i][cid-1] = *even[tid].rbegin();
			even[tid].erase(res[i][cid-1]);
		}
		++cid;
		id = 0;
		rep3(i, cid+1, n) {
			while (odd[id].empty()) id = (id + 1) % 3;
			res[i][cid] = *odd[id].rbegin();
			odd[id].erase(res[i][cid]);
		}
		rep3(i, cid+1, n) {
			int tid = (3 - (res[i][cid]%3)) % 3;
			res[i][cid-1] = *even[tid].rbegin();
			even[tid].erase(res[i][cid-1]);
		}
		id = 0;
		rep3(i, cid, n) rep(j, n) if (res[j][i] == 0) {
			while (odd[id].empty()) id = (id + 1) % 3;
			res[j][i] = *odd[id].rbegin();
			odd[id].erase(res[j][i]);
		}
		id = 0;
		--cid;
		rep(i, cid) rep(j, n) if (res[j][i] == 0) {
			while (even[id].empty()) id = (id + 1) % 3;
			res[j][i] = *even[id].rbegin();
			even[id].erase(res[j][i]);
		}
	}
	rep(i, n) rep(j, n) cout << res[i][j] << (j<n-1?' ':'\n');
	return 0;
}
