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

// 本番AC

const vector<string> tar = { "ABC", "ARC", "AGC", "AHC" };

int main() {
	vector<int> cnt(4);
	rep(i, 3) {
		string si;
		cin >> si;
		rep(j, 4) if (si == tar[j]) {
			cnt[j]++;
			break;
		}
	}
	rep(i, 4) if (cnt[i] == 0) {
		cout << tar[i] << endl;
		break;
	}
	return 0;
}
