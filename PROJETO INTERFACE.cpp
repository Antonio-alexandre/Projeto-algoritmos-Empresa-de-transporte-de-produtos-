#include <iostream>
#include <cstring>

using namespace std;

float china (int frete)
{
	float freteinternacional;


	freteinternacional = 2;



	return freteinternacional;
}


int main()
{
	char pais1[50];
	char pais2[50];
	char uf1[50];
	char uf2[50];
	char cidade1[50];
	char cidade2[50];
	int x;
	float valor; // valor que retorna o preço do frete internacional

	cout << "------------------------------" << endl;
	cout << "PAIS - ORIGEM : " << endl;
	cin >> pais1;
	cout << "PAIS - DESTINO: " << endl;
	cin >> pais2;

	if (strcmp (pais1, pais2) == 0)
	{
		cout << "------------------------------" << endl;
		cout << "UF - ORIGEM : " << endl;
		cin >> uf1;
		cout << "UF - DESTINO : " << endl;
		cin >> uf2;
		cout << "------------------------------" << endl;
		cout << "CIDADE - ORIGEM : " << endl;
		cin >> cidade1;
		cout << "CIDADE - DESTINO : " << endl;
		cin >> cidade2;
	}

	else
	{
		cout << "------------------------------" << endl;
		cout << "UF - DESTINO : " << endl;
		cin >> uf2;
		cout << "CIDADE - DESTINO : " << endl;
		cin >> cidade2;
	}

	if (strcmp(pais2, "china") != 0)
	{
		valor = china(x);

		cout << valor << endl;
	}

	return 0;
}

// colocar o país escrito em extenso