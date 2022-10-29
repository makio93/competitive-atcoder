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

int main() {
	vector<string> s(9);
	rep(i, 9) cin >> s[i];
	int res = 0;
	auto is_square = [](int id1, int id2, int id3, int id4) -> bool {
		vector<int> ord(4), ids = { id1, id2, id3, id4 };
		iota(all(ord), 0);
		do {
			int r0 = ids[ord[0]]/9, c0 = ids[ord[0]]%9, r1 = ids[ord[1]]/9, c1 = ids[ord[1]]%9;
			int r2 = ids[ord[2]]/9, c2 = ids[ord[2]]%9, r3 = ids[ord[3]]/9, c3 = ids[ord[3]]%9;
			if (make_pair(r1-r0,c1-c0)!=make_pair(r3-r2,c3-c2) || make_pair(r2-r0,c2-c0)!=make_pair(r3-r1,c3-c1)) continue;
			if ((r1-r0)*(r1-r0)+(c1-c0)*(c1-c0) != (r2-r0)*(r2-r0)+(c2-c0)*(c2-c0)) continue;
			if ((r1-r0)*(r2-r0)+(c1-c0)*(c2-c0) == 0) return true;
		} while (next_permutation(all(ord)));
		return false;
	};
	rep(i1, 81) rep3(i2, i1+1, 81) rep3(i3, i2+1, 81) rep3(i4, i3+1, 81) {
		if (s[i1/9][i1%9]!='#' || s[i2/9][i2%9]!='#' || s[i3/9][i3%9]!='#' || s[i4/9][i4%9]!='#') continue;
		if (is_square(i1, i2, i3, i4)) ++res;
	}
	cout << res << endl;
	return 0;
}
