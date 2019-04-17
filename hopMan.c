
	
}HopManNode;

/*함수들*/
HopManNode* newHopManNode(int,char,HopManNode*,HopManNode*);
void init();


/*변수들*/
HopManNode* nodes[MAX];
char asci[MAX]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";// 아스키 문자의 최대 경우(일단 알파벳만) 
char fromText[BUFFER];//버퍼 


int main(void){
	
init();



}




void init(){
FILE *filePointer;
filePointer=fopen(INPUT, "r");
fscanf(filePointer, "%s" ,fromText);
printf("읽어온 부분 : %s \n", fromText);
fclose(filePointer);

int i=0;
int j=0;
int nodesCount=0;
int count=0;
 
for(i;asci[i]!='\0';i++){
	
for(j;j<sizeof(fromText)&&(fromText[j]!='\0');j++){
	
	if(fromText[j]==asci[i]){
		count++;
	
	}

}
	if(count!=0){
	
	printf("\n%c의 빈도수: %2d  ",asci[i],count);
	nodes[nodesCount] = newHopManNode(count,asci[i],NULL,NULL);
	nodesCount++;
	count=0;
}

j=0;
	
}

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
