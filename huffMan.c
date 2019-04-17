#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 127
#define BUFFER 150
#define INPUT "input.txt"


typedef struct hopmanNode {
int number;
char text;
struct hopmanNode* Right;
struct hopmanNode* Left	;	
	
}HopManNode;

/*함수들*/
HopManNode* newHopManNode(int,char,HopManNode*,HopManNode*);
void init();
void readFile(char **,int*);
void sort();
/*변수들*/
HopManNode* nodes[MAX];//배열 테스트용 
HopManNode**nodesArray; //동적 노드 포인터 배 열 
char asci[MAX]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";// 아스키 문자의 경우(알파벳만)  


int main(void){
	
init();
sort();
int a = 0;

for( ; nodesArray[a]!=NULL ; a++) {
    printf("\n문자%c , 빈도%d",nodesArray[a]->text,nodesArray[a]->number);
    }



    
}




void init(){
char* fromText;//읽어온 텍스트
int size;
int i=0;
int j=0;
int arraySize=0;
int nodesCount=0;
int count=0;


readFile(&fromText,&size);


printf("%s",fromText,sizeof(fromText));
 
nodesArray = (HopManNode**)malloc(size*sizeof(HopManNode**));//노드 배열 선언 

 
 
for(i;asci[i]!='\0';i++){
	
for(j;j<size&&(fromText[j]!='\0');j++){
	
	if(fromText[j]==asci[i]){
		count++;
	
	}

}
	if(count!=0){
	
	printf("\n%c의 빈도수: %2d  ",asci[i],count);
	nodes[nodesCount] = newHopManNode(count,asci[i],NULL,NULL);
	nodesArray[nodesCount]=newHopManNode(count,asci[i],NULL,NULL);
	nodesCount++;
	count=0;
}

j=0;
	
}





free(fromText);



}








HopManNode* newHopManNode(int number,char text ,HopManNode* Left ,HopManNode* Right){
	
	HopManNode *node = (HopManNode*)malloc (sizeof(HopManNode));
	if(Right!=NULL&&Left!=NULL){
		node->number =number;
		node->text= '\0';
		node->Left= Left;
		node->Right = Right;
		
			
	}else{
		
		node->number =number;
		node->text = text;		
	}
	
	return node;	
}





void readFile(char **buffer,int* refsize){

	int size;

    FILE *fp = fopen(INPUT, "r");
	fseek(fp, 0, SEEK_END);

	size = ftell(fp);

    *buffer = (char*)malloc(size + 1);

    memset(*buffer, 0, size + 1);

    fseek(fp, 0, SEEK_SET);

    fread(*buffer, size, 1, fp);
    *refsize =size;

    fclose(fp);

}

void sort(){
	/*선택정렬*/
	
	
	
	HopManNode**temp;
	int i=0;
	int j=0;
	
for(i = 0 ; nodesArray[i+1]!=NULL ; i++) {
    for(j = i+1 ;nodesArray[j]!=NULL ; j ++) {
        if(nodesArray[i]->number> nodesArray[j]->number) {
            temp = nodesArray[j];
            nodesArray[j] =nodesArray[i];
            nodesArray[i] = temp;
       }
    }
}

	
	
	
} 
