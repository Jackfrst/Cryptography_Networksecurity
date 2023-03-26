#include <bits/stdc++.h>
using namespace std;
unordered_map<char,char> hashMap;

string encrypt(string msg)
{
  string ciphertext;
  for(int counter=0; counter<msg.size(); counter++)
  {
    if(isblank(msg[counter])){
        ciphertext.push_back(msg[counter]);
    }
    else{
        ciphertext.push_back(hashMap[msg[counter]]);
    }
  }

  return ciphertext;
}

string decrypt(string msg)
{
  string plaintext;
  for(int counter=0; counter<msg.size(); counter++)
  {
    if(isblank(msg[counter])){
        plaintext.push_back(msg[counter]);
    }
    else{
        plaintext.push_back(hashMap[msg[counter]]);
    }
  }

  return plaintext;
}

void hashFn(string alphabet, string substitution)
{
  hashMap.clear();
  for(int counter=0; counter<alphabet.size(); counter++)
  {
    hashMap.insert(make_pair(alphabet[counter],substitution[counter]));
  }
}

string mod_message(string message){
    string moded_message;
    for(int counter = 0;counter<message.length();counter++){
        moded_message.push_back(tolower(message[counter]));
    }
    return moded_message;
}

int main()
{
    while(true){
        cout << "\t\t-------- MONO ALPHABETIC CIPHER --------\t\t"<<endl;

        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        string substitution = "qwertyuiopasdfghjklzxcvbnm";
        hashFn(alphabet, substitution);

        string message;
        cout<<endl<<"Enter the message string : ";
        getline(cin >> ws ,message);

        cout<<endl<<"Original  Plain  Text: "<<message<<endl;
        string alt_message = mod_message(message);
        string cipher = encrypt(alt_message);

        cout<<"Encrypted Cipher Text: "<<cipher<<endl;

        hashFn(substitution, alphabet);
        string plain = decrypt(cipher);
        cout<<"Decrypted Plain  Text: "<<plain<<endl<<endl;
    }
    return 0;
}
