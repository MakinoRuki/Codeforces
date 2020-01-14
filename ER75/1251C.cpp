#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
typedef long long ll;
int t;
string s;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>s;
    int n = s.size();
    string s1 = "";
    string s2 = "";
    for (int i = 0; i < n; ++i) {
      int d = s[i]-'0';
      if (d%2) s1.push_back(s[i]);
      else s2.push_back(s[i]);
    }
    int i = 0;
    int j = 0;
    string ans ="";
    while(i < s1.size() && j < s2.size()) {
      if (s1[i] < s2[j]) {
        ans.push_back(s1[i++]);
      } else {
        ans.push_back(s2[j++]);
      }
    }
    while(i < s1.size()) {
      ans.push_back(s1[i++]);
    }
    while(j < s2.size()) {
      ans.push_back(s2[j++]);
    }
    cout<<ans<<endl;
  }
	return 0;
}
