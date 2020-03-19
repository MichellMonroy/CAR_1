#include <stdio.h> /* Incluye rutinas estándar tales como input/ouput, etc. */
#include <math.h> /* Incluye las librerias para usar funciones matemáticas */
 
int main () {  /*ejecuta el sistema operativo al llamar a un programa C */

    double x[10], f[10];
    double pi;
    int i,j;
    FILE *fp;
    

    pi = 3.141592;

    /* Escribir el archivo */

    fp = fopen("sin.dat", "w");
  
    /* Llenar los arreglos de x y f[x] */

    for ( i = 0; i < 10; i++ ) { 
    x[i] = (double)(i)/(10.0-1.0); 
    f[i] = sin(2.0*pi*x[i]);
    } 

    /* Escribir los arreglos x y f[x] en el archivo sin.dat */

    for (j = 0; j < 10; j++) {
    fprintf(fp,"%7.6lf%11.6lf\n", x[j], f[j]);
    }
    fclose(fp);
   return 0;

}


