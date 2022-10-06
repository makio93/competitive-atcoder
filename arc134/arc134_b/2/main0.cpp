// 学習2回目,自力AC

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
    int rid = n-1;
    rep(i, n) {
        if (i >= rid) break;
        ccnt[s[i]-'a']--;
        int cid = -1;
        rep(j, s[i]-'a') if (ccnt[j] > 0) {
            cid = j;
            break;
        }
        if (cid == -1) continue;
        while (s[rid]-'a' != cid) {
            ccnt[s[rid]-'a']--;
            --rid;
        }
        ccnt[s[rid]-'a']--;
        swap(s[i], s[rid]);
        --rid;
    }
    cout << s << endl;
    return 0;
}
