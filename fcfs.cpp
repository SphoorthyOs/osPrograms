#include<stdio.h>

int queue[10][4],n;

void getWTTime(){

    queue[0][1] = 0;
    queue[0][2] = queue[0][0];
    for(int i=1;i<n;i++){
        queue[i][1] = queue[i-1][1] + queue[i-1][0];
        queue[i][2] = queue[i][0] + queue[i][1];
    }

}


void display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",queue[i][j]);
        }
        printf("\n");
    }
}

int main(){

    float awt = 0,atat = 0;

    printf("\nEnter number of processes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("\nEnter id and burst time of  process %d : ",i+1);
            scanf("%d", &queue[i][0]);
    }
    getWTTime();

    for(int i=0;i<n;i++){
        awt += queue[i][1];
        atat += queue[i][2];
    }

    display();

    printf("\nAverage waiting time = %f",awt/n);
    printf("\nAverage turn around time = %f",atat/n);

}