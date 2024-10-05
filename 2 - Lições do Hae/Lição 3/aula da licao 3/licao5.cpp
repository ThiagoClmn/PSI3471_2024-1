#include <cekeikon.h>

int main(){

    COR vermelho = COR(0,0,255);

    Mat_<FLT> ent , q,q2, inst, inst2;
    Mat_<COR> saida;
    float lim=0.8;

    le(ent,"a.png");
    le(q, "q.png");
    q2 = q.clone();
    q2 = 1-q2;

    inst = matchTemplateSame(ent,q,CV_TM_CCOEFF_NORMED, 0.0);
    inst2 = matchTemplateSame(ent,q2,CV_TM_CCOEFF_NORMED, 0.0);
    converte(ent,saida);

    mostra(inst);
    mostra(inst2);

    for(int l = 0 ; l<inst.rows ; l++){
        for(int c = 0 ; c<inst.cols ; c++){
            if(inst(l,c)>lim || inst2(l,c)>lim){
                saida(l,c) = vermelho;
            }
        }
    }

    imp(saida,"p.png");

}