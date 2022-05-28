// 復習1回目,解説AC

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
    int n;
    string s;
    cin >> n >> s;
    vector<int> ccnt(26);
    rep(i, n) ccnt[s[i]-'a']++;
    int ri = n-1;
    rep(i, n) {
        if (ri <= i) break;
        ccnt[s[i]-'a']--;
        int cid = -1;
        rep(j, 26) if (ccnt[j] > 0) {
            cid = j;
            break;
        }
        if (cid == -1) break;
        if (cid >= s[i]-'a') continue;
        while (s[ri] != (char)(cid+'a')) {
            ccnt[s[ri]-'a']--;
            --ri;
        }
        swap(s[i], s[ri]);
        ccnt[cid]--;
        --ri;
    }
    cout << s << endl;
    return 0;
}
