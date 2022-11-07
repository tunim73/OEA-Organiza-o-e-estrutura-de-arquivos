#include <stdio.h>

// stdout, stdin, stderr

#define TAMANHO 256


int main()
{
	FILE *entrada, *saida;

    int c;

    entrada = fopen("loremipsum copy.txt","rb");
    saida = fopen("concluido.txt","wb");
	
	if(!entrada)
	{
		fprintf(stderr,"Arquivo não pode ser aberto para leitura\n");
		return 1;
	}
	if(!saida)
	{
		fprintf(stderr,"Arquivo não pode ser aberto para escrita\n");
		return 1;
	}


    c = fgetc(entrada);
	int cont =0;
	while(c != EOF) 
	{
		printf("\nc == %i \t cont == %i",c,cont);
		cont++;		
        if(c==10){
			fputc(13,saida);
		}
		fputc(c,saida);
		c = fgetc(entrada);
	}

	fclose(entrada);
	return 0;
}

