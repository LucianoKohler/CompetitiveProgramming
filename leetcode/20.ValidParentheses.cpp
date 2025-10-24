// https://leetcode.com/problems/valid-parentheses/
#include <bits/stdc++.h>

class Solution {
public:
    bool isValid(string s) {
        stack<char> pilha;
        for(char c : s){
            if(pilha.size() == 0){
                pilha.push(c);
                continue;
            }

                 if(pilha.top() == '(' && c == ')'){ pilha.pop(); }
            else if(pilha.top() == '[' && c == ']'){ pilha.pop(); }
            else if(pilha.top() == '{' && c == '}'){ pilha.pop(); }
            else                                   { pilha.push(c); }
        }

        return pilha.size() == 0;
    }
};