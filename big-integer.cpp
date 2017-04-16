//x > 0
vector<int> build(int x) {
    vector<int> res;
    while (x > 0) {
        res.push_back(x % 10);
        x /= 10;
    }
    return res;
}

//b >= 0
void mult(vector<int>& a, int b) {
    int r = 0;
    for (int i = 0; i < a.size(); ++i) {
        int t = a[i] * b + r;
        a[i] = t % 10;
        r = t / 10;
    }
    while (r > 0) {
        a.push_back(r % 10);
        r /= 10;
    }
    while (a.size() > 1 && a[a.size()-1] == 0)
        a.pop_back();
}

//a >= b
void subtr(vector<int>& a, vector<int> b) {
    int r = 0;
    for (int i = 0; i < a.size(); ++i) {
        a[i] -= (i < b.size() ? b[i] : 0) + r;
        if (a[i] < 0) {
            a[i] += 10;
            r = 1;
        } else
            r = 0;
    }
    while (a.size() > 1 && a[a.size()-1] == 0)
        a.pop_back();
}

void println(vector<int> x) {
    for (int i = x.size()-1; i >= 0; --i)
        cout << x[i];
    cout << endl;
}