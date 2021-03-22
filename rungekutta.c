/*ルンゲクッタ法を用いて、線形一階常微分方程式を解くプログラムを書いてみました。*/
#include <stdio.h>
#include <math.h>

void task(double);
double f(double x, double y);
double fexa(double x);


int main(){
  double h[]={0.25, 0.05, 0.01, 0.002};
  int count;
  FILE *file=fopen("date.txt","w");
  fclose(file);
  for(count=0;count<(sizeof(h)/sizeof(h[0]));count++){
    task(h[count]);
  }
  return 0;
}

void task(double h){
  int i = 0;
  double x = 0.0;
  double y = 10.0;
  double k1 = 0.0;
  double k2 = 0.0;
  double k3 = 0.0;
  double k4 = 0.0;
  double k=0;
  int IMAX = (int)(10.0/h);
  double S=0;

  for (i=0; i<=IMAX; i++){
    S+=pow((y-fexa(x)),2);
    printf("i=%d\tx=%lf\ty=%e\tyexa=%e\t\n", i, x, y,fexa(x));

    k1=h*f(x,y);
    k2=h*f(x+h/2,y+k1/2);
    k3=h*f(x+h/2,y+k2/2);
    k4=h*f(x+h,y+k3);
    k=(k1+2*k2+2*k3+k4)/6;
    x+=h,y+=k;
  }
  double dif=sqrt(S/IMAX);
  printf("dif=%e\n",dif);
  //データ書き込み
  FILE *file=fopen("date.txt","a");
  fprintf(file,"%lf %e\n",h,dif);
  fclose(file);
  printf("Output: data.txt\n");
}

double f(double X, double Y){
  double z;
  z=-X*Y+exp(-X*X/2);
  return z;
}

double fexa(double x){
  double z2;
  z2=(x+10)*exp(-x*x/2);
  return z2;
}
