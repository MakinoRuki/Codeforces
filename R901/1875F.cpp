#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <ctime>
#include <list>
#include <stack>
#include <bitset>
#define N 300005
#define M 5002
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k;
int t;
int a[N];
vector<int> edges[N];
double p[M][M];
double res[M];
int main() {
  p[0][0]=0;
  for (int i = 1; i < M; ++i) {
    p[i][0]=0;
    p[i][1] = 1;
    for (int j = 2; j <= i; ++j) {
      if (i-2>=0) {
        p[i][j] += p[i-2][j-2]*(double)(j-2);
      }
      if (i-2>=0) {
        p[i][j] += p[i-2][j-1]*(double)(i-j);
      }
    }
    for (int j = 1; j <= i; ++j) {
      p[i][j] /= (double)i;
    }
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
    }
    for (int i = 1; i <= m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
    }
    res[n] = 1;
    for (int i = n-1; i >= 1; --i) {
      vector<double> v;
      v.clear();
      for (int j = 0; j < edges[i].size(); ++j) {
        int u = edges[i][j];
        v.push_back(res[u]);
      }
      sort(v.begin(), v.end());
      reverse(v.begin(), v.end());
      res[i] = 0.0;
      int sz = (int)edges[i].size();
      for (int j = 0; j < edges[i].size(); ++j) {
        res[i] += v[j] * p[sz][j+1];
      }
    }
    printf("%.12lf\n", res[1]);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

