// Uses Sliding window along with Hash Function to reduce complexity from O(N*M) to O(N-M)
vector <int> search(string pat, string txt)
 {
            //code here. 
    int M = (pat.length()); 
    int N = (txt.length()); 
    int i, j; 
    int p = 0; // hash value for pattern 
    int t = 0; // hash value for txt 
    int h = 1; 
  int d = 256, q = 101;
  vector<int>res;
    // The value of h would be "pow(d, M-1)%q" 
    for (i = 0; i < M-1; i++) 
        h = (h*d)%q; 
  
    // Calculate the hash value of pattern and first 
    // window of text 
    for (i = 0; i < M; i++) 
    { 
        p = (d*p + pat[i])%q; 
        t = (d*t + txt[i])%q; 
    } 
  

    for (i = 0; i <= N - M; i++) 
    { 
  
   
        if ( p == t ) 
        { 
    
            for (j = 0; j < M; j++) 
            { 
                if (txt[i+j] != pat[j]) 
                    break; 
            } 
  
  
            if (j == M) 
             res.push_back(i+1);
        } 
  
        if ( i < N-M ) 
        { 
            t = (d*(t - txt[i]*h) + txt[i+M])%q; 
  
      
            if (t < 0) 
            t = (t + q); 
        } 
    
    }
    if(res.size()==0)
    return {-1};
    return res;
        }
