#include <bits/stdc++.h>
using namespace std;

string encryptcipher_matrixFence(string plain_text, int key)
{
	char cipher_matrix[key][(plain_text.length())];

	for (int counter=0; counter<key; counter++){
        for (int counter_lenght = 0; counter_lenght < plain_text.length(); counter_lenght++){
            cipher_matrix[counter][counter_lenght] = '+';
        }
	}

	bool directory_downward = false;
	int row = 0, column = 0;

	for (int counter=0; counter<plain_text.length(); counter++){
		if (row == 0 || row == key-1){
            directory_downward = !directory_downward;
		}
		cipher_matrix[row][column++] = plain_text[counter];
		directory_downward ? row++ : row--;
	}

	string cipher_text;
	for (int counter=0; counter<key; counter++){
        for (int counter_lenght=0; counter_lenght<plain_text.length(); counter_lenght++){
            if (cipher_matrix[counter][counter_lenght]!='+'){
                cipher_text.push_back(cipher_matrix[counter][counter_lenght]);
            }
        }
	}
	return cipher_text;
}

string decryptcipher_matrixFence(string cipher, int key)
{
	char cipher_matrix[key][cipher.length()];

	for (int counter=0; counter < key; counter++){
        for (int counter_lenght=0; counter_lenght < cipher.length(); counter_lenght++){
            cipher_matrix[counter][counter_lenght] = '+';
        }
	}

	bool directory_downward;
	int row = 0, column = 0;

	for (int counter=0; counter < cipher.length(); counter++){
		if (row == 0){
            directory_downward = true;
        }
		if (row == key-1){
            directory_downward = false;
		}
		cipher_matrix[row][column++] = '*';
        directory_downward?row++ : row--;
	}


	int index = 0;
	for (int counter=0;counter<key; counter++){
        for (int counter_lenght=0; counter_lenght<cipher.length(); counter_lenght++){
            if (cipher_matrix[counter][counter_lenght] == '*' && index<cipher.length()){
                cipher_matrix[counter][counter_lenght] = cipher[index++];
            }
        }
	}

	string plain_text;
    row = 0, column = 0;

	for (int counter=0; counter< cipher.length(); counter++)
	{
		if (row == 0){
            directory_downward = true;
		}
		if (row == key-1){
            directory_downward = false;
		}
		if (cipher_matrix[row][column] != '*'){
            plain_text.push_back(cipher_matrix[row][column++]);
		}
		directory_downward?row++: row--;
	}
	return plain_text;
}

int main(){
    string message,cipher_text,plain_text;
    int key;
    while(!(message == "stop" && key == -1)){
        cout<<"\t\t -------------- Rail Fence Cipher --------------\t\t"<<endl<<endl;

        cout<<"Enter you'r message : ";
        getline(cin >> ws,message);
        cout<<"Enter the key : ";
        cin>>key;

        if(message == "stop" && key == -1){
            break;
        }

        cipher_text = encryptcipher_matrixFence(message,key);
        plain_text = decryptcipher_matrixFence(cipher_text,key);

        cout<<endl<<"Original  Plain  Text: "<<message<<endl;
        cout<<"Encrypted Cipher Text: "<<cipher_text<<endl;
        cout<<"Decrypted Plain  Text: "<<plain_text<<endl<<endl;

        cout<<"Help Note : \t-------- message: stop & key:-1 to exit ---------\t\t"<<endl<<endl<<endl;
    }
    return 0;
}
