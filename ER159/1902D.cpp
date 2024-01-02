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
#define N 300005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
map<pair<int,int>, vector<int>> mp;
int px[N], py[N];
int main() {
  cin>>n>>q;
  mp.clear();
  string s;
  cin>>s;
  int x=0,y=0;
  mp[make_pair(0,0)].push_back(0);
  px[0]=0;
  py[0]=0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'U') y++;
    else if (s[i] == 'D') y--;
    else if (s[i] == 'L') x--;
    else x++;
    mp[make_pair(x,y)].push_back(i+1);
    px[i+1]=x;
    py[i+1]=y;
  }
  while(q-->0) {
    int l,r;
    scanf("%d%d%d%d", &x, &y, &l, &r);
    if (mp.find(make_pair(x,y)) != mp.end()) {
      // 此处要用reference，否则是copy！！！
      auto& v = mp[make_pair(x,y)];
      int id = lower_bound(v.begin(), v.end(), l) - v.begin();
      if (id > 0) {
        puts("YES");
        continue;
      }
      id = lower_bound(v.begin(), v.end(), r) - v.begin();
      if (id < v.size()) {
        puts("YES");
        continue;
      }
    }
    int x2 = px[l-1]+px[r]-x;
    int y2 = py[l-1]+py[r]-y;
    if (mp.find(make_pair(x2,y2)) != mp.end()) {
      // 此处要用reference，否则是copy！！！
      auto& v = mp[make_pair(x2,y2)];
      int id = lower_bound(v.begin(), v.end(), l) - v.begin();
      int id2 = lower_bound(v.begin(), v.end(), r) - v.begin()-1;
      if (id <= id2 && id>=0 && id<v.size() && id2>=0 && id2<v.size()) {
        puts("YES");
        continue;
      }
    }
    puts("NO");
  }
  return 0;
}
