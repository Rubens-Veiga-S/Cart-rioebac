#include <stdio.h> 
#include <stdlib.h> 
#include <locale.h> 
#include <string.h>

	

int registro()                         
{
										
	char arquivo[40];                               
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
		
	
	printf("Digite o CPF a ser cadastrado:\n ");
	scanf("%s", cpf);				
	
	strcpy(arquivo,cpf);  				
	
	FILE *file;    				   	
	file = fopen(arquivo, "w");      
	fprintf(file, "\n CPF: "); 
	fprintf(file, cpf);				
	fclose(file);					
	
	file = fopen(arquivo,"a");			
	fprintf(file, "\n NOME: "); 	
	fclose(file);					
	
	printf("Digite o nome a ser cadastrado:\n ");		
	scanf("%s", nome);					
	
	file = fopen(arquivo, "a"); 	
	fprintf(file, nome);			
	fclose(file);					
	
	file = fopen(arquivo, "a");		
	fprintf(file,"\n SOBRENOME: ");				
	fclose(file);						
	printf("Digite o sobrenome a ser cadastrado:\n ");				
	scanf("%s", sobrenome); 			
	
	file = fopen(arquivo, "a"); 		 
	fprintf(file, sobrenome); 			
	fclose(file); 							
			
	file = fopen(arquivo, "a");						
	fprintf(file, "\n CARGO: "); 				
	fclose(file);						
	
	printf("Digite o cargo a ser cadastrado:\n ");			
	scanf("%s", cargo);					
	
	
	file = fopen(arquivo, "a");			
	fprintf(file, cargo);;				
	fclose(file);						
	
	file = fopen(arquivo, "a");			
	fprintf(file, "\n\n");			
	fclose(file);						
	
	printf("\nUsuário cadastrado com sucesso!\n\n");			
	system("pause");
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");				
	
	char cpf[40];
	char conteudo[200];
	

	
	printf ("Digite o CPF a ser consultado: ");		
	scanf ("%s", cpf);
	
	FILE *file;										
	file = fopen(cpf,"r" );							
	
		
	
	if (file == NULL)							
	{	
		printf("\nNão foi possível abrir o arquivo, arquivo não localizado!\n\n");		
		system("pause");
		system("cls");
	}
	
					
	while (fgets(conteudo, 200, file) != NULL)		
	{	
	
		printf ("%s", conteudo);					
	}
	printf ("\nEssas são as informações do usuário:\n");
	fclose(file);
	system ("pause");
	system ("cls");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado:\n");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	printf("Usuário excluido com sucesso!\n\n");
	system("pause");
	system("cls");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n\n");
		system("pause");
		system("cls");
	}
	
	fclose(file);
}

int main()
{
	int opcao=0; 										
	int laco=1;
	
	for(laco=1;laco=1;)
	{   
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); 					
	
		printf("--- Cartório da Ebac --- \n\n"); 		
		printf("Escolha a opção desejada:\n\n");
		printf("\t1 - CADASTRAR NOMES\n");
		printf("\t2 - CONSULTAR NOMES\n");
		printf("\t3 - DELETAR NOMES\n"); 
		printf("\t4 - SAIR DO SISTEMA\n\n");
		printf("Opção: "); //fim do menu

		scanf("%d", &opcao); 							
	
		system("cls");
			
		switch(opcao)
		{
			case 1:
				registro();
				break;
					
			case 2:
				consulta();	
				break;
					
			case 3:
				deletar();
				break;
				
			case 4:
				printf("Obrigado por utilizar o sistema!\n\n");
				return 0;
				break;
								
			default:
				printf("\nEssa opção não está disponível! \nEscolha entre as opções 1, 2 e 3:\n\n");
				system("pause");	
				break;
					
		}
		
}
}
