#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

main(){
	int n,cont=1,aux=0,r;
	cin>>n;
	vector <string> v1(n);
	vector <string> v2;
	for(int i=0;i<n;i++){
		cin>>v1[i];
	}
	for (int i=0;i<n;i++)
		for (int e=0;e<v1[i].size();e++){
			if (v1[i][e]>=65 && v1[i][e]<=90)
				v1[i][e]+=32;
		}
	for (int i=0;i<n;i++){
		if (v1[i][0]==v1[i][v1[i].size()-1])
			v2.push_back(v1[i]);
	}
	
	for(int i=0;i<v2.size();i++){
		cout<<v2[i]<<endl;
	}
}
