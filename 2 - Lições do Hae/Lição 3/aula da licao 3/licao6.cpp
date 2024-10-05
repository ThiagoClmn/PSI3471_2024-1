#include<cekeikon.h>

int main(){
    Mat_<GRY> ent;
    Mat_<GRY> saida;
    le(ent,"lennag.jpg");
    float fator = 3.6;

    imp(ent,"0lenna.png");

    resize(ent, saida, Size(0,0), fator,fator,INTER_NEAREST);
    imp(saida,"1INTER_NEAREST.png");

    resize(ent, saida, Size(0,0), fator,fator,INTER_AREA);
    imp(saida,"2INTER_AREA.png");

    resize(ent, saida, Size(0,0), fator,fator,INTER_LINEAR);
    imp(saida,"3INTER_LINEAR.png");

    resize(ent, saida, Size(0,0), fator,fator,INTER_CUBIC);
    imp(saida,"4INTER_CUBIC.png");

    resize(ent, saida, Size(0,0), fator,fator,INTER_LANCZOS4);
    imp(saida,"5INTER_LANCZOS4.png");
 
}
