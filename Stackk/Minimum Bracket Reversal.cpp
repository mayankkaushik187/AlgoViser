int countBracketReversals(string str) {
	// Write your code here
    int n = str.size();
    if(n%2 != 0){
        return -1;
    }
    
    stack<int> s;
    for(int i = 0 ; i < n ; i++){
        if(str[i] == '{'){
            s.push(str[i]);
        }else if(str[i] == '}' and !s.empty() and s.top() == '{'){
            s.pop();
        }else if(str[i] == '}' and !s.empty() and s.top() == '}'){
         	s.push(str[i]);   
        }else if(str[i] == '}' and s.empty()){
            s.push(str[i]);
        }
    }
    
    int count = 0;
    while(!s.empty()){
        char c1 = s.top();s.pop();
        char c2 = s.top();s.pop();
        
        count += c1 == c2 ? 1 : 2;
    }
    return count;
}
