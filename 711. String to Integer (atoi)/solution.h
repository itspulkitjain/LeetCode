class Solution {
public:
    bool isOverflow(long long a, long long b){
        long long res=a*10+b-48;
        if(res>INT_MAX)
            return true;
        return false;
    }
    
    int myAtoi(string s) {
        int c=0;
        bool isminus=0;
        bool nostart=0;
        for(int i=0;i<s.size();i++){
            
            if(s[i]==32){
                if(!nostart)
                    continue;
                else
                    break;
            }
            else if(s[i]==43){
                if(!nostart)
                    nostart=1;
                else
                    break;
            }
            else if(s[i]==45){
                if(nostart)
                    break;
                else{
                    isminus=1;
                    nostart=1;
                }
            }
            else if((s[i]<48)||s[i]>57){
                break;
            }
            else{
                nostart=1;
                if(isOverflow(c,s[i])){ 
                    if(isminus){
                        c=INT_MIN;
                        isminus=0;
                    }
                    else{
                        c=INT_MAX;
                    }
                    break;
                }
                    
                else{
                    c=c*10+(s[i]-48);
                }
                
            }
        }
        
        if(isminus){
            c=c*-1;
        }
        
        return c;
    }
};
