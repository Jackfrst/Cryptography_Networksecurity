#include <bits/stdc++.h>
using namespace std;

string chypher(string msg,int key){
    int length = msg.length();
    for(int counter = 0; counter < msg.length(); counter = counter+1){
        if(isblank(msg[counter])){
            //ignoring blank space
            msg[counter] = msg[counter];
        }
        else{
            char casetest = msg[counter];
            msg[counter] = msg[counter] + key;
            if(msg[counter] > 'Z' && isupper(casetest)){
                msg[counter] = ((( msg[counter] % 'Z') + 'A') - 1);
            }
            else if(msg[counter] > 'z' && islower(casetest)){
                msg[counter] = ((( msg[counter] % 'z') + 'a') - 1);
            }
        }
    }
    return msg;
}

string dechypher(string msg,int key){
    int length = msg.length();
    for(int counter = 0; counter < msg.length(); counter = counter+1){
        if(isblank(msg[counter])){
            //ignoring blank space
            msg[counter] = msg[counter];
        }
        else{
            char casetest = msg[counter];
            msg[counter] = msg[counter] - key;
            if(msg[counter] < 'A' && isupper(casetest)){
                msg[counter] = ((( msg[counter] % 'A') + 26));
            }
            else if(msg[counter] < 'a' && islower(casetest)){
                msg[counter] = ((( msg[counter] % 'a') + 26));
            }
        }
    }
    return msg;
}

int main(){
    string msg;
    int key;

    cout<<"Enter the Message to be encrypted :"<<endl;
    getline(cin,msg);
    cout<<"Enter the Key to be encrypted :"<<endl;
    cin>>key;

    string cyphertext = chypher(msg,key);
    cout<<endl<<"The cypher text is :"<<endl;
    cout<<cyphertext<<endl;

    string decypheredtext = dechypher(cyphertext,key);
    cout<<endl<<"The decyphered text is :"<<endl;
    cout<< decypheredtext<<endl;


    return 0;
}
