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
#define N 102
#define M 400005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
int n;
string s;
int main() {
	cin>>n>>s;
	int tot=0;
	while(true) {
		bool ok = false;
		for (char c = 'z'; c >= 'a'; --c) {
			while(true) {
				bool found= false;
				for (int i =0; i < s.size(); ++i) {
					if (s[i] == c) {
						if ((i-1>=0 && s[i-1] == c-1) || (i+1<s.size() && s[i+1]==c-1)) {
							ok = true;
							found=true;
							s.erase(s.begin()+i);
							tot++;
							break;
						}
					}
				}
				if (!found) break;
			}
		}
		if (!ok) break;
	}
	cout<<tot<<endl;
	return 0;
}
