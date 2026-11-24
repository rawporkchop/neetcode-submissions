class Solution {
public:
    std::unordered_set<int> seen{};
    bool hasDuplicate(vector<int>& nums) {
        for (auto e : nums) {
            if (seen.contains(e)) return true;
            seen.insert(e);
        }
        return false;
    }
};