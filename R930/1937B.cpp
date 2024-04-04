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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s1, s2;
    cin>>s1;
    cin>>s2;
    string ans="";
    ans.push_back(s1[0]);
    int cnt=0;
    for (int i = 2; i <= n; ++i) {
      int i2=i-1;
      if (s1[i-1] == s2[i2-1]) {
        ans.push_back(s1[i-1]);
        cnt++;
      } else {
        if (s1[i-1] < s2[i2-1]) {
          ans.push_back(s1[i-1]); 
          cnt=0;
        } else {
          ans.push_back(s2[i2-1]);
          for (int i = i2+1; i < n; ++i) {
            ans.push_back(s2[i-1]);
          }
          break;
        }
      }
    }
    ans.push_back(s2[n-1]);
    cout<<ans<<endl;
    printf("%d\n", cnt+1);
  }
  return 0;
}
