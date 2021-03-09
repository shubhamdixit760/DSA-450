// THIS ALGO USES SLIDING WINDOW ALONG WITH HASHING SO COMPLEXITY IS O(N-M) UNLIKE NORMAL RKP WITH O(N*M)

int hash(string txt, int m)
    {
        if(m<0)
        return 0;
        long long int res = 0;
        for(int i=0;i<m;i++)
        {
            res+=pow(txt[i],19);
            res%=100001;
        }
        return (int)res;
    }
        vector <int> search(string pat, string txt)
        {
            //code here.
             //code here.
            int MOD = 101;
            int D = 256;
            vector<int>result;
            int m = pat.size(), n = txt.size();
            int hash_pat = hash(pat,m), hash_window = hash(txt,m);
            
            
            for(int i=0;i<n-m;i++)
            {
                if(hash_pat==hash_window)
                {
                    int j=0;
                    for(j=0;j<m;j++)
                    {
                        if(txt[i+j]!=pat[j])
                        break;
                    }
                    if(j==m)
                    result.push_back(i+1);
                }
                if(i<n-m)
                {
                   long long int x = pow(txt[i],19), y = pow(txt[i+m],19);
                   hash_window = hash_window- (x%100001) + (y%100001);
                }
            }
            if(result.size()==0)
            result.push_back(-1);
            return result;
        }
