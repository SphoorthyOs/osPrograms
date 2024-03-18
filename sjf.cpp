#include<stdio.h>

int queue[10][3],n;

void getWTTime(){

    queue[0][2] = 0;
    for(int i=1;i<n;i++){
        queue[i][2] = queue[i-1][2] + queue[i-1][1];
    }

}

void rearrange(){
    int t1,t2;
    for(int i=0;i<n-1;i++){
    	for(int j=i+1;j<n;j++){
    	    if(queue[i][1]>queue[j][1]){
            	t1 = queue[i][0];
            	t2 = queue[i][1];
            	queue[i][0] = queue[j][0];
            	queue[i][1] = queue[j][1];
            	queue[j][0] = t1;
            	queue[j][1] = t2;    
			}
		}
    }
}

void display(){
    for(int i=0;i<n;i++){
    	printf("p[%d]\t",queue[i][0]);
        for(int j=1;j<3;j++){
            printf("%d\t",queue[i][j]);
        }
        printf("\n");
    }
}

int main(){

    float awt = 0;

    printf("\nEnter number of processes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("\nEnter Arraival time and burst time of  process %d : ",i+1);
        for(int j=0;j<2;j++){
            scanf("%d", &queue[i][j]);
        }
    }
    rearrange();
    getWTTime();

    for(int i=0;i<n;i++){
        awt += queue[i][2];
    }
    
    printf("\n-------------------------------------------------------------------------------\n");
    display();
    printf("\n-------------------------------------------------------------------------------\n");

    printf("\nAverage waiting time = %f",awt/n);

}