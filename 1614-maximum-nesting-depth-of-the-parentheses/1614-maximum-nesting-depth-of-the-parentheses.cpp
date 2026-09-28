class Solution {
public:
    int maxDepth(string s) {
        int res =0;
        int current=0;
        for(char& c: s)
        {
            if( c =='(')
            {
                res = max(++current,res);
            }
            if(c ==')')
            {
                current--;
            }

        }
        return res;
        
    }
};