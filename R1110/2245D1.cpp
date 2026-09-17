
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#define N 1005
using namespace std;
typedef long long ll;

int n, m;
int t;
int h[N][N];
int col[N];
int deg[N];
int ans[N];
vector<int> g[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i) {
      g[i].clear();
      deg[i] = 0;
    }

    for (int k = 1; k <= m; ++k) {
      int o, i, j;
      scanf("%d%d%d", &o, &i, &j);
      h[i][j] = o;
    }

    for (int i = 1; i <= n; ++i) {
      col[i] = h[i][i];
    }

    int ok = 1;

    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        if (col[i] == col[j]) {
          if (h[i][j] != col[i]) {
            ok = 0;
          }
        } else {
          int b = (col[i] == 1 ? i : j);
          int w = (col[i] == 2 ? i : j);

          if (h[i][j] == 1) {
            g[w].push_back(b);
            ++deg[b];
          } else {
            g[b].push_back(w);
            ++deg[w];
          }
        }
      }
    }

    queue<int> q;

    for (int i = 1; i <= n; ++i) {
      if (deg[i] == 0) {
        q.push(i);
      }
    }

    int cnt = 0;

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      ans[u] = ++cnt;

      if (col[u] == 2) {
        ans[u] = -ans[u];
      }

      for (int v : g[u]) {
        --deg[v];

        if (deg[v] == 0) {
          q.push(v);
        }
      }
    }

    if (!ok || cnt != n) {
      printf("NO\n");
    } else {
      printf("YES\n");

      for (int i = 1; i <= n; ++i) {
        printf("%d%c", ans[i], " \n"[i == n]);
      }
    }
  }

  return 0;
}
