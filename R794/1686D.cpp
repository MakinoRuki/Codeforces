#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int a,b,c,d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    string s;
    cin>>s;
    n = (int)s.size();
    int na=0,nb=0;
    vector<string> v1, v2, v3;
    v1.clear();
    v2.clear();
    v3.clear();
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'A') na++;
      else nb++; 
    }
    if (na != a+c+d || nb != b+c+d) {
      puts("NO");
      continue;
    }
   // cout<<"???"<<endl;
    string tmp;
    tmp.clear();
    int ra = 0, rb = 0;
    for (int i = 0; i < n; ++i) {
      if (i == 0 || s[i] != s[i-1]) {
        tmp.push_back(s[i]);
      } else {
        int sz = (int)tmp.size();
        if (sz == 1) {
          if (tmp[0] == 'A') ra++;
          else rb++;
        } else {
          if (sz % 2) {
            v3.push_back(tmp);
          } else {
            if (tmp[0] =='A') v1.push_back(tmp);
            else v2.push_back(tmp);
          }
        }
        tmp.clear();
        tmp.push_back(s[i]);
      }
    }
    if (!tmp.empty()) {
      int sz = (int)tmp.size();
      if (sz == 1) {
        if (tmp[0] == 'A') ra++;
        else rb++;
      } else {
        if (sz % 2) {
          v3.push_back(tmp);
        } else {
          if (tmp[0] =='A') v1.push_back(tmp);
          else v2.push_back(tmp);
        }
      }
      tmp.clear();
    }
    sort(v1.begin(), v1.end(), [](const string& sa, const string& sb) {
      return sa.size() < sb.size();
    });
    sort(v2.begin(), v2.end(), [](const string& sa, const string& sb) {
      return sa.size() < sb.size();
    });
    sort(v3.begin(), v3.end(), [](const string& sa, const string& sb) {
      return sa.size() < sb.size();
    });
 //   cout<<v1.size()<<" "<<v2.size()<<" "<<v3.size()<<endl;
    int a1 = ra, b1 = rb, ab1 = 0, ba1 = 0;
    if (c >= d) {
      for (int i = 0; i < v1.size(); ++i) {
        int x = (int)v1[i].size();
        if (ab1 + x/2 <= c) {
          ab1 += x/2;
        } else {
          int dt = c-ab1;
          int y = x-dt*2;
          ab1 = c;
          int z = min(d-ba1, max(y-2,0)/2);
          ba1 += z;
          a1 += (y-z*2)/2;
          b1 += (y-z*2)/2;
        }
      }
      for (int i = 0; i < v3.size(); ++i) {
        int x = (int)v3[i].size();
        if (ab1 + x/2 <= c) {
          ab1 += x/2;
          if (v3[i][0] == 'A') a1++;
          else b1++;
        } else {
          int dt = c-ab1;
          int y = x-dt*2;
          ab1 = c;
          int z = min(d-ba1, y/2);
          ba1 += z;
          a1 += (y-z*2)/2;
          b1 += (y-z*2)/2;
          if (v3[i][0] == 'A')a1++;
          else b1++;
        }
      }
      if (ab1 < c) {
        reverse(v2.begin(), v2.end());
      }
      for (int i = 0; i < v2.size(); ++i) {
        int x = (int)v2[i].size();
        int dt = min(c-ab1, (x-2)/2);
        ab1 += dt;
        if (dt > 0) {
          x -= dt * 2 + 2;
          a1++;
          b1++;
          int z = min(d-ba1, x/2);
          ba1 += z;
          a1 += (x-z*2)/2;
          b1 += (x-z*2)/2;
        } else {
          int z = min(d-ba1, x/2);
          ba1 += z;
          a1 += (x-z*2)/2;
          b1 += (x-z*2)/2;
        }
      }
    } else {
      for (int i = 0; i < v2.size(); ++i) {
        int x = (int)v2[i].size();
        if (ba1 + x/2 <= d) {
          ba1 += x/2;
        } else {
          int dt = d-ba1;
          int y = x-dt*2;
          ba1 = d;
          int z = min(c-ab1, max(y-2,0)/2);
          ab1 += z;
          a1 += (y-z*2)/2;
          b1 += (y-z*2)/2;
        }
      }
      for (int i = 0; i < v3.size(); ++i) {
        int x = (int)v3[i].size();
        if (ba1 + x/2 <= d) {
          ba1 += x/2;
          if (v3[i][0] == 'A') a1++;
          else b1++;
        } else {
          int dt = d-ba1;
          int y = x-dt*2;
          ba1 = d;
          int z = min(c-ab1, y/2);
          ab1 += z;
          a1 += (y-z*2)/2;
          b1 += (y-z*2)/2;
          if (v3[i][0] == 'A')a1++;
          else b1++;
        }
      }
      if (ba1 < d) {
        reverse(v1.begin(), v1.end());
      }
      for (int i = 0; i < v1.size(); ++i) {
        int x = (int)v1[i].size();
        int dt = min(d-ba1, (x-2)/2);
        ba1 += dt;
    //    cout<<"i="<<i<<" "<<x<<" "<<dt<<" "<<ba1<<endl;
        if (dt > 0) {
          x -= dt * 2 + 2;
          a1++;
          b1++;
      //    cout<<"i="<<i<<" "<<ba1<<" "<<a1<<" "<<b1<<endl;
          int z = min(c-ab1, x/2);
          ab1 += z;
          a1 += (x-z*2)/2;
          b1 += (x-z*2)/2;
        } else {
          int z = min(c-ab1, x/2);
          ab1 += z;
          a1 += (x-z*2)/2;
          b1 += (x-z*2)/2;
        }
      }
    }
    if (a1 == a && b1 == b && ab1 == c && ba1 == d) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}
