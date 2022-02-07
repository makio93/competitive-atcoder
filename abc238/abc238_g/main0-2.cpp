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

// 終了後,自力解答,WA(RE)

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int amx = 2;
	rep(i, n) amx = max(amx, a[i]);
	vector<bool> vlst(amx*2+1);
	vector<int> plst;
	rep3(i, 2, amx+1) {
		if (vlst[i]) continue;
		plst.push_back(i);
		for (int j=i*2; j<=amx; j+=i) vlst[j] = true;
	}
	int m = plst.size();
	vector<bitset<700>> pcnts(n+1, bitset<700>(0));
	rep(i, n) {
		int aval = a[i];
		rep(j, m) {
			if (aval < plst[j]) break;
			while (aval%plst[j] == 0) {
				int tval = (pcnts[i+1][2*j+1]*2+pcnts[i+1][2*j]+1) % 3UL;
				pcnts[i+1][2*j+1] = tval / 2;
				pcnts[i+1][2*j] = tval % 2;
				aval /= plst[j];
			}
		}
	}
	rep(i, n) rep(j, m) {
		int tval = (pcnts[i+1][2*j+1]*2+pcnts[i+1][2*j]+pcnts[i][2*j+1]*2+pcnts[i][2*j]) % 3UL;
		pcnts[i+1][2*j+1] = tval / 2;
		pcnts[i+1][2*j] = tval % 2;
	}
	rep(i, q) {
		int li, ri;
		cin >> li >> ri;
		--li;
		bool ok = true;
		rep(j, m) if (((pcnts[ri][2*j+1]*2+pcnts[ri][2*j])-(pcnts[li][2*j+1]*2+pcnts[li][2*j])+3UL)%3UL != 0UL) {
			ok = false;
			break;
		}
		if (ok) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
