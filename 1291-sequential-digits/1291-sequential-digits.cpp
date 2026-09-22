class Solution {
    bool check(int n, int low, int high){
        return n>=low && n<=high;
    }
    int digitLen(int n){
        if(!n) return 1;

        int ans = 0;
        while(n){
            ans++;
            n/=10;
        }
        return ans;
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int curr_len = digitLen(low);
        int end_len = digitLen(high);

        while(curr_len <= end_len){
            for(int m = 0; m<10-curr_len; m++){
                int n = 0;
                for(int i = 1+m; i<=curr_len+m; i++){
                    n*=10;
                    n+=i;
                }

                if(check(n,low,high)){
                    ans.push_back(n);
                }
            }
            curr_len++;
        }
        return ans;
    }
};