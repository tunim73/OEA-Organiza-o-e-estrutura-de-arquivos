#include <stdio.h>

// stdout, stdin, stderr

#define TAMANHO 256

void preeFor (int *pt){
	for(int i =0; i<TAMANHO; i++){
		pt[i]=0;
	}
}


int main()
{
	FILE *entrada, *saida;

	int qtd[TAMANHO];
	char frase[100];
    int c;
	preeFor(&qtd);

    entrada = fopen("loremipsum.txt","rb");
	
	if(!entrada)
	{
		fprintf(stderr,"Arquivo %s não pode ser aberto para leitura\n", "loremipsum.txt");
		return 1;
	}

    c = fgetc(entrada);

	while(c != EOF)
	{
        qtd[c]++;
		c = fgetc(entrada);
	}

	saida = fopen("conclusão.txt","w");
	if(!saida)
	{
		fclose(entrada);
		fprintf(stderr,"Arquivo %s não pode ser aberto para escrita\n", "conclusão.txt");
		return 1;
	}

	

    for(int i =0; i<TAMANHO; i++){
		if((i>64 && i<91)|| i>96 && i<123){
		/*strcpy(frase,"\n Letra =  \t quantidade = ");
		fputs(frase,saida);*/
		printf("\n Letra = %c \t quantidade = %i", i, qtd[i]);
		}
    }

	fclose(entrada);
	fclose(saida);
	return 0;
}

