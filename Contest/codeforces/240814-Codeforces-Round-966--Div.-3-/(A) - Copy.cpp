#include<bits/stdc++.h>

using namespace std;

string s;

int main() {
	
	int t; cin>>t;
	for(int i = t; i--; ) {
		cin>>s;
		if(s.size() < 3) {puts("NO"); continue;}
		if(s[1] == '0' && s[0] == '1') {
			if(s[3]) {
				if(s[2] != '0') {puts("YES"); continue;}
			}
			else if(s[2] >= '2') {puts("YES"); continue;}
		}
		puts("NO");
	}
}