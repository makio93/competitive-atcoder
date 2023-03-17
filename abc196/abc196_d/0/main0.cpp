// 本番AC

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;
#define v(t) vector<t>
#define p(t) pair<t, t>
#define p2(t, s) pair<t, s>
#define vp(t) v(p(t))

#define rep(i, n) for (int i=0,i##_len=((int)(n)); i<i##_len; ++i)
#define rep2(i, a, n) for (int i=((int)(a)),i##_len=((int)(n)); i<=i##_len; ++i)
#define repr(i, n) for (int i=((int)(n)-1); i>=0; --i)
#define rep2r(i, a, n) for (int i=((int)(n)),i##_len=((int)(a)); i>=i##_len; --i)

#define repi(itr, c) for (__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); ++itr)
#define repir(itr, c) for (__typeof((c).rbegin()) itr=(c).rbegin(); itr!=(c).rend(); ++itr)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define eb emplace_back

#define INF (1e9)
#define LINF (1e18)
#define PI (acos(-1))
#define EPS (1e-7)
#define DEPS (1e-10)

int h, w;
v(v(bool)) board;
ll dfs(int y, int x, int k, int a, int b) {
    if (a==1 && b==0) {
        if (k==0) {
            if (y+1>=h) return 0;
            if (!board[y+1][x] && !board[y][x]) return 1;
        }
        else if (k==1) {
            if (x+1<w && !board[y][x+1] && !board[y][x]) return 1;
        }
    }
    else if (a==0 && b==1) {
        if (k==2) {
            if (!board[y][x]) return 1;
        }
    }
    /*
    if (y==h-1 && x==w-1) {
        if (k == 2) {
            if (a==0&&b==1&&!board[y][x]) return 1;
            else return 0;
        }
        else return 0;
    }
    if (y==h-1 && x==w-2) {
        if (k == 2) {
            if (a==0 && b==1 && !board[y][x] && board[y][x+1]) return 1;
        }
        else if (k == 1) {
            if (a==1 && b==0 && !board[y][x] && !board[y][x+1]) return 1;
        }
    }
    */
    ll res = 0;
    int ny = y, nx = x+1;
    if (nx >= w) {
        nx = 0; ny = y+1;
        if (ny >= h) return 0;
    }
    if (k==0) {
        if (a<=0) return 0;
        else if ((y+1>=h) || (board[y][x] || board[y+1][x])) {
            res += dfs(ny, nx, k, a, b);
        }
        else {
            board[y][x] = board[y+1][x] = true;
            rep(i, 3) res += dfs(ny, nx, i, a-1, b);
            board[y][x] = board[y+1][x] = false;
        }
    }
    else if (k==1) {
        if (a<=0) return 0;
        else if ((x+1>=w) || (board[y][x] || board[y][x+1])) {
            res += dfs(ny, nx, k, a, b);
        }
        else {
            board[y][x] = board[y][x+1] = true;
            rep(i, 3) res += dfs(ny, nx, i, a-1, b);
            board[y][x] = board[y][x+1] = false;
        }
    }
    else if (k==2) {
        if (b<=0) return 0;
        else if (board[y][x]) {
            res += dfs(ny, nx, k, a, b);
        }
        else {
            board[y][x] = true;
            rep(i, 3) res += dfs(ny, nx, i, a, b-1);
            board[y][x] = false;
        }
    }
    return res;
}

int main(){
    int a, b;
    cin >> h >> w >> a >> b;
    ll res = 0;
    board = v(v(bool))(h, v(bool)(w));
    rep(i, 3) res += dfs(0, 0, i, a, b);
    cout << res << endl;
    return 0;
}
