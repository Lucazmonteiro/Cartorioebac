#include <stdio.h> //biblioteca de comunica��o com o us�ario
#include <stdlib.h> //biblioteca de espa�o em mem�ria
#include <locale.h> //biblioteca de alo�a�es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o resp�nsavel por cadastrar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); // Definindo o idioma
	
	//In�cio cria��o de vari�veis/string
	char arquivo[40];		//Toda vez que cadastrar um cpf ele vai ser salvo como um novo arquivo com o numero de cpf diferente
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: ");   //Coletando informa��o do us�rio
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);   //Respons�vel por copiar os valores das string
	
	FILE *file;   //Cria o arquivo
	file = fopen(arquivo, "w");  //Cria o arquivo e o "w" significa "Para escrever"
	fprintf(file,"CPF: %s \n", cpf); // Salva o valor da vari�vel
	fclose(file);  //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");   //Esse "a" quer dizer que o nome do arquivo que est� sendo salvo vai atualizar
	fprintf(file, "Nome: %s \n", nome);  //Aqui � o que ser� escrito e implementado na nova atualiza��o
	fclose(file);  //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");     //Esse "a" quer dizer que o nome do arquivo que est� sendo salvo vai atualizar
	fprintf(file, "Sobrenome: %s \n", sobrenome);   //Aqui � o que ser� escrito e implementado na nova atualiza��o
	fclose(file);    //Fecha o arquivo

	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");     //Esse "a" quer dizer que o nome do arquivo que est� sendo salvo vai atualizar
	fprintf(file,"Cargo: %s \n", cargo);    //Aqui � o que ser� escrito e implementado na nova atualiza��o
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
		printf("\nO n�mero de CPF pesquisado n�o pode ser localizado! \n");	
	}
	else
	{
		printf("\nEsses s�o os dados do CPF: \n\n");
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
	
	printf("Digite o CPF do us�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!. \n");
		system("pause");
	}
	else
	{
	printf("Usu�rio deletado!. ");
	system("pause");	
	}
}

int main()
{
	int opcao=0;		//Definindo as vari�veis
	int laco=1;
	
	for (laco=1; laco=1;)
	{
		system ("cls");  //Respons�vel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); // Definindo o idioma
		printf("### Cart�rio da EBAC ###\n\n");  //Inicio do menu
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: ");    // Fim do menu
	
		scanf("%d", &opcao);   //Armazenando a escolha do us�ario
		system("cls");
		
		switch(opcao)   //In�cio da sele��o do menu
		{	
			case 1:
			registro();   //Chamada de fun��es
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
			printf("Essa op��o � invalida! \n");
			system("pause");
			break;	//Fim da sele��o
		}
	}
}

