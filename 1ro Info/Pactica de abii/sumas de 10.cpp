#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

main(){
	int n,cont=0;
	cin>>n;
	vector <int> v1(n);
	for (int i=0;i<n;i++)
		cin>>v1[i];
	sort(v1.begin(),v1.end());
	for (int i=0;i<n-2;i++){
		if (v1[i]+v1[i+1]>v1[i+2])
			cont++;
	}
	cout<<cont;
}
