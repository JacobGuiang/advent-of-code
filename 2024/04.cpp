#include <bits/stdc++.h>
using namespace std;

ifstream fin;

int n,m;

bool check1(int i, int j, vector<string>& g, string cur, int dx, int dy) {
    string xmas="XMAS";
    int ii=i+dx, jj=j+dy;
    if(ii>=0 && ii<n && jj>=0 && jj<m && g[ii][jj]==xmas[cur.size()]) {
        cur.push_back(xmas[cur.size()]);
        if(cur==xmas)
            return 1;
        return check1(ii, jj, g, cur, dx, dy);
    }
    return 0;
}

bool check2(int i, int j, vector<string>& g) {
    vector<vector<string>> xmas={
        {
            "M.M",
            ".A.",
            "S.S"
        },
        {
            "M.S",
            ".A.",
            "M.S"
        },
        {
            "S.S",
            ".A.",
            "M.M"
        },
        {
            "S.M",
            ".A.",
            "S.M"
        }
    };
    vector<string> cur;
    for(int r=0; r<3; r++) {
        string s="";
        for(int c=0; c<3; c++)
            s.push_back(g[i+r][j+c]);
        cur.push_back(s);
    }
    cur[0][1]='.';
    cur[1][0]='.';
    cur[1][2]='.';
    cur[2][1]='.';
    for(auto& s : xmas)
        if(s==cur)
            return 1;
    return 0;
}

void solve1() {
    vector<string> g;
    string s;
    int res=0;
    while(fin >> s)
        g.push_back(s);
    n=g.size(), m=g[0].size();
    vector<vector<int>> dir={
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0, -1},
        {0, 1},
        {1, -1},
        {1, 0},
        {1, 1}
    };
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(g[i][j]=='X')
                for(auto& d : dir)
                    res+=check1(i, j, g, "X", d[0], d[1]);
    cout << res << endl;
}

void solve2() {
    vector<string> g;
    string s;
    int res=0;
    while(fin >> s)
        g.push_back(s);
    n=g.size(), m=g[0].size();
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(i+2<n && j+2<m)
                res+=check2(i, j, g);
    cout << res;
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