#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
//bez obzira na broj bitova 2 byta
//prvi bit rezerviran za (0-127)+0/1
//broj pixela + jesu li 0 ili 1

int run_length_encoding(FILE *fp, FILE *fpr){
	
	int c, C; //trenutni, prethodni
	int r=0; //rezultat
	int i=0; //broj bitova
	
	int j=0; 
	
//pgm header avoid
	int enter=0;
	while(enter!=5){
	
	c=fgetc(fp);
	printf("%c",c);
	if(c=='\n'){
		enter++;
		}
	}
//first char	
	C=fgetc(fp);
	
 	while((c=fgetc(fp)) != EOF ){
	
		if(c==C && i<127){
			i++;
		}
		
		if (c==C && i==127 ){
			printf(" %c%d ",C,i);
			if(c &~0b01111111){ //if 0b1xxxxxxx (0b11111111) 
			r=0b10000000+i;	//1 <number of bits>			
			}else r=i; //0 <number of bits>
	
			printf(" ");
			for (j = 0; j < 8; j++) {
				printf("%d", !!((r << j) & 0x80));
			}
			fputc(r,fpr);
			i=0;
		}
		
		if(c!=C){
			printf(" %c%d  ",C,i);
			r=i;
			if(C &~0b01111111){
			r=0b10000000+i;				
			}else r=i;
			
			printf(" ");
			for (j = 0; j < 8; j++) {
				printf("%d", !!((r << j) & 0x80));
			}
			fputc(r,fpr);
			i=1;	
			C=c;
		}
		

	}

	return 0;
}

int main(void)
{
    FILE *fp;
	int c=0;
	 
    if(!(fp = fopen("shannon.pgm", "r+"))){
		printf("Greska kod otvaranja");
		 exit(0);
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

	
	int enter=0;
	
	while(enter!=5){
		
		c=fgetc(fp);
		fputc(c,fp1);
		fputc(c,fp2);
		fputc(c,fp3);
		fputc(c,fp4);
		fputc(c,fp5);
		fputc(c,fp6);		
		fputc(c,fp7);
		fputc(c,fp8);		
		
		printf("%c",c);
		if(c=='\n'){
			enter++;
			}
		}
	char C;
	while((c=fgetc(fp)) != EOF ){

		if(c==EOF) fclose(fp);
		//c&=~0b11011111;
		C = c &~0b11111110;
		
		if(c &~0b11111110){
			C=0b11111111;
		}else C=0b00000000;	
		
		fputc(C,fp1);

		C = c &~0b11111101;
		
		if(c &~0b11111101){
			C=0b11111111;
		}else C=0b0000000;	
		
		fputc(C,fp2);
		
		C = c &~0b11111011;
		if(c &~0b11111011){
			C=0b11111111;
		}else C=0b0000000;	
		
		fputc(C,fp3);

		C = c &~0b11110111;
		
		if(c &~0b11110111){
			C=0b11111111;
		}else C=0b0000000;	
		
		fputc(C,fp4);

		C = c &~0b11101111;
		if(c &~0b11101111){
			C=0b11111111;
		}else C=0b0000000;	
		
		fputc(C,fp5);
		
		C = c &~0b11011111;
		if(c &~0b11011111){
			C=0b11111111;
		}else C=0b0000000;	
		
		fputc(C,fp6);

		C = c &~0b10111111;
		C = c &~0b0111111;
		
		if(c &~0b10111111){
			C=0b11111111;
		}else C=0b0000000;	
		
		fputc(C,fp7);
		
		C = c &~0b01111111;
		
		if(c &~0b01111111){
			C=0b11111111;				
		}else C=0b00000000;
		
		fputc(C,fp8);	
			
		if(c==EOF) fclose(fp);
	}
	
	
	FILE *fpr;
	  
	if(!(fp = fopen("shannon1.pgm", "r+"))){
		printf("Greska kod otvaranja");
		}
		
	if(!(fpr = fopen("rle_shannon1.bin", "w+"))){
	printf("Greska kod otvaranja");
	}

	run_length_encoding(fp, fpr);
	fclose(fpr);
	fclose(fp);
	
		if(!(fp = fopen("shannon2.pgm", "r+"))){
		printf("Greska kod otvaranja");
		}
		
	if(!(fpr = fopen("rle_shannon2.bin", "w+"))){
	printf("Greska kod otvaranja");
	}
		
	run_length_encoding(fp, fpr);
	fclose(fpr);
	fclose(fp);
	
		if(!(fp = fopen("shannon3.pgm", "r+"))){
		printf("Greska kod otvaranja");
		}
		
	if(!(fpr = fopen("rle_shannon3.bin", "w+"))){
	printf("Greska kod otvaranja");
	}
		
	run_length_encoding(fp, fpr);
	fclose(fpr);
	fclose(fp);

	if(!(fp = fopen("shannon4.pgm", "r+"))){
		printf("Greska kod otvaranja");
		}
		
	if(!(fpr = fopen("rle_shannon4.bin", "w+"))){
	printf("Greska kod otvaranja");
	}
		
	run_length_encoding(fp, fpr);
	fclose(fpr);
	fclose(fp);

	if(!(fp = fopen("shannon5.pgm", "r+"))){
		printf("Greska kod otvaranja");
		}
		
	if(!(fpr = fopen("rle_shannon5.bin", "w+"))){
	printf("Greska kod otvaranja");
	}
		
	run_length_encoding(fp, fpr);
	fclose(fpr);
	fclose(fp);
	
		if(!(fp = fopen("shannon6.pgm", "r+"))){
		printf("Greska kod otvaranja");
		}
		
	if(!(fpr = fopen("rle_shannon6.bin", "w+"))){
	printf("Greska kod otvaranja");
	}
		
	run_length_encoding(fp, fpr);
	fclose(fpr);
	fclose(fp);
	
		if(!(fp = fopen("shannon7.pgm", "r+"))){
		printf("Greska kod otvaranja");
		}
		
	if(!(fpr = fopen("rle_shannon7.bin", "w+"))){
	printf("Greska kod otvaranja");
	}
		
	run_length_encoding(fp, fpr);
	fclose(fpr);
	fclose(fp);
	
	if(!(fp = fopen("shannon8.pgm", "r+"))){
		printf("Greska kod otvaranja");
		}
		
	if(!(fpr = fopen("rle_shannon8.bin", "w+"))){
	printf("Greska kod otvaranja");
	}
		
	run_length_encoding(fp, fpr);
	fclose(fpr);
	fclose(fp);

	return 0;
	
}
