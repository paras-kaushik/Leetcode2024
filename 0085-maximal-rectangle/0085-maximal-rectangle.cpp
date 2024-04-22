class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> histogram(m, 0);
        int maxArea = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                histogram[j] = matrix[i][j] == '0' ? 0 : histogram[j] + 1;
            }
            maxArea = max(maxArea, largestRectangularAreaInHistogram(histogram));
        }

        return maxArea;
    }

private:
    vector<int> nextSmallerToLeft(vector<int>& ans) {
        int n = ans.size();
        vector<int> nsl(n);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && ans[st.top()] >= ans[i]) {
                st.pop();
            }
            nsl[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return nsl;
    }

    vector<int> nextSmallerToRight(vector<int>& ans) {
        int n = ans.size();
        vector<int> nsr(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && ans[st.top()] >= ans[i]) {
                st.pop();
            }
            nsr[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nsr;
    }

    int largestRectangularAreaInHistogram(vector<int>& histogram) {
        vector<int> nsl = nextSmallerToLeft(histogram);
        vector<int> nsr = nextSmallerToRight(histogram);

        int largestArea = INT_MIN;
        for (int i = 0; i < histogram.size(); ++i) {
            int l = histogram[i];
            int b = nsr[i] - nsl[i] - 1;
            largestArea = max(largestArea, l * b);
        }
        return largestArea;
    }
};
