// Compare Version Numbers 

// Compare two version numbers version1 and version2.
// If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

// You may assume that the version strings are non-empty and contain only digits and the . character.
// The . character does not represent a decimal point and is used to separate number sequences.
// For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

// Here is an example of version numbers ordering:

// 0.1 < 1.1 < 1.2 < 13.37

#include <iostream>
#include <string>
#include <vector> 
using namespace std;

//clever!!! using  ##istringstream##
class Solution {
public:
    int compareVersion(string version1, string version2) {
        for(auto& w : version1) if (w == '.') w=' ';
        for(auto& w : version2) if (w == '.') w=' ';
        istringstream s1(version1), s2(version2);
        while(1) {
            int n1,n2;
            if (!(s1 >> n1) ) n1 = 0;
            if (!(s2 >> n2) ) n2 = 0;
            if (! s1 && ! s2) return 0;
            if (n1<n2) return -1;
            if (n1>n2) return 1;
        }
    }
};

//ver1.0 "10.6.5", "10.6" wrong when there are more than one '.' in a version
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int firstVer1, firstVer2;
        int secondVer1 = 0, secondVer2 = 0;    
        size_t dot1 = version1.find('.');
        size_t dot2 = version2.find('.');
        cout<<dot1<<" "<<dot2<<endl; 
        if(dot1 != string::npos) {
            firstVer1 = stoi(version1.substr(0, dot1));
            secondVer1 = stoi(version1.substr(dot1 + 1));
        }
        else firstVer1 = stoi(version1);
        if(dot2 != string::npos){
            firstVer2 = stoi(version2.substr(0, dot2));
            secondVer2 = stoi(version2.substr(dot2 + 1));
        }
        else firstVer2 = stoi(version2);
        cout<<firstVer1<<" "<<secondVer1<<" "
        	<<firstVer2<<" "<<secondVer2<<endl;
        if(firstVer1 > firstVer2){
            return 1;
        }
        else if(firstVer2 > firstVer1){
            return -1;
        }
        else{
            if(secondVer1 > secondVer2){
                return 1;
            }
            else if(secondVer2 > secondVer1){
                return -1;
            }
            else return 0;
        }
    }
};

//correct solution
class Solution {
public:
    int compareVersion(string version1, string version2) {
        //const int N = 5;
        vector<int> nums1;//(N, 0);
        vector<int> nums2;//(N, 0);
        
        int start = 0;
        int index = 0;
        for(int i = 0; i < version1.size(); ++i){
            if(version1[i] == '.'){
                //nums1[index] = (stoi(version1.substr(start ,i)));
                nums1.push_back(stoi(version1.substr(start ,i)));
				start = i + 1;
                //++index;
            }
        }
        //nums1[index] = (stoi(version1.substr(start)));
        nums1.push_back(stoi(version1.substr(start)));
        
        start = 0;
        index = 0;
        for(int i = 0; i < version2.size(); ++i){
            if(version2[i] == '.'){
                nums2.push_back(stoi(version2.substr(start ,i)));
                start = i + 1;
                ++index;
            }
        }
        nums2.push_back(stoi(version2.substr(start)));

		int l1 = nums1.size();
		int l2 = nums2.size();
		if(l1 > l2){
			for(int i = 0; i < l1 - l2; ++i){
				nums2.push_back(0);
			}
		}
		if(l2 > l1){
			for(int i = 0; i < l2 - l1; ++i){
				nums1.push_back(0);
			}
		}
        //for(int i = 0; i < N; ++i){
        if(nums1 > nums2) return 1;
        else if(nums2 > nums1) return -1;
        //}
        else return 0;
    }
};

int main(){
	Solution st;
	string v1 = "10.6.5";
	string v2 = "10.6";
	cout << st.compareVersion(v1, v2) << endl;
	cout << st.compareVersion("1.0", "1")<<endl;
	cout << st.compareVersion("0.9.9.9.9.9.9.9.9.9.9.9.9", "1.0");

}
