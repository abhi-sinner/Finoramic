int Solution::braces(string A) {
   int n=A.length();
    stack<char> s;                              //Stack for storing the sub-expression
    
    for(int i=0;i<n;i++)
    {
        if(A[i]==')')                                 //the sub-expression ends here
        {
            int x=1;                                    //x as a flag
            char ch =s.top();                             
            s.pop();                                        //poping because a char will be always there for valid exp.
            
                                                           //loops untill starting of sub-exp.
            while(ch!='(')                                  
                {
                    if(ch=='+'||ch=='/'||ch=='*'||ch=='-')        //operands must be there for non-redundancy
                        x=0;      
                    ch=s.top();
                    s.pop();
                
                }
                if(x==1)                                        //no operands means redundant e.g. (a)
                return x;
        }
        else
           s.push(A[i]);                
          
    }   
    return 0;

}
