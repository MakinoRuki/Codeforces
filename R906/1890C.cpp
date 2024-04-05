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
#define N 1000005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    list<int> ls;
    ls.clear();
    for (int i = 0; i < n; ++i) {
      ls.push_back(s[i]-'0');
    }
    bool ok=true;
    int cnt=0;
    int l=1,r=n;
    vector<int> ans;
    ans.clear();
    while(!ls.empty()) {
      if (ls.size() == 1) {
        ok=false;
        break;
      }
      if (ls.front() != ls.back()) {
        ls.pop_front();
        ls.pop_back();
        l++;
        r--;
      } else {
        if (cnt >= 300) {
          ok=false;
          break;
        }
        cnt++;
        if (ls.front() == 0) {
          ls.pop_front();
          ls.push_back(0);
          ans.push_back(r);
          r++;
          l++;
        } else {
          ls.pop_back();
          ls.push_front(1);
          ans.push_back(l-1);
          l++;
          r++;
        }
      }
    }
    if (!ok || !ls.empty()) {
      puts("-1");
    } else {
      printf("%d\n", (int)ans.size());
      for (int i = 0; i < ans.size(); ++i) {
        printf("%d ", ans[i]);
      }
      cout<<endl;
    }
  }
  return 0;
}
