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


    for(int i =0; i<TAMANHO; i++){
		if((i>64 && i<91)|| i>96 && i<123)
		printf("\n Letra = %c \t quantidade = %i", i, qtd[i]);
    }


	fclose(entrada);
	return 0;
}

