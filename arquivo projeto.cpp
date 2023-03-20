#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

int main()
{
	fstream arquivo;
	float aux;
	char uf1[10];
	char uf2[10];
	int x;

	cin >> uf1 >> uf2;
	
	strcat (uf1,uf2);
	
	x = strlen (uf1);
	
	uf1[x] = '.';
	uf1[x+1] = 't';
	uf1[x+2] = 'x';
	uf1[x+3] = 't';
	uf1[x+4] = '\0';
	

	arquivo.open(uf1); // como eu posso fazer pra ele abrir um arquivo 

	arquivo.seekg(arquivo.beg);

	arquivo >> aux;
	cout << fixed << setprecision(1) << aux << endl;


	arquivo.close();

	return 0;
}
