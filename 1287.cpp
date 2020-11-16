#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

int main() {
	string entrada, numero;
	double num;
	while(getline(cin, entrada)) {
		if(entrada.length()>0) {
			numero = "";
			for(int i=0;i<entrada.length();i++) {
				if(isdigit(entrada[i]))
					numero += entrada[i];
				else if(entrada[i] == 'o' or entrada[i] == 'O')
					numero +=  "0";
				else if(entrada[i] == 'l')
					numero += "1";
				else if(entrada[i]!=' ' and entrada[i] != ',') {
					i = entrada.length();
					numero = "";
				}
			}
			if(numero.length()>0){
				num = stod(numero);
				if(num <= 2147483647)
					cout << fixed << setprecision(0) << num << endl;
				else
					cout << "error" << endl;
			} else
				cout << "error" << endl;
		} else 
			cout << "error" << endl;
	}
	return 0;
}