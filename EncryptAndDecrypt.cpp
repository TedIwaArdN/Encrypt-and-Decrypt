#include<iostream>
#include<fstream>
using namespace std;
int main() {
	char ch;
	bool is_encrypt;								//true-encrypt, false-decrypt
	
	cout << "~~~~~~Hello, thanks for using encrypt or decrypt function!~~~~~~\n";
	cout << "~~~Please put your data in encrypt.txt if you want to encrypt~~~\n";
	cout << "~~~Please put your data in decrypt.txt if you want to decrypt~~~\n";
	
	while(cout << "Encrypt or Decrypt? (E/D)\n") {
		cin >> ch;
		if(ch == 'E' || ch == 'e') {
			is_encrypt = true;
			break;
		}
		if(ch == 'D' || ch == 'd') {
			is_encrypt = false;
			break;
		}
	}
	
	if(is_encrypt) {
		ifstream trueCode("truecode.txt");
		ofstream cryptogram("cryptogram.txt");
		cout << "Your cryptogram is: \n";
		int num = 0;
		while(trueCode.get(ch)) {
			if(trueCode.eof()) {
				break;
			}
			int num = (int)ch;
			cout << (9 - num % 10) << (9 - num % 100 / 10) << (9 - num / 100);
			cryptogram << (9 - num % 10) << (9 - num % 100 / 10) << (9 - num / 100);
		}
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~Don't forget it!~~~~~~~~~~~~~~~~~~~~~~~~\n";
		trueCode.close();
		cryptogram.close();
	}
	
	else {
		ifstream cryptogram("cryptogram.txt");
		ofstream trueCode("truecode.txt");
		cout<<"Your true code is: \n";
		int digit1, digit2, digit3;
		int num;
		while(1) {
			cryptogram.get(ch);
			digit3 = ch - '0';
			
			if(cryptogram.eof()) {
				break;
			}
			
			cryptogram.get(ch);
			digit2 = ch - '0';
			
			if(cryptogram.eof()) {
				break;
			}
			
			cryptogram.get(ch);
			digit1 = ch - '0';
			
			if(cryptogram.eof()) {
				break;
			}
			
			num = (9 - digit1) * 100 + (9 - digit2) * 10 + (9 - digit3);
			
			cout << (char)num;
			trueCode << (char)num;
		}
		cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~That's a secret!~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cryptogram.close();
		trueCode.close();
	}
	return 0;
}

