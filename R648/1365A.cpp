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
#define N 52
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
int t, n, m;
int a[N][N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n>>m;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        scanf("%d", &a[i][j]);
      }
    }
    int r = 0, c = 0;
    for (int i = 1; i <= n; ++i) {
      int cnt=0;
      for (int j = 1; j <= m; ++j) {
        if (a[i][j]) cnt++;
      }
      if (!cnt) r++;
    }
    for (int j = 1; j <= m; ++j) {
      int cnt=0;
      for (int i =1 ; i <= n; ++i) {
        if (a[i][j])cnt++;
      }
      if (!cnt) c++;
    }
    int x = min(r,c);
    if (x%2) {
      cout<<"Ashish"<<endl;
    } else {
      cout<<"Vivek"<<endl;
    }
  }
  return 0;
}
