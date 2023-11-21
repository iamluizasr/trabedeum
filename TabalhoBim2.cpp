#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

struct TpExemplares {
    int Codigo;
    TpExemplares *ProxExemplar;
};

struct TpLivro {
    char Titulo [50], Autor [50];
    TpLivro *ProxLivro;
    TpExemplares *ExemplarE, *ExemplarD;
};

TpLivro* LerArquivo(){

    char AuxTitulo[50], AuxAutor[50];
    int ExemplarE, ExemplarD;
    TpLivro *Cabeca, *CopiaCabeca;

    FILE *Pont = fopen("livros.txt","r");
    
    if(Pont == NULL){
        printf("Erro de Abertura !");
    }
    else{
    	
        TpLivro *NovaCaixa = new TpLivro;
        fscanf(Pont,"%[^;];%[^;]", &AuxAutor, &AuxTitulo);
		
        strcpy(NovaCaixa->Titulo, AuxTitulo);
        strcpy(NovaCaixa->Autor, AuxAutor);
        Cabeca = NovaCaixa;
        CopiaCabeca = NovaCaixa;

        while(!feof(Pont)){  //ARRUMAR

            fscanf(Pont,"%[^;];%[^;]", &AuxAutor ,&AuxTitulo);
            NovaCaixa = new TpLivro;
            strcpy (NovaCaixa->Titulo, AuxTitulo);
            strcpy (NovaCaixa->Autor, AuxAutor);
            CopiaCabeca->ProxLivro=NovaCaixa;
            CopiaCabeca=NovaCaixa;
        }
    }

    fclose(Pont);
    getch();
    
    return Cabeca;
}



void Exibir(TpLivro *Cabeca){
	
	printf("nnnn");
	if (Cabeca == NULL)
	{
		//gotoxy();
		printf("Lista Vazia");	
	}
	else{
	    while(Cabeca->ProxLivro != NULL){
	        printf("%c ", Cabeca-> Titulo);
	        Cabeca = Cabeca-> ProxLivro;
	    }
	    printf("%c ", Cabeca-> Titulo);
	    getch();
	}
}





//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Moldura(int CI, int LI, int CF, int LF, int cortexto, int background){
	
	int i;
	
	textcolor(cortexto);
	textbackground(background);
	
	gotoxy(CI,LI); 
	printf("%c",201);		//superior esquerdo
	
	gotoxy(CF,LI);
	printf("%c",187);		//superior direito
	
	gotoxy(CI,LF);			
	printf("%c",200);		//inferior esquerdo
	
	gotoxy(CF,LF);
	printf("%c",188);		//inferior direitro
	
	for(i=CI+1; i<CF; i++){		//linhas
		gotoxy(i,LI);
		printf("%c",205);		//linha superior
		gotoxy(i,LF);
		printf("%c",205);		//linha inferior
	}
	
	for(i=LI+1; i<LF; i++){		//colunas
		gotoxy(CI,i);
		printf("%c",186);		//coluna esquerda
		gotoxy(CF,i);
		printf("%c",186);		//coluna direita
	}
	
	textcolor(7);				//retorna ao normal as cores
	textbackground(0);
}

void MolduraMenu(){
	
	clrscr();		//limpar a tela
	Moldura(1, 1, 80, 25, 3, 0);		//moldura externa
	Moldura(2, 2, 78, 4, 3, 0);		//moldura dentro acima
	Moldura(2, 5, 27, 21, 3, 0); // moldura menu
	Moldura(2, 22, 79, 21, 3, 0); // moldura exibiçao
	Moldura(28, 5, 79, 21, 3, 0);			//moldura fora baixo

}

void Menu(){
	
	char op;
	MolduraMenu();
	
	do{
	
		gotoxy(35,3);
		printf("BIBLIOTECA");
		
		gotoxy(13,6);
	    printf("MENU");
		gotoxy(50,6);
	    printf("EXIBICAO");
	    
		gotoxy(4,8);
	    printf("[A] - Gerar Emprestimo\n");
	   	gotoxy(4,10);
	    printf("[B] - Gerar Devolucao\n");
	   	gotoxy(4,12);
	    printf("[C] - Pesquisar Exemplar\n");
	  	gotoxy(4,14);
	    printf("[D] - Gerar Relatorio\n");
	  	gotoxy(4,16);
	    printf("[ESC] - SAIR\n");
	    
	    //gotoxy(4,16);
	    //printf("Mensagem:);
   
	    
	    op = toupper(getch());
	    
	}while(op!=27);
	
	switch (op){

        case 'A':
                    break;
        case 'B':
                    break;
        case 'C':
                    break;
        case 'D':
                    break;
                    

	}
}


/*void LimpaTela(void){
	int x1 = 2, x2 = 99, y1 = 5, y2 = 24, i, j;
	for(i=x1; i<x2; i++)
		for(j=y1; j<y2; j++){
			gotoxy(i,j);
			printf(" ");
		}
}*/


int main(){

	TpLivro *Cabeca;
	
    Cabeca = LerArquivo();
    Exibir(Cabeca);
  	Menu();
    
    return 0;
}
