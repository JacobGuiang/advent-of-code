#include <bits/stdc++.h>
using namespace std;

ifstream fin;

void solve1() {
    unordered_map<int, unordered_set<int>> mp;
    string s;
    bool first=1;
    int res=0;
    while(getline(fin, s)) {
        if(!s.size()) {
            first=0;
        } else if(first) {
            string a=s.substr(0, 2);
            string b=s.substr(3, 2);
            mp[stoi(a)].insert(stoi(b));
        } else {
            string p="";
            vector<int> cur;
            for(int i=0; i<s.size(); i++) {
                if(s[i]!=',')
                    p.push_back(s[i]);
                if(i==s.size()-1 || s[i]==',') {
                    cur.push_back(stoi(p));
                    p="";
                }
            }
            bool ok=1;
            for(int i=0; i<cur.size()-1; i++) {
                for(int j=i+1; j<cur.size(); j++) {
                    unordered_set<int>* s=&mp[cur[i]];
                    if(mp.count(cur[i]) && mp.count(cur[j]) && !s->count(cur[j])) {
                        ok=0;
                    }
                }
            }
            if(ok)
                res+=cur[cur.size()/2];
        }
    }
    cout << res << endl;
}

void solve2() {
    unordered_map<int, unordered_set<int>> mp;
    string s;
    bool first=1;
    int res=0;
    while(getline(fin, s)) {
        if(!s.size()) {
            first=0;
        } else if(first) {
            string a=s.substr(0, 2);
            string b=s.substr(3, 2);
            mp[stoi(a)].insert(stoi(b));
        } else {
            string p="";
            vector<int> cur;
            for(int i=0; i<s.size(); i++) {
                if(s[i]!=',')
                    p.push_back(s[i]);
                if(i==s.size()-1 || s[i]==',') {
                    cur.push_back(stoi(p));
                    p="";
                }
            }
            bool ok=1;
            for(int i=0; i<cur.size()-1; i++) {
                for(int j=i+1; j<cur.size(); j++) {
                    unordered_set<int>* s=&mp[cur[i]];
                    if(mp.count(cur[i]) && mp.count(cur[j]) && !s->count(cur[j])) {
                        ok=0;
                        swap(cur[i], cur[j]);
                    }
                }
            }
            if(!ok)
                res+=cur[cur.size()/2];
        }
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fin.open("input.txt");
    freopen("output.txt", "w", stdout);

    solve1();
    fin.clear();
    fin.seekg(0);
    solve2();

    fin.close();

    return 0;
}