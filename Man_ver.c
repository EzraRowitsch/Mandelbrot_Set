#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <mpi.h>

int main (int argc, char *argv[])
{
double start_time, end_time, total_time;
MPI_Init(&argc, &argv);
float ai, bi;
int i, j, rank, size, is_man=0;
double a_cur = 0.0, b_cur = 0.0, RES=0.00390625, a2=0;
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);
if(rank==0){
start_time=MPI_Wtime();
int a_XT = 2/RES+1, b_XT = 2/RES+1, a_ct = 0, b_ct=b_XT-1;
int mand_pts[b_XT][a_XT];
	for(ai=-2.0; ai<=0; ai=ai+RES){
	b_ct=b_XT-1;
		for(bi=-1.0; bi<=1.0; bi=bi+RES){
        	a_cur = 0.0;
        	b_cur = 0.0;
        		for(i=0;i<1000;i=i+1){
           	 	a2=a_cur;
           	 	a_cur=a_cur*a_cur - b_cur*b_cur + ai;
           	 	b_cur=2*a2*b_cur + bi;
           			if(sqrt(a_cur*a_cur + b_cur*b_cur) >= 2){
                   	 	is_man = 0;
                   	 	break;
                   	 	}
                		else{
                   	 	is_man = 1;
                   	 	}
            		}
        			if(is_man == 1){
				mand_pts[b_ct][a_ct]=1;
				b_ct=b_ct-1;
				}	
				else{
				mand_pts[b_ct][a_ct]=0;
				b_ct=b_ct-1;
				}
			}
			a_ct=a_ct+1;
		}
		end_time = MPI_Wtime();
		total_time = end_time - start_time;
                printf("Rank 0, Total Time: %f \n",total_time);
		printf("Rank 0 array start\n");
		for (i = 0; i < b_XT; i++ ){
			for (j = 0; j < a_XT; j++ ){
				printf("%d ", mand_pts[i][j] );
				if (j==a_XT-1){
					printf(" \n");
				}
			}
		}
		printf("Rank 0 array end\n");
		sleep(1);	
        MPI_Send(&RES,1,MPI_FLOAT,1,1,MPI_COMM_WORLD);
}

if(rank==1){
start_time=MPI_Wtime();
//printf("This is rank 1");
int a_XT = 2/RES, b_XT = 2/RES+1, a_ct = 0, b_ct=b_XT-1;
int mand_pts[b_XT][a_XT];
        for(ai=0.0+RES; ai<=2; ai=ai+RES)
        {
	//printf("this is rank 1 in first loop");
        b_ct=b_XT-1;
                for(bi=-1.0; bi<=1.0; bi=bi+RES)
                {
		//printf("This is Rank 1 in second Loop");
                a_cur = 0.0;
                b_cur = 0.0;
                        for(i=0;i<1000;i=i+1)
                        {
                        a2=a_cur;
                        a_cur=a_cur*a_cur - b_cur*b_cur + ai;
                        b_cur=2*a2*b_cur + bi;
                                if(sqrt(a_cur*a_cur + b_cur*b_cur) >= 2)
                                {
                                is_man = 0;
                                break;
                                }
                                else
                                {
                                is_man = 1;
                                }
                        }
                                if(is_man == 1)
                                {
                                mand_pts[b_ct][a_ct]=1;
                                b_ct=b_ct-1;
                                }
                                else
                                {
                                mand_pts[b_ct][a_ct]=0;
                                b_ct=b_ct-1;
                                }
                        }
                        a_ct=a_ct+1;
                }
		end_time = MPI_Wtime();
		total_time = end_time - start_time;
                MPI_Recv(&RES,1,MPI_FLOAT,0,1,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("Rank 1, Total Time: %f\n", total_time);
		printf("Rank 1 array start\n");
                for (i = 0; i < b_XT; i++ )
                {       
                        for (j = 0; j < a_XT; j++ )
                        {       
                                printf("%d ", mand_pts[i][j] );
                                if (j==a_XT-1)
                                {       
                                        printf(" \n");
                                }
                        }
                }
		printf("Rank 1 array end\n");
		sleep(1);  
}
MPI_Finalize();
} 
