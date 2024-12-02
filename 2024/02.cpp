#include <bits/stdc++.h>
using namespace std;

ifstream fin;

bool check1(vector<int>& nums) {
    if(!is_sorted(nums.begin(), nums.end()) && !is_sorted(nums.begin(), nums.end(), [](int a, int b){return a>b;}))
        return 0;
    for(int i=1; i<nums.size(); i++)
        if(abs(nums[i]-nums[i-1])<1 || abs(nums[i]-nums[i-1])>3)
            return 0;
    return 1;
}

bool check2(vector<int> nums, int i) {
    nums.erase(nums.begin()+i);
    return check1(nums);
}

void solve1() {
    string s;
    int res=0;
    while(getline(fin, s)) {
        istringstream ss(s);
        int n;
        vector<int> nums;
        while(ss >> n)
            nums.push_back(n);
        res+=check1(nums);
    }
    cout << res << endl;
}

void solve2() {
    string s;
    int res=0;
    while(getline(fin, s)) {
        istringstream ss(s);
        int n;
        vector<int> nums;
        while(ss >> n)
            nums.push_back(n);
        for(int i=0; i<nums.size(); i++) {
            if(check2(nums, i)) {
                res++;
                break;
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

    solve1();
    fin.clear();
    fin.seekg(0);
    solve2();

    fin.close();

    return 0;
}