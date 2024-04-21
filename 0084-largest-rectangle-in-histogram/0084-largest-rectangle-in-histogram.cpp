class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        
        stack<int> st;// NSR
        vector<int> nsr(n,-1);
        for(int i=n-1;i >= 0;i--){
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            nsr[i]= st.empty() ? n : st.top();
            st.push(i);
        }
        
        while (!st.empty()) st.pop();// reusing stack
        
        vector<int> nsl(n,-1);// Left to right and pop when stack top is greater or eq
        for(int i=0;i<n;i++){
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            nsl[i]=st.empty() ? -1: st.top();
            st.push(i);
        }
        int maxArea=INT_MIN;
        for(int i=0;i<n;i++){
           // cout<<i<<" : "<<heights[i]<<" "<<nsr[i]<<" : "<<heights[nsr[i] ||0]<<endl;
           // cout<<i<<" -> "<<nsr[i]<<endl;
            int l=heights[i];
            int b=nsr[i]-nsl[i]-1;
            maxArea=max(maxArea,l*b);
        }
        return maxArea;
    }
};