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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    vector<int> v;
    v.clear();
    vector<int> ids;
    ids.clear();
    int ans=0;
    for (int i = 0; i < 2*n; ++i) {
      if (s[i] == '(') {
        v.push_back(i);
      } else {
        if (!v.empty()) {
          int pre=v.back();
          v.pop_back();
          ans++;
          if (ids.empty()) {
            ids.push_back(i);
          } else {
            while(!ids.empty()) {
              if (pre < ids.back()) {
                ids.pop_back();
              } else {
                if (pre == ids.back()+1) {
                  ids.pop_back();
                  ans--;
                }
                break;
              }
            }
            ids.push_back(i);
          }
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
