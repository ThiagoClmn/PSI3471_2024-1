//nn_cv3.cpp
#include "procimagem.h"
int main() {
  Mat_<float> ax; le(ax,"ax.txt");
  Mat_<float> ay; le(ay,"ay.txt");
  Mat_<float> qx; le(qx,"qx.txt");
  Mat_<float> qy; le(qy,"qy.txt");
  Mat_<float> qp;
  Ptr<ml::KNearest>  knn(ml::KNearest::create());
  knn->train(ax, ml::ROW_SAMPLE, ay);
  Mat_<float> dist;
  knn->findNearest(qx, 1, noArray(), qp, dist);
  int erros=0;
  for (int i=0; i<qp.rows; i++)
    if (qp(i)!=qy(i)) erros++;
  printf("Erros=%d/%d.   Pct=%1.3f%%\n",erros,qp.rows,100.0*erros/qp.rows);
}