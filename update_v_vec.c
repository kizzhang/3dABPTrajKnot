#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "ran2.h"
#define NB    2
#define PI 3.141592653589793

double dtheta;

void update_v_vec(double* v_vec, double* buffer, double dtheta1, double dtheta2, double dtheta3, int time_i);

 
void update_v_vec(double* v_vec, double* buffer, double dtheta1, double dtheta2, double dtheta3, int time_i){

    double vx = *buffer;
    double vy = *(buffer+1);
    double vz = *(buffer+2);

    *(v_vec+time_i) = vx * (cos(dtheta2)*cos(dtheta3)) + 
                      vy * (sin(dtheta1)*sin(dtheta2)*cos(dtheta3) - cos(dtheta1)*sin(dtheta3)) +
                      vz * (cos(dtheta1)*sin(dtheta2)*cos(dtheta3) + sin(dtheta1)*sin(dtheta3));
    
    *(v_vec+ time_i+ NB) = vx * (cos(dtheta2)*sin(dtheta3)) +
                          vy * (sin(dtheta1)*sin(dtheta2)*sin(dtheta3) + cos(dtheta1)*cos(dtheta3)) +
                          vz * (cos(dtheta1)*sin(dtheta2)*sin(dtheta3) - sin(dtheta1)*cos(dtheta3));

    *(v_vec+time_i+ NB*2) = vx * (-1*sin(dtheta2)) +
                            vy * (sin(dtheta1)*cos(dtheta2)) +
                            vz * (cos(dtheta1)*cos(dtheta2));
   
    /*
    *(v_vec+time_i) = *(v_vec+time_i) + sin(dtheta) / dtheta * (-1. * dthetaz * *(v_vec+time_i+ NB) + dthetay * *(v_vec+time_i+ NB*2))
                + (1-cos(dtheta)) / (dtheta * dtheta) * ( (-1. * dthetaz*dthetaz - dthetay*dthetay)*(*v_vec + time_i) +(dthetax*dthetay) * *(v_vec+time_i+ NB) +
                (dthetax*dthetaz)* *(v_vec+time_i+ NB*2) );


    *(v_vec+time_i+ NB) = *(v_vec+time_i+ NB) + sin(dtheta) / dtheta * (dthetaz * *(v_vec+time_i) - dthetax * *(v_vec+time_i+ NB*2))
                + (1-cos(dtheta)) / (dtheta * dtheta) * ( (dthetax*dthetay)*(*v_vec + time_i) +(-1.*dthetaz*dthetaz - dthetax*dthetax) * *(v_vec+time_i+ NB) +
                (dthetay*dthetaz)* *(v_vec+time_i+ NB*2) );

    *(v_vec+time_i+ NB*2) = *(v_vec+time_i+ NB*2) + sin(dtheta) / dtheta * (-1.*dthetay * *(v_vec+time_i) + dthetax * *(v_vec+time_i+ NB))
                + (1-cos(dtheta)) / (dtheta * dtheta) * ( (dthetax*dthetaz)*(*v_vec + time_i) +(dthetay*dthetaz) * *(v_vec+time_i+ NB) +
                (-1.* dthetax*dthetax -dthetay*dthetay)* *(v_vec+time_i+ NB*2) );*/
}