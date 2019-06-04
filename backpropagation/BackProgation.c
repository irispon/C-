#include<stdio.h>
#include <stdlib.h>       //srand
#include <time.h>     //time
#include <string.h> 
#include <math.h>

#define getSize(X) sizeof(X)/sizeof(X[0])
#define INPUTMAX 101
#define OUTPUTMAX 10
#define HIDDENMAX 21
#define TARGETMAX 10
#define MAX_LENGTH 100
#define MAIN_CONTEXT 10
#define RANDMAX 32767
#define RUNNINGMATE 0.00005

#define INDEX 10

/*��� �ϳ� = 9���� 10ĭ ����(1ĭ ����)*/
struct TextFile{
	
int index;
//char context[10][200];
double input_data[10][10];
	
	
}typedef TextFiles;


double inputTohiddenSigma(int,int);
double hiddenToouputSigma(int ,int);
void training(int,int);
void test(int,int);
int pare();
void readFile();
double sigmoid(double);
double sigmoid2(double);
/*������*/
double InputNodes[INPUTMAX];
double HiddenNodes[HIDDENMAX];
double outputs[OUTPUTMAX];
double low_hidden_weight[INPUTMAX][HIDDENMAX-1];	
double midle_high_weight[HIDDENMAX][OUTPUTMAX];


TextFiles InputData[INDEX][500];
int length=0;
int datalength=0;
	


int main(void){
	
InputNodes[0]=1;
HiddenNodes[0]=1;/*�ٺ� ����*/

printf("\n\n����ġ �ʱ�ȭ\n\n");
srand( (unsigned)time(NULL) );

int i = 0;
int j = 0;
float max =RANDMAX;


/*�ο�-> ���� ����ġ */
printf("row->hidden weight \n");
for(i=0;i<101;i++){
	for(j=0;j<20;j++){
		low_hidden_weight[i][j] = rand()/max;
		
		}

	
	}

/*����->��ǲ ����ġ*/
printf("hidden->input weight \n");
for(i =0;i<21;i++){
	for(j=0;j<10;j++){
		midle_high_weight[i][j] = rand()/max;
	//	printf(" %f ",midle_high_weight[i][j]);
		
	}
	

} 

/*���� �ø��� indexing*/
readFile();
int count=1;



printf("\n\n");
printf("pair \n");


//pare(10);
//while(){
//	

//	
//}	
//	
//}	

	while(pare(90)){
	for(i =0;i<datalength;i++){
	for(j=0;j<10;j++){
		training(j,i);
		
	}
		
		
	}
}
//
//	training(0,1);
//	training(1,1);
//
//printf("\n\n");







 









}

void training(int index,int count){

 int i = 0;
 int j = 0;
 int k = 1;
 double HM_distance[OUTPUTMAX];//Ÿ�� ���Ϳ�����   
 double ML_distance[HIDDENMAX];
 double targetVector[OUTPUTMAX];
 double middle_low_correction[INPUTMAX][OUTPUTMAX];
 double midle_high_weight_correction[HIDDENMAX][OUTPUTMAX];
 targetVector[index]=1;
 

 for(i = 0; i<10;i++){

 	for(j=0; j<10;j++){
 		 	InputNodes[k]= InputData[index][count].input_data[i][j];
 			k++;
 		/*��� �ʱ�ȭ */
	 }
 	
 }
 
 
// for(i =1;i<101;i++){
// 	
// 	printf("  %f  ",InputNodes[i]);
// }
//	

/*hidden nodes�� �ö�*/


for(i=1;i<HIDDENMAX;i++ ){
	HiddenNodes[i]= sigmoid(inputTohiddenSigma(i,INPUTMAX));
	
//	printf(" %f ",HiddenNodes[i]);	
	
} 
//	printf("\n\n");
/*output layer�� �ö� */
//printf("\n\n");	
for(i=0;i<OUTPUTMAX;i++){
	
	outputs[i]= sigmoid(hiddenToouputSigma(i,HIDDENMAX));
	
//	printf(" %f ",outputs[i]);	
}

//printf("\n\n");
/*Error Ȯ��*/
for(i=0;i<OUTPUTMAX;i++){
	HM_distance[i]=(targetVector[i]-outputs[i])*sigmoid2(outputs[i]);
//	printf(" %f ",HM_distance[i]);
} 


/*output -> hidden ���� */
for(i=0;i<HIDDENMAX;i++){
	for(j=0;j<OUTPUTMAX;j++){
		
		midle_high_weight_correction[i][j]=RUNNINGMATE*HM_distance[j]*HiddenNodes[i];
	}
	
}


/*hidden->input*/
double tmp_hidden[HIDDENMAX][OUTPUTMAX];

for(i=0;i<HIDDENMAX;i++){
	for(j=0;j<OUTPUTMAX;j++){
		
		tmp_hidden[i][j]=HM_distance[j]*midle_high_weight[i][j];
		
	}
	}
	
for(i=0;i<HIDDENMAX;i++){
	for(j=0;j<OUTPUTMAX;j++){
		
			ML_distance[i]=ML_distance[i]+(tmp_hidden[i][j]*midle_high_weight[i][j]);
	}


	
}

for(i=0;i<INPUTMAX;i++){
	for(j=0;j<HIDDENMAX;j++){
		
		middle_low_correction[i][j]=RUNNINGMATE*ML_distance[j]*InputNodes[i];
	}
	
}

for(i=0;i<HIDDENMAX;i++){
	for(j=0;j<OUTPUTMAX;j++){
		
		midle_high_weight[i][j]=midle_high_weight[i][j]+midle_high_weight_correction[i][j];
		
	}
}

for(i=0;i<INPUTMAX;i++){
	for(j=0;j<HIDDENMAX;j++){
		
		low_hidden_weight[i][j]=middle_low_correction[i][j]+midle_high_weight_correction[i][j];
		
	}
}


}


int pare(double target){

int index;
int count;
double account=0;
double success=0;
int i=0;
int j=0;
int k=1;
int result=0;
double tmp= outputs[0];

for(count=0;count<datalength;count++){
	for(index=0;index<10;index++){
		
		account++;
		k=1;
	 for(i = 0; i<10;i++){

 	for(j=0; j<10;j++){
 		 	InputNodes[k]= InputData[index][count].input_data[i][j];
 			k++;
 			
 		/*��� �ʱ�ȭ */
	 }
 			
 }
 
//printf("\nindex:%d \n\n",index);
//printf("count:%d \n\n",count);

 
 	//printf("\n ");
for(i=1;i<HIDDENMAX;i++ ){
	
	HiddenNodes[i]= sigmoid(inputTohiddenSigma(i,INPUTMAX));
  //  printf("%f  ", HiddenNodes[i]);
}
 //	printf("\n--------------\n");
for(i=0;i<OUTPUTMAX;i++){
	
	outputs[i]= sigmoid(hiddenToouputSigma(i,HIDDENMAX));
}



tmp= outputs[0];
for(i=0;i<OUTPUTMAX;i++){
	if(tmp<outputs[i]){
	//    printf("\n tmp  %f ->  result  %f",tmp,outputs[i]);
	 	tmp=outputs[i];
		result=i;


	}
	
}
//	printf("\n\nresult:%d   index:%d\n\n",result,index);
if(result==index){
	
	success++;
//	printf("\n\nsuccess! \n\n");
}




 }
}
	

printf("\nSuccess, Account %f  %f\n",success,account);	
if(target<(success/account)*100){
	
	return -1;
}else{
	
	return 1;
}


	
} 

void test(int index, int count){

double account=0;
double success=0;
int i=0;
int j=0;
int k=1;
int result=0;
double tmp= outputs[0];


	for(i = 0; i<10;i++){

 	for(j=0; j<10;j++){
 		 	InputNodes[k]= InputData[index][count].input_data[i][j];
 		 	//printf("%f  ",InputNodes[k]);
 		 	//printf("%f  ", InputNodes[k]);
 			k++;
 			
 		/*��� �ʱ�ȭ */
	 }
 			
 }
 
 	//printf("\n ");
for(i=1;i<HIDDENMAX;i++ ){
	HiddenNodes[i]= inputTohiddenSigma(i,INPUTMAX);
	//printf("%f  ",HiddenNodes[i]);
} 

for(i=0;i<OUTPUTMAX;i++){
	
	outputs[i]= hiddenToouputSigma(i,HIDDENMAX);
}



tmp= outputs[0];
for(i=0;i<OUTPUTMAX;i++){
	if(tmp<outputs[i]){
	//	printf("\n tmp%f ->  result%f",tmp,outputs[i]);
	 	tmp=outputs[i];
		result=i;


	}
	
}

if(result==index){
	
	success++;
	
}

//printf("\n\n");

	
} 
//
//void test(int index,int count){
//
// int i = 0;
// int j = 0;
// int k = 1;
// double distance;//Ÿ�� ���Ϳ�����   
//
//
//
//
// for(i = 0; i<10;i++){
//
// 	for(j=0; j<10;j++){
// 		 	InputNodes[k]= InputData[index][count].input_data[i][j];
// 			k++;
// 		/*��� �ʱ�ȭ */
//	 }
// 	
// }
// 
//
//for(i=1;i<HIDDENMAX;i++ ){
//	HiddenNodes[i]= sigmoid(inputTohiddenSigma(i,INPUTMAX));
//	
//	printf(" %f ",HiddenNodes[i]);	
//} 
//
//printf("\n\n");	
//for(i=0;i<OUTPUTMAX;i++){
//	
//	outputs[i]= sigmoid(hiddenToouputSigma(i,HIDDENMAX));
//	printf(" %f ",outputs[i]);	
//}
//
//int result=0;
//double tmp= outputs[0];
//
//for(i=0;i<OUTPUTMAX;i++){
//	if(tmp<outputs[i]){
//	 	tmp=outputs[i];
//		result=i;
//	}
//	
//}
//
//printf("\n\n���: %d ",result);
//
//
//}


//readFile();
//Node inputnode[INPUTMAX];
//Node additionalNode;
//initialize(inputnode);
//check(inputnode);


//�ñ׸��̵� 
double sigmoid(double x){
	double result = 1/(1+exp(-x));	
	return result;
	
}

double sigmoid2(double x) // �̺��� �ñ׸��̵� �Լ�

{
	double result =sigmoid(x)*(1-sigmoid(x));
return  result;

}

double inputTohiddenSigma(int nodeNumber,int toSize){
 int i = 0;
 double result=0;
	
 	for(i=0;i<toSize;i++){
 		
 		result =result+(InputNodes[i]*low_hidden_weight[i][nodeNumber]);

 		//printf(" %f ",result);
	 }
       //printf("\n\n");
 	
 	return result;
 




}

double hiddenToouputSigma(int nodeNumber,int toSize){
 int i = 0;
 double result=0;

 	for(i=0;i<toSize;i++){
 		
 		result =result+(InputNodes[i]*midle_high_weight[i][nodeNumber]);
	 }
 
 	
 	return result;
 


}




	
   


void readFile(){
	
	int line_count =0;//�� ��  
	int data_count=0; //input data count��(��� ī��Ʈ)
	int data_index=0;
	int index_tmp=0;
	

	
	int index =1;
	int indexline=0;
	int mainContext = index+index*MAIN_CONTEXT;


	int setData=0;
	char buffer[MAX_LENGTH]; 


	int i = 0;  
    FILE *fp =NULL;
	 if(0==fopen_s(&fp,"train.txt", "rt")){
	 	
	 	while(fgets(buffer,MAX_LENGTH,fp)){
	 		
			//	printf("\n\n����: %s \n\n",buffer);
				
			if(line_count==11){	
			 	line_count =0;
			 	data_count++;		 
			}
	 		
	 	    if(line_count==0){
	 	    	index = atoi(buffer);
	 	    	if(index!=index_tmp){
	 	    		datalength=data_count;
	 	    		data_count=0;
				 }
	 			InputData[index][data_count].index =atoi(buffer); 
	 			index_tmp = index;
	 	 //	printf("index:%d \n",InputData[index][data_count].index);
	 			line_count++;
			 }else if(line_count<11){
	 		//	strcat(InputData[index][data_count].context[line_count-1],buffer);
	 			
	 			char *ptr = strtok(buffer, " ");      // " " ���� ���ڸ� �������� ���ڿ��� �ڸ�, ������ ��ȯ
				 while (ptr != NULL)               // �ڸ� ���ڿ��� ������ ���� ������ �ݺ�
				{
				   InputData[index][data_count].input_data[line_count-1][i]=(double)atof(ptr);
				  // printf("����:\n%f\n", InputData[index][data_count].input_data[line_count-1][i]);          // �ڸ� ���ڿ� ���
				   ptr = strtok(NULL, " ");      // ���� ���ڿ��� �߶� �����͸� ��ȯ
				   i++;
				}
				i=0;
	 		//	printf("context: %s\n",InputData[index][data_count].context[line_count-1]);
	 			line_count++;
	 			 
			 }

			length++;
		}
			
		fclose(fp);
			
		}
		printf("��ü ���� %d\nIndex �絥���� �� :%d \n",length,datalength);


		
		
  		
		 
}
		 

  





