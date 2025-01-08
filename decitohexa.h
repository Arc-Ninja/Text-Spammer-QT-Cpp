#ifndef DECITOHEXA_H
#define DECITOHEXA_H

#endif // DECITOHEXA_H
#include <bits/stdc++.h>
using namespace std;
class decitohexa{
public:
    decitohexa(){
    }
    string converttohex(int i){
        int n = i;
        string rem= "";
        while(n!=0){
            if(n%16<10) rem+= to_string(n%16);
            else rem+=char(55+(n%16));
            n/=16;
        }
        reverse(rem.begin(), rem.end());
        return rem;
    }
};
