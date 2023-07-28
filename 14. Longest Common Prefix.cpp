class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str;
        bool flag=true;
        for(int i=0;i<strs[0].size();i++){
            char c=strs[0][i];
            for(int j=0;j<strs.size();j++){
                if(c==strs[j][i]){
                    continue;
                }else{
                    flag=false;
                    break;
                }
            }
            if(flag==false){
                break;
            }else{
                str=str+c;
            }
        }
        return str;
    }
};
