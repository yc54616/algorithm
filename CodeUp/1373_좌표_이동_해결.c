#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll C[2500][2500];

void build_combination_table(int n, int p) {
    for(int i = 0; i <= n; i++) {
        C[i][0] = 1;
        for(int j = 1; j <= i; j++) {
			if(p != 0) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
			else C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}

ll solve_math(int n, int m, int k, int p){
	if(n > 0 && m > 0){
		ll total = C[n + m][n];
		ll bad = 2;

		if(k == 1){
			if(n == m) bad += 2;
			else if(n == m + 1 || m == n + 1) bad += 1; 
		}

		if(p == 0) return total - bad;
		else return (total - bad + p * 5) % p;
	}
	else{
		int d = n + m;
		ll total = C[d + 1][2] * 2;

		if(p == 0) return total;
		else return total % p;
	}
}

int tn, tm, tk;
ll path_count;
int v_h[100][100];
int v_v[100][100];
#define OFF 50

void dfs(int x, int y, int dir, int turns, int cur_str, int max_str, int rem){
	if(abs(tn - x) + abs(tm - y) > rem) return;

	if(rem == 0){
		if(x == tn && y == tm){
			int final_max = (cur_str > max_str) ? cur_str : max_str;
			if(turns >= 2){
				if(tk == 0 || (tk == 1 && final_max >= 2)) path_count++;
			}
		}
		return;
	}

	int dx[] = {1, -1, 0, 0};
	int dy[] = {0, 0, 1, -1};
	int next_dir[] = {1, 1, 2, 2};

	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		int *visit_flag;
		if(i == 0) visit_flag = &v_h[x + OFF][y + OFF];
		else if(i == 1) visit_flag = &v_h[x - 1 + OFF][y + OFF];
		else if(i == 2) visit_flag = &v_v[x + OFF][y + OFF];
		else visit_flag = &v_v[x + OFF][y - 1 + OFF];

		if(*visit_flag) continue;

		*visit_flag = 1;

		int n_dir = next_dir[i];
		int n_turns = (dir != 0 && n_dir != dir) ? turns + 1 : turns;
		int n_cur_str = (n_dir == dir) ? cur_str + 1 : 1;
		int n_max_str = (cur_str > max_str) ? cur_str : max_str;

		dfs(nx, ny, n_dir, n_turns, n_cur_str, n_max_str, rem - 1);

		*visit_flag = 0;
	}
}

int main(){
	int n, m, k, p;
	scanf("%d %d %d %d", &n, &m, &k, &p);

	n = abs(n);
	m = abs(m);

	if(n + m > 6){
		build_combination_table(n + m + 5, p);
		ll solve = solve_math(n, m, k, p);
		if(n > 0 && m > 0) printf("%d %lld\n", n + m, solve);
		else printf("%d %lld\n", n + m + 2, solve);
	}
	else{
		tn = n; tm = m; tk = k;
		int dist = n + m;
		
		while (1)
		{
			path_count = 0;
			dfs(0, 0, 0, 0, 0, 0, dist);

			if(path_count > 0){
				printf("%d %lld\n", dist, (p == 0) ? path_count : path_count % p);
				break;
			}

			dist += 2;
		}
		

	}

	return 0;
}
