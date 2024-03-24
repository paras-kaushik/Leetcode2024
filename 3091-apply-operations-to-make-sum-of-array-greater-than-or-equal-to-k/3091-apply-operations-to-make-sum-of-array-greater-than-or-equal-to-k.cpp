class Solution {
public:
    int minOperations(int k) {
        if(k<=1) return 0;
        int lo=1;
        int hi=k;
        int minOps=INT_MAX;
        for(int i=lo;i<=hi;i++){
            int operations= i-1;
            if(i!=k)
                operations += (ceil(k*1.000/i)-1);
           // cout<<i<<" "<<operations<<endl;
            minOps=min(operations,minOps);
        }
            
        return minOps;
    }
};