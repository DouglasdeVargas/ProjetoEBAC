#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string


int registrar()  //Fun��o respos�vel por cadastrar os usu�rios no sistema
{
	//In�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da cria��o de vari�veis/string
	
	printf("Digite o cpf a ser cadastrado: "); 
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file;  //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);	
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
		
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese");  // definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Por favor, digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Desculpe, n�o foi poss�vel localizar o arquivo desejado. Confira os dados novamente.\n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nDados do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
	
	
}

int excluir()
{

	char cpf[40];
	
	printf("Por favor, digite o CPF a ser excluido: ");
	scanf("%s",cpf);
		
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL);
	{
		printf("O CPF pesquisado n�o foi encontrado.\n");
		system("pause");
	}	
}



int main() 
{
    int opcao=0;  // definindo vari�veis 
    int laco=1; // definindo repeti��o
    
    for(laco=1;laco=1;)  // definindo ponto de retorno
    {
	
		system("cls");  //respos�vel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese");  // definindo a linguagem
    
    	printf("--- Banco de Dados EBAC ---\n\n");  // in�cio do menu
    	printf("Por favor, escolha a op��o desejada:\n\n");
    	printf("\t1 - Cadastrar Aluno(a)\n");
    	printf("\t2 - Consultar Aluno(a)\n");
    	printf("\t3 - Excluir cadastro de Aluno(a)\n\n\n");  
		printf("Op��o: "); // fim do menu
    
    	scanf("%d" , &opcao);  // armazenando a escolha do usu�rio
    
    	system("cls");
    
    	switch(opcao)
    	{
    		case 1: // in�cio da sele��o
    		registrar(); //chama de fun��o
			break;
			
			case 2: 
			consultar();
			break;
			
			case 3:
			excluir();
			break;
			
			default:
			printf("Esta op��o n�o est� dispon�vel.\n\n");
			system("pause");
			break;  // fim da sele��o
		}
	
	}
	
}

