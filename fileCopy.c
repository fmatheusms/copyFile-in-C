#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
/*

	Esse programinha copia o conte�do bin�rio de qualquer arquivo para um novo arquivo designado por linha de comando
	Sua sintaxe �:
		
		.\copiaArquivo arquivoOriginal.extensao novoArquivo.extensao
		-> Aten��o nas extens�es: se o arquivo original foi um .exe e o destino for .txt, obviamente n�o vai funcionar corretamente.
	
	
	O programa funciona por linha de comando e necessita que sejam passados dois argumentos: 
		1 - o arquivo original seguido de sua extens�o;
		2 - o nome do novo arquivo seguido de sua extens�o;

*/

void main (int argc, char*argv[])
{
	setlocale(LC_ALL, "Portuguese");
	FILE *fileIn, *fileOut;
	int ch;
	
	if (argc!=3)
		{
			printf("\n\nSintaxe -> .\\copiaArquivo arquivoOriginal.extensao novoArquivo.extensao\n\n � necess�rio dois argumentos!\n\n");
		}
	else
		{
			fileIn = fopen(argv[1], "rb");
			
			if(fileIn==NULL)
				{
					printf("Impossivel abrir o arquivo %s\n", argv[1]);
					exit(2);
				}
			
			fileOut = fopen(argv[2], "wb");
			
			if (fileOut==NULL)
				{
					printf("Nao foi possivel criar o arquivo %s\n", argv[2]);
					exit(3);
				}
			
			while ((ch=fgetc(fileIn))!=EOF)
				{
					fputc(ch, fileOut);
				}
				
			fclose(fileIn);
			fclose(fileOut);
		}
	
	printf("\n\n##############################\n\n%s copiado com sucesso para %s\n\n##############################", argv[1], argv[2]);
		
	
}
