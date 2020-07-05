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
#define N 100005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, p;
int t;
ll a,b,c;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string s;
    cin>>s;
    n = s.size();
    int sum=0;
    vector<pair<int,int>> idx;
    idx.clear();
    for (int i = 0; i < s.size(); ++i) {
      if (s[i]=='+') sum++;
      else sum--;
      if (sum < 0) {
        if (idx.empty() || idx.back().second > sum) {
          idx.push_back(make_pair(i+1, sum));
        }
      }
    }
    ll tot=n;
    for (int i = 0; i < idx.size(); ++i) {
      tot += idx[i].first;
    }
    cout<<tot<<endl;
  }
  return 0;
}
