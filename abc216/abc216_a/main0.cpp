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

int main() {
	string xy;
	cin >> xy;
	int pid = xy.find('.');
	int x = stoi(xy.substr(0, pid)), y = stoi(xy.substr(pid+1));
	string ci;
	if (y>=0 && y<=2) ci = "-";
	else if (y>=7 && y<=9) ci = "+";
	cout << x << ci << endl;
	return 0;
}
