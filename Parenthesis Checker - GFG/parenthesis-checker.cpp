//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        // MAY THE FORCE BE WITH YOUR EX
        
        map<char,char> mp{{'{', '}'}, {'(', ')'}, {'[', ']'}};
        stack<char> check;
        
        for(auto i : x){
            //if the stack is empty and the there is a closing bracket then return false
            if(check.empty() && mp.find(i) == mp.end()) return false;
            
            //if an opening bracket insert in stack
            if(mp.find(i) != mp.end())
                check.push(mp[i]);
                
            // if the recently opened bracket is being closed then pop the stack else return false
            else if(!check.empty()){
                if(check.top() == i){
                    check.pop();
                }
                else return false;
            }
            
        }
        
        if(check.size()) return false;
        return true;
        
        
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends