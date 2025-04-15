int compress(vector<char>& chars) {
        int n = chars.size();
        if(n == 1) return 1;
        int i = 0, j = 0, ans = 0, ptr = 0;
        while(j<n){
            int cnt = 0;
            char ch = chars[j];
            while(j < n && chars[j] == ch){
                cnt++;
                j++;
            }
            if(cnt == 1){
                ans += cnt;
                chars[i++] = ch;
            }
            else if(cnt > 1){
                ans += 1;
                chars[i++] = ch;
                string s = to_string(cnt);
                for(char x : s){
                    ans += 1;
                    chars[i++] = x;
                }
            }else{
                j++;
            }
        }
        //chars.resize(ans);
        
        return ans;
    }
