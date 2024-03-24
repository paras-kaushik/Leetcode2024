class Solution {
public:
    bool isValid(unordered_map<char, int>& um){
        for(auto it:um) if(it.second>2) return false;
        return true;
    }
    int maximumLengthSubstring(string s) {
        string ans;
        int maxLen=1;
        int n=s.length();
        int start=0,end=0;
        unordered_map<char, int> um;
        while (start <=end && end<n) {
            um[s[end]]++;
            while (!isValid(um)) {
                um[s[start]]--;
                if(um[s[start]]==0) um.erase(s[start]);
                start++;
            }
            maxLen=max(maxLen,end-start+1);
            end++;
        }
        
        return maxLen;
    }
};