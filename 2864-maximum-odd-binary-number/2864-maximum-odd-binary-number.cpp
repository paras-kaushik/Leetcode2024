class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        //maximum odd binary number that can be created from this combination.
        int count=0;
        for(char& c:s) if(c=='1') count++;
        count--;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(count){
                s[i]='1';
                count--;
            }
            else if (i == n-1) s[i]='1';
            else s[i]='0';
        }
    
        return s;
    }
};