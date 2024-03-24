typedef long long ll;
class Solution{
public:
    vector<ll> mostFrequentIDs(vector<int> &nums, vector<int> &freq){
        priority_queue<pair<ll, int>> pq;// num->freq
        unordered_map<int, ll> mp;// freq->num
        vector<ll> ans;
        for (int i = 0; i < nums.size(); i++){
            mp[nums[i]] += freq[i];
            pq.push({mp[nums[i]], nums[i]});
            while (!pq.empty()){
                pair<ll, int> p = pq.top();
                if (mp[p.second] != p.first)
                {
                    pq.pop();
                    if (mp[p.second])
                        pq.push({mp[p.second], p.second});
                }
                else
                {
                    break;
                }
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};