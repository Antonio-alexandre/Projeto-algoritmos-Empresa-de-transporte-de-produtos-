#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;


// FUNÇÃO DO CÁLCULO DO PESO CUBADO, PORCENTAGEM E PREÇO DE CARGA OCUPADA
float fretepeso (float peso2, float volume2)
{
	float cubagem; // calculo da cubagem

	cubagem = volume2 * 300;

	if (cubagem > peso2)
	{
		cubagem = cubagem * 10;
		return cubagem;
	}

	else
	{
		peso2 = peso2 * 10;
		return peso2;
	}
}

int main()
{
// ENTRADA DE DADOS 
// variaveis do caminhoneiro
	float gasto;
	
// variaveis relacionadas ao produto
	float peso; // PESO EM KG
	float volume; // VOLUME EM M^3
	float pesocubado;
	float porcentagem; // PORCENTAGEM DE OCUPAÇÃO DO PRODUTO DENTRO DA CAPACIDADE TOTAL
	
// variaveis relacionadas ao cálculo da distância
	fstream arquivo;
	float km;
	float aux;
	char uf1[10];
	char uf2[10];
	int x;

// entrada de dados do produto

	cin >> peso >> volume;
	pesocubado = fretepeso(peso, volume); // calcula o valor do frete peso em reais

	porcentagem = pesocubado/
	
	
// entrada de dados para cálculo da distância
	
	

	cin >> uf1 >> uf2;

	strcat (uf1, uf2);

	x = strlen (uf1);

	uf1[x] = '.';
	uf1[x + 1] = 't';
	uf1[x + 2] = 'x';
	uf1[x + 3] = 't';
	uf1[x + 4] = '\0';
	

	arquivo.open(uf1); // como eu posso fazer pra ele abrir um arquivo

	arquivo.seekg(arquivo.beg);

	arquivo >> aux;
	cout << fixed << setprecision(1) << aux << endl;


	arquivo.close();
	
	km = aux;


// CALCULADA A PORCENTAGEM, DEFINIR QUAL É O VALOR GASTO DO CAMINHONEIRO

//Agora que temos a porcentagem ocupada, e a km, podemos calcular o gasto do caminhoneiro

	gasto = km * porcentagem * 3.00;


// TAXAS (10% sobre o valor de custo)
// ENTREGA TERCEIRIZADA (7,5 REAIS SE FOR DA REGIÃO METROPOLITANA, 15 SE NÃO FOR)
// LUCRO: 20% DO VALOR FINAL ENCONTRADO


// PREÇO FINAL =





	return 0;
}









// ideia: criar arquivos cujos nomes sejam os dos estados, sendo assim, lá dentro está a informação com o valor que eu preciso, e a única coisa a fazer é usar essa kilometragem pra posteriores cálculos
