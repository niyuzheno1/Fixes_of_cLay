/*Fix the TLE issues related to get divsiors*/
/*Assumption: we have get our primes in p: psz = Prime(sqrt(MN)+10,p);*/
int get_factors(int x, int * fac, int * fs){
    int sz = 0;
    if(x%2 == 0){
        fac[sz] = 2;
        fs[sz] = 1;
        x/=2;
        while(x%2 == 0){
            x/=2;
            ++fs[sz];
        }
        ++sz;
    }
    rep(i,psz){
        if(p[i] == 2) continue;
        if(p[i]*p[i] > x) break;
        if(x % p[i] == 0){
            fac[sz] = p[i];
            fs[sz] = 1;
            x /= p[i];
            while(x % p[i] == 0){
                x /= p[i];
                ++fs[sz];
            }
            ++sz;
        }
    }
    if(x > 1){
        fac[sz] = x;
        fs[sz] = 1;
        ++sz;
    }
    return sz;
}
int getdivisor(int x, int * res){
    int * fc = new int[500];
    int * fs = new int[500];
    int fsz = get_factors(x, fc, fs);
    int sz = 0;
    res[sz++] = 1;
    rep(i,fsz){
        int s = sz;
        int k = s*fs[i];
        rep(j,k){
            res[sz++] = res[j]*fc[i];
        }
    }
    delete[] fc;
    delete[] fs;
    return sz;
}
