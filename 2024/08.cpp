#include <bits/stdc++.h>
using namespace std;

ifstream fin;

vector<string> g;
int n,m;
map<char, vector<pair<int, int>>> mp;

void check1(pair<int, int>& c1, pair<int, int>& c2, set<pair<int, int>>& antinodes, char ch) {
    int x=c2.first+(c2.first-c1.first);
    int y=c2.second+(c2.second-c1.second);
    if(x>=0 && x<n && y>=0 && y<m && g[x][y]!=ch)
        antinodes.insert({x, y});
}

void check2(pair<int, int>& c1, pair<int, int>& c2, set<pair<int, int>>& antinodes, char ch) {
    int x=c2.first+(c2.first-c1.first);
    int y=c2.second+(c2.second-c1.second);
    while(x>=0 && x<n && y>=0 && y<m) {
        if(g[x][y]!=ch)
            antinodes.insert({x, y});
        x+=c2.first-c1.first;
        y+=c2.second-c1.second;
    }
}

void solve1() {
    set<pair<int, int>> antinodes;
    for(auto& [ch, coords] : mp) {
        int sz=coords.size();
        for(int i=0; i<sz-1; i++) {
            for(int j=i+1; j<sz; j++) {
                check1(coords[i], coords[j], antinodes, ch);
                check1(coords[j], coords[i], antinodes, ch);
            }
        }
    }
    cout << antinodes.size() << endl;
}

void solve2() {
    set<pair<int, int>> antinodes;
    for(auto& [ch, coords] : mp)
        for(auto& coord : coords)
            antinodes.insert(coord);
    for(auto& [ch, coords] : mp) {
        int sz=coords.size();
        for(int i=0; i<sz-1; i++) {
            for(int j=i+1; j<sz; j++) {
                check2(coords[i], coords[j], antinodes, ch);
                check2(coords[j], coords[i], antinodes, ch);
            }
        }
    }
    cout << antinodes.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fin.open("input.txt");
    freopen("output.txt", "w", stdout);

    string s;
    while(fin >> s)
        g.push_back(s);
    n=g.size(), m=g[0].size();
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(g[i][j]!='.')
                mp[g[i][j]].push_back({i,j});

    solve1();
    solve2();

    fin.close();

    return 0;
}