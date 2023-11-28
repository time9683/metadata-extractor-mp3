#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/stat.h>
#include <sys/stat.h>
#include <string.h>


void ExtractData(int dataToRead,char buff[],int* i,char data[]){
int j = *i;
int bytes_read = 0;
int void_bites = 0;


for (int l = j+5; l < 10+j; l++)
{
    if(buff[l] == 0){
        void_bites++;
    }
}



// read a metada content
printf("\n");
for (int k = j+5+void_bites; k < dataToRead+j+7; k++) 
{

if(buff[k] == 0){
    continue;
}


data[bytes_read] = buff[k];
bytes_read++;

}

data[bytes_read] = '\0';
j = bytes_read+j+7;

*i = j;
}




int main(int argc,char *argv[]){
char buff[1524680];
if(argc != 2){
    printf("Error: Invalid number of arguments\n");
    exit(-1);
}

int file = open(argv[1],O_RDONLY);
FILE *fp = fopen("./image.jpg","wb");

int read_ch = read(file,buff,1524680);
 char title[256];
 char artist[256];
 char address_email[256];
 char date_public[256];


 int size_image = 1268241;
 char ramdon_data[size_image];

;
for(int i=3;i<read_ch;i++){

if(buff[i]=='T' && buff[i+1]=='I' && buff[i+2]=='T' && buff[i+3]=='2'){
i=i+3;
int title_bytes = buff[i+4];
ExtractData(title_bytes,buff,&i,title);
}


if(buff[i]=='T' && buff[i+1]=='P' && buff[i+2]=='E' && buff[i+3]=='1'){
i=i+3;
int artist_bytes = buff[i+4];
ExtractData(artist_bytes,buff,&i,artist);
}


if(buff[i]=='P' && buff[i+1]=='O' && buff[i+2]=='P' && buff[i+3]=='M'){
i=i+3;
int artist_bytes = buff[i+4];
ExtractData(artist_bytes,buff,&i,address_email);
}

if(buff[i]=='T' && buff[i+1]=='D' && buff[i+2]=='R' && buff[i+3]=='C'){
i=i+3;
int artist_bytes = buff[i+4];
ExtractData(artist_bytes,buff,&i,date_public);
}

if(buff[i]=='A' && buff[i+1]=='P' && buff[i+2]=='I'){




}


if(buff[i]=='P' && buff[i+1]=='N' && buff[i+2]=='G'){



int o = 0;
fwrite(&buff[i-1],1,1,fp);

for (int k = i; k<1524680; k++)
{

fwrite(&buff[k],1,1,fp);

// IEND
if( buff[k-3] == 'I' && buff[k-2] == 'E' && buff[k-1] == 'N' && buff[k] == 'D'){

break;

}


}






}


}
printf("extracted metadata\n");
printf("title:%s\n",title);
printf("artist:%s\n",artist);
printf("address:%s\n",address_email);
printf("date:%s\n",date_public);
printf("image extracted in ./image.png");


 return 0;

}
