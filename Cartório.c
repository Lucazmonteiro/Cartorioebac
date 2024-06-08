#include <stdio.h> //biblioteca de comunicação com o usúario
#include <stdlib.h> //biblioteca de espaço em memória
#include <locale.h> //biblioteca de aloçaões de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função respónsavel por cadastrar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); // Definindo o idioma
	
	//Início criação de variáveis/string
	char arquivo[40];		//Toda vez que cadastrar um cpf ele vai ser salvo como um novo arquivo com o numero de cpf diferente
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: ");   //Coletando informação do usário
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);   //Responsável por copiar os valores das string
	
	FILE *file;   //Cria o arquivo
	file = fopen(arquivo, "w");  //Cria o arquivo e o "w" significa "Para escrever"
	fprintf(file,"CPF: %s \n", cpf); // Salva o valor da variável
	fclose(file);  //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");   //Esse "a" quer dizer que o nome do arquivo que está sendo salvo vai atualizar
	fprintf(file, "Nome: %s \n", nome);  //Aqui é o que será escrito e implementado na nova atualização
	fclose(file);  //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");     //Esse "a" quer dizer que o nome do arquivo que está sendo salvo vai atualizar
	fprintf(file, "Sobrenome: %s \n", sobrenome);   //Aqui é o que será escrito e implementado na nova atualização
	fclose(file);    //Fecha o arquivo

	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");     //Esse "a" quer dizer que o nome do arquivo que está sendo salvo vai atualizar
	fprintf(file,"Cargo: %s \n", cargo);    //Aqui é o que será escrito e implementado na nova atualização
	fclose(file);    //Fecha o arquivo
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo o idioma
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\nO número de CPF pesquisado não pode ser localizado! \n");	
	}
	else
	{
		printf("\nEsses são os dados do CPF: \n\n");
		while(fgets(conteudo, 200, file) != NULL)
	{	
		printf("%s", conteudo);
	}
		fclose(file);
	}
	printf("\n");
	system("pause");
  	
}
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!. \n");
		system("pause");
	}
	else
	{
	printf("Usuário deletado!. ");
	system("pause");	
	}
}

int main()
{
	int opcao=0;		//Definindo as variáveis
	int laco=1;
	
	for (laco=1; laco=1;)
	{
		system ("cls");  //Responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); // Definindo o idioma
		printf("### Cartório da EBAC ###\n\n");  //Inicio do menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: ");    // Fim do menu
	
		scanf("%d", &opcao);   //Armazenando a escolha do usúario
		system("cls");
		
		switch(opcao)   //Início da seleção do menu
		{	
			case 1:
			registro();   //Chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;   //Pra sair do sistema e encerrar o programa!!!
			break;
			
			default:
			printf("Essa opção é invalida! \n");
			system("pause");
			break;	//Fim da seleção
		}
	}
}

