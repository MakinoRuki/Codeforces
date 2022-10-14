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
#define N 200005
#define M 2505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int cnt[10];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string s;
    cin>>s;
    n = (int)s.size();
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; ++i) {
      cnt[s[i-1]-'0']++;
    }
    vector<int> v;
    v.clear();
    int cur = 0;
    string ans="";
    for (int i = 1; i <= n; ++i) {
      while(cur <= 9 && cnt[cur] == 0) {
        cur++;
      }
      if (s[i-1] - '0' == cur) {
        ans.push_back(s[i-1]);
        cnt[cur]--;
      } else {

        v.push_back(min(s[i-1]-'0'+1, 9));
      //  cout<<"y="<<v.back()<<endl;
        cnt[s[i-1]-'0']--;
      }
    }
  //  cout<<"x="<<ans<<endl;
    sort(v.begin(), v.end());
    string ans2="";
    int i = 0, j = 0;
    while(i < ans.size() && j < v.size()) {
      if (ans[i]-'0' < v[j]) {
        ans2.push_back(ans[i]);
        i++;
      } else {
        ans2.push_back('0' + v[j]);
        j++;
      }
    }
    while(i < ans.size()) {
      ans2.push_back(ans[i]);
      i++;
    }
    while(j < v.size()) {
      ans2.push_back(v[j]+'0');
      j++;
    }
    cout<<ans2<<endl;
  }
  return 0;
}
