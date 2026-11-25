class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // One way we could solve this is by iterating through the entire nums
        // list and then iterating through the hashmap through its values and
        // finding the k most frequent elements. This would mean one iterate
        // loop and one loop to iterate through the values seen.

        // We could create a heap, given the key and values, heapify, and then
        // pop the K elements.

        std::unordered_map<int, size_t> umap;
        umap.reserve(nums.size());
        for (int num : nums)
            ++umap[num];

        std::vector<std::pair<size_t, int>> freqInt;
        freqInt.reserve(umap.size());
        for (auto [key, value] : umap)
            freqInt.push_back({value, key});

        std::make_heap(freqInt.begin(), freqInt.end());

        std::vector<int> returnVec;
        returnVec.reserve(k);
        for (size_t i{0u}; i < k; ++i) {
            std::pop_heap(freqInt.begin(), freqInt.end());
            auto [reps, num] = freqInt.back();
            freqInt.pop_back();
            returnVec.push_back(num);
        }
  
        return returnVec;
    }
};
