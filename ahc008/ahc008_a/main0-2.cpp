// 本番提出,AC

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

const int TRN = 300;
const int BRD = 30;
int SZ = 10;
const vector<vector<pair<int, int>>> PNT = {
	{ { 1, SZ }, { 1, BRD-SZ-1 }, { BRD-2, SZ }, { BRD-2, BRD-SZ-1 } },
	{ { SZ+1, SZ }, { SZ+1, BRD-SZ-1 }, { BRD-SZ-2, SZ }, { BRD-SZ-2, BRD-SZ-1 } },
	{ { SZ+1, 0 }, { SZ+1, BRD-1 }, { BRD-SZ-2, 0 }, { BRD-SZ-2, BRD-1 } },
	{ { SZ-1, 0 }, { SZ-1, BRD-1 }, { BRD-SZ, 0 }, { BRD-SZ, BRD-1 } },
	{ { SZ-1, SZ-1 }, { SZ-1, BRD-SZ }, { BRD-SZ, SZ-1 }, { BRD-SZ, BRD-SZ } },
	{ { SZ-1, SZ-1 }, { SZ-1, BRD-SZ }, { BRD-SZ, SZ-1 }, { BRD-SZ, BRD-SZ } },
};
const pair<int, int> XLR = { SZ+1, BRD-SZ-2 }, YLR = { SZ+1, BRD-SZ-2 };
const vector<vector<pair<int, int>>> DIF = {
	{ { 1, 0 }, { 1, 0 }, { -1, 0 }, { -1, 0 } },
	{ { 0, -1 }, { 0, 1 }, { 0, -1 }, { 0, 1 } },
	{ { -1, 0 }, { -1, 0 }, { 1, 0 }, { 1, 0 } },
	{ { 0, 1 }, { 0, -1 }, { 0, 1 }, { 0, -1 } },
	{ { 0, 1 }, { 0, -1 }, { 0, 1 }, { 0, -1 } }
};
const vector<vector<int>> MDIR = {
	{ 1, 1, 0, 0 }, { 2, 3, 2, 3 }, { 0, 0, 1, 1 }, { 3, 2, 3, 2 }, { 3, 2, 3, 2 }
};
const vector<vector<int>> BDIR = {
	{ 0, 0, 1, 1 }, { 4, 4, 4, 4 }, { 4, 4, 4, 4 }, { 1, 1, 0, 0 }, { 4, 4, 4, 4 }, { 1, 1, 0, 0 }
};
const string opr0 = "udlr.", opr1 = "UDLR.";
const vector<pair<int, int>> OPDIR = {
	{ { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }, { 0, 0 } }
};

int n, m;
vector<vector<vector<bool>>> pets, humans, prehumans;
vector<vector<bool>> blocks;
vector<int> px, py, hx, hy;
vector<int> st;

bool move_ok(int hid, int tx, int ty) {
	if (tx<0 || tx>=BRD || ty<0 || ty>=BRD) return false;
	if (blocks[tx][ty]) return false;
	return true;
}

void move_human(int hid, int dx, int dy) {
	humans[hid][hx[hid]][hy[hid]] = false;
	hx[hid] += dx, hy[hid] += dy;
	humans[hid][hx[hid]][hy[hid]] = true;
}

void move_pet(int pid, int dx, int dy) {
	pets[pid][px[pid]][py[pid]] = false;
	px[pid] += dx, py[pid] += dy;
	pets[pid][px[pid]][py[pid]] = true;
}

bool block_ok(int hid, int tx, int ty) {
	if (tx<0 || tx>=BRD || ty<0 || ty>=BRD) return false;
	rep(i, n) if (pets[i][tx][ty]) return false;
	rep(i, m) if (humans[i][tx][ty]) return false;
	rep(i, m) if (prehumans[i][tx][ty]) return false;
	const vector<int> dx = { -1, 0, 1, 0 }, dy = { 0, 1, 0, -1 };
	rep(i1, 4) {
		int nx = tx + dx[i1], ny = ty + dy[i1];
		if (nx<0 || nx>=BRD || ny<0 || ny>=BRD) continue;
		rep(i, n) if (pets[i][nx][ny]) return false;
	}
	return true;
}

int main() {
	cin >> n;
	pets = vector<vector<vector<bool>>>(n, vector<vector<bool>>(BRD, vector<bool>(BRD)));
	px = vector<int>(n), py = vector<int>(n);
	vector<int> pt(n);
	rep(i, n) {
		cin >> px[i] >> py[i] >> pt[i];
		px[i]--; py[i]--; pt[i]--;
		pets[i][px[i]][py[i]] = true;
	}
	cin >> m;
	humans = vector<vector<vector<bool>>>(m, vector<vector<bool>>(BRD, vector<bool>(BRD)));
	hx = vector<int>(m), hy = vector<int>(m);
	SZ = m / 5 * 6;
	rep(i, m) {
		cin >> hx[i] >> hy[i];
		hx[i]--; hy[i]--;
		humans[i][hx[i]][hy[i]] = true;
	}
	blocks = vector<vector<bool>>(BRD, vector<bool>(BRD));
	st = vector<int>(m);
	rep(i0, TRN) {
		string res;
		prehumans = humans;
		rep(i1, 4) {
			char opch = '.';
			if (st[i1] < 6) {
				if (hx[i1]==PNT[st[i1]][i1].first && hy[i1]==PNT[st[i1]][i1].second) st[i1]++;
				int tx = 0, ty = 0, bx = 0, by = 0, dx = 0, dy = 0;
				switch (st[i1]) {
				case 0:
					tx = PNT[st[i1]][i1].first, ty = PNT[st[i1]][i1].second;
					if (abs(tx-hx[i1]) != 0) {
						if (tx-hx[i1]>0 && move_ok(i1, hx[i1]+1, hy[i1])) {
							move_human(i1, 1, 0);
							opch = 'D';
						}
						else if (tx-hx[i1]<0 && move_ok(i1, hx[i1]-1, hy[i1])) {
							move_human(i1, -1, 0);
							opch = 'U';
						}
					}
					else if (abs(ty-hy[i1]) != 0) {
						if (ty-hy[i1]>0 && move_ok(i1, hx[i1], hy[i1]+1)) {
							move_human(i1, 0, 1);
							opch = 'R';
						}
						else if (ty-hy[i1]<0 && move_ok(i1, hx[i1], hy[i1]-1)) {
							move_human(i1, 0, -1);
							opch = 'L';
						}
					}
					break;
				case 1:
					bx = hx[i1] + OPDIR[BDIR[st[i1]-1][i1]].first, by = hy[i1] + OPDIR[BDIR[st[i1]-1][i1]].second;
					if (!blocks[bx][by]) {
						if (block_ok(i1, bx, by)) {
							blocks[bx][by] = true;
							opch = opr0[BDIR[st[i1]-1][i1]];
						}
					}
					else {
						int dx = DIF[st[i1]-1][i1].first, dy = DIF[st[i1]-1][i1].second;
						if (move_ok(i1, hx[i1]+dx, hy[i1]+dy)) {
							move_human(i1, dx, dy);
							opch = opr1[MDIR[st[i1]-1][i1]];
						}
					}
					break;
				case 2:
					dx = DIF[st[i1]-1][i1].first, dy = DIF[st[i1]-1][i1].second;
					if (move_ok(i1, hx[i1]+dx, hy[i1]+dy)) {
						move_human(i1, dx, dy);
						opch = opr1[MDIR[st[i1]-1][i1]];
					}
					break;
				case 3:
					dx = DIF[st[i1]-1][i1].first, dy = DIF[st[i1]-1][i1].second;
					if (move_ok(i1, hx[i1]+dx, hy[i1]+dy)) {
						move_human(i1, dx, dy);
						opch = opr1[MDIR[st[i1]-1][i1]];
					}
					break;
				case 4:
					bx = hx[i1] + OPDIR[BDIR[st[i1]-1][i1]].first, by = hy[i1] + OPDIR[BDIR[st[i1]-1][i1]].second;
					if (!blocks[bx][by]) {
						if (block_ok(i1, bx, by)) {
							blocks[bx][by] = true;
							opch = opr0[BDIR[st[i1]-1][i1]];
						}
					}
					else {
						dx = DIF[st[i1]-1][i1].first, dy = DIF[st[i1]-1][i1].second;
						if (move_ok(i1, hx[i1]+dx, hy[i1]+dy)) {
							move_human(i1, dx, dy);
							opch = opr1[MDIR[st[i1]-1][i1]];
						}
					}
					break;
				case 5:
					dx = DIF[st[i1]-1][i1].first, dy = DIF[st[i1]-1][i1].second;
					if (move_ok(i1, hx[i1]+dx, hy[i1]+dy)) {
						move_human(i1, dx, dy);
						opch = opr1[MDIR[st[i1]-1][i1]];
					}
					break;
				default:
					break;
				}
			}
			else {
				int bx = hx[i1] + OPDIR[BDIR[st[i1]-1][i1]].first, by = hy[i1] + OPDIR[BDIR[st[i1]-1][i1]].second;
				if (!blocks[bx][by] && block_ok(i1, bx, by)) {
					blocks[bx][by] = true;
					opch = opr0[BDIR[st[i1]-1][i1]];
				}
			}
			res.push_back(opch);
		}
		rep3(i1, 4, m) {
			char opch = '.';
			if (st[i1] < 6) {
				if (hx[i1] < XLR.first) {
					if (move_ok(i1, hx[i1]+1, hy[i1])) {
						move_human(i1, 1, 0);
						opch = 'D';
					}
				}
				else if (hx[i1] > XLR.second) {
					if (move_ok(i1, hx[i1]-1, hy[i1])) {
						move_human(i1, -1, 0);
						opch = 'U';
					}
				}
				else if (hy[i1] < YLR.first) {
					if (move_ok(i1, hx[i1], hy[i1]+1)) {
						move_human(i1, 0, 1);
						opch = 'R';
					}
				}
				else if (hy[i1] > YLR.first) {
					if (move_ok(i1, hx[i1], hy[i1]-1)) {
						move_human(i1, 0, -1);
						opch = 'L';
					}
				}
				else st[i1] = 6;
			}
			res.push_back(opch);
		}
		cout << res << endl;
		rep(i1, n) {
			string pstr;
			cin >> pstr;
			int plen = pstr.length();
			rep(i, plen) {
				int did = opr1.find(pstr[i]);
				move_pet(i1, OPDIR[did].first, OPDIR[did].second);
			}
		}
	}
	return 0;
}
