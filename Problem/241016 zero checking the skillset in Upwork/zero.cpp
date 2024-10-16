#include <bits/stdc++.h>

using namespace std;

vector<string> vec;
char s[1010];

int main() {
    freopen("skills.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    while(gets(s)) vec.push_back(s);
    
    for(int i = 0, j = 0; i < vec.size(); i = j) {
        for(; j < vec.size() && vec[i] == vec[j]; j++);
        printf("%3d => %s\n", j - i, vec[i].c_str() + 3);
    }
    return 0;
}