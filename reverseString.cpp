// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}

// } Driver Code Ends


//User function Template for C++
void reverseWordUtil(string &str,int l,int r)
{
    if(l>=r)
        return;
    swap(str[l],str[r]);
    reverseWordUtil(str,l+1,r-1);
}
string reverseWord(string str){
    
  reverseWordUtil(str,0,str.length()-1);
  return str;
  //Your code here
}