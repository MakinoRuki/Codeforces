#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int x;
string s, t;
int main() {
  cin>>n;
  cin>>s>>t;
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());
  deque<char> dq;
  for (int i = 0; i < t.size(); ++i) {
    dq.push_back(t[i]);
  }
  int ans1=0,ans2=0;
  for (int i = 0; i < s.size(); ++i) {
    if (dq.front() >= s[i]) {
      dq.pop_front();
    } else {
      dq.pop_back();
      ans1++;
    }
  }
  int j = 0;
  for (int i = 0; i < t.size(); ++i) {
    while(j < s.size() && t[i] <= s[j]) {
      j++;
    }
    if (j < s.size()) {
      ans2++;
      j++;
    }
  }
  cout<<ans1<<endl<<ans2<<endl;
  return 0;
}
