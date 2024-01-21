import numpy as np
from numpy import linalg
import sympy as sp
from matplotlib import pyplot as plt
import math

def bai01():
    print('=============== BÀI 1 ================\n')
    variables = np.array([sp.Symbol('x1'), sp.Symbol('x2'), sp.Symbol('x3')]) # tạo các biến x1 x2 x3
    print('Ta có ma trận A và q lần lượt: ')
    # ma trận A
    A = np.array([
        [1, -2, 1],
        [-2, 1, -2],
        [1, -2, 1]
    ])

    # ma trận q
    q = np.array([1,2,-1])
    print('ma trận A:')
    print(A)
    print('ma trận q:')
    print(q)

    print('Các giá trị riêng của ma trận A lần lượt là: ')
    eigVals = linalg.eig(A)[0] # tính giá trị riêng của ma trận A
    for eig in eigVals:
        print(eig, end = "\n")

    countPosVal = 0 # đếm giá trị riêng dương
    # Kiểm tra tính lõm/lồi     
    for i in eigVals:
        if i > 0:
            countPosVal += 1

    if countPosVal == len(eigVals): # Hàm lồi nếu toàn bộ giá trị riêng là dương
        print("=> Hàm lồi.")
    elif countPosVal == 0: # Hàm lõm nếu toàn giá trị riêng là âm
        print('=> Hàm lõm.')
    else: # Không lồi không lõm nếu có cả hai loại âm và dương
        print('=> Không lồi không lõm.')

    f = variables @ A @ np.transpose(variables) + np.transpose(q)*variables + 1
    print('Phương trình df: ')
    # đạo hàm phương trình f đề cho
    delta = 2 * A @ variables + np.transpose(q)
    print(delta)
    # tính nghiệm 3 ẩn của phương trình delta
    roots = sp.linsolve(delta.tolist(), variables.tolist())

def bai02():
    print('\n=============== BÀI 2 ================\n')
    data = np.array([[0, 10], [1, 8], [2, 7], [3, 5], [4, 2]]) # các điểm dữ liệu đề cho

    a = data[:, 0] # lấy danh sách điểm x
    b = data[:, 1] # lấy danh sách điểm y

    X = np.zeros((2,2)) # tạo ma trận X để tính tổng ma trận A^t*A với số dòng và cột là số toán hạng của phương trình
    for k in range(len(a)): # vòng lặp để tính tổng
        A = np.array([
            [1, a[k]],
        ])

        X = X +  np.transpose(A) @ A
    
    Y = np.zeros((2,1)) # tạo ma trận Y để tính tổng ma trận A^t*b với số dòng là số toán hạng của phương trình
    for k in range(len(b)): # vòng lặp để tính tổng
        A = np.array([[1, a[k]]])
        Y = Y + np.transpose(A) * b[k]

    print('Ta có tổng chuỗi ma trận A^t*A và A^t*b lần lượt là: ')
    print('Tổng chuỗi ma trận A^t*A: ')
    print(X)
    print('Tổng chuỗi ma trận A^t*b: ')
    print(Y)
    print('Từ đó ta tìm được giá trị bình phương cực tiểu theo công thức x = (A^t*A)^-1 * A^t*b')
    R = np.linalg.inv(X) @ Y # tìm được nghiệm bình phương tối thiểu từ hai ma trận X và Y
    print('=> Ma trận x tìm được:')
    print(R)
    print('\n=> Phương trình đường thẳng thể hiện lượng thuốc giảm theo thời gian: y = {} + {}*x'.format(R[0], R[1]))

def bai03():

    print('\n=============== BÀI 3 ================\n')
    # Bài 3 câu a tương tự như bài 2
    data = np.array([[-2, -1], [0, 1.5], [1, 3.1], [2, 6.3], [4, 11.1]])

    a = data[:, 0]
    b = data[:, 1]

    X = np.zeros((3,3))

    for k in range(len(a)):
        A = np.array([[1, a[k], np.log(a[k]**2 + 1)]])

        X = X + np.transpose(A) @ A

    Y = np.zeros((3,1))

    for k in range(len(b)):
        A = np.array([[1, a[k], np.log(a[k]**2 + 1)]])
        Y = Y + np.transpose(A) * b[k]

    print('Ta có tổng chuỗi ma trận A^t*A và A^t*b lần lượt là: ')
    print('Tổng chuỗi ma trận A^t*A: ')
    print(X)
    print('Tổng chuỗi ma trận A^t*b: ')
    print(Y)
    print('Từ đó ta tìm được giá trị bình phương cực tiểu theo công thức x = (A^t*A)^-1 * A^t*b')
    R = np.linalg.inv(X) @ Y
    print('=> Ma trận x tìm được:')
    print(R)
    print('\n=> Phương trình liên hệ giữa độ giảm trọng lượng hợp chất và khoảng thời gian mà hợp chất tiếp xúc với không khí:')
    print('y = {} + {}*x + {}*ln(x^2 + 1)'.format(R[0], R[1], R[2]))
    
    print('----- Câu b ------')
    curvePoints = [0]*len(a) # tạo phương trình để lưu điểm sau khi truyền các điểm x vào phương trình
    for i in range(len(a)): # vòng lặp truyền các điểm x vào phương trình
        curvePoints[i] = R[0] + R[1]*a[i] + R[2]*math.log(a[i]**2 + 1)
    
    for i in range(len(a)): # vẽ từng điểm lên đồ thị
        plt.plot(a[i], b[i], 'ro')
    plt.plot(a, curvePoints) # vẽ phương trình hồi quy tuyến tính
    plt.title(label='Đồ thị thể hiện mối liên hệ giữa độ giảm trọng lượng của\n hợp chất và khoảng thời gian mà hợp chất tiếp xúc với không khí')
    plt.xlabel('Khoảng thời gian (tính theo năm)')
    plt.ylabel('Độ giảm trọng lượng')
    plt.show() # hiện màn hình đồ thị

    print("Dự đoán độ giảm trọng lượng hợp chất tại năm 6.5: {} gram".format(R[0] + R[1]*6.5 + R[2]*math.log(6.5**2 + 1)))
    
    print('----- Câu c ------')
    hasZero = False
    hasNegVal = False
    for i in range(len(a)): # kiểm tra các giá trị có thỏa điêu kiện phương trình không
        if a[i] == 0:
            hasZero = True
            break
        if a[i] < 0:
            hasNegVal = False
    if hasNegVal or hasZero:
        print('Không thể sử dụng hàm y = a + b*x + c*ln(x) vì sẽ có các bộ mà tại đó x <= 0')
    if hasZero:
        print('Không thể sử dụng hàm y = a + b*x + c/x vì có các bộ mà tại đó x có giá trị là 0')
    
def main(): # hàm main thực thi chương trình
    bai01()
    bai02()
    bai03()

if __name__ == '__main__': # chạy chương trình
    main()    


