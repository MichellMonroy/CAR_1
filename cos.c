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
#include <math.h>

float f(float x){
    float y;
    y = cos(x);
    return y;
}

int main(int nargs, char **argv){
    float a = 0.0;
    float b = 0.0;
    float dx = 0.1;
    float x = 0.0;
    int n = 0;
    // int i = 0;
    // for(int i = 0; i<nargs; i++){
    //     printf("%s\n", argv[i]);
    // }
    if (nargs != 4){
        printf("Number of arguments wrong. You need 3 arguments \n");
        return 0;
    }
    sscanf(argv[1], "%f", &a);
    sscanf(argv[2], "%f", &b);
    sscanf(argv[3], "%f", &dx);
    x = a;
    n = (b-a)/dx;
    printf("n=%i\n", n);
    for(int i = 1; i<=n; i++){
        printf("%f\t%f\n", x,f(x));
        // x = x + dx;
        x = a + (i*dx);
    }
    return 0;
}

