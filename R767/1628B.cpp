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
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q, p;
int l, r;
int t;
string s;
int a[N];
int cnt1[26][26], cnt2[26][26][26];
//int cnt3[26][26][26], cnt4[26][26][26];
vector<string> v;
bool check(string ss) {
  if (ss.size() == 1) return true;
  if (ss.size() == 2 && ss[0] == ss[1]) return true;
  if (ss.size() == 3 && ss[0] == ss[2]) return true;
  return false;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));
   // memset(cnt3, 0, sizeof(cnt1));
   // memset(cnt4, 0, sizeof(cnt1));
    set<string> ss;
    ss.clear();
    v.clear();
    bool ok = false;
    for (int i = 1; i <= n; ++i) {
      cin>>s;
      ss.insert(s);
      v.push_back(s);
      if (check(s)) {
     //   cout<<"i1="<<i<<endl;
        ok=true;
      }
    }
  //  cout<<"ok="<<ok<<endl;
    if (ok) {
      puts("YES");
    } else {
    //   for (int i = 0; i < v.size(); ++i) {
    //     cout<<"i="<<i<<" "<<ok<<endl;
    //     if (v[i].size() == 2) {
    //       int x=v[i][0]-'a';
    //       int y=v[i][1]-'a';
    //       if (cnt2[x][y] > 0) {
    //         cout<<"a"<<endl;
    //         ok=true;
    //         break;
    //       }
    //       if (cnt1[y][x] > 0) {
    //         cout<<"b"<<endl;
    //         ok=true;
    //         break;
    //       }
    //     }
    //     if (v[i].size() == 3) {
    //       int x=v[i][0]-'a';
    //       int y=v[i][1]-'a';
    //       int z=v[i][2]-'a';
    //       if (cnt4[x][y][z]>0) {
    //         ok=true;
    //         break;
    //       }
    //       if (cnt3[z][y][x]>0) {
    //         ok=true;
    //         break;
    //       }
    //     }
    //     cout<<"i="<<i<<" "<<ok<<endl;
    //   }
    //   if (ok) puts("YES");
    //   else puts("NO");
    // }
      for (int i = 0; i < v.size(); ++i) {
        if (v[i].size() == 2) {
          int x=v[i][0]-'a';
          int y=v[i][1]-'a';
          if (cnt1[y][x] >0 ) {
         //   cout<<"x"<<endl;
            ok=true;
            break;
          }
          for (int j = 0; j < 26; ++j) {
            if (cnt2[y][x][j]>0) {
           //   cout<<"y"<<endl;
              ok=true;
              break;
            }
          }
          if (ok) break;
          cnt1[x][y]++;
        } else {
          int x=v[i][0]-'a';
          int y=v[i][1]-'a';
          int z=v[i][2]-'a';
          if (cnt1[z][y]>0) {
            ok=true;
            break;
          }
          if (cnt2[z][y][x]>0) {
            ok=true;
            break;
          }
          cnt2[x][y][z]++;
        }
      }
      if (ok) puts("YES");
      else puts("NO");
    }
  }
  return 0;
}
