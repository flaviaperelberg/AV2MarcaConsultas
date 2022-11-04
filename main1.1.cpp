/*É necessario concertar alguns pontos.
2   - Faz-se necessario a criação de quatro novas funções para melhor funcionamento do código.
3   - O escopo das novas funções já foi criado, cada uma tem sua propria explicação no cabeçalho da mesma
4   - Faz-se necessario criar duas matrizes, 
4.1 - Uma matriz para os usuarios já criados, todos varchar com 70x5.
4.2 - Uma matriz para as datas de 10x2.
5   - Faz-se necessario a retenção a apresentação dos dados da consulta.
6   - Faz-se necessario a verificação dos dados recebidos no cadastro, para que
6.1 - Não se envie numeros em locais em que só podem receber letras.
6.2 - Não se envie letras em locais onde só pode receber valores.
6.3 - Não se envie dados já registrados por outro usuario.
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#define SIZE 200

char nome[SIZE] [70];
char nascimento[SIZE][10];
char email[SIZE] [50];
char cpf[SIZE][50];
int numeroSUS;

int numspecialist, nummedico, unid, op, cpfInt[SIZE];


void cadastro(){

	static int linha;
	int opCadastro;
	do{//obtenção dos dados do cliente
		fflush(stdin);
		printf("\nPor favor, digite seu nome completo: \n\n\n");
		gets(nome[linha]);
		system("cls");
		fflush(stdin);
		printf("\n \nDigite sua data de nascimento:\n\n\n");
		printf("\nEx.: 25 12 1984 \n\n\n");
		gets(nascimento[linha]);
		system("cls");
		fflush(stdin);
		printf("\n \nDigite seu e-mail:\n\n\n");
		printf("\nEx.: exemplo@email.com \n\n\n");
		gets(email[linha]);
		system("cls");
		fflush(stdin);
		
		printf("\n \nDigite seu CPF: \n\n\n");
		printf("\nEx.: 000.000.000-00 \n\n\n");
		gets(cpf[linha]);
		system("cls");
		printf("\n\n Digite o Seu numero SUS.\n\n\n");
		printf("\nEx.: 123456 Sem Pontos.\n");
		scanf("%d",&numeroSUS);
		cpfInt[linha] = 1;
		
	
				//clausula de saida do looping.
		printf("\n \nDigite 1 para continuar com a marcação, ou outro valor para sair\n \n");
		scanf("%d", &op);
		linha++;
		system("cls");
			//o sistema está terminando aqui, deve ser concertado.
	}while(opCadastro==1);
	
	
}
void pesquisa() {
	char cpfPesquisa[50];
	char emailPesquisa[50];
	int i;
	int opPesquisa;
	do{
		printf("Digite 1 para pesquisar por CPF ou 2 para pesquisar por email: \n");
		scanf("%d", &opPesquisa);
		switch(opPesquisa) {
			case 1:
				printf("\nDigite o CPF: \n");
				scanf("%s", &cpfPesquisa);
				for(i=0;i<SIZE;i++) {
					if(strcmp(cpf[i], cpfPesquisa)==0) {
						printf("\nNome: %s\nData de Nascimento: %s\nEmail: %s\nCPF: %s", nome[i], nascimento[i], email[i], cpf[i]);
						break;
					}
					if(i==199){
						i+=1;
						//printf("\n%d",i);
					}
					if(strcmp(cpf[i], cpfPesquisa)!=0 && i == SIZE){
						printf("Pessoa não encontrada !");
					}
				}
				break;
			case 2: 
				printf("\nDigite o E-mail: ");
				scanf("%s", emailPesquisa);
				for(i=0; i<SIZE; i++) {
					if(strcmp(email[i], emailPesquisa)==0) {
						printf("\nNome: %s\nData de Nascimento: %s\nEmail: %s\nCPF: %s", nome[i], nascimento[i], email[i], cpf[i]);
					}
					if(i==199){
						i+=1;
						//printf("\n%d",i);
					}
					else if(strcmp(email[i], emailPesquisa)!=0 && i == SIZE){
						printf("Pessoa não encontrada !");
					}
				}
				break;
			default:
				printf("\n Opção invalida");	
				break;
		}
		printf("\n\nDigite 1 para continuar pesquisando ou outro valor para sair: ");
		scanf("%d", &opPesquisa);
		system("cls");
	}while(opPesquisa==1);	
}
// menu para especialidades
void specialist () {
	printf("\n\n_________________________ ESPECIALIDADES _________________________\n\n");
    printf("\n                      1 - Clínico Geral.\n\n");
    printf("\n                      2 - Cardiologista.\n\n");
    printf("\n                      3 - Oftalmologista.\n\n");
    printf("\n                      4 - Pediatra.\n\n");
    printf("\n                      5 - Ortopedista e Traumatologia.\n\n");
    printf("\n                      6 - Neurologista e Psiquiatra.\n\n");
    printf("\n                      7 - Ginecologista e Obstetra.\n\n");

	printf("\nPor favor, escolha o número da opção correspondente a especialidade desejada:\n\n");
	scanf("%d", &numspecialist);
    system("cls");
}
void specialistMedicos1(){
  	printf("\n\n_________________________ ESPECIALISTAS _________________________\n\n");  
  	printf("\n\n_________________________ Clínica Geral _________________________\n\n");
	printf("\n                      1 - Dr. Huberto Castro.\n\n");
    printf("\n                      2 - Drª. Liandra Cerqueira.\n\n");
    printf("\n                      3 - Dr. Magno Florêncio.\n\n");
    printf("\n_________________________ ESPECIALISTAS _________________________\n");
    
    printf("\nEscolha o número da opção correspondente ao médico de sua preferência:\n\n");
	scanf("%d", &nummedico);
	system("cls");
}
void specialistMedicos2(){
	printf("\n\n_________________________ ESPECIALISTAS __________________________\n");  
  	printf("\n\n__________________________ Cardiologia ___________________________\n");
	printf("\n__                      1 - Dr. Pedro Paulo Souza.                __\n");
    printf("\n__                      2 - Dr. Victor Almeida.                   __\n");
    printf("\n__                      3 - Dr. Robert de Jesus.                  __\n");
    printf("\n_________________________ ESPECIALISTAS ____________________________\n");
    
    printf("\nEscolha o número da opção correspondente ao médico de sua preferência:\n\n");
    scanf("%d", &nummedico);
    system("cls");
}
void specialistMedicos3 (){
	printf("\n_________________________ ESPECIALISTAS __________________________\n");  
  	printf("\n__________________________ Oftamologia ___________________________\n");
  	printf("\n__                      1 - Drª. Flavia Perelberg.              __\n");
    printf("\n__                      2 - Dr. Matheus Costa.                  __\n");
    printf("\n__                      3 - Dr. Daniel da Cruz.                 __\n");
    printf("\n_________________________ ESPECIALISTAS __________________________\n");
    	
    printf("\nEscolha o número da opção correspondente ao médico de sua preferência:\n\n");
	scanf("%d", &nummedico);
	system("cls");
}
void specialistMedicos4 (){ 
    printf("\n_________________________________________________________________\n");
	printf("\n_________________________ ESPECIALISTAS _________________________\n");  
  	printf("\n___________________________ Pediatria ___________________________\n");
  	printf("\n__                      1 - Drª. Alderiza Costa.               __\n");
    printf("\n__                      2 - Drª. Lis Alphontes.                __\n");
    printf("\n__                      3 - Dr. Luiz Dahora.                   __\n");
    printf("\n_________________________________________________________________\n");
    printf("\n_________________________ ESPECIALISTAS _________________________\n");
    printf("\n_________________________________________________________________\n");
    
    printf("\nEscolha o número da opção correspondente ao médico de sua preferência:\n\n");
	scanf("%d", &nummedico);
	system("cls");
}
void specialistMedicos5 (){
	printf("\n\n_________________________ ESPECIALISTAS _________________________\n\n");  
  	printf("\n\n___________________ Ortopedia e Traumatologia ___________________\n\n");
  	printf("\n                      1 - Dr. Huberto Celestim.\n\n");
    printf("\n                      2 - Drª. Amanda Almeid.\n\n");
    printf("\n                      3 - Dr. Hildebrando Caetano.\n\n");
    
    printf("\nEscolha o número da opção correspondente ao médico de sua preferência:\n\n");
	scanf("%d", &nummedico);
	system("cls");
}
void specialistMedicos6 () {
	printf("\n\n_________________________ ESPECIALISTAS _________________________\n\n");  
  	printf("\n\n____________________ Neurologia e Psiquiatria ___________________\n\n");
  	printf("\n                      1 - Drª. Talita Rocha.\n\n");
    printf("\n                      2 - Dr. Amorim.\n\n");
    printf("\n                      3 - Dr. Joaquim.\n\n");
    
    printf("\nEscolha o número da opção correspondente ao médico de sua preferência:\n\n");
	scanf("%d", &nummedico);
	system("cls");
}
void specialistMedicos7 () {  
    printf("\n\n_________________________ ESPECIALISTAS _________________________\n\n");  
  	printf("\n\n____________________ Ginecologia e Obstetricia ___________________\n\n");
  	printf("\n                      1 - Drª. Celso Rodrigues.\n\n");
    printf("\n                      2 - Dr. Lorena Viega.\n\n");
    printf("\n                      3 - Dr. Patricia Lima.\n\n");
    
    printf("\nEscolha o número da opção correspondente ao médico de sua preferência:\n\n");
	scanf("%d", &nummedico);
	system("cls");
}
void unidades () {
	printf("\n\n1 - Unidade de Saúde da Familia Brotas\n");
	printf("\n\n2 - Unidade de Saúde da Familia Ribeira\n");
	printf("\n\n3 - Unidade de Saúde da Familia Boca do Rio\n");
	printf("\n\n4 - Unidade de Saúde da Familia Itapuã\n");
	printf("\n\n5 - Unidade de Saúde da Familia Itinga\n");
	printf("\n\n6 - Hospital da Mulher\n");
	printf("\n\n7 - Hospital Geral do Estado\n");
	printf("\n\n8 - Hospital Menandro de Farias\n");
	
	printf("\n\nEscolha o número da opção correspondente a unidade de sua preferência:\n\n");
	scanf("%d", &unid);
	system("cls");
}

//lugar onde os possiveis horarios estarão disponiveis
void banco(){
	
}
//varificação dos dados de cadastro
void verificaCadastro(){
	
}
//verificação dos dados de login
void verificaLogin(){
	
}
//confirmação dos dados da consulta
void criarConsulta(){
} 
//criação de arquivode consulta
void arquivo(){
	
}

int main(void){
setlocale(LC_ALL,"");

    //estrutura de boas vindas.
    
    do{//estrutura de repetição para cadastro, existe um parametro de armazenamento implementado no código.
		printf("\n* --------------------- SISTEMA ---------------------- *\n\n");
		printf("\n* -------------------- SUS UniRuy -------------------- *\n \n ");
		printf("\n \n* Seja bem-vindo(a) ao sistema de marcação de consultas! *\n \n ");
		printf("\n \nPara iniciar o atendimento escolha a opção desejada:\n \n");
		printf("\n\n  1 - Cadastre-se. \n \n  2 - Consultar Cadastros.\n \n  3 - Já Tenho Cadastro.\n\n  4 -  Saida. \n\n");
		scanf("%d", &op);
		system("cls");
		
		if(op==4)break;//saida forçada do "do".
		
		switch(op) {
			case 1:
				cadastro();
				system("cls");
				//if já dentro de um outro método, não faz parte do boas vindas
				
				if (op==1){
					specialist();
					    switch(numspecialist){//condições em cadeia
							case 1:
								specialistMedicos1 ();
								unidades();//não grava o médico!!!
								break;
							case 2:
								specialistMedicos2 ();
								unidades();
								break;
							case 3:
								specialistMedicos3 ();
								unidades();
								break;
							case 4:
								specialistMedicos4 ();
								unidades();
								break;
							case 5:
								specialistMedicos5 ();
								unidades();
								break;
							case 6:
	    						specialistMedicos6 ();
	    						unidades();
	    						break;
							case 7:
	    						specialistMedicos7 ();
	    						unidades();
								break;
							default:
								while(numspecialist>=7 || numspecialist<=1){//laço de repetição que força o usuario digitar um valor aceito
								printf("\n\n__________________________________________________________________\n\n");
								printf("\n\n*_____________________ Opção inválida!!! _____________________* \n\n ");
								printf("\n\n_________________ Por favor, Tente novamente!!! _______________\n\n ");	
    							printf("\n\n__________________________________________________________________\n\n");
							
								specialist();
								
								break;//ele volta para o MENU principal, deveria voltar para especialistas e entrar na opcao!!!
						}system("cls");
				}	
				break;
			case 2:
				pesquisa();
				break;
			case 3:
				system("exit");
				break;
			default:
				printf("\n\n__________________________________________________________________\n\n");
				printf("\n\n*_____________________ Opção inválida!!! _____________________* \n\n ");
				printf("\n\n_________________ Por favor, Tente novamente!!! _______________\n\n ");	
    			printf("\n\n__________________________________________________________________\n\n");
				getchar();
				getchar();
				break;
				}
				system("cls");
		}
	}while(op!=3);
    system("cls");
    
	/*unidades ();//chamando a função unidades para apresentar as opções	
	while(unid>8 || unid<1){//laço de repetição para forçar o usuario digitar um valor validado
	printf("\n \nOpção inválida!!! Tente novamente. \n\n");
	unidades();	
	}*/

}
