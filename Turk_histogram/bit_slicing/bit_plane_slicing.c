//http://netpbm.sourceforge.net/doc/pgm.html :standard za header PGM-a
//P5<ws>width<ws>height<ws>max_gray<ws>data
#include <stdio.h>


int main(void)
{
	
	
    int c=0;
/*
	FILE *fp; 
    if(!(fp = fopen("shannon.pgm", "r+"))){
		printf("Greska kod otvaranja");
		}
	FILE *fp1;
	if(!(fp1 = fopen("shannon1.pgm", "w+"))){
	printf("Greska kod otvaranja");
	}
	FILE *fp2;
	if(!(fp2 = fopen("shannon2.pgm", "w+"))){
	printf("Greska kod otvaranja");
	}
	FILE *fp3;
	if(!(fp3 = fopen("shannon3.pgm", "w+"))){
	printf("Greska kod otvaranja");
	}
	FILE *fp4;
	if(!(fp4 = fopen("shannon4.pgm", "w+"))){
	printf("Greska kod otvaranja");
	}
	FILE *fp5;
	if(!(fp5 = fopen("shannon5.pgm", "w+"))){
	printf("Greska kod otvaranja");
	}
	FILE *fp6;
	if(!(fp6 = fopen("shannon6.pgm", "w+"))){
	printf("Greska kod otvaranja");
	}
	FILE *fp7;
	if(!(fp7 = fopen("shannon7.pgm", "w+"))){
	printf("Greska kod otvaranja");
	}
	FILE *fp8;
	if(!(fp8 = fopen("shannon8.pgm", "w+"))){
	printf("Greska kod otvaranja");
	} 
*/
	FILE *fp;
	if(!(fp = fopen("acroyoga.pgm", "r+"))){
	printf("Greska kod otvaranja");
	}
	FILE *fp1;
	if(!(fp1 = fopen("acroyoga1.pgm", "w+"))){
	printf("Greska kod otvaranja");
	}
	FILE *fp2;
	if(!(fp2 = fopen("acroyoga2.pgm", "w+"))){
	printf("Greska kod otvaranja");
	}
	FILE *fp3;
	if(!(fp3 = fopen("acroyoga3.pgm", "w+"))){
	printf("Greska kod otvaranja");
	}
	FILE *fp4;
	if(!(fp4 = fopen("acroyoga4.pgm", "w+"))){
	printf("Greska kod otvaranja");
	}
	FILE *fp5;
	if(!(fp5 = fopen("acroyoga5.pgm", "w+"))){
	printf("Greska kod otvaranja");
	}
	FILE *fp6;
	if(!(fp6 = fopen("acroyoga6.pgm", "w+"))){
	printf("Greska kod otvaranja");
	}
	FILE *fp7;
	if(!(fp7 = fopen("acroyoga7.pgm", "w+"))){
	printf("Greska kod otvaranja");
	}
	FILE *fp8;
	if(!(fp8 = fopen("acroyoga8.pgm", "w+"))){
	printf("Greska kod otvaranja");
	}


	
	int enter=0;
	int ws=0;

	//ako ne radi, prilagoditi broj entera
	
	while(enter<3){
		
		c=fgetc(fp);
		printf("%c",c);
		fputc(c,fp1);
		fputc(c,fp2);
		fputc(c,fp3);
		fputc(c,fp4);
		fputc(c,fp5);
		fputc(c,fp6);		
		fputc(c,fp7);
		fputc(c,fp8);		
		
		if(c=='\n'){
//			printf("\\n");
			enter++;
			ws++;
			}
		if(c==' '){
//			printf("<sp>");	
			ws++;
			}
		if(c=='	'){
//			printf("<tab>");	
			ws++;
			}
		if(c=='#'){
			ws++;
			enter--;
			enter--;
			}
		}
//	printf("\nws:%d",ws);	
//	printf("\nenter:%d",enter);	
	
	char C;
	while((c=fgetc(fp)) != EOF ){
		if(c==EOF) fclose(fp);
		//c&=~0b11011111;
		C = c &~0b11111110;
		fputc(C,fp1);
		
		C = c &~0b11111101;
		fputc(C,fp2);
		
		C = c &~0b11111011;
		fputc(C,fp3);

		C = c &~0b11110111;
		fputc(C,fp4);

		C = c &~0b11101111;
		fputc(C,fp5);
		
		C = c &~0b11011111;
		fputc(C,fp6);

		C = c &~0b10111111;
		fputc(C,fp7);
		
		C = c &~0b01111111;
		fputc(C,fp8);	
			
		if(c==EOF) fclose(fp);
	}
	   
	return 0;
	
}
