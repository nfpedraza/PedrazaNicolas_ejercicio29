#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;


FILE *output;

int main ()
{
    int numx=100;
    int numt=2000;
    double dx=1.0/numx;
    double dt=0.00005;
    double C[numx][numt];
    double x=0.0;
    int i=0, j=0;
    double mu=0.5;
    double sigma=0.05;


    ofstream fout("Clase_29.dat");


    for(i=0; i < numx; i++){                         //intial condition         
        x=i*dx;
        C[i][0]=
            exp(-pow((x-mu),2.0)/(2.0*pow(sigma,2.0)))/pow(
                (2.0*PI*pow(sigma,2.0)),0.5);
    }
    C[0][0]=0.0;

    ///////////////////////////////////////////////////////////////////   
    // This must be numx-1, else you're going past the end of the array         
    // MAXIMUM subscripts are numx-1 and numt-1, as arrays are indexed          
    // starting from 0                                                          
    ///////////////////////////////////////////////////////////////////         
    C[numx-1][0]=0.0;

///////////////////////////////////                                             
//    fprintf(output, "%e\n\n", C[2][0]);                                       
///////////////////////////////////                                             

    for(j = 0;
        j < numt - 1; // This must be numt-1, else                              
                      // the j+1 in the calculation below                       
                      // will overstep the bounds of the array                  
        j++){

        ///////////////////////////////////////////////////////////////////     
        // This must be numx-1, else you're going past the end of the array     
        // in the calculation                                                   
        ///////////////////////////////////////////////////////////////////     
        for(i=1; i<numx-1; i++){
            x=i*dx;

            C[i][j+1] = C[i][j] +
                (dt/pow(dx,2))*(C[i+1][j] - 2*C[i][j] + C[i-1][j]);
        }
/////////////////////////////////                                               
//        fprintf(output, "%e\n", C[2][0]);                                     
/////////////////////////////////                                               

        C[0][j+1]=0.0;                             //boundary condition i)      
        ///////////////////////////////////////////////////////////////////     
        // This must be numx-1, else you're going past the end of the array     
        ///////////////////////////////////////////////////////////////////     
        C[numx-1][j+1]=0.0;                        //boundary condition ii)     

    }

    for (i = 0; i < numx; ++i)
    {
        x = i * dx;
        fprintf(output, "%e\t", x);
        
        for (j = 0; j < numt; ++j)
        {
            fprintf(output, "%e\t", C[i][j]);
        }
        fprintf(output, "\n");
    }
///////////////////////////////////                                             
//    fprintf(output, "\n%e\n", C[2][0]);                                       
///////////////////////////////////                                             

    fflush(output);
    fclose(output);

    return 0; // Need to return an int here.                                    
}
