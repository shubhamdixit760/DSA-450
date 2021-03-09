// SIMPLE SOLUTION
class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
     unordered_map<string, int> m; 
    for (int i = 0; i<n; i++) 
        m[arr[i]]++; 
    int first = -1, sec = -1; 
    // DIVYA SIR'S ALGO FOR FINDING SECOND SMALLEST ELEMENT IN N STEPS  
    for (auto it:m) { 
        if (it.second > first) { 
            sec = first; 
            first = it.second; 
        } 
  
        else if (it.second > sec&&it.second != first) 
            sec = it.second; 
    } 
  
    for (auto it:m) 
        if (it.second == sec) 
            return it.first;
    return "NOT FOUND";
    }
};
