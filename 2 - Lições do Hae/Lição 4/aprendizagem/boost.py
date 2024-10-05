#boost.py - grad2023
import numpy as np
from sklearn import ensemble
import sys, cv2

#<<<<<<<<<<<<<<< main <<<<<<<<<<<<<<<<<
ax=cv2.imread("ax.png",1)
ay=cv2.imread("ay.png",0)
if ax.shape[0]!=ay.shape[0] or ax.shape[1]!=ay.shape[1]:
  sys.exit("Erro: Imagens com dimensoes diferentes");

features=(ax/255).reshape((ax.shape[0]*ax.shape[1],3))
saidas  =(ay/255).reshape((ay.shape[0]*ax.shape[1],))

clf = ensemble.GradientBoostingClassifier()
clf = clf.fit(features,saidas)

qx = cv2.imread("f1.jpg",1)
query = (qx/255).reshape((qx.shape[0]*qx.shape[1],3))

qp = clf.predict(query)
qp = qp.reshape((qx.shape[0],qx.shape[1]))
cv2.imwrite("f1-bo-py.png",255*qp)
