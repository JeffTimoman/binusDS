#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Nama Kelompok 3:
1. Caroline Natalia Amran / 2602189171 / PPTI 14
2. Muhammad Arya Aqilah Fauzan / 2602189316 / PPTI 14
3. Peter Pratama Mulyadi / 
4. Putu Aryasatya Dharma Kenzhie / 
5. Valina Evelyn Pranoto / 2602189354 / PPTI 14
*/

int size = 0;
int flag = 0;

struct emp
{
  /* data */
  char name[100];
  char department[100];
}eDetail;

struct comp{
    //1 - 6
    float compA;
    float compB;
    float compC;
    float compD;
    float compE;
}kpiComp;

struct kpi
{
    /* data */
    int idEmployee;
    emp empDetail;
    comp components;
    //sum setiap komponen
    float kpiScore;

}KPI;

kpi empKPI[1000];

void swap(kpi *a, kpi *b){
		kpi temp = *a;
 		*a = *b;
  	*b = temp;
}

int partitionScore(int l, int r){
	float pivot = empKPI[r].kpiScore;
  int i = l-1;
  
  for(int j = l; j < r; j++){
    if(flag == 1){
			if(empKPI[j].kpiScore < pivot){
        	i++;
			swap(&empKPI[i], &empKPI[j]);
      }
    }else {
			if(empKPI[j].kpiScore > pivot){
        	i++;
			swap(&empKPI[i], &empKPI[j]);
      }
    }
			// if(empKpi[j].Score < pivot){
			// i++;
			// 		swap(empKpi[i].score, empKpi[j].score);
			// }
  }
  
  swap(&empKPI[i+1], &empKPI[r]);
  return i+1;
}

int partitionId(int l, int r){
	int pivot = empKPI[r].idEmployee;
  int i = l-1;
  
  for(int j = l; j <= r; j++){
    if(flag == 1){
		if(empKPI[j].idEmployee < pivot){
       		i++;
			swap(&empKPI[i], &empKPI[j]);
      }
    }else {
		if(empKPI[j].idEmployee > pivot){
        	i++;
			swap(&empKPI[i], &empKPI[j]);
      }
    }
			// if(empKpi[j].Score < pivot){
			// i++;
			// 		swap(empKpi[i].score, empKpi[j].score);
			// }
  }
  
  swap(&empKPI[i+1], &empKPI[r]);
  return i+1;			
}

void quicksortScore(int l, int r){
	if(l < r){
			int pivot = partitionScore(l, r);
    	quicksortScore(l, pivot - 1);
    	quicksortScore(pivot + 1, r);
  }
}

void quicksortId(int l, int r){
	if(l < r){
		int pivot = partitionId(l, r);
    	quicksortId(l, pivot - 1);
    	quicksortId(pivot + 1, r);
  }
}


void deleteData(kpi empKpi[]){
    int indeks;

    // do{
    //     scanf("%d", &indeks); getchar();
    // }while(indeks < 1 || indeks > size);
  	printf("Input ID : ");
  	scanf("%d", &indeks); getchar();

    for(int i = 0; i < size; i++){
      	if(empKpi[i].idEmployee == indeks){
          for(int j=i; j<size-1; j++){
            empKpi[j] = empKpi[j+1];
          }
          break;
        }
    }

    size--;
}

void inputData(kpi empKpi[]){
  	int i = size;
  	int temp = size;
    int n;
  	printf("Input how many employee : ");
  	scanf("%d", &n); getchar();
  	while(i<n+temp){
		printf("Input Data: \n");
      empKpi[i].idEmployee = i+1;
      printf("ID Employee: %d\n", empKpi[i].idEmployee); 
	    // scanf("%d",&empKpi[i].idEmployee);
      // getchar();
      printf("Employee Name: "); 
	    scanf("%[^\n]", &empKpi[i].empDetail.name);
//      printf("")
      getchar();
        do{
            printf("Enter comp A: ");
            scanf("%f", &empKpi[i].components.compA); getchar();
        }while(empKpi[i].components.compA > 6 || empKpi[i].components.compA < 1);
      
        do {
            printf("Enter comp B: ");
            scanf("%f", &empKpi[i].components.compB); getchar();
        }while(empKpi[i].components.compB > 6 || empKpi[i].components.compB < 1);

        do {
            printf("Enter comp C: ");
            scanf("%f", &empKpi[i].components.compC); getchar();
        }while(empKpi[i].components.compC > 6 || empKpi[i].components.compC < 1);

        do {
            printf("Enter comp D: ");
            scanf("%f", &empKpi[i].components.compD); getchar();
        }while(empKpi[i].components.compD > 6 || empKpi[i].components.compD < 1);

        do {
            printf("Enter comp E: ");
            scanf("%f", &empKpi[i].components.compE); getchar();
        }while(empKpi[i].components.compE > 6 || empKpi[i].components.compE < 1);
      

        empKpi[i].kpiScore += ((empKpi[i].components.compA + empKpi[i].components.compB + empKpi[i].components.compC + empKpi[i].components.compD + empKpi[i].components.compE) / 5);
        i++;
     		size++;
    }
}

void printData(kpi empKpi[], int n){
    char pilihan[10];
    char ding[15];
  	flag = 0;
    do{
      	printf("Sorting based on? [id / score] : ");
      	scanf("%[^\n]", pilihan); getchar();
    }while(strcmp(pilihan, "id")!=0 && strcmp(pilihan, "score")!=0);

    if(strcmp(pilihan, "id")==0){
        do{
          printf("ascending / descending : ");
          scanf("%[^\n]", ding); getchar();
          if(strcmp(ding, "ascending")==0){
            flag = 1;
          }
          else if(strcmp(ding, "descending")==0){
            flag = 2;
          }
        }while(strcmp(ding, "ascending")!= 0 && strcmp(ding, "descending")!=0);
//        swap(&empKpi[0], &empKpi[size]);
     	  quicksortId(0, size-1);
    }
  
  else{
    do{
          printf("ascending / descending : ");
          scanf("%[^\n]", ding); getchar();
          if(strcmp(ding, "ascending")==0){
            flag = 1;
          }
          else if(strcmp(ding, "descending")==0){
            flag = 2;
          }
        }while(strcmp(ding, "ascending")!=0 && strcmp(ding, "descending")!=0);
//        swap(&empKpi[0], &empKpi[size-1]);
     	  quicksortScore(0, size-1);
  }
  
  	  	printf("|ID\t|Name\t|A\t|B\t|C\t|D\t|E\t|KPI Score|\n");
  	for(int i = 0; i < size; i++){
  		printf("|%d\t|%s\t|%.2f\t|%.2f\t|%.2f\t|%.2f\t|%.2f\t|%.2f|\n", empKpi[i].idEmployee, empKpi[i].empDetail.name,
		  empKpi[i].components.compA, empKpi[i].components.compB, empKpi[i].components.compC,
		  empKpi[i].components.compD, empKpi[i].components.compE, empKpi[i].kpiScore);
  	// for(int i = 0; i < size; i++){
				// printf("ID Employee: %d\n", empKpi[i].idEmployee);
				// printf("Employee Name: %s\n",empKpi[i].empDetail.name);
				// printf("Comp A: %.2f\n", empKpi[i].components.compA);
				// printf("Comp B: %.2f\n", empKpi[i].components.compB);
				// printf("Comp C: %.2f\n", empKpi[i].components.compC);
				// printf("Comp D: %.2f\n", empKpi[i].components.compD);
				// printf("Comp E: %.2f\n", empKpi[i].components.compE);
				// printf("Kpi Score: %.2f\n", empKpi[i].kpiScore);
				// printf("\n");
    }
}

int findIndex(kpi empKpi[], int n, int id){
    int i = 0;
    while(i < n && empKpi[i].idEmployee != id){
        i++;
    }
    if(i < n){
        return i;
    }
    else{
        return -1;
    }
}


void findData(kpi empKpi[]){
    int inputFind;
  	do{
      	printf("Input ID to find: ");
      	scanf("%d", &inputFind); getchar();
    }while(inputFind < 1 || inputFind > size);
    
    int index = findIndex(empKpi, size, inputFind);
    
    if (index != -1){
        printf("ID Employee: %d\n", empKpi[index].idEmployee);
        printf("Employee Name: %s\n",empKpi[index].empDetail.name);
        printf("Comp A: %.2f\n", empKpi[index].components.compA);
        printf("Comp B: %.2f\n", empKpi[index].components.compB);
        printf("Comp C: %.2f\n", empKpi[index].components.compC);
        printf("Comp D: %.2f\n", empKpi[index].components.compD);
        printf("Comp E: %.2f\n", empKpi[index].components.compE);
        printf("Kpi Score: %.2f\n", empKpi[index].kpiScore);
    }
    else{
        printf("Data not found\n");
    }
}

void menu(){
   	// system("CLS");
    printf("1. Input Data\n");
    printf("2. Print Data\n");
  	printf("3. Delete Data\n");
  	printf("4. Find Data\n");
    printf("0. Exit\n");
}

int main(){
    
    int inp = 1;
  
    while (inp != 0)
    {
        menu();
        printf("Choose >> ");
        scanf("%d",&inp); getchar();
        switch (inp)
        {
        case 1:
            inputData(empKPI);
            break;
        
        case 2:
            printData(empKPI, size);
            break;
        
        case 3:
            deleteData(empKPI);
            break;
				
        case 4:
            findData(empKPI);
            
        default:
            break;
        }
     
    }
    printf("THANK YOU");
    
    return 0;
    
}