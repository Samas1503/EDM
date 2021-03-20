#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	string p;
	int a;
	cin>>p;
	cin>>a;
    p[a-1]='X';
	cout<<p;
}
