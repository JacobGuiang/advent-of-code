#include <bits/stdc++.h>
using namespace std;

ifstream fin;

void solve1() {
    vector<int> left, right;
    int l, r;
    while(fin >> l >> r) {
        left.push_back(l);
        right.push_back(r);
    }
    int res=0;
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    for(int i=0; i<left.size(); i++)
        res+=abs(left[i]-right[i]);
    cout << res << endl;
}

void solve2() {
    vector<int> left;
    unordered_map<int, int> right;
    int l, r;
    while(fin >> l >> r) {
        left.push_back(l);
        right[r]++;
    }
    int res=0;
    for(int i : left)
        res+=i*right[i];
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