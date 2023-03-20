#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;


// FUNÇÃO DO CALCULO DO TEMPO DE ENTREGA
void tempo(int origem, float kilometragem, int &time, float &cubageminternacional, float peso, float volume)
{
	int contador;
	int conta;
	time = 3; //tempo padrão de coleta;
	if(origem == 1)
	{
		contador = kilometragem / 80; //conta em solo brasileiro dividindo km por 80 para ver quantas horas
		if(contador % 6 == 0) //se a conta for exata a conta dividio por 6 horas cada dia, entregará numero exato de dias
			conta = contador / 6;
		else //caso nao seja exata soma-se um dia para maior confiabilidade
		{
			conta = (contador / 6) + 1;
		}
		time = time + conta; //soma-se os dias basicos com a conta do caminhoneiro para o resultado final
	}

	else if(origem == 2)
	{
		time = 11; //tempo minimo somou-se 8 pois 2 dias de viagem, mais 6 de embarcacao coleta e tempos necessarios da coleta na origem america do norte e porto do Brasil
		contador = kilometragem / 80; //conta padrao em solo brasileiro
		if(contador % 6 == 0)
			conta = contador / 6;
		else
		{
			conta = contador / 6 + 1;
		}
		time = time + conta;
		cubageminternacional = volume * 167;
	}

	else if(origem == 3)
	{
		time = 13; //tempo minimo somou-se 10 pois 4 dias de viagem, mais 6 de embarcacao coleta e tempos necessarios da coleta na origem america do norte e porto do Brasil
		contador = kilometragem / 80;
		if(contador % 6 == 0)
			conta = contador / 6;
		else
		{
			conta = contador / 6 + 1;
		}

		time = time + conta;
		cubageminternacional = volume * 167;
	}

	else if(origem == 4)
	{
		time = 11; //tempo minimo somou-se 8 pois 2 dias de viagem, mais 6 de embarcacao coleta e tempos necessarios da coleta na origem Europa e porto do Brasil
		contador = kilometragem / 80; //conta padrao em solo brasileiro
		if(contador % 6 == 0)
			conta = contador / 6;
		else
		{
			conta = contador / 6 + 1;
		}
		time = time + conta;
		cubageminternacional = volume * 167;

	}

	else if(origem == 5)
	{
		time = 9; //tempo minimo somou-se 6 pois 1 dias de viagem, mais 5 de embarcacao coleta e tempos necessarios da coleta na origem America do sul e porto do Brasil
		contador = kilometragem / 80; //conta padrao em solo brasileiro
		if(contador % 6 == 0)
			conta = contador / 6;
		else
		{
			conta = contador / 6 + 1;
		}
		time = time + conta;
		cubageminternacional = volume * 167;

	}
}


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


// FUNÇÃO DO CÁLCULO DA ENTREGA TERCEIRIZADA
float valor(float gasto, float pesoc, int eterceirizada, float cubageminternacional)
{
	float valortotal;

	if(eterceirizada == 1) // 1 = 7,50 | 2 = 15,00
	{
		valortotal = gasto + pesoc + cubageminternacional + 7.50 + 0.10 * (7.50 + pesoc + gasto + cubageminternacional);
	}
	else if(eterceirizada == 2)
	{
		valortotal = gasto + pesoc + cubageminternacional + 15 + 0.10 * (15 + pesoc + gasto + cubageminternacional);
	}

	return valortotal;
}


// INT MAIN


int main()
{

// menu
	int saida;

// variaveis do caminhoneiro
	float gasto;

// variaveis relacionadas ao produto
	float peso; // PESO EM KG
	float volume; // VOLUME EM M^3
	float pesocubado;
	float cubageminternacional;
	float porcentagem; // PORCENTAGEM DE OCUPAÇÃO DO PRODUTO DENTRO DA CAPACIDADE TOTAL

// variaveis relacionadas ao cálculo da distância
	fstream arquivo;
	float km;
	float aux;
	char uf1[10];
	char uf2[10];
	char uf3[10];
	char cidade[50];
	char cidade2[50];
	int x;
	int paisorigem;
	int time;

//variaveis relacionadas ao cálculo do preço
	float vtotal;
	float lucro;
	int eterceirizada;


// ENTRADA E LEITURA DE DADOS
	// DADOS PARA CÁLCULO DA CUBAGEM
	while (saida != 2)
	{
		system("CLS");
		cubageminternacional = 0;


		cout << "------------------------------------------------------" << endl;
		cout << "                     UAILOG                             " << endl;
		cout << "------------------------------------------------------" << endl;
		cout << "DIGITE O PESO E O VOLUME DA CARGA" << endl;
		cin >> peso >> volume;
		pesocubado = fretepeso(peso, volume); // calcula o valor do frete peso em reais

		porcentagem = (pesocubado / 6000);


		// DADOS PARA CÁLCULO DA DISTÂNCIA

		cout << "" << endl;	 //apresentando opcoes
		cout << "1 --> BRASIL ----------------------------------" << endl;
		cout << "2 --> AMERICA DO NORTE ------------------------" << endl;
		cout << "3 --> ASIA ------------------------------------" << endl;
		cout << "4 --> EUROPA ----------------------------------" << endl;
		cout << "5 --> AMERICA DO SUL --------------------------" << endl;
		cout << "" << endl;

		do
		{
			cout << "" << endl;
			cout << "-----ESCOLHA QUAL REGIAO OU PAIS DE ORIGEM-----" << endl;
			cout << "" << endl;
			cin >> paisorigem;
		}
		while(paisorigem != 1 && paisorigem != 2 && paisorigem != 3 && paisorigem != 4 && paisorigem != 5);  //critica para escolher de 1 a 5


		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//AO ESCOLHER ALGUMA REGIAO FORA DO BRASIL, DEIXA PRE-ESCOLHIDO O UF1 COMO PARANÁ OU PR

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		cout << "------------------------------" << endl;
		cout << "     DIGITE APENAS A SIGLA    " << endl;
		cout << "------------------------------" << endl;
		cout << "UF - ORIGEM : " << endl;
		if (paisorigem != 1)
		{
			strcpy (uf1, "pr");
			cout << uf1 << endl;;
		}
		else
		{
			cin >> uf1 ;
		}
		cout << "UF - DESTINO : " << endl;
		cin >> uf2;

		cout << "---------------------------------------------" << endl;
		cout << "DIGITE EM MINUSCULO, E DE ESPACO SE PRECISAR" << endl;
		cout << "---------------------------------------------" << endl;
		cout << "CIDADE - ORIGEM : " << endl;
		cin.ignore();
		if (paisorigem != 1)
		{
			strcpy (cidade, "curitiba");
			cout << cidade << endl;
		}

		else
		{
			cin.getline (cidade, 50);
		}
		cout << "CIDADE - DESTINO : " << endl;
		cin.getline (cidade2, 50);

		strcpy (uf3, uf1); // PASSO A UF1 PARA UF3, POIS VOU PRECISAR MAIS PRA FRENTE NO CÓDIGO DA SIGLA DA UF1

		strcat (uf1, uf2); // UNE AS DUAS UFS, PARA ENCONTRAR ARQUIVO COM ESSE NOME

		x = strlen (uf1); // SABENDO O TAMANHO DA STRING, POSSO COLOCAR .TXT DEPOIS PARA CONSEGUIR ABRIR O ARQUIVO

		uf1[x] = '.';
		uf1[x + 1] = 't';
		uf1[x + 2] = 'x';
		uf1[x + 3] = 't';
		uf1[x + 4] = '\0';


		arquivo.open(uf1, ios :: in); // ABRIR O ARQUIVO CUJO NOME É A JUNÇÃO DAS DUAS STRINGS

		arquivo.seekg(arquivo.beg); // CURSOR NO INICIO

		arquivo >> aux;
		arquivo.close();

		km = aux; // O DADO DENTRO DO ARQUIVO É A KM ENTRE AS CAPITAIS DAS UFS, LOGO A VARIÁVEL KM RECEBE ESSE VALOR


		// CALCULO DO TEMPO

		tempo (paisorigem, km, time, cubageminternacional, peso, volume);


		// CUBAGEM INTERNACIONAL
		cubageminternacional = (cubageminternacional * 10); // cubagem internacional = 0 caso a região seja brasil


		//GASTO CAMINHONEIRO

		gasto = km * porcentagem * 3.0; // KILOMETRAGEM  * 3 REAIS POR KM * PORCENTAGEM DE OCUPAÇÃO


		// TAXAS (10% sobre o valor de custo)

		if (strcmp (cidade2, cidade) == 0 || strcmp (uf3, uf2) == 0 || strcmp(uf2, "mg") == 0 && strcmp (cidade2, "belo horizonte") == 0 || strcmp(uf2, "sp") == 0 && strcmp (cidade2, "sao paulo") == 0 || strcmp(uf2, "rj") == 0 && strcmp (cidade2, "rio de janeiro") == 0 || strcmp(uf2, "es") == 0 && strcmp (cidade2, "vitoria") == 0 || strcmp(uf2, "pr") == 0 && strcmp (cidade2, "curitiba") == 0 || strcmp(uf2, "sc") == 0 && strcmp (cidade2, "floarianopolis") == 0 || strcmp(uf2, "rs") == 0 && strcmp (cidade2, "porto alegre") == 0 || strcmp(uf2, "ms") == 0 && strcmp (cidade2, "campo grande") == 0 || strcmp(uf2, "mt") == 0 && strcmp (cidade2, "cuiaba") == 0 || strcmp(uf2, "go") == 0 && strcmp (cidade2, "goiania") == 0 || strcmp(uf2, "df") == 0 && strcmp (cidade2, "brasilia") == 0 || strcmp(uf2, "ro") == 0 && strcmp (cidade2, "porto velho") == 0 || strcmp(uf2, "ac") == 0 && strcmp (cidade2, "rio branco") == 0 || strcmp(uf2, "am") == 0 && strcmp (cidade2, "manaus") == 0 || strcmp(uf2, "rr") == 0 && strcmp (cidade2, "boa vista") == 0 || strcmp(uf2, "pa") == 0 && strcmp (cidade2, "belem") == 0 || strcmp(uf2, "ap") == 0 && strcmp (cidade2, "macapa") == 0 || strcmp(uf2, "to") == 0 && strcmp (cidade2, "palmas") == 0 || strcmp(uf2, "ma") == 0 && strcmp (cidade2, "sao luis") == 0 || strcmp(uf2, "pi") == 0 && strcmp (cidade2, "teresina") == 0 || strcmp(uf2, "ba") == 0 && strcmp (cidade2, "salvador") == 0 || strcmp(uf2, "ce") == 0 && strcmp (cidade2, "fortaleza") == 0 || strcmp(uf2, "rn") == 0 && strcmp (cidade2, "natal") == 0 || strcmp(uf2, "pb") == 0 && strcmp (cidade2, "joao pessoa") == 0 || strcmp(uf2, "pe") == 0 && strcmp (cidade2, "recife") == 0 || strcmp(uf2, "al") == 0 && strcmp (cidade2, "maceio") == 0 || strcmp(uf2, "se") == 0 && strcmp (cidade2, "aracaju") == 0)
			eterceirizada = 1; // se a pessoa mora na cidade do cdd, ou for da mesma cidade de origem, paga apenas 7,50 pela entrega terceirizada

		else
			eterceirizada = 2; // se a pessoa não mora na cidade do cdd, paga 15 pela entrega terceirizada

		vtotal = valor(gasto, pesocubado, eterceirizada, cubageminternacional); //encaminha para a função que calcula o valor total

		lucro = vtotal * 0.20; //CÁLCULO DO LUCRO (20% do total)


		// SAÍDA DE DADOS
		cout << fixed << setprecision(1) << "O valor final e de " << vtotal + lucro << " reais" << " e a entrega sera feita em " << time << " dias" << endl;

		cout << "-----------------------------------------------------------------------------------------------" << endl;
		cout << "DESEJA FAZER OUTRO CALCULO DE FRETE? (1- SIM     2 - NAO)                                      " << endl;
		cin >> saida;
	}
	system("CLS"); // LIMPA A TELA
	cout << "----------------------------------------" << endl;
	cout << "OBRIGADO PELA PREFERENCIA!" << endl;
	cout << "        UAILOG            " << endl;
	cout << "----------------------------------------" << endl;

	return 0;
}
