#include <bits/stdc++.h>
using namespace std;
class Vigenere {
   public:
      string moded_key;

   Vigenere(string key) {
      for (int counter = 0; counter < key.size(); ++counter) {
         if (key[counter] >= 'A' && key[counter] <= 'Z')
            moded_key += key[counter];
         else if (key[counter] >= 'a' && key[counter] <= 'z')
            moded_key += key[counter] + 'A' - 'a';
      }
   }

   string encryption(string message) {
      string cipher_text;
      for (int i = 0, j = 0; i < message.length(); ++i) {
         char character = message[i];
         if(isblank(character)){
                cipher_text += character;
         }
         else{
              if (character >= 'a' && character <= 'z')
                 character += 'A' - 'a';
              else if (character < 'A' || character > 'Z')
                 continue;
              cipher_text += (character + moded_key[j] - 2 * 'A') % 26 + 'A';
              j = (j + 1) % moded_key.length();
             }
      }
      return cipher_text;
   }

   string decryption(string cipher_text) {
      string plain_text;
      for (int i = 0, j = 0; i < cipher_text.length(); ++i) {
         char character = cipher_text[i];
         if(isblank(character)){
                plain_text += character;
         }
         else{
             if (character >= 'a' && character <= 'z')
                character += 'A' - 'a';
             else if (character < 'A' || character > 'Z')
                continue;
             plain_text += (character - moded_key[j] + 26) % 26 + 'A';
             j = (j + 1) % moded_key.length();
         }
      }
      return plain_text;
   }
};

int main() {
    string key;
    string message;

    while(true){
        cout << "\t\t-------- VIGENERE CIPHER --------\t\t"<<endl;
        cout<<endl<<"Enter the key string : ";
        cin>>key;
        cout<<endl<<"Enter the message string : ";
        getline(cin >> ws ,message);

        Vigenere v(key);
        string encrypt = v.encryption(message);
        string decrypt = v.decryption(encrypt);

        cout <<endl<<"Original  Message: "<<message<< endl;
        cout << "Encrypted Message: " << encrypt << endl;
        cout << "Decrypted Message: " << decrypt << endl<<endl;
    }
    return 0;
}
