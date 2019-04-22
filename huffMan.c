#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 127
#define BUFFER 150
#define INPUT "input.txt"
#define OUTPUT "output.txt"
#define DECODE "decode.txt"

typedef struct huffmanNode {
int freq;
char character;
struct huffmanNode* Right;
struct huffmanNode* Left;	
struct huffmanNode* parent;	
}huffmanNode;

/*함수들*/
huffmanNode* newhuffmanNode(int,char,huffmanNode*,huffmanNode*);
void init();
void readFile(char[],char **,int*);
void sort();
void setTree();
void treeSearch(char ,huffmanNode*);
void encode(); 
void decode(); 
/*변수들*/
huffmanNode* nodes[MAX];//배열 테스트용 
huffmanNode**nodesArray; //동적 노드 포인터 배 열 
char asci[MAX]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";// 아스키 문자의 경우(알파벳만)  
int arraySize=0;// 
char* fromText;//읽어온 텍스트


int main(void){
		
init();
printf("\n배열크기: %d",arraySize);
setTree();
encode();
decode(); 
free(nodesArray);
free(fromText);

}




void init(){

int size;
int i=0;
int j=0;
int nodesCount=0;
int count=0;
 
/*아웃풋파일 초기화.*/
FILE *fp = fopen(OUTPUT, "w");
fprintf(fp,"");
fclose(fp);
fp = fopen(DECODE, "w");
fprintf(fp,"");
fclose(fp);

readFile(INPUT,&fromText,&size);
printf("%s",fromText,sizeof(fromText));
nodesArray = (huffmanNode**)malloc(size*sizeof(huffmanNode**));//노드 배열 선언 
memset(nodesArray,NULL,size*sizeof(huffmanNode**));
arraySize=size; 


for(i;asci[i]!='\0';i++){
	
for(j;j<size&&(fromText[j]!='\0');j++){
	
	if(fromText[j]==asci[i]){
		count++;	
	}

}
	if(count!=0){
	
	printf("\n%c의 빈도수: %2d  ",asci[i],count);
	nodesArray[nodesCount]=newhuffmanNode(count,asci[i],NULL,NULL);
	nodesCount++;
	count=0;
}

j=0;
	
}

}






/*트리노드 생성*/

huffmanNode* newhuffmanNode(int freq,char character ,huffmanNode* Left ,huffmanNode* Right){
	
	huffmanNode *node = (huffmanNode*)malloc (sizeof(huffmanNode));
	if(Right!=NULL&&Left!=NULL){
		node->freq =freq;
		node->character= '\0';
		node->Left= Left;
		node->Right = Right;
		node->parent = NULL;
			
	}else{
		
		node->freq =freq;
		node->character = character;
		node->Left= NULL;
		node->Right = NULL;	
		node->parent = NULL;	
	}
	
	return node;	
}


/*파일 읽어오는 부분*/
void readFile(char filename[30],char **buffer,int* refsize){

	int size;

    FILE *fp = fopen(filename, "r");
	fseek(fp, 0, SEEK_END);

	size = ftell(fp);

    *buffer = (char*)malloc(size + 1);

    memset(*buffer, 0, size + 1);

    fseek(fp, 0, SEEK_SET);

    fread(*buffer, size, 1, fp);
    *refsize =size;

    fclose(fp);

}


 

/*선택정렬*/
void sort(){

	huffmanNode*temp;
	int i=0;
	int j=0;

int c=0; 


for(i = 0 ;i<arraySize-1 ; i++) {

    for(j = i+1 ;j<arraySize; j ++) {
    	if(nodesArray[i]!=NULL&&nodesArray[j]!=NULL){
	
        if(nodesArray[i]->freq> nodesArray[j]->freq) {
            temp = nodesArray[j];
            nodesArray[j] =nodesArray[i];
            nodesArray[i] = temp;
            
         
       }
       
       	}
    }
    	if(nodesArray[i]==NULL){
	
		}
    	
}
	printf("\n\n   정렬결과");
for(i = 0 ;i<arraySize ; i++) {
    	if(nodesArray[i]!=NULL){

			printf("\n문자:%c, 빈도수: %d",nodesArray[i]->character,nodesArray[i]->freq);   
			
 
       	}
    }

    
}

	


void setTree(){

	
if(nodesArray[1]==NULL){
	
printf("\n\n 트리구성 완료\n\n");	
	
}else{
sort();
int nullPoint =0;	
huffmanNode* parentsNode;
huffmanNode* tmpNode;
parentsNode=newhuffmanNode((nodesArray[0]->freq)+(nodesArray[1]->freq),NULL,nodesArray[1],nodesArray[0]);
printf("\n\n 트리 생성:%d",parentsNode->freq);
nodesArray[0]->parent = parentsNode;
nodesArray[1]->parent = parentsNode;
nodesArray[0]=parentsNode;

for(nullPoint=0;nullPoint<arraySize;nullPoint++){
	
	if(nodesArray[nullPoint]==NULL){
		nodesArray[1]=nodesArray[nullPoint-1];
		nodesArray[nullPoint-1]=NULL;
		break;
	}
	
}

setTree();

}


	
}


void encode(){
int i;
for(i=0;fromText[i]!='\0';i++){
	 treeSearch(fromText[i],nodesArray[0]);
	
	
	
}	
	
	
}

void decode(){
int size;
char* outputText;
char intput;
huffmanNode node = *nodesArray[0];
readFile(OUTPUT,&outputText,&size);


FILE *f;
f=fopen(DECODE,"a");

int i =0;
for(;outputText[i]!='\0';i++){

if(outputText[i]=='0'){
	
	if(node.Left->character=='\0'){
		node = *node.Left;
		printf("\noutputText[i] %c  %d",outputText[i], i);
		
	}else{
		intput = node.Left->character;
		
		printf("\ninput: %c %d",intput, i);
		fprintf(f,"%c",intput);
		
		node = *nodesArray[0];
		
	}
	
}
else if(outputText[i]=='1'){
		if(node.Right->character=='\0'){
		node = *node.Right;
		printf("\noutputText[i] %c  %d",outputText[i], i);
		

	}else{

		intput = node.Right->character;
		printf("\ninput: %c %d",intput, i);
		fprintf(f,"%c",intput);
		node = *nodesArray[0];
	}
	
	
}else{
	printf("\n4 ");
	break; 
}
	
	
}

fclose(f);




free(outputText);
	
	
}

void treeSearch(char character,huffmanNode*node){
//	printf("->%d",node->freq,character);
	//   strcat(s2, s1);  s2 뒤에 s1를 붙임 strrev(  ) 문자열 뒤집기 
	if(character==(node->character)){
		char binary[30]="";
		int i;
		int j;
		huffmanNode currentNode=*node;
		huffmanNode parent;
		for(;currentNode.parent!=NULL;){
			parent = *currentNode.parent;
			if(currentNode.freq<parent.Left->freq){
				strcat(binary, "1");
			
			}else{
				strcat(binary, "0");
				
			}
			currentNode = parent;
			
			
		}
		strrev(binary); 
		printf("\n%c코드: %s",character,binary);
		FILE *f;
		f=fopen(OUTPUT,"a");
		fprintf(f,binary);
		fclose(f);
		
		return binary;
		
	}else{
		
		if(node->Right!=NULL){
			
			treeSearch(character,node->Right);
			
		}
		
		if(node->Left!=NULL){
		
			treeSearch(character,node->Left);
			
		}
	
		
	}
	
	return '0';
}
