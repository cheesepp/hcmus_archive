import copy

# hàm nhân ma trận với hệ số
def multiplyScalarMatrix(scalar, A):
    return [scalar * a for a in A]

# hàm tính tích vô hướng
def innerproduct(v1, v2):
    result = 0
    if len(v1) != len(v2): # xét chiều dài hai vector
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

# hàm nhân ma trận
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

# hàm phụ trợ chuyển vị ma trận
def transpose(A):
    #Khoi tao ma tran ket qua
    AT = [[0 for _ in range(len(A))] for _ in range(len(A[0]))]
    m=len(A)#Cho biet so dong cua A
    n=len(A[0])#Cho biet so cot cua A
    for i in range(m):
        for j in range(n):
            AT[j][i]=A[i][j]
    return AT

# hàm in ma trận
def printMatrix(A):
    for i in range(len(A)):
        for j in range(len(A[0])):
            print("%.2f" % A[i][j], end = " ")
        print()

# hàm phụ trợ trừ ma trận
def TruMaTran(A, B):
    #Khoi tao ma tran ket qua
    C = [0 for _ in range(len(A))]
    #Cong hai ma tran
    m=len(A)#Cho biet so dong cua A
    for i in range(m):
        C[i] = A[i] - B[i]
    return C

# hàm phụ trợ tìm bậc ma trận
def gaussElimination(arr):
    rows = len(arr)
    cols = len(arr[0])

    considerCol = 0
    i = 0
    while i < rows:
        if considerCol >= cols - 1:
            break
        if (arr[i][considerCol] == 0):
            isAllZero = False
            noneZeroRow = -1
            for t in range(i, rows):
                if arr[t][considerCol] == 0:
                    isAllZero = True
                else: 
                    isAllZero = False
                    noneZeroRow = t                        
                    break
            if not isAllZero:
                for j in range (cols):
                    arr[noneZeroRow][j] += arr[i][j]
                    arr[i][j] = arr[noneZeroRow][j] - arr[i][j]
                    arr[noneZeroRow][j] -= arr[i][j]   
            else:
                considerCol = considerCol + 1
                i = i
                continue
        else:
            isAllZero = False
        for j in range(i + 1, rows):
            multiplier = arr[j][considerCol] / arr[i][considerCol]  
            for k in range(cols):
                arr[j][k] = arr[j][k] - multiplier*arr[i][k]
            considerCol = considerCol + 1
            i += 1

    for i in range(rows):
        isZero = isZeroRow(arr, i, cols)
        if isZero:
            for k in range(i +1, rows):
                if(isZeroRow(arr, k, cols)):
                    pass
                else:
                    for j in range(cols):
                        arr[k][j] += arr[i][j]
                        arr[i][j] = arr[k][j] - arr[i][j]
                        arr[k][j] -= arr[i][j]
                    i += 1
    printMatrix(arr)
# hàm xác định tính phụ thuộc của ma trận
def isLinearDependent(A):
    arr = copy.deepcopy(A)
    gaussElimination(arr)
    rows = len(arr)
    cols = len(arr[0])
    count = 0
    for i in range(rows):
        for j in range(cols):
            if i == j:
                if arr[i][j] != 0:
                    count += 1
    if count == cols:
        return False
                
    return True

# check a row is all zero
def isZeroCol(arr, j, rows):
    isZero = False
    for i in range(rows):
            if arr[i][j] == 0:
                isZero = True
                continue
            else:
                isZero = False
                break
    return isZero

# check a row is all zero
def isZeroRow(arr, i, cols):
    isZero = False
    for j in range(cols):
            if arr[i][j] == 0:
                isZero = True
                continue
            else:
                isZero = False
                break
    return isZero

# hàm xử lí gram-schmidt
def gramSchmidtProcess(A):

    # if(isLinearDependent(A)): # kiểm tra ma trận độc lập hay phụ thuộc tuyến tính
    #     print("Ma trận phụ thuộc tuyến tính! Không thể xét ma trận!")
    #     exit()

    rows = len(A) # lấy số hàng của ma trận
    cols = len(A[0]) # lấy số hàng của ma trận 
    temp = copy.deepcopy(A) # dùng hàm deepcopy để tham trị ma trận A
    v1 = [row[0] for row in temp] # lấy vector đầu tiên của ma trận

    gmResult = [[0]*rows]*cols # tạo ma trận để thu các vector khác

    gmResult[0] = v1 # gán vector đầu tiên cho ma trận
    gmCols = 1 # tạo biến để lưu các cột có vector đã lưu trong gmResult
    for i in range(1, cols): # vòng lặp tính các giá trị vector tiếp theo
        v = [row[i] for row in temp] # lưu các phần tử hàng i để bắt đầu tính toán
        x = [row[i] for row in temp] 
        for j in range(gmCols): # vòng lặp tính các giá trị của vector
            scalar = innerproduct(x, gmResult[j]) / (getSize(gmResult[j]) * getSize(gmResult[j])) # dòng này tương đương với (<ui * vi> / ||vi||^2)

            v = TruMaTran(v, multiplyScalarMatrix(scalar, gmResult[j])) # lấy kết quả vừa tìm được trừ dồn vào giá trị của v trước đó

        gmResult[gmCols] = v # gán kết quả của vector vừa tìm được vào ma trận kết quả

        gmCols += 1 # tăng số cột chứa vector lên 1

    i = 0
    while i < cols: # chạy vòng lặp đi qua từng cột
        module = getSize(gmResult[i]) # tính module của vector
        for j in range(rows): # vòng lặp tính các phần tử của ma trận
            gmResult[i][j] = gmResult[i][j] / module
        i+= 1

    gmResult = transpose(gmResult) # chuyển vị ma trận về ma trận Q
    return gmResult # kết quả trả về là ma trận Q cần tìm

# hàm phân rã QR
def QR_factorization(A):
    temp = copy.deepcopy(A) # deepcopy dùng để tham trị ma trận A
    Q = gramSchmidtProcess(A) # tìm được Q từ phương pháp gram schmidt

    QT = transpose(Q) # chuyển vị ma trận Q để tìm R
    (R, rows, cols) = NhanMaTran(QT, temp) # tính R bằng cách QT nhân với ma trận A
   
   # vòng lặp để định dạng kết quả
    for i in range(rows):
        for j in range(cols):
            if abs(R[i][j]) < 1e-10:
                R[i][j]=0
    
    return Q, R

# đọc file input
with open("input.txt", "r") as file:
    A = [[float(x) for x in line.split()] for line in file]
            
Q, R = QR_factorization(A)

print('======== MA TRẬN ĐẦU VÀO ========')
printMatrix(A)

print('======== MA TRẬN Q ========')
printMatrix(Q)

print('======== MA TRẬN R ========')
printMatrix(R)
# t = gramSchmidtProcess(A)




