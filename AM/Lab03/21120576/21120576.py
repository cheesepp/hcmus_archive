import numpy as np
from numpy import linalg
import math

# hàm đọc ma trận đầu vào
def readFile(filename):
    a = np.loadtxt(filename)
    # để tính toán ma trận sao cho thuận tiện, ta đưa mô hình đã cho về dạng y = ax + b,
    # với y = log10(N), x = (t - 1970)
    b = a[:, len(a[0]) - 1:] # tách cột thứ 2 của ma trận
    a = a[:, :len(a[0]) - 1] # tách cột đầu tiên của ma trận
    for i in range(len(b)): # vòng lặp để tính toán giá trị của ma trận b khớp với mô hình
        if b[i] != 0:
            b[i] = math.log10(b[i])
        a[i] = a[i] - 1970
    col = [[1]] * len(a)
    # để ma trận a biểu diễn theo y = ax + b, ta thêm cột hệ số b vào ma trận a ban đầu
    a = np.append(a, col, axis=1)
    return a, b

# hàm phân tích điểm kì dị SVD
def analyzeSVD(a):
    U, D, VT = linalg.svd(a)
    UT = np.transpose(U) # chuyển vị ma trận U
    V = np.transpose(VT) # chuyển vị ma trận V
    E = np.zeros((len(U[0]), len(VT))) # tạo ma trận toàn 0
    for i in range(len(D)): # vòng lặp để thêm các giá trị tìm được trong D vào ma trận E
        E[i][i] = D[i]
    Ep = np.transpose(E) # hoán vị ma trận E để tìm ma trận giả nghịch đảo
    for i in range(len(Ep)): # nghịch đảo các giá trị của ma trận chuyển vị E
        for j in range(len(Ep[0])):
            if Ep[i, j] != 0:
                Ep[i, j] = 1 / Ep[i, j]
    Ap = V.dot(Ep).dot(UT) # tìm ma trận giả nghịch A+
    return Ap

# hàm tìm nghiệm bình phương tối thiểu
def leastSquare(a, b):
    Ap = analyzeSVD(a)
    x = np.dot(Ap,b) # tìm giá trị bằng công thức A+*b
    return x

# hàm dự đoán số bóng bán dẫn của năm cần tìm
def predictNumOfTransistors(x, param):
    return 10**(x[1] + x[0]*(param - 1970))

# hàm thực thi chương trình
def main():

    print ("================= CÂU A =================")
    a, b = readFile("input.txt")
    print ("-------- MA TRẬN A --------")
    print(a)
    print ("\n-------- MA TRẬN B --------")
    print(b)

    # tìm nghiệm bình phương tối thiểu
    x = leastSquare(a, b)
    print("\nĐường thẳng khớp với mô hình là: y = {}x + {}".format(x[0], x[1]))

    print ("================= CÂU B =================")
    print("Số bóng bán dẫn trong bộ vi xử lí được dự đoán vào năng 2015: {}".format(predictNumOfTransistors(x,2015)))
    print("Độ chênh lệch của số bóng bán dẫn của bộ vi xử lí vừa tìm được với bộ vi xử lí IBM Z13 ra đời năm 2015: {} bóng bán dẫn.".format(abs(predictNumOfTransistors(x,2015) - 4e+09)))
    return 1

main()
