// 

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
	int h, w;
	cin >> h >> w;
	vector<string> s(h), t(h);
	rep(i, h) cin >> s[i];
	rep(i, h) cin >> t[i];
	vector<string> sw(w, string(h, '.')), tw(w, string(h, '.'));
	rep(i, w) rep(j, h) if (s[j][i] == '#') sw[i][j] = '#';
	rep(i, w) rep(j, h) if (t[j][i] == '#') tw[i][j] = '#';
	sort(all(sw));
	sort(all(tw));
	if (sw == tw) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
