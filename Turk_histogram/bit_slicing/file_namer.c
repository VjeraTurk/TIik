#include <stdio.h>

int main(int argc, char **argv)
{
	int i;
	char file_name[] = "acroyoga";


	printf("\nFILE *fp;\nif(!(fp = fopen(\"%s.pgm\", \"r\"))){\nprintf(\"Greska kod otvaranja\");\n}",file_name);
	i=2243735;
	for(i=1;i<9;i++){

				printf("\nFILE *fp%d;\nif(!(fp%d = fopen(\"%s%d.pgm\", \"w+\"))){\nprintf(\"Greska kod otvaranja\");\n}", i,i,file_name,i);

	}
	return 0;
}

