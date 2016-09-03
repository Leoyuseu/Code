// Write a function that takes a string as input and returns the string reversed.

// Example:
// Given s = "hello", return "olleh".

char* reverseString(char* s) {
    char * result = malloc((strlen(s)+1)*sizeof(char));
    memset(result,'\0',(strlen(s)+1)*sizeof(char));
    result += strlen(s)-1;
    while(*s != '\0'){
        *(result--) = *(s++);
    }
    result +=1;
    return result;
}

char* reverseString(char* s) {
	if(!s||!*s) return s;
	char* temp_s=s-1;
	char* s_point=s;
	while(*++temp_s);
	while(--temp_s>s){
	    *temp_s+=*s;
	    *s=*temp_s-*s;
	    *temp_s-=*s++;
	}
	return s_point;
}


//c++
class Solution {
public:
	string reverseString(string s) {
		string to_reverse;
		for (size_t i = s.size(); i > 0; --i)
		to_reverse.push_back(s.at(i - 1));
		return to_reverse;
	}
};