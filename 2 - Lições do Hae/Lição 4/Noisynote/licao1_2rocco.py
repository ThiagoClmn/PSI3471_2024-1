#iris_dt2.py
import numpy as np
from sklearn import tree
import matplotlib.pyplot as plt

def le(nomearq):
    with open(nomearq,"r") as f:
        linhas=f.readlines()
    linha0=linhas[0].split()
    nl=int(linha0[0]); nc=int(linha0[1])
    a=np.empty((nl,nc),dtype=np.float32)
    for l in range(nl):
        linha=linhas[l+1].split()
        for c in range(nc):
            a[l,c]=np.float32(linha[c])
    return a

### main
ax=le("/home/vinir/Inteli/aula7/noisynote/ax.txt"); ay=le("/home/vinir/Inteli/aula7/noisynote/ay.txt")
qx=le("/home/vinir/Inteli/aula7/noisynote/qx.txt"); qy=le("/home/vinir/Inteli/aula7/noisynote/qy.txt")

arvore= tree.DecisionTreeClassifier()
arvore= arvore.fit(ax, ay)
qp=arvore.predict(qx)
erros=0
for i in range(qp.shape[0]):
    if qp[i]!=qy[i]: erros+=1
print("Erros=%d/%d. Pct=%1.3f%%\n"%(erros,qp.shape[0],100.0*erros/qp.shape[0]))
