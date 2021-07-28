#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
int t=13,i,vf;
float d;
float xf[12],yf[12];
float xb[12]={80,90,99,108,116,125,133,141,151,160,179,180};
float yb[12]={0,-2,-5,-9,-15,-18,-23,-29,-28,-25,-21,-20,-17};

printf("xb:80,90,99,108,116,125,133,141,151,160,179,180\n");
printf("yb:0,-2,-5,-9,-15,-18,-23,-29,-28,-25,-21,-20,-17\n");
xf[0]=0;
yf[0]=50;
vf=20;
printf("xf[0] is %f and yf[0] is %f\n",xf[0],yf[0]);
printf("Velocity of fighter:%d\n",vf);
  for(t=0;t<=12;t++) {
    d=sqrt(pow((yb[t]-yf[t]),2)+pow((xb[t]-xf[t]),2));
    if(d<10)
    {
    printf("\nCaught at %d mts and %f kms\n",t,d);
    break;
     }
    else
    {
    xf[t+1]=xf[t]+(vf*(xb[t]-xf[t])/d);
    yf[t+1]=yf[t]+(vf*(yb[t]-yf[t])/d);
     }
}
if(t>12)
printf("Target Escaped\n");
getch();
return(0);
  }
