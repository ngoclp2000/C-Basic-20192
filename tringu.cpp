#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
main(){
	ll n,t;
	cin >> t;
	while(t--){
		cin >> n;
		int a = 0, check = 1;
		for(int i = 2; i <= n; i++){
			if(n % i == 0){
				a ++;
				int dem = 0;
				while(n % i == 0){
					n = n / i;
					dem ++;
				}
				if(dem > 1){
					check = 0;
					break;
				} 
			}	
		}
		if((a == 3) && (check == 1)) cout << "1\n";
        else cout << "0\n";
	}
}
