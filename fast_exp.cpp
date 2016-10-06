ll fast_exp(ll base, ll exp){
	ll res = 1;
	while(exp>0){
		if(exp&1) res = ((res%M)*(base%M))%M;
		base = ((base%M)*(base%M))%M;
		exp>>=1;
	}
	return res%M;
}
