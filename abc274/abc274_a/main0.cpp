// 自力AC

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
	int a, b;
	cin >> a >> b;
	int val = (b * 10000 / a + 5) / 10;
	string s = string(1, (char)(val/1000+'0')) + ".";
	string bstr = to_string(val%1000);
	bstr = string(3-(int)(bstr.length()), '0') + bstr;
	s += bstr;
	cout << s << endl;
	return 0;
}
