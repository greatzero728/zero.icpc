#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using pii = pair<int, int>;
using ppi = pair<pii, int>;

const int NN = 1515151, _mx = 21;

int st[NN], ed[NN];
char s[NN];

ppi pos[NN];
int H[NN], Rank[NN], sa[NN];

int head[NN], nxt[NN];
ppi buf[NN], tbuf[NN];

void b_sort(int n, bool f) {
	int e = 0, N = 0, ed = max(n + 2, 130), i = ed, u, deg;
	while(i--) head[i] = -1;
	while(++i < n) {
		u = (f ? pos[i].x.x : pos[i].x.y) + 1;
		buf[e] = pos[i], nxt[e] = head[u], head[u] = e++;
	}
	for(u = 0; u < ed; u++) {
		for(deg = 0, e = head[u]; ~e; e = nxt[e]) tbuf[deg++] = buf[e];
		while(deg) pos[N++] = tbuf[--deg];
	}
	return;
}

void build_suf(char *s, int n) {
	int i, j = n, cnt, u;
	while(j--) Rank[j] = s[j]; pos[n] = {{-1, -1}, -1};
//	Rank[n] = -1e9;
	Rank[n] = 0;
	while(++j < _mx) {
		i = n, cnt = 0;
		while(i--) pos[i] = {{Rank[i], Rank[min(n, i + (1 << j))]}, i};
//		sort(pos, pos + n);
		b_sort(n, 0), b_sort(n, 1);
		while(++i < n) {
			Rank[pos[i].y] = cnt + 1;
			if(pos[i].x != pos[i + 1].x) cnt++;
		}
		if(cnt == n) break;
	}
	while(i--) sa[Rank[i]] = i;
	return;
}
void Height(char *s, int n) {
	for(int i = 0, j, h = 0; i < n; i++) if(Rank[i] > 1) {
		h = max(0, h - 1), j = sa[Rank[i] - 1];
		while(s[i + h] == s[j + h]) h++;
		H[Rank[i]] = h;
	}
	return;
}

int mn[NN][_mx];
void rmq(int n) {
	int i = 0, j = 0;
	while(i++ < n) mn[i][0] = H[i];
	while(++j < _mx) for(i = 0; i++ < n; ) {
		mn[i][j] = min(mn[i][j - 1], mn[min(n, i + (1 << j - 1))][j - 1]);
	}
	return;
}
int calc_min(int L, int R) {
	int k = 31 - __builtin_clz(R - L + 1);
	return min(mn[L][k], mn[R - (1 << k) + 1][k]);
}

int B[NN], n;

void update(int u) {
	for(; u <= n; u += u & -u) B[u]++;
	return ;
}

int calc(int u) {
	int ans = 0;
	for(; u; u ^= u & -u) ans += B[u];
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif
	
	int q; scanf("%s %d", s, &q);
	n = strlen(s);
	st[0] = 0, ed[0] = n - 1;
	for(int i = 1; i <= q; i++) {
		s[n++] = '$', st[i] = n;
		scanf("%s", s + st[i]);
		n = st[i] + strlen(s + st[i]);
		ed[i] = n - 1;
	}
	
	build_suf(s, n);
	Height(s, n);
	rmq(n);
	
	for(int i = st[0]; i <= ed[0]; i++) update(Rank[i]);
	
	for(int i = 1; i <= q; i++) {
		int rk = Rank[st[i]], len = ed[i] - st[i] + 1;
		
		int st = 0, ed = rk;
		while(ed - st > 1) {
			int md = st + ed >> 1;
			if(md == rk || calc_min(md + 1, rk) >= len) ed = md;
			else st = md;
		}
		int ST = ed;
		
		st = rk, ed = n + 1;
		while(ed - st > 1) {
			int md = st + ed >> 1;
			if(md == rk || calc_min(rk + 1, md) >= len) st = md;
			else ed = md;
		}
		int ED = st;
		
		printf("%d\n", calc(ED) - calc(ST - 1));
	}
	
	return 0;
}
