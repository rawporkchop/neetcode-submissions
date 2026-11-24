class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, size_t> mapS{};
        std::unordered_map<char, size_t> mapT{};

        auto hashStr = [](std::string_view str, 
                          std::unordered_map<char, size_t>& strMap) {
            for (const char c : str) {
                ++strMap[c];
            }
        };

        hashStr(s, mapS);
        hashStr(t, mapT);

        return mapS == mapT;
    }
};
