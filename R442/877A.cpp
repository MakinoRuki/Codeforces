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
#define M 20005
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
string a,b;
string s;
int main() {
	cin>>s;
	unordered_map<string, int> cnt;
	cnt.clear();
	int tot=0;
	for (int i = 0; i < s.size(); ++i) {
		string tmp="";
		for (int j = i; j < s.size(); ++j) {
			tmp.push_back(s[j]);
			if (tmp=="Danil" || tmp=="Olya" || tmp=="Slava" || tmp=="Ann" || tmp=="Nikita") {
				tot++;
			}
		}
	}
	if (tot==1) {
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}
	return 0;
}
