// x >= 0
vector<int> create(int x)
{
    vector<int> res;

    while (x > 0)
    {
        res.push_back(x % 10);
        x /= 10;
    }
    if (res.empty()) res.push_back(0);

    return res;
}

// x >= 0
vector<int> create(const string& x)
{
    vector<int> res;

    for (size_t i = 0; i < x.size(); ++i)
    {
        res.push_back(x[i] - '0');
    }
    reverse(res.begin(), res.end());

    return res;
}

// x >= 0
string to_string(const vector<int>& x)
{
    string res;

    for (size_t i = 0; i < x.size(); ++i)
    {
        res += x[i] + '0';
    }
    reverse(res.begin(), res.end());

    return res;
}

// b >= 0
vector<int> multiply(const vector<int>& a, int b)
{
    vector<int> res(a.size());

    int r = 0;
    for (size_t i = 0; i < a.size(); ++i)
    {
        int t = a[i] * b + r;
        res[i] = t % 10;
        r = t / 10;
    }

    while (r > 0)
    {
        res.push_back(r % 10);
        r /= 10;
    }

    while (res.size() > 1 && res.back() == 0) res.pop_back();

    return res;
}

// a >= b
vector<int> subtract(const vector<int>& a, const vector<int>& b)
{
    vector<int> res(a);

    int r = 0;
    for (size_t i = 0; i < a.size(); ++i)
    {
        res[i] -= (i < b.size() ? b[i] : 0) + r;

        if (res[i] < 0)
        {
            res[i] += 10;
            r = 1;
        }
        else
        {
            r = 0;
        }
    }

    while (res.size() > 1 && res.back() == 0) res.pop_back();

    return res;
}
