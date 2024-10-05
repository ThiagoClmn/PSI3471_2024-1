import numpy as np
from tensorflow.keras.datasets import mnist
from sklearn.model_selection import train_test_split
import time
import cv2


####### Importação do dataset
# Carregar o dataset MNIST
(x_train, y_train), (x_test, y_test) = mnist.load_data()


# Redimensionar os dados para 2D (cada imagem 28x28 será um vetor de 784)
x_train = x_train.reshape(x_train.shape[0], -1)
x_test = x_test.reshape(x_test.shape[0], -1)


# Normalizar os dados
x_train = x_train.astype('float32') / 255
x_test = x_test.astype('float32') / 255


# Dividir os dados de teste para ter um conjunto menor para a comparação de tempo
x_test, x_test_small, y_test, y_test_small = train_test_split(x_test, y_test, test_size=0.1, random_state=42)






## Dataset usado será menor para treino e teste em ambos os casos
## para que o tempo não seja tão grande




####### Implementação manual do KNN
# Reduzir o tamanho dos dados de treinamento e teste para acelerar a execução
small_train_size = 1000  # número menor de dados de treinamento
small_test_size = 100    # número menor de dados de teste


x_train_small = x_train[:small_train_size]
y_train_small = y_train[:small_train_size]
x_test_small = x_test[:small_test_size]
y_test_small = y_test[:small_test_size]


def euclidean_distance(x1, x2):
    return np.sqrt(np.sum((x1 - x2) ** 2))


def knn_manual(x_train, y_train, x_test, k=3):
    y_pred = []
    for x in x_test:
        distances = []
        for i in range(len(x_train)):
            dist = euclidean_distance(x, x_train[i])
            distances.append((dist, y_train[i]))
        distances.sort(key=lambda x: x[0])
        neighbors = [distances[i][1] for i in range(k)]
        y_pred.append(np.argmax(np.bincount(neighbors)))
    return np.array(y_pred)


# Medir o tempo de processamento do KNN manual com conjunto menor
start_time = time.time()
y_pred_manual = knn_manual(x_train_small, y_train_small, x_test_small, k=3)
manual_time = time.time() - start_time






####### Implementação do KNN via OpenCV
# Treinar o modelo KNN usando OpenCV com conjunto menor
knn = cv2.ml.KNearest_create()
knn.train(x_train_small.astype(np.float32), cv2.ml.ROW_SAMPLE, y_train_small.astype(np.float32))


# Medir o tempo de processamento do KNN com OpenCV com conjunto menor
start_time = time.time()
ret, result, neighbours, dist = knn.findNearest(x_test_small.astype(np.float32), k=3)
opencv_time = time.time() - start_time








####### Tempos obtidos
ratio = manual_time/opencv_time


print(f"""
Tempo do KNN manual: {manual_time:.4f} s
Tempo do KNN com OpenCV: {opencv_time:.4f} s


O tempo manual é {ratio:.4f} vezes o tempo com OpenCV
""")