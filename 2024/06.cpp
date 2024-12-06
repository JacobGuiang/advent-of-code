#include <bits/stdc++.h>
using namespace std;

ifstream fin;

vector<string> g;
vector<vector<int>> vis1;
int n,m,starti,startj;
int dirs[][2]={
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

void solve1() {
    for(int r=0; r<n; r++)
        for(int c=0; c<m; c++)
            if(g[r][c]=='^')
                starti=r, startj=c;
    int d=0, nexti, nextj, i=starti, j=startj, res=0;
    while(1) {
        if(!vis1[i][j])
            ++res;
        vis1[i][j]=1;
        int dir=d%4;
        nexti=i+dirs[dir][0], nextj=j+dirs[dir][1];
        if(nexti<0 || nexti==n || nextj<0 || nextj==m)
            break;
        if(g[nexti][nextj]=='#')
            ++d;
        else
            i=nexti, j=nextj;
    }
    cout << res << endl;
}

void solve2() {
    int res=0;
    for(int r=0; r<n; r++) {
        for(int c=0; c<m; c++) {
            if(vis1[r][c]) {
                vector<vector<vector<bool>>> vis2(n, vector<vector<bool>>(m, vector<bool>(4)));
                int d=0, nexti, nextj, i=starti, j=startj;
                bool loop=0;
                g[r][c]='#';
                while(1) {
                    int dir=d%4;
                    if(vis2[i][j][dir]) {
                        loop=1;
                        break;
                    }
                    vis2[i][j][dir]=1;
                    nexti=i+dirs[dir][0], nextj=j+dirs[dir][1];
                    if(nexti<0 || nexti==n || nextj<0 || nextj==m)
                        break;
                    if(g[nexti][nextj]=='#')
                        ++d;
                    else
                        i=nexti, j=nextj;
                }
                g[r][c]='.';
                res+=loop;
            }
        }
    }
    cout << res;
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
    vis1.resize(n, vector<int>(m));

    solve1();
    solve2();

    fin.close();

    return 0;
}