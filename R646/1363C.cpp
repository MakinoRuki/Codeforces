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
#define N 1002
#define M 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t;
int n, x;
int deg[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; ++i) {
      deg[i] = 0;
    }
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      deg[u]++;
      deg[v]++;
    }
    if (deg[x]<=1) {
      cout<<"Ayush"<<endl;
    } else {
      if ((n-2)%2) cout<<"Ashish"<<endl;
      else cout<<"Ayush"<<endl;
    }
  }
  return 0;
}
