import numpy as np
import copy

# hàm đọc file ma trận
def readFile(filename):
    a = np.loadtxt(filename)
    return a

# hàm tính tích vô hướng
def innerproduct(v1, v2):
    result = 0
    if len(v1) != len(v2):
        print("Lỗi! Chiều dài của hai vector khác nhau!")
        exit()
    for i in range(len(v1)):
        result += v1[i]*v2[i]
    return result

# hàm tính độ lớn ma trận
def getSize(v): 
    result = 0
    for i in range(len(v)):
        result += v[i] * v[i]
    result = result**(1/2)
    return result

# hàm xử lí gram-schmidt
def gramSchmidtProcess(A):
    temp = copy.copy(A)
    rows , cols = temp.shape
    v1 = temp[:, 0]
    gmResult = np.zeros((cols, rows))
    gmResult[0] = v1
    gmCols = 1
    for i in range(1, cols):
        v = temp[:, i]
        for j in range(gmCols):
            v -= (innerproduct(temp[:, i], gmResult[j]) / (getSize(gmResult[j]) * getSize(gmResult[j]))) * gmResult[j]
        gmResult[gmCols] = v
        gmCols += 1
    gmResult = np.transpose(gmResult)
    for i in range(gmCols):
        gmResult[:, i] = gmResult[:, i] / getSize(gmResult[:, i])
    return gmResult

# hàm phân rã QR
def QR_factorization(A):
    temp = copy.copy(A)
    Q = gramSchmidtProcess(A)

    QT = np.transpose(Q)
    R = QT @ temp
    rows, cols = R.shape
   
    for i in range(rows):
        for j in range(cols):
            if abs(R[i][j]) < 1e-10:
                R[i][j]=0
  
    return Q, R


A = readFile("input.txt")
Q, R = QR_factorization(A)

print('======== GIÁ TRỊ Q ========')
print(Q)
print('======== GIÁ TRỊ R ========')
print(R)




