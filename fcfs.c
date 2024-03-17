#include<stdio.h>

int queue[10][4],n;

void getWTTime(){

    queue[0][2] = 0;
    queue[0][3] = queue[0][1];
    for(int i=1;i<n;i++){
        queue[i][2] = queue[i-1][2] + queue[i-1][1];
        queue[i][3] = queue[i][1] + queue[i][2];
    }

}

void rearrange(){
    int t1,t2;
    for(int i=0;i<n-1;i++){
        if(queue[i][0]>queue[i+1][0]){
            t1 = queue[i][0];
            t2 = queue[i][1];
            queue[i][0] = queue[i+1][0];
            queue[i][1] = queue[i+1][1];
            queue[i+1][0] = t1;
            queue[i+1][1] = t2;    
        }
    }
}

void display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            printf("%d\t",queue[i][j]);
        }
        printf("\n");
    }
}

void main(){

    float awt = 0,atat = 0;

    printf("\nEnter number of processes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("\nEnter id and burst time of  process %d : ",i+1);
        for(int j=0;j<2;j++){
            scanf("%d", &queue[i][j]);
        }
    }
    rearrange();
    getWTTime();

    for(int i=0;i<n;i++){
        awt += queue[i][2];
        atat += queue[i][3];
    }

    display();

    printf("\nAverage waiting time = %f",awt/3);
    printf("\nAverage turn around time = %f",atat/3);

}