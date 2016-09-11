#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

void findrect(const vector<int> xarr, const vector<int> yarr, vector<vector<int>> &rect){
	int x1, y1, x2, y2;
	if(xarr.size() < 2) return;
	x1 = *min_element(xarr.begin(), xarr.end());
	y1 = *min_element(yarr.begin(), yarr.end());
	x2 = *max_element(xarr.begin(), xarr.end());
	y2 = *max_element(yarr.begin(), yarr.end());
	if(x1 == x2 || y1 == y2) return;
	vector<int> temp;
	temp.push_back(x1);
	temp.push_back(y1);
	temp.push_back(x2);
	temp.push_back(y2);
	rect.push_back(temp);
	return;
}

int main(){
	string input;
	vector<int> xarray;
	vector<int> yarray;
	vector<vector<int>> rect;
	while(getline(cin, input)){
		int x = 0, y = 0;
		for(size_t i = 0; i < input.size(); ++i){
			if(!isspace(input[i])){
				x = x*10 + input[i] - '0';
			}
			else{
				for(size_t j = i + 1; j < input.size(); ++j)
					y = y*10 + input[j] - '0';
				break;
			}
		}
		if (x>1000||x<-1000||y>1000||y<-1000) {  
            return 0;  
        }
		if(x == 0 && y== 0){
			if(xarray.empty())
				break;
			else{
				findrect(xarray, yarray, rect);
				xarray.clear();
				yarray.clear();
			}
		}
		else{
			xarray.push_back(x);
			yarray.push_back(y);
		}
	}
	for(vector<vector<int>>::iterator it = rect.begin(); it != rect.end(); ++it){
		vector<int>::iterator it1 = (*it).begin();
		for(; it1 != (*it).end() - 1; ++it1){
			cout << *it1 << " ";
		}
		cout << *it1 << endl;
	}
	return 0;
}



//问题在输入格式上
#include<iostream>  
#include<vector>  
#include<algorithm>  
using namespace std;  
int rect(vector<int>&vx, vector<int>&vy)  
{  
    if ((vx.size()==1&&vy.size()==1)||(vx.size()==0&&vy.size()==0))  
    {  
        return 0;  
      
    }  
    else  
    {  
        sort(vx.begin(),vx.end());  
        sort(vy.begin(),vy.end());  
        int x1=vx[0];  
        int y1=vy[0];  
        int x2=vx[vx.size()-1];  
        int y2=vy[vy.size()-1];  
        if (x1==x2||y1==y2||(x1==0&&y1==0)||(x2==0&&y2==0))  
        {  
            return 0;  
        }  
       cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;  
       vx.clear();  
       vy.clear();  
    }  
}  
int main()  
{  
    vector<int>vx,vy;  
    int x,y;  
    while (cin>>x>>y)  
    {  
        if (x>1000||x<-1000||y>1000||y<-1000)  
        {  
            return 0;  
        }  
        if (x==0&&y==0)  
        {  
            rect(vx,vy);  
        }  
        else  
        {  
            vx.push_back(x);  
            vy.push_back(y);  
        }  
    }  
}  