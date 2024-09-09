#include <iostream>
#include <stack>
#include <unordered_map>

class Solution {
public:
    bool isValid(std::string s) {
        std::unordered_map<char, char> bracketMap = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        std::stack<char> stack;

        for (char ch : s) {
            if (bracketMap.find(ch) != bracketMap.end()) {
                if (!stack.empty() && stack.top() == bracketMap[ch]) {
                    stack.pop(); 
                } else {
                    return false; 
                }
            } else {
                stack.push(ch);
            }
        }

        return stack.empty();
    }
};