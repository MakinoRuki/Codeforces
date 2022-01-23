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
#define M 500005
#define N 1005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q, p;
int l, r;
int t;
string s;
int a[N][N];
bool vis[N][N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool check(int x, int y, int d) {
  if (x >= 1 && x <= n && y >= 1 && y <= n) {
    int z = x+dx[d];
    int w = y+dy[d];
    if (z >= 1 && z <=n && w >=1 &&w<=n) {
      if (vis[x][y] || vis[z][w]) return false;
      for (int d2 = 0; d2 < 4; ++d2) {
        int x2 = x+dx[d2];
        int y2 = y+dy[d2];
       // if (x==2&&y==2&&d2==3) cout<<"xy="<<x2<<
        if (x2 >= 1 && x2 <= n && y2 >= 1 && y2 <= n && !(x2==z&&y2==w) && vis[x2][y2]) {
          return false;
        }
        int z2 = z+dx[d2];
        int w2 = w+dy[d2];
        if (z2 >= 1 && z2 <= n && w2 >= 1 && w2 <= n && !(z2==x&&w2==y) && vis[z2][w2]) {
          return false;
        }
      }
      return true;
    }
  }
  return false;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        scanf("%d", &a[i][j]);
        vis[i][j] = false;
      //  a[i][j] = rand()%n;
      }
    }
    int res=0;
    int x=1,y=1,z=1,w=2;
    int d=0;
    while(true) {
      res ^= a[x][y] ^ a[z][w];
      vis[x][y]=true;
      vis[z][w]=true;
    //  cout<<x<<" "<<y<<" "<<z<<" "<<w<<endl;
      bool found=false;
      if (check(z+dx[d]*3, w+dy[d]*3, d)) {
        x = z+dx[d]*3;
        y = w+dy[d]*3;
        z = x+dx[d];
        w = y+dy[d];
        found=true;
      } else {
        int d2 = (d+1)%4;
        if (check(z+dx[d]*2+dx[d2], w+dy[d]*2+dy[d2], d2)) {
          x = z+dx[d]*2+dx[d2];
          y = w+dy[d]*2+dy[d2];
          z = x+dx[d2];
          w = y+dy[d2];
          d = d2;
          found=true;
        } else if (check(z+dx[d]+dx[d2]*2, w+dy[d]+dy[d2]*2, d2)) {
          x = z+dx[d]+dx[d2]*2;
          y = w+dy[d]+dy[d2]*2;
          z = x+dx[d2];
          w = y+dy[d2];
          d = d2;
          found=true;
        } else if (check(z+dx[d2]*3, w+dy[d2]*3, d2)) {
          x = z+dx[d2]*3;
          y = w+dy[d2]*3;
          z = x+dx[d2];
          w = y+dy[d2];
          d = d2;
          found=true;
        }
      }
      if (!found) break;
    }
    // for (int i = 1; i <= n; ++i) {
    //   for (int j = 1; j <= n; ++j) {
    //     printf("%d",vis[i][j]);
    //   }
    //   cout<<endl;
    // }
    printf("%d\n", res);
  }
  return 0;
}
