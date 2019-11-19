#include <iostream>
#include <cmath>
#include <fstream>
//Codigo extraido y modificado de : https://www.dreamincode.net/forums/topic/125770-simulating-diffusion-equation/

using namespace std;

int main ()
{
    int x_n=30;
    int t_n=30;
    double sigma = 0.2;
    double dx=1.0/x_n;
    double dt= sigma * pow(dx,2.0);
    double C[x_n][t_n];
    double x=0.0;
    double mu=0.5;
    double alpha= dt/pow(dx,2.0);

    ofstream fout("Clase_29.dat");

    for(int i=0; i < x_n; i++){                         //intial condition         
        x=i*dx;
        C[i][0]= exp(-pow((x-mu),2.0)/(2.0*pow(sigma,2.0)))/pow((2.0*M_PI*pow(sigma,2.0)),0.5);
    }
    C[0][0]=0.0;

    C[x_n-1][0]=0.0;

                                         

    for(int j = 0; j < t_n - 1; j++){
        
        for(int i=1; i<x_n-1; i++){
            x=i*dx;
			
            C[i][j+1] = C[i][j] +(dt/pow(dx,2))*(C[i+1][j] - 2*C[i][j] + C[i-1][j]);
        }

        C[0][j+1]=0.0;                             //boundary condition i)      
   
        C[x_n-1][j+1]=0.0;                        //boundary condition ii)     

    }

    for (int i = 0; i < x_n; ++i)
    {
        x = i * dx;
        fout<<x<<"  ";
        
        for (int j = 0; j < t_n; ++j)
        {
            fout<<C[i][j]<<"\t";
        }
        fout<<"\n";
    }

    fout.close();

    return 0; // Need to return an int here.                                    
}
