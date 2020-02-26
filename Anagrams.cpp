vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    int n=A.size();
    unordered_map<string,int>m(n);          //Map to store the sorted string as key and a index of particular output row
    
    vector<vector<int>> out;                  //output vector
    int x=0;
    for(int i=0;i<n;i++)
    { 
        string s=A[i];                                  //local string copying the original string
        
        sort(s.begin(),s.end());                          //sorting the local string to act as a key 
        
        if(m.find(s)==m.end())                              //if currently there is no matching string
       {
           
           m.insert({s,x});                                   //insert it into map
           out.push_back({i+1});                                  //insert its index to output vector
           x++;                                              // "x" stores the count to keys allocated
           
       }   
        else
            out[m[s]].push_back(i+1);                               //adding the similar to output vector
        
    }
    return out;
}
