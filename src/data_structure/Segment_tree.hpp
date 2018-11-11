class Segment_tree
{
public:
    Segment_tree(size_t n) : tree(n * 4, {0, 0}), n(n)
    {}

    // Complexity: O(Log(N)) - time & space
    void assign(size_t index, int value)
    {
        assert(index >= 0 && index < n);
        assign_aux(0, 0, n-1, index, value);
    }

    // Complexity: O(Log(N)) - time & space
    int get(size_t index)
    {
        assert(index >= 0 && index < n);
        return sum(index, index);
    }

    // Complexity: O(Log(N)) - time & space
    void add_on_range(size_t left, size_t right, int value)
    {
        assert(left >= 0 && left < n && right >= 0 && right < n && left <= right);
        add_on_range_aux(0, 0, n-1, left, right, value);
    }

    // Complexity: O(Log(N)) - time & space
    int sum(size_t left, size_t right)
    {
        assert(left >= 0 && left < n && right >= 0 && right < n && left <= right);
        return sum_aux(0, 0, n-1, left, right);
    }

private:
    struct Node
    {
        int sum;
        int add;
    };

    vector<Node> tree;
    int n;

    int assign_aux(int cur, int cur_left, int cur_right, int index, int value)
    {
        propagate(cur, cur_right - cur_left + 1);

        int diff;
        if (index < cur_left || index > cur_right) return 0;
        if (cur_left == cur_right && cur_left == index)
        {
            diff = value - tree[cur].sum;
            tree[cur].sum = value;
            return diff;
        }

        int mid = cur_left + (cur_right - cur_left) / 2;
        
        if (index <= mid)
            diff = assign_aux(node_left(cur), cur_left, mid, index, value);
        else
            diff = assign_aux(node_right(cur), mid + 1, cur_right, index, value);

        tree[cur].sum += diff;

        return diff;
    }

    void add_on_range_aux(int cur, int cur_left, int cur_right, int left, int right, int value)
    {
        if ((right - cur_left) * (left - cur_right) > 0) return;
        if (cur_left >= left && cur_right <= right)
        {
            tree[cur].add += value;
            return;
        }

        int mid = cur_left + (cur_right - cur_left) / 2;
        add_on_range_aux(node_left(cur), cur_left, mid, left, right, value);
        add_on_range_aux(node_right(cur), mid + 1, cur_right, left, right, value);

        int intersection = min(cur_right, right) - max(cur_left, left) + 1;
        tree[cur].sum += intersection * value;
    }

    int sum_aux(int cur, int cur_left, int cur_right, int left, int right)
    {
        propagate(cur, cur_right - cur_left + 1);

        if ((right - cur_left) * (left - cur_right) > 0) return 0;
        if (cur_left >= left && cur_right <= right) return tree[cur].sum;

        int mid = cur_left + (cur_right - cur_left) / 2;
        int sum_left = sum_aux(node_left(cur), cur_left, mid, left, right);
        int sum_right = sum_aux(node_right(cur), mid + 1, cur_right, left, right);

        return sum_left + sum_right;
    }

    int node_left(int cur) { return cur * 2 + 1; }
    int node_right(int cur) { return cur * 2 + 2; }

    void propagate(int cur, int len)
    {
        if (!tree[cur].add) return;

        tree[cur].sum += tree[cur].add * len;

        if (len > 1)
        {
            tree[node_left(cur)].add += tree[cur].add;
            tree[node_right(cur)].add += tree[cur].add;
        }

        tree[cur].add = 0;
    }
};