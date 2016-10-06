const int size = 1e6 + 9;
int phi[size],chk[size];
void preprocess(void)
{
    int i, j;
   
    for(i=1 ; i<size ; i++)
    {
        phi[i]=i;
        chk[i]=1;
    }
    for(i=2 ; i<size ; i++)
    {
        if(chk[i]==1)
        {
            	for(j = i;j<=size;j++){
			chk[j]=0;
			phi[j] /=i;
			phi[j] *= i-1;
		}
        }
    }
}

