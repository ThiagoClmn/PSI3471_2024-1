//boosting.cpp 2024 OpenCV v3/v4
#include "procimagem.h"

int main() {
  Mat_<Vec3b> ax=imread("ax.png",1);
  Mat_<uchar> ay=imread("ay.png",0);
  if (ax.size()!=ay.size()) erro("Erro: Dimensoes diferentes");

  Mat_<float> features(ax.total(),3);
  Mat_<int> saidas(ay.total(),1);
  for (unsigned i=0; i<ax.total(); i++) {
    features(i,0)=ax(i)[0]/255.0;
    features(i,1)=ax(i)[1]/255.0;
    features(i,2)=ax(i)[2]/255.0;
    saidas(i,0)=ay(i);
  }

  Ptr<ml::Boost> ind = ml::Boost::create();
  ind->train(features,ml::ROW_SAMPLE,saidas);
  Mat_<Vec3b> qx=imread("f1.jpg",1);
  Mat_<uchar> qp(qx.rows,qx.cols);

  for (unsigned i=0; i<qx.total(); i++) {
    Mat_<float> query(1,3);
    query(0)=qx(i)[0]/255.0;
    query(1)=qx(i)[1]/255.0;
    query(2)=qx(i)[2]/255.0;
    qp(i)=ind->predict(query);
  }
  imwrite("f1-boosting.png",qp);
}
