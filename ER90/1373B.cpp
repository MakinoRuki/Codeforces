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
    int tot=0;
    vector<int> vs;
    vs.clear();
    for (int i = 0; i < s.size(); ++i) {
      if (!vs.empty() && vs.back() != s[i]-'0') {
        tot++;
        vs.pop_back();
      } else {
        vs.push_back(s[i]-'0');
      }
    }
    if (tot%2) {
      cout<<"DA"<<endl;
    } else {
      cout<<"NET"<<endl;
    }
  }
  return 0;
}
