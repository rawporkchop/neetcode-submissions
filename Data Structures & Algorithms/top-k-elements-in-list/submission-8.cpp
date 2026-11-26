class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Bucket sort method

        std::unordered_map<int, size_t> umap{};
        for (int num : nums)
            ++umap[num];

        const size_t bucketLen{nums.size() + 1};
        std::vector<std::vector<int>> buckets(bucketLen);
        for (auto [key, value] : umap)
            buckets[value].push_back(key);

        std::vector<int> returnValues;
        returnValues.reserve(k);
        for (size_t i{bucketLen-1}; i > 0; --i) {
            for (int element : buckets[i]) {
                returnValues.push_back(element);
                if (returnValues.size() == k) return returnValues;
            }
        }

        return returnValues;
    }
};
