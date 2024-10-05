#include<cekeikon.h>

int main(){
    Mat_<GRY> ent;
    Mat_<GRY> saida;
    le(ent,"calib_result.jpg");
    mostra(ent);

    Mat_<float> src = (Mat_<float>(4,2) << 
    139,44,
    108,295,
    353,294,
    322,34);

    Mat_<float> dst = (Mat_<float>(4,2)<<
    110,50,
    110,300,
    360,300,
    360,50);

    Mat_<double> perspective_correction = getPerspectiveTransform(src,dst);

    warpPerspective(ent,saida,perspective_correction,Size(ent.cols,ent.rows), 1,1);

    imp(saida,"correcao.jpg");

}