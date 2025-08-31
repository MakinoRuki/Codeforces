int dfn[N];
int low[N];
int ts;
int stk[N];
vector<vector<int>> cs;
int cnt;
int top;
int id[N];
void tarjan(int u, int p) {
  dfn[u] = low[u] = ++ ts;
  stk[++ top] = u;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    if (!dfn[v]) {
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
    }
    else low[u] = min(low[u], dfn[v]);
  }
  
  if (low[u] == dfn[u]) {
    int temp = 0;
    cnt ++, cs.push_back(vector<int>());
    do { 
      temp = stk[top --];
      id[temp] = cnt;
      cs.back().push_back(temp);
    } while (temp != u);
  }
}
for (int i= 1; i <= n; ++i) {
  col[i]=-1;
  dfn[i] = low[i]=0;
}
ts=0;
cnt=0;top=-1;
cs.clear();
tarjan(1, 0);
