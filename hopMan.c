#include<stdio.h>

typedef struct hopmanNode {
int number;
char text;
struct hopmanNode* Right;
struct hopmanNode* Left	;	
	
}HopManNode;

HopManNode* newHopManNode(int,char,HopManNode*,HopManNode*);


int main(void){

char asci[127]="";
printf("³Ä? %c,%c ",asci[0],asci[1]);

HopManNode *node = newHopManNode(1,'A',NULL,NULL);
HopManNode *node2 = newHopManNode(2,'B',NULL,NULL);
HopManNode *node3 = newHopManNode((node->number)+(node2->number),'A',node,node2);

printf("³Ä? %d, %d,%c,%c",node3->number,node3->Left->number,node3->Right->text,node3->text);

}


HopManNode* newHopManNode(int number,char text ,HopManNode* Left ,HopManNode* Right){
	
	HopManNode *node = (HopManNode*)malloc (sizeof(HopManNode));
	if(Right!=NULL&&Left!=NULL){
		node->number =number;
		node->text =NULL;
		node->Left= Left;
		node->Right = Right;
		
			
	}else{
		
		node->number =number;
		node->text = text;		
	}
	
	return node;	
}


