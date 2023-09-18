#include <stdio.h> //biblioteca de comunica��o com o usu�rio.
#include <stdlib.h> //biclioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca resposavel por cuidar das strings

int registro() // Fun��o resposavel por cadastrar o usu�rios nos sistema
{
	//Inicio cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); // resposavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo valor da variavel
	fclose(file); // fecha o arquivo
	
	file= fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, ",");
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file= fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file= fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file= fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file= fopen(cpf,"r");
	
	if(file== NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}

	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Essas s�o as informa��es do usuario: ");
		printf("%s",conteudo);
		printf("\n\n");
	}

	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE* file;
	file = fopen(cpf,"r");
	
	if(file== NULL)
	{
		printf("Deletado com sucesso! O usu�rio n�o se encontra no sistema.\n");
		system("pause");
	}
	
	
}

int main()
    {
	int opcao=0; // Definindo as variaveis
	int laco=1;
	
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
		
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); // Inicio do MENU
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o:"); // Fim do MENU
	
		scanf("%d", &opcao); // Armazenando a escolha do usuario
	
		system("cls"); // resposavel por limpar a tela
		
		
		switch(opcao) //inicio da sele��o de menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta(); //chamada de fun��es
			break;
			
			case 3:
			deletar(); // chamda de fun��es
			break;
	
			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;
		}
	
	
    }
}
