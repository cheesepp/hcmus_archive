import copy

def multiplyScalarMatrix(scalar, A):
    return [scalar * a for a in A]

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

def NhanMaTran(A, B):
     
     #Khoi tao ma tran ket qua
     C = [[0 for _ in range(len(B[0]))] for _ in range(len(A))]
     #Nhan hai ma tran
     m=len(A)#Cho biet so dong cua A
     n=len(B[0])#Cho biet so cot cua B
     p=len(B)# Cho biet so dong cua B
     if(len(A[0])==len(B)):
        for i in range(m):
         for j in range(n):
            total = 0
            for k in range(p):
                total=total + A[i][k]*B[k][j]
            C[i][j] = total
        return (C, m, n)
     exit("Hai ma trận không phù hợp")

def transpose(A):
    #Khoi tao ma tran ket qua
    AT = [[0 for _ in range(len(A))] for _ in range(len(A[0]))]
    m=len(A)#Cho biet so dong cua A
    n=len(A[0])#Cho biet so cot cua A
    for i in range(m):
        for j in range(n):
            AT[j][i]=A[i][j]
    return AT

def printMatrix(A):
    for i in range(len(A)):
        for j in range(len(A[0])):
            print(A[i][j], end = " ")
        print()

def TruMaTran(A, B):
    #Khoi tao ma tran ket qua
    C = [0 for _ in range(len(A))]
    #Cong hai ma tran
    m=len(A)#Cho biet so dong cua A
    for i in range(m):
        C[i] = A[i] - B[i]
    return C

# hàm xử lí gram-schmidt
def gramSchmidtProcess(A):
    rows = len(A)
    cols = len(A[0])
    temp = copy.copy(A)
    v1 = [row[0] for row in temp]

    gmResult = [[0]*rows]*cols

    gmResult[0] = v1
    gmCols = 1
    for i in range(1, cols):
        v = [row[i] for row in temp]
        for j in range(gmCols):
            x = [row[i] for row in temp]
            scalar = innerproduct(x, gmResult[j]) / (getSize(gmResult[j]) * getSize(gmResult[j]))

            v = TruMaTran(v, multiplyScalarMatrix(scalar, gmResult[j]))

        gmResult[gmCols] = v

        gmCols += 1

    i = 0
    while i < cols:
        module = getSize(gmResult[i])
        for j in range(rows):
            gmResult[i][j] = gmResult[i][j] / module
        i+= 1

    gmResult = transpose(gmResult)
    return gmResult

# hàm phân rã QR
def QR_factorization(A):
    temp = copy.copy(A)
    Q = gramSchmidtProcess(A)

    QT = transpose(Q)
    (R, rows, cols) = NhanMaTran(QT, temp)
   
    for i in range(rows):
        for j in range(cols):
            if abs(R[i][j]) < 1e-10:
                R[i][j]=0
    
    return Q, R


with open("input.txt", "r") as file:
    A = [[float(x) for x in line.split()] for line in file]
            
Q, R = QR_factorization(A)

print('======== GIÁ TRỊ Q ========')
printMatrix(Q)
print('======== GIÁ TRỊ R ========')
printMatrix(R)
# t = gramSchmidtProcess(A)




