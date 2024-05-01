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
#define N 200005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
bool vis[3][N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s1,s2;
    cin>>s1>>s2;
    for (int i =1; i <= n; ++i) {
      vis[1][i]=vis[2][i]=false;
    }
    vis[1][1]=true;
    queue<pair<int,int>> q;
    q.push(make_pair(1,1));
    while(!q.empty()) {
      auto pr = q.front();
      q.pop();
      int x=pr.first;
      int y=pr.second;
      vector<pair<int,int>> v;
      v.clear();
      if (x-1>=1) {
        v.push_back(make_pair(x-1, y));
      }
      if (x+1<=2) {
        v.push_back(make_pair(x+1, y));
      }
      if (y-1>=1) {
        v.push_back(make_pair(x,y-1));
      }
      if (y+1<=n) {
        v.push_back(make_pair(x,y+1));
      }
      for (int i = 0; i < v.size(); ++i) {
        int x=v[i].first;
        int y=v[i].second;
        if (x==1) {
          if (s1[y-1] == '<') {
            y--;
          } else {
            y++;
          }
        } else {
          if (s2[y-1] == '<') {
            y--;
          } else {
            y++;
          }
        }
        if (!vis[x][y]) {
          vis[x][y]=true;
          q.push(make_pair(x,y));
        }
      }
    }
    if (vis[2][n]) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}
