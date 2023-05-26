#include <bits/stdc++.h>
using namespace std;

string encryptcipher_matrixFence(string text, int key)
{
	char cipher_matrix[key][(text.length())];

	for (int counter=0; counter < key; counter++){
        for (int counter_lenght = 0; counter_lenght < text.length(); counter_lenght++){
            cipher_matrix[counter][counter_lenght] = '\n';
        }
	}

	bool directory_downward = false;
	int row = 0, column = 0;

	for (int counter=0; counter < text.length(); counter++){
		if (row == 0 || row == key-1){
            directory_downward = !directory_downward;
		}
		cipher_matrix[row][column++] = text[counter];
		directory_downward?row++ : row--;
	}

	string result;
	for (int counter=0; counter < key;counter++){
        for (int counter_lenght=0; counter_lenght < text.length(); counter_lenght++){
            if (cipher_matrix[counter][counter_lenght]!='\n'){
                result.push_back(cipher_matrix[counter][counter_lenght]);
            }
        }
	}
	return result;
}


string decryptcipher_matrixFence(string cipher, int key)
{
	char cipher_matrix[key][cipher.length()];

	for (int counter=0; counter < key; counter++){
        for (int counter_lenght=0; counter_lenght < cipher.length(); counter_lenght++){
            cipher_matrix[counter][counter_lenght] = '\n';
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

	string result;
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
            result.push_back(cipher_matrix[row][column++]);
		}
		directory_downward?row++: row--;
	}
	return result;
}

int main()
{
    string message,cipher_text,plain_text;
    int key;
    while(true){
        cout<<"\t\t-------- cipher_matrix Fence --------\t\t"<<endl<<endl;

        cout<<"Enter you'r message : ";
        getline(cin >> ws,message);
        cout<<"Enter the key : ";
        cin>>key;

        cipher_text = encryptcipher_matrixFence(message,key);
        plain_text = decryptcipher_matrixFence(cipher_text,key);

        cout<<endl<<"Original  Plain  Text: "<<message<<endl;
        cout<<"Encrypted Cipher Text: "<<cipher_text<<endl;
        cout<<"Decrypted Plain  Text: "<<plain_text<<endl<<endl;
    }
    return 0;
}
