#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

// ----------------------------------------
// [파트 1] 큰 좌표용: 수학 공식 (조합)
// ----------------------------------------
ll C[2500][2500];

void build_combination(int n, int p) {
    // p=0일 때를 대비해 충분히 큰 소수로 모듈러 연산 방지 (혹은 그냥 계산)
    // 문제 특성상 p=0이면 long long 범위 내 답일 확률이 높음
    ll mod = (p == 0) ? 0 : p; 
    
    for (int i = 0; i <= n; i++) {
        C[i][0] = 1;
        if (p != 0) C[i][0] %= p;
        for (int j = 1; j <= i; j++) {
            if (p == 0) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            else C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
        }
    }
}

ll solve_math(int n, int m, int k, int p) {
    // 1. 직사각형 (n, m 모두 0 아님) -> 최단거리 n+m
    if (n > 0 && m > 0) {
        ll total = C[n + m][n];
        ll bad = 2; // 'ㄴ'자, 'ㄱ'자 (회전 1회)

        if (k == 1) { // 지그재그 제외
            if (n == m) bad += 2;
            else if (n == m + 1 || m == n + 1) bad += 1;
        }
        
        if (p == 0) return total - bad;
        else return (total - bad + p * 5) % p; // 음수 방지
    }
    
    // 2. 축 위 이동 (n=0 또는 m=0) -> 최단거리 n+m+2
    else {
        int d = n + m; // 직선 거리
        // d+1개 점 중 2개 선택 * 2방향
        ll total = C[d + 1][2] * 2; 
        
        // d > 3 이상이면 우회 시 무조건 직진 구간 발생하므로 뺄 것 없음
        if (p == 0) return total;
        else return total % p;
    }
}

// ----------------------------------------
// [파트 2] 작은 좌표용: DFS (직접 탐색)
// ----------------------------------------
int tn, tm, tk;
ll path_count;
int v_h[100][100]; // 가로 간선 방문
int v_v[100][100]; // 세로 간선 방문
// 좌표 오프셋 (음수 인덱스 방지)
#define OFF 50 

// x, y: 현재좌표, dir: 0시작/1가로/2세로
// turns: 꺾은횟수, max_str: 최대직진, cur_str: 현재직진, rem: 남은거리
void dfs(int x, int y, int dir, int turns, int max_str, int cur_str, int rem) {
    // 가지치기: 남은 거리로 도착 불가능하면 중단
    if (abs(tn - x) + abs(tm - y) > rem) return;

    // 도착
    if (rem == 0) {
        if (x == tn && y == tm) {
            int final_max = (cur_str > max_str) ? cur_str : max_str;
            // 조건: 회전 2회 이상, (k=1이면 최대직진 2이상)
            if (turns >= 2) {
                if (tk == 0 || (tk == 1 && final_max >= 2)) {
                    path_count++;
                }
            }
        }
        return;
    }

    // 4방향 탐색
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    int next_dir[] = {1, 1, 2, 2}; // 1:가로, 2:세로

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        // 간선 중복 방문 체크
        // i=0(우): (x,y)-(x+1,y) -> v_h[x][y]
        // i=1(좌): (x-1,y)-(x,y) -> v_h[x-1][y]
        // i=2(상): (x,y)-(x,y+1) -> v_v[x][y]
        // i=3(하): (x,y-1)-(x,y) -> v_v[x][y-1]
        
        int *visit_flag;
        if (i == 0) visit_flag = &v_h[x + OFF][y + OFF];
        else if (i == 1) visit_flag = &v_h[x - 1 + OFF][y + OFF];
        else if (i == 2) visit_flag = &v_v[x + OFF][y + OFF];
        else visit_flag = &v_v[x + OFF][y - 1 + OFF];

        if (*visit_flag) continue;

        *visit_flag = 1;
        
        int nd = next_dir[i];
        int n_turns = (dir != 0 && dir != nd) ? turns + 1 : turns;
        int n_cur_str = (dir == nd) ? cur_str + 1 : 1;
        int n_max_str = (cur_str > max_str) ? cur_str : max_str;
        
        dfs(nx, ny, nd, n_turns, n_max_str, n_cur_str, rem - 1);
        
        *visit_flag = 0;
    }
}

int main() {
    int n, m, k, p;
    if (scanf("%d %d %d %d", &n, &m, &k, &p) != 4) return 0;

    // 계산 편의를 위해 양수로 통일 (대칭성)
    n = abs(n);
    m = abs(m);

    // [전략 선택]
    // 좌표 합이 6 이하면 DFS, 크면 수학 공식
    if (n + m > 6) {
        build_combination(n + m + 5, p);
        if (n > 0 && m > 0) {
            printf("%d %lld\n", n + m, solve_math(n, m, k, p));
        } else {
            printf("%d %lld\n", n + m + 2, solve_math(n, m, k, p));
        }
    } else {
        tn = n; tm = m; tk = k;
        int dist = n + m;
        
        // 답이 나올 때까지 거리를 2씩 늘림 (최대 14 정도면 충분)
        while (1) {
            path_count = 0;
            // 0,0에서 시작
            dfs(0, 0, 0, 0, 0, 0, dist);
            
            if (path_count > 0) {
                printf("%d %lld\n", dist, (p == 0) ? path_count : path_count % p);
                break;
            }
            dist += 2;
        }
    }

    return 0;
}