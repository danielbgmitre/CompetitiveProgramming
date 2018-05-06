#include <bits/stdc++.h>
using namespace std;

map<char, int> letras;

int main() {
	string entrada;
	cin >> entrada;

	for (char c : entrada){
		letras[c]++;
	}

	int impares = 0;
	for (pair<char, int> letra : letras){
		if (letra.second % 2 == 1) impares++;
	}

	if (impares <= 1 || impares % 2 == 1){
		printf("First\n");
	} else {
		printf("Second\n");
	}

	return 0;
}
