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

/*변수들*/
HopManNode* nodes[MAX];
HopManNode *nodesArray; 
char asci[MAX]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";// 아스키 문자의 최대 경우(일단 알파벳만)  
char* file();

int main(void){
	
init();



}


void init(){
char* fromText;//읽어온 텍스트
int size;
int i=0;
int j=0;
int nodesCount=0;
int count=0;


readFile(&fromText,&size);


printf("%s",fromText,sizeof(fromText));
 
 for(i;asci[i]!='\0';i++){
	
for(j;j<size&&(fromText[j]!='\0');j++){
	
	if(fromText[j]==asci[i]){
		count++;
	
	}

}
	

j=0;
	
}
 
 nodesArray = (HopManNode*)malloc(i*sizeof(HopManNode));
 i=0;
 
for(i;asci[i]!='\0';i++){
	
for(j;j<size&&(fromText[j]!='\0');j++){
	
	if(fromText[j]==asci[i]){
		count++;
	
	}

}
	if(count!=0){
	
	printf("\n%c의 빈도수: %2d  ",asci[i],count);
	nodesArray[nodesCount] = newHopManNode(count,asci[i],NULL,NULL);
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




//void nodeSorting(HopManNode*nodes[],int size){
// int i=0;
// int j=0;
// int min=0;
// HopManNode* nodeTmp=NULL;
// HopManNode* sortingNodes[MAX];
// 
// 
// for(i;nodes[i]!=NULL;i++){
// 	nodeTmp = nodes[i];
// 	for(j=i;j<(size/sizeof(nodes[0]))&&(nodes[j]!=NULL);j++){
// 		
//		if(nodeTmp->number>nodes[j]->number){
//		   nodeTmp=nodes[j];				
//			 
//		}	
// 		
//	 }
// 	sortingNodes[j]=nodeTmp;
// 	printf("\n%c,%d",sortingNodes[i]->text,sortingNodes[i]->number);
// 	
// }
//
// nodes= sortingNodes;
// 
//
//}
