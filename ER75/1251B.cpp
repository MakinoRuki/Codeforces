#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
typedef long long ll;
int t, n;
vector<string> ss;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ss.clear();
    cin>>n;
    int zn = 0;
    int on = 0;
    vector<pair<int, string>> os;
    os.clear();
    vector<pair<int, string>> es;
    es.clear();
    for (int i = 0; i < n; ++i) {
      string s;
      cin>>s;
      ss.push_back(s);
      if (s.size() % 2) {
        os.push_back(make_pair(s.size(), s));
      } else {
        es.push_back(make_pair(s.size(), s));
      }
      for (int j = 0; j < s.size(); ++j) {
        if (s[j] == '0') zn++;
        else on++;
      }
    }
    sort(os.begin(), os.end());
    sort(es.begin(), es.end());
    int ans = 0;
    int cnt1=0;
    int cnt2=0;
    for (int i = 0; i < es.size(); ++i) {
      cnt1 += es[i].first/2;
      for (int j = 0; j < os.size(); ++j) {
        cnt2 += os[j].first/2;
        int p1 = zn/2 + on/2;
        if (cnt1+cnt2<=p1 && (zn+on-(cnt1+cnt2)*2 >= j+1)) {
          ans = max(ans, i+1+j+1);
        }
      }
      cnt2 = 0;
      if (zn/2 + on/2 >= cnt1) {
        ans = max(ans, i+1);
      }
    }
    cnt1=0;
    cnt2=0;
    for (int i = 0; i < os.size(); ++i) {
      cnt1 += os[i].first/2;
      for (int j = 0; j < es.size(); ++j) {
        cnt2 += es[j].first/2;
        int p1 = zn/2 + on/2;
        if (cnt1+cnt2<=p1 && (zn+on-(cnt1+cnt2)*2 >= i+1)) {
          ans = max(ans, i+1+j+1);
        }
      }
      cnt2 = 0;
      if (zn/2 + on/2 >= cnt1 && zn+on > cnt1*2) {
        ans = max(ans, i+1);
      }
    }
    cout<<ans<<endl;
  }
	return 0;
}
