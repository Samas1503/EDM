#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
main(){
	int n;
	cin>>n;
	bool band=true;;
	vector <int> v1(n);
	vector <bool> v2(n);
	for (int i=0;i<n;i++){
		v1[i]=i+1;
	}
	for (int i=0;i<n;i++){
		for(int e=2;e<n;e++){
				if (v1[i]%e==0) band=false;
			if(band==true)
				v2[i]=v1[i];
	}
}
	for (int i=0;i<n;i++){
		cout<<v2[i]<<endl;
	}
}
	
