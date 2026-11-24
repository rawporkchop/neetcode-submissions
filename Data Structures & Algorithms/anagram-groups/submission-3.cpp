#include <ranges>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        std::unordered_map<std::string, std::vector<std::string>> classes{};

        for (std::string str : strs) {
            std::string strClass{str};
            std::ranges::sort(strClass);
            classes[strClass].push_back(str);
        }

//        std::vector<std::vector<std::string>> vecStrs;
//        vecStrs.reserve(classes.size());
//        for (auto [key, value] : classes) {
//            vecStrs.push_back(value);
//        }

//        return classes | std::views::values | std::ranges::to<std::vector>();

        std::vector<std::vector<std::string>> vecStrs;
        vecStrs.reserve(classes.size());
        for (auto& [key, val] : classes) {
            vecStrs.push_back(std::move(val));
        }
        return vecStrs;

    }
};
