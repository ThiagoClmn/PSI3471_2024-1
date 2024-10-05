//Usa OpenCV2
#include <cekeikon.h>

int main() {
    Mat_<GRY> ax; le(ax,"janei.pgm");
    Mat_<GRY> ay; le(ay,"janei-1.pgm");
    Mat_<GRY> qx; le(qx,"julho.pgm");

    mostra(ax);
    mostra(ay);
    mostra(qx);

    if (ax.size()!=ay.size()) erro("Erro dimensao");

    Mat_<GRY> qp(qx.rows,qx.cols);

    //Cria as estruturas de dados para alimentar OpenCV
    Mat_<FLT> features(ax.rows*ax.cols,9);
    Mat_<FLT> saidas(ax.rows*ax.cols,1);
    
    int i=0;
    for (int l=0; l<ax.rows; l++){
        for (int c=0; c<ax.cols; c++) {
            if( l-1 < 0 || l+1 > ax.rows || c-1<0 || c+1>ax.cols){
                features(i,0)=1;
                features(i,1)=1;
                features(i,2)=1;
                features(i,3)=1;
                features(i,4)=1;
                features(i,5)=1;
                features(i,6)=1;
                features(i,7)=1;
                features(i,8)=1;
            }else{
                features(i,0)=ax(l-1,c-1)/255.0;
                features(i,1)=ax(l-1,c)/255.0;
                features(i,2)=ax(l-1,c+1)/255.0;
                features(i,3)=ax(l,c-1)/255.0;
                features(i,4)=ax(l,c)/255.0;
                features(i,5)=ax(l,c+1)/255.0;
                features(i,6)=ax(l+1,c-1)/255.0;
                features(i,7)=ax(l+1,c)/255.0;
                features(i,8)=ax(l+1,c+1)/255.0;
            }
            saidas(i)=ay(l,c)/255.0;
            i++;
        }
    }

    flann::Index ind(features,flann::KDTreeIndexParams(4));

    // Aqui, as 4 arvores estao criadas
    Mat_<FLT> query(1,9);
    vector<int> indices(1);
    vector<FLT> dists(1);
    
    for (int l=0; l<qp.rows; l++){
        for (int c=0; c<qp.cols; c++) {
            if( l-1 < 0 || l+1 > ax.rows || c-1<0 || c+1>ax.cols){
                query(0)=1;
                query(1)=1;
                query(2)=1;
                query(3)=1;
                query(4)=1;
                query(5)=1;
                query(6)=1;
                query(7)=1;
                query(8)=1;
            }else{
                query(0)=qx(l-1,c-1)/255.0;
                query(1)=qx(l-1,c)/255.0;
                query(2)=qx(l-1,c+1)/255.0;
                query(3)=qx(l,c-1)/255.0;
                query(4)=qx(l,c)/255.0;
                query(5)=qx(l,c+1)/255.0;
                query(6)=qx(l+1,c-1)/255.0;
                query(7)=qx(l+1,c)/255.0;
                query(8)=qx(l+1,c+1)/255.0;
            }
            //mostra(query);
            // Zero indica sem backtracking
            ind.knnSearch(query,indices,dists,1,flann::SearchParams(0));
            // Saida e' um numero entre 0 e 255
            qp(l,c)=255*saidas(indices[0]);
        }
    }
    mostra(qp);
    medianBlur(qp,qp, 5);
    //medianBlur(qp,qp, 4);
    mostra(qp);

}
