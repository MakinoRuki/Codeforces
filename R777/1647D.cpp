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
#define M 202
#define N 20000
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
vector<pair<int,int>> check(int x) {
  vector<pair<int,int>> res;
  res.clear();
  for (ll i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      int cnt=0;
      while(x % i == 0) {
        cnt++;
        x/=i;
      }
      res.push_back(make_pair(i, cnt));
    }
  }
  if (x > 1) {
    res.push_back(make_pair(x, 1));
  }
  return res;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x,d;
    scanf("%d%d", &x, &d);
  //  x = rand() % 100 + 2;
    //d = rand() % 100 + 2;
   // cout<<x<<" "<<d<<endl;
    if (x < d || (x %d)) {
      puts("NO");
      continue;
    }
    auto v1 = check(d);
    // for (int i = 0; i <v1.size(); ++i) {
    //   cout<<"x="<<v1[i].first<<" "<<v1[i].second<<endl;
    // }
    int y = x;
    int pw = 0;
    while(x % d == 0) {
      x/=d;
      pw++;
    }
  //  cout<<"pw="<<pw<<endl;
    auto v2 = check(x);
    // for (int i = 0; i <v2.size(); ++i) {
    //   cout<<"x2="<<v2[i].first<<" "<<v2[i].second<<endl;
    // }
    if (v1.size() == 1 && v1[0].second == 1) {
      if (pw == 1) {
        puts("NO");
      } else {
        if (x == 1 || (v2.size() == 1 && v2[0].second == 1)) {
          puts("NO");
        } else {
          puts("YES");
        }
      }
    } else {
      if (pw == 1) {
        puts("NO");
      } else if (pw == 2) {
        if (x == 1 || (v2.size() == 1 && v2[0].second == 1)) {
          puts("NO");
        } else {
          puts("YES");
        }
      } else {
        if (v1.size() > 1) {
          puts("YES");
        } else {
          int cnt=0;
          while(y % v1[0].first == 0) {
            cnt++;
            y/=v1[0].first;
          }

          int num=0;
          int n1 = v1[0].second;

          for (int i = 1; i <= 30; ++i) {
            if (n1 * i <= cnt && (n1 + n1-1) * i >= cnt) {
              num++;
            }
          }
          if (num > 1) {
            puts("YES");
          } else {
            if (x == 1 || (v2.size() == 1 && v2[0].second == 1)) {
              puts("NO");
            } else {
              puts("YES");
            }
          }
        }
      }
    }
  }
  return 0;
}
