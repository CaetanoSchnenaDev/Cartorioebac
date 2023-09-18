#include <stdio.h> //biblioteca de comunicação com o usuário.
#include <stdlib.h> //biclioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca resposavel por cuidar das strings

int registro() // Função resposavel por cadastrar o usuários nos sistema
{
	//Inicio criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
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
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}

	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Essas são as informações do usuario: ");
		printf("%s",conteudo);
		printf("\n\n");
	}

	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE* file;
	file = fopen(cpf,"r");
	
	if(file== NULL)
	{
		printf("Deletado com sucesso! O usuário não se encontra no sistema.\n");
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
	
		printf("### Cartório da EBAC ###\n\n"); // Inicio do MENU
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção:"); // Fim do MENU
	
		scanf("%d", &opcao); // Armazenando a escolha do usuario
	
		system("cls"); // resposavel por limpar a tela
		
		
		switch(opcao) //inicio da seleção de menu
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta(); //chamada de funções
			break;
			
			case 3:
			deletar(); // chamda de funções
			break;
	
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
		}
	
	
    }
}
