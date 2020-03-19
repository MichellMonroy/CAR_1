/*
    cos.c
    Copyright (C) 2020 Mariana Michell Flores Monroy
                        mychyll3@gmail.com
                        
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
// #include <math.h>
#include "library.h"
#include "Timming.h"
#include <mpi.h>

int main(int nargs, char **argv){
    int miproc;
    int numproc;
    int n = 0;

    float x = 0.0;
    float y;
    float *vector;

    double utime0, stime0, wtime0,
           utime1, stime1, wtime1,
           utime2, stime2, wtime2;

    vector = malloc(sizeof(float)*numproc);
    MPI_Init (&nargs, &argv); //Inicializa MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &miproc); //determina el rango
    MPI_Comm_size(MPI_COMM_WORLD, &numproc); //determina el número de procesos
    MPI_Barrier(MPI_COMM_WORLD);

    if (nargs != 1){
        printf("Number of arguments wrong. You need 1 arguments \n");
        return 0;
    }

    for(int i = 0; i<numproc; i++){
        // printf("%f\t%f\n", x,f(x));
        vector[i] = miproc + 1;
        y = f(vector[i]);
        printf("%d\t%d\t%f\n", miproc+1, i, y);
        // printf("%f\n", y); 
        // printf("%d\n", numproc); 

    }

    MPI_Barrier(MPI_COMM_WORLD);

    if (miproc == 0){
        // printf("I'm 0 process \n");
        uswtime(&utime1, &stime1, &wtime1); //toma el tiempo
        
        printf("\nBenchmarks (sec): \n");
        printf("real %.3f\n", wtime1-wtime0);
        printf("user %.3f\n", utime1-utime0);
        printf("sys %.3f\n", stime1-stime0);
        printf("\n");
        printf("CPU/Wall %.3f %% \n", 
        100.0 * (utime1-utime0 + stime1-stime0)/(wtime1-wtime0));
        printf("\n");

    }

    MPI_Finalize();
    free(vector);
    return 0;
}

