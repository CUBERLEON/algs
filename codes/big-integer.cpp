/* Long arithmetic operations */

#include <bits/stdc++.h>
using namespace std;

//x >= 0
vector<int> build(int x) {
    vector<int> res;
    while (x > 0) {
        res.push_back(x % 10);
        x /= 10;
    }
    if (res.empty()) res.push_back(0);
    return res;
}

//b >= 0
vector<int> mult(const vector<int>& a, int b) {
    vector<int> res(a.size());
    int r = 0;
    for (int i = 0; i < a.size(); ++i) {
        int t = a[i] * b + r;
        res[i] = t % 10;
        r = t / 10;
    }
    while (r > 0) {
        res.push_back(r % 10);
        r /= 10;
    }
    while (res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}

//a >= b
vector<int> subtr(const vector<int>& a, const vector<int>& b) {
    vector<int> res(a);
    int r = 0;
    for (int i = 0; i < a.size(); ++i) {
        res[i] -= (i < b.size() ? b[i] : 0) + r;
        if (res[i] < 0) {
            res[i] += 10;
            r = 1;
        } else
            r = 0;
    }
    while (res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}

void println(const vector<int>& x) {
    for (int i = x.size()-1; i >= 0; --i) cout << x[i];
    cout << endl;
}

main() {
	println(mult(build(8), 13)); //104
    println(mult(build(0), 78)); //0
	println(subtr(build(35), build(27))); //8
    println(subtr(build(88), build(0))); //88
	println(subtr(mult(build(8), 13), build(101))); //3
}
