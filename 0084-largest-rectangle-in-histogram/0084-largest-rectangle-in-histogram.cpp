class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int* nsr=new int[n]();//right to left and pop when stack top is greater or eq
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while (!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            nsr[i]= st.empty()? n: st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        int* nsl=new int[n]();
        // left to right and pop when stack top is greater or eq
        for(int i=0;i<n;i++){
            while (!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            nsl[i]= st.empty()? -1: st.top();
            st.push(i);
        }
        int maxArea=INT_MIN;
        for(int i=0;i<n;i++){
            int l= nsr[i]-nsl[i]-1;
            maxArea=max(maxArea,l*heights[i]);
        }
        return maxArea;
    }
};