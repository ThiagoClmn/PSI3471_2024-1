//iris_bd.cpp
#include <cekeikon.h>
int main() {
  Mat_<float> irisdata; le(irisdata,"irisdata.txt");  // 150x4
  Mat_<float> iristarget; le(iristarget,"iristarget.txt"); // 150x1 (numeros de 0 a 2)

  Mat_<float> ax(90,4);
  Mat_<float> ay(90,1);
  Mat_<float> qx(60,4);
  Mat_<float> qy(60,1);
  Mat_<float> qp(60,1);

  for (int i=0; i<3; i++)
    for (int j=0; j<30; j++) {
      for (int k=0; k<4; k++)
        ax(i*30+j,k)=irisdata(i*50+j,k);
      ay(i*30+j)=iristarget(i*50+j);
    }
  imp(ax,"ax.txt");
  imp(ay,"ay.txt");

  for (int i=0; i<3; i++)
    for (int j=0; j<20; j++) {
      for (int k=0; k<4; k++)
        qx(i*20+j,k)=irisdata(i*50+30+j,k);
      qy(i*20+j)=iristarget(i*50+30+j);
    }
  imp(qx,"qx.txt");
  imp(qy,"qy.txt");
}
