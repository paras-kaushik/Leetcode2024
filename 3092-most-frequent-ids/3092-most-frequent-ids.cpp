typedef long long ll;
class Solution {
public:
    ll getNonRedundantMaximumFreq(unordered_map<ll, ll>& um,priority_queue<pair<ll, ll>>& pq){
        while (!pq.empty() && um[pq.top().second]!= pq.top().first) pq.pop();
        return pq.top().first;
    }
    vector<ll> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        size_t n=nums.size();
        unordered_map<ll, ll> freq_map;
        priority_queue<pair<ll, ll>> maxFreqWithElem;// lazy updated pq
        vector<ll> ans;
        for(int i=0;i<n;i++){
            freq_map[nums[i]] +=freq[i];
            //cout<<nums[i] <<" -> "<<freq_map[nums[i]]<<endl;
            maxFreqWithElem.push({freq_map[nums[i]],nums[i]});
            ans.push_back(getNonRedundantMaximumFreq(freq_map,maxFreqWithElem));
        }
        return ans;
    }
};
