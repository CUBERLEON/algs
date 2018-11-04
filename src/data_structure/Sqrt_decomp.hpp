class Sqrt_sum
{
public:
    Sqrt_sum(size_t n)
    : arr(n, 0)
    , len(ceil(sqrt(n)))
    , sum_blocks(len, 0)
    , add_blocks(len, 0)
    {}

    // Complexity: O(1) - time & space
    void assign(size_t index, int value)
    {
        size_t block = index / len;
        assert(block < len);

        value -= add_blocks[block]; // required for AddOnRange
        sum_blocks[block] += value - arr[index];
        arr[index] = value;
    }

    // Complexity: O(sqrt(N)) - time, O(1) - space
    void add_on_range(size_t left, size_t right, int value)
    {
        assert(0 <= left && left <= right && right < arr.size());

        size_t left_block = left / len;
        size_t right_block = right / len;
        assert(left_block < len && right_block < len);

        if (left_block == right_block)
        {
            for (size_t i = left; i <= right; ++i)
            {
                arr[i] += value;
                sum_blocks[left_block] += value;
            }
        }
        else
        {
            for (size_t i = left; i <= (left_block + 1) * len - 1; ++i)
            {
                arr[i] += value;
                sum_blocks[left_block] += value;
            }
            for (size_t i = left_block + 1; i <= right_block - 1; ++i)
            {
                add_blocks[i] += value;
            }
            for (size_t i = right_block * len; i <= right; ++i)
            {
                arr[i] += value;
                sum_blocks[right_block] += value;
            }
        }
    }

    // Complexity: O(sqrt(N)) - time, O(1) - space
    int sum(size_t left, size_t right)
    {
        int result = 0;

        assert(0 <= left && left <= right && right < arr.size());

        size_t left_block = left / len;
        size_t right_block = right / len;
        assert(left_block < len && right_block < len);

        if (left_block == right_block)
        {
            for (size_t i = left; i <= right; ++i)
            {
                result += arr[i] + add_blocks[left_block];
            }
        }
        else
        {
            for (size_t i = left; i <= (left_block + 1) * len - 1; ++i)
            {
                result += arr[i] + add_blocks[left_block];
            }
            for (size_t i = left_block + 1; i <= right_block - 1; ++i)
            {
                result += sum_blocks[i] + add_blocks[i] * len;
            }
            for (size_t i = right_block * len; i <= right; ++i)
            {
                result += arr[i] + add_blocks[right_block];
            }
        }

        return result;
    }
private:
    vector<int> arr;

    int len;
    vector<int> sum_blocks;
    vector<int> add_blocks; // required for add_on_range
};
