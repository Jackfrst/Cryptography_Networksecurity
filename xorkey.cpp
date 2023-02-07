#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int * cypher(int incat[11]){
    int cypherkey[11] = {1,0,0,1,1,1,0,0,0,1,1};
    static int cyphercode[11];

    for(int i = 0; i < 11; i++){
        if(incat[i] == cypherkey[i]){
            cyphercode[i] = 1;
        }
        else{
            cyphercode[i] = 0;
        }
        printf("%d  ",cyphercode[i]);
    }

    return cyphercode;
}

int main(){
    int incat[11] = {1,1,0,0,1,0,1,0,1,1,0};

    printf("PlainInput CODE: ");
    for(int i = 0; i < 11; i++){
        printf("%d  ",incat[i]);
    }
    printf("\n");

    printf("Encrypted CODE: ");
    int * p;
    p = cypher(incat);
    printf("\n");

    printf("Decrypted CODE: ");
    cypher(p);
    printf("\n");
    return 0;
}
