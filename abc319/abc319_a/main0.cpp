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
map<string, int> rk = {
	{ "tourist", 3858 }, 
	{ "ksun48", 3679 }, 
	{ "Benq", 3658 }, 
	{ "Um_nik", 3648 }, 
	{ "apiad", 3638 }, 
	{ "Stonefeang", 3630 }, 
	{ "ecnerwala", 3613 }, 
	{ "mnbvmar", 3555 }, 
	{ "newbiedmy", 3516 }, 
	{ "semiexp", 3481 }
};

int main() {
	string s;
	cin >> s;
	cout << rk[s] << endl;
	return 0;
}
