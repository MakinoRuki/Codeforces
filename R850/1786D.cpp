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
#define N 300005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
vector<int> ids[3][3];
void solve(int x, int y, int dt, vector<pair<int,int>>& res) {
  for (int i = 1; i <= dt; ++i) {
    int z = ids[x][y].back();
    ids[x][y].pop_back();
    res.push_back(make_pair(z, x));
    z = ids[y][x].back();
    ids[y][x].pop_back();
    res.push_back(make_pair(z, y));
  }
}
void solve2(int x, int y, vector<pair<int,int>>& res) {
  while(!ids[x][y].empty()) {
    int z = 3-x-y;
    if (ids[y][z].empty() || ids[z][x].empty()) {
      break;
    }
    int id1=ids[x][y].back();
    ids[x][y].pop_back();
    int id2=ids[y][z].back();
    ids[y][z].pop_back();
    int id3=ids[z][x].back();
    ids[z][x].pop_back();
    res.push_back(make_pair(id1, x));
    res.push_back(make_pair(id2, y));
    res.push_back(make_pair(id2, x));
    res.push_back(make_pair(id3, z));
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int n01=0,n02=0;
    int n10=0,n12=0;
    int n20=0,n21=0;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        ids[i][j].clear();
      }
    }
    for (int i = 1; i <= n; ++i) {
      string s;
      cin>>s;
      if (s[0] == s[1] && s[0] == s[2]) {
        if (s[0] == 'w') {
          n01++;
          n02++;
          ids[0][1].push_back(i);
          ids[0][2].push_back(i);
        } else if (s[0] == 'i') {
          n10++;
          n12++;
          ids[1][0].push_back(i);
          ids[1][2].push_back(i);
        } else {
          n20++;
          n21++;
          ids[2][0].push_back(i);
          ids[2][1].push_back(i);
        }
      } else if (s[0] != s[1] && s[0] != s[2] && s[1] != s[2]) {
        continue;
      } else {
        int n0=0,n1=0,n2=0;
        for (int j = 0; j < 3; ++j) {
          if (s[j] == 'w') n0++;
          else if (s[j] == 'i') n1++;
          else n2++;
        }
        if (n0 == 2) {
          if (n1==1) {
            n02++;
            ids[0][2].push_back(i);
          } else {
            n01++;
            ids[0][1].push_back(i);
          }
        } else if (n1 == 2) {
          if (n0==1) {
            n12++;
            ids[1][2].push_back(i);
          } else {
            n10++;
            ids[1][0].push_back(i);
          }
        } else {
          if (n0==1) {
            n21++;
            ids[2][1].push_back(i);
          } else {
            n20++;
            ids[2][0].push_back(i);
          }
        }
      }
    }
    ll ans=0LL;
    vector<pair<int,int>> res;
    res.clear();
    int dt=min(n01, n10);
    if (dt > 0) {
      ans += dt;
      n01-=dt;
      n10-=dt;
      solve(0, 1, dt, res);
    }
    dt = min(n02, n20);
    if (dt > 0) {
      ans += dt;
      n02-=dt;
      n20 -= dt;
      solve(0, 2, dt, res);
    }
    dt = min(n12, n21);
    if (dt > 0) {
      ans += dt;
      n12 -= dt;
      n21 -= dt;
      solve(1, 2, dt, res);
    }
    ll tot = n01+n10+n12+n21+n02+n20;
    ans += tot/3 * 2;
    solve2(0,1,res);
    solve2(1,0,res);
    solve2(1,2,res);
    solve2(2,1,res);
    solve2(0,2,res);
    solve2(2,0,res);
    printf("%lld\n" ,ans);
    vector<string> cc={"w", "i", "n"};
    for (int i = 0 ; i< res.size(); i += 2) {
      printf("%d ", res[i].first);
      cout<<cc[res[i].second]<<" ";
      printf("%d ", res[i+1].first);
      cout<<cc[res[i+1].second]<<" ";
      cout<<endl;
    }
  }
  return 0;
}
