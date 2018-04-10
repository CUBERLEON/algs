/*
 * Finds all entries of a needle to a text (start indices in the text)
 */

/*
 * Computes prefix function of a string
 * Complexity: O(N)
 */
vector<int> PrefixValues(const string& s)
{
    int n = s.size();
    vector<int> res(n, 0);

    for (int i = 1; i < n; ++i)
    {
        int len = res[i - 1];
        while (len > 0 && s[i] != s[len])
        {
            len = res[len - 1];
        }

        res[i] = len + (s[i] == s[len]);
    }

    return res;
}

/*
 * KMP 1: not optimized
 * Complexity: O(N+M) - time & space
 */
vector<int> KMP1(const string& needle, const string& text)
{
    int n = needle.size();
    if (!n) return {};

    int m = text.size();

    auto max_prefixes = PrefixValues(needle + "#" + text);
    vector<int> res;

    for (int i = n + 1; i < max_prefixes.size(); ++i)
    {
        if (max_prefixes[i] == n)
        {
            res.push_back(i - 2 * n);
        }
    }

    return res;
}

/*
 * KMP 2: improved memory consumption
 * Complexity: O(N+M) - time, O(N) - space
 */
vector<int> KMP2(string needle, const string& text)
{
    int n = needle.size();
    if (!n) return {};

    int m = text.size();

    auto max_prefixes = PrefixValues(needle);

    vector<int> res;

    int last_prefix = 0;
    for (int i = 0; i < m; ++i)
    {
        int len = last_prefix;
        while (len > 0 && (len == n || text[i] != needle[len]))
        {
            len = max_prefixes[len - 1];
        }

        last_prefix = len + (text[i] == needle[len]);

        if (last_prefix == n)
        {
            res.push_back(i - n + 1);
        }
    }

    return res;
}
