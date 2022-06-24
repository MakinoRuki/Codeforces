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
#define N 1000006
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 2000000000;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
//  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &m, &k);
    string s1, s2;
    cin>>s1>>s2;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    string ans="";
    int i = 0, j = 0;
    int cnt= 0;
    int x = 0;
    while(i < s1.size() && j < s2.size()) {
      if (s1[i] < s2[j]) {
        if (!x) {
          if (cnt < k) {
            ans.push_back(s1[i++]);
            cnt++;
          } else {
            ans.push_back(s2[j++]);
            x=!x;
            cnt=1;
          }
        } else {
          ans.push_back(s1[i++]);
          x=!x;
          cnt=1;
        }
      } else {
        if (x) {
          if (cnt < k) {
            ans.push_back(s2[j++]);
            cnt++;
          } else {
            ans.push_back(s1[i++]);
            x=!x;
            cnt=1;
          }
        } else {
          ans.push_back(s2[j++]);
          x=!x;
          cnt=1;
        }
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
