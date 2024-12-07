#include <bits/stdc++.h>
using namespace std;

ifstream fin;

bool check1(long long total, vector<int>& nums, long long cur, int i) {
    if(total==cur)
        return 1;
    if(i+1<nums.size())
        return check1(total, nums, cur+nums[i+1], i+1) || check1(total, nums, cur*nums[i+1], i+1);
    return 0;
}

bool check2(long long total, vector<int>& nums, long long cur, int i) {
    if(total==cur)
        return 1;
    if(i+1<nums.size())
        return check2(total, nums, cur+nums[i+1], i+1) || check2(total, nums, cur*nums[i+1], i+1) || check2(total, nums, stoll(to_string(cur)+to_string(nums[i+1])), i+1);
    return 0;
}

void solve1() {
    string s;
    long long res=0;
    while(getline(fin, s)) {
        istringstream ss(s);
        string sum;
        int n;
        vector<int> nums;
        ss >> sum;
        while(ss >> n)
            nums.push_back(n);
        long long total=stoll(sum.substr(0, sum.size()-1));
        if(check1(total, nums, nums[0], 0))
            res+=total;
    }
    cout << res << endl;
}

void solve2() {
    string s;
    long long res=0;
    while(getline(fin, s)) {
        istringstream ss(s);
        string sum;
        int n;
        vector<int> nums;
        ss >> sum;
        while(ss >> n)
            nums.push_back(n);
        long long total=stoll(sum.substr(0, sum.size()-1));
        if(check2(total, nums, nums[0], 0))
            res+=total;
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