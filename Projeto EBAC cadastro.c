#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string


int registrar()  //Função resposável por cadastrar os usuários no sistema
{
	//Início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da criação de variáveis/string
	
	printf("Digite o cpf a ser cadastrado: "); 
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file;  //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da variável
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
		printf("Desculpe, não foi possível localizar o arquivo desejado. Confira os dados novamente.\n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nDados do usuário: ");
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
		printf("O CPF pesquisado não foi encontrado.\n");
		system("pause");
	}	
}



int main() 
{
    int opcao=0;  // definindo variáveis 
    int laco=1; // definindo repetição
    
    for(laco=1;laco=1;)  // definindo ponto de retorno
    {
	
		system("cls");  //resposável por limpar a tela
	
		setlocale(LC_ALL, "Portuguese");  // definindo a linguagem
    
    	printf("--- Banco de Dados EBAC ---\n\n");  // início do menu
    	printf("Por favor, escolha a opção desejada:\n\n");
    	printf("\t1 - Cadastrar Aluno(a)\n");
    	printf("\t2 - Consultar Aluno(a)\n");
    	printf("\t3 - Excluir cadastro de Aluno(a)\n\n\n");  
		printf("Opção: "); // fim do menu
    
    	scanf("%d" , &opcao);  // armazenando a escolha do usuário
    
    	system("cls");
    
    	switch(opcao)
    	{
    		case 1: // início da seleção
    		registrar(); //chama de função
			break;
			
			case 2: 
			consultar();
			break;
			
			case 3:
			excluir();
			break;
			
			default:
			printf("Esta opção não está disponível.\n\n");
			system("pause");
			break;  // fim da seleção
		}
	
	}
	
}

