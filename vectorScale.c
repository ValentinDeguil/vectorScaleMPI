#include <mpi/mpi.h>
#include <stdio.h>

int main(int argc , char * argv []){

    MPI_Init (&argc, &argv);

    int p;
    MPI_Comm_size(MPI_COMM_WORLD, &p);

    int my_id;
    MPI_Comm_rank (MPI_COMM_WORLD , &my_id);

    int n;
    double scale;

    if(my_id == 0){
        //int n;
        printf("Enter n :\n");
        scanf("%d", &n);

        //double scale;
        printf("Enter scale :\n");
        scanf("%lf",&scale);

    }

    MPI_Barrier(MPI_COMM_WORLD);

    MPI_Bcast(&n,1,MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&scale,1,MPI_DOUBLE, 0, MPI_COMM_WORLD);

    MPI_Barrier(MPI_COMM_WORLD);

    double x[n];

    if(my_id == 0){
        double temp;
        for (int i=0; i<n; i++){
            printf("Enter x[%d] :\n", i);
            scanf("%lf",&temp);
            x[i] = temp;
        }
    }

    MPI_Barrier(MPI_COMM_WORLD);

    MPI_Comm_size(MPI_COMM_WORLD, &p);

    int nbElemByCore = n/p;
    double localdata[nbElemByCore];

    MPI_Scatter(&x, nbElemByCore, MPI_DOUBLE, &localdata, nbElemByCore, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    for (int i=0; i<nbElemByCore; i++){
        localdata[i] = localdata[i]*scale;
    }

    MPI_Gather(localdata, nbElemByCore, MPI_DOUBLE, x, nbElemByCore, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    MPI_Finalize();

    if(my_id == 0){
        printf("\n");
        printf("Result :\n");
        for (int i=0; i<8; i++){
            printf("%f\n", x[i]);
        }

    }

    return 0;
}