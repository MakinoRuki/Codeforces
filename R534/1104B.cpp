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
#define N 52
#define M 1000005
#define inf 1000000000
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
string s;
int main() {
	cin>>s;
	int tot=0;
	string t = "";
	for (int i = 0; i < s.size(); ++i) {
		if (!t.empty() && t.back()== s[i]) {
			t.pop_back();
			tot++;
		} else {
			t.push_back(s[i]);
		}
	}
	if (tot%2) {
		cout<<"Yes"<<endl;
	} else {
		cout<<"No"<<endl;
	}
  return 0;
}
