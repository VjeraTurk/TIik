#include <stdio.h>
#include <math.h>
#include <locale.h>
#define TNOCHAR 256  /* Total Number of characters*/

double Shannon_entropy(int character[], int total){

	double H=0; //entropy
	double propability[TNOCHAR];
	int i;
	int used=0; //broj samo korištenih od 256 znakova
	
	//printf("char	i	character[i]	p(char)\n");

	for(i=0;i<TNOCHAR;++i)
		{

			propability[i] = (double)character[i]/(double)total; //vjerojatnost: broj ponavljanja znaka na indexu i/ broj svih znakova u fileu
		
			if(character[i]!=0){	
			H -= propability[i]*log2((propability[i]));
			 used++;
			}
			
//			putchar(i);
//			printf("  %10d    %10d",i, character[i]);
//			printf("	%10f",propability[i]);
//			putchar('\n');
	   
		}
	printf("\ntotal: %d",total);
    printf("\nused: %d",used);
    printf("\nH: %f\n",H);
    
    return H;
}
int histogram(FILE *fp, int character[]){
	
	 
    int total=0; // ukupan broj znakova
	int c=0,i=0;
	
    for(i=0;i<TNOCHAR;++i) character[i] = 0;
    
    while((c=fgetc(fp)) != EOF ){
		total++;
        ++character[c];
   }
	return total;
}

int main(void)
{
    int character[TNOCHAR];
	int total=0;
    double h_txt=0;
    double h_zip, h_rar, h_tar, h_gz;
    
    FILE *fp;
     
	printf("\nTimeMachine.txt");
    if(!(fp = fopen("shannon1.pgm", "r"))){
    //if(!(fp = fopen("proba.txt", "r"))){
		printf("Greska kod otvaranja");
		}

	total=histogram(fp, &character[0]);
    h_txt = Shannon_entropy( &character[0], total);
    fclose(fp);
    /*
    printf("\nTimeMachine.txt.xz");	
	if(!(fp = fopen("TimeMachine.txt.xz", "r"))){
		printf("Greska kod otvaranja");
	}	
	total=histogram(fp, &character[0]);
    h_zip = Shannon_entropy( &character[0], total);
    fclose(fp);
    
    
    printf("\nTimeMachine.txt.7z");	
	if(!(fp = fopen("TimeMachine.txt.7z", "r"))){
		printf("Greska kod otvaranja");
	}	
	total=histogram(fp, &character[0]);
    h_zip = Shannon_entropy( &character[0], total);
    fclose(fp);
    
	printf("\nTimeMachine.zip");	
	if(!(fp = fopen("TimeMachine.zip", "r"))){
		printf("Greska kod otvaranja");
	}	
	total=histogram(fp, &character[0]);
    h_zip = Shannon_entropy( &character[0], total);
    fclose(fp);
    
   	printf("\nTimeMachine.rar");
    if(!(fp = fopen("TimeMachine.rar", "r"))){
		printf("Greska kod otvaranja");
	}
    total=histogram(fp, &character[0]);
    h_rar = Shannon_entropy( &character[0], total);
    fclose(fp);    
    

    printf("\nTimeMachine.txt.gz");
    if(!(fp = fopen("TimeMachine.txt.gz", "r"))){
   	printf("Greska kod otvaranja");
		}
    total=histogram(fp, &character[0]);
    h_gz = Shannon_entropy( &character[0], total);
    fclose(fp);    
    
	printf("\nTimeMachine.txt.tar");
    if(!(fp = fopen("TimeMachine.txt.tar", "r"))){
   	printf("Greska kod otvaranja");
		}
    total=histogram(fp, &character[0]);
    h_gz = Shannon_entropy( &character[0], total);
    fclose(fp);    
    */

        
	return 0;
	
}
