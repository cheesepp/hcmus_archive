import numpy as np

# read the matrix from the input file
def readFile(filename):
    a = np.loadtxt(filename)
    return a

# gauss elimination function
def gaussElimination(arr):
    rows, cols =  arr.shape

    considerCol = 0
    i = 0
    while i < rows:
        if considerCol >= cols - 1:
            break
        if (arr[i, considerCol] == 0):
            isAllZero = False
            noneZeroRow = -1
            for t in range(i, rows):
                if arr[t, considerCol] == 0:
                    isAllZero = True
                else: 
                    isAllZero = False
                    noneZeroRow = t                        
                    break
            if not isAllZero:
                arr[noneZeroRow] += arr[i]
                arr[i] = arr[noneZeroRow] - arr[i]
                arr[noneZeroRow] -= arr[i]   
            else:
                considerCol = considerCol + 1
                i = i
                continue
        else:
            isAllZero = False
        for j in range(i + 1, rows):
            multiplier = arr[j, considerCol] / arr[i, considerCol]  
            arr[j] = arr[j] - multiplier*arr[i]
        considerCol = considerCol + 1
        i += 1

    for i in range(rows):
        isZero = isZeroRow(arr, i, cols)
        if isZero:
            for k in range(i +1, rows):
                if(isZeroRow(arr, k, cols)):
                    pass
                else:
                    arr[k] += arr[i]
                    arr[i] = arr[k] - arr[i]
                    arr[k] -= arr[i]
                    i += 1
    # change element which is -0 to 0
    for i in range(rows):
        for j in range(cols):
            if arr[i][j] == -0:
                arr[i][j] = 0


# back substitue function
def backSubstitution(arr):
    rows, cols =  arr.shape
    endNoZeroRow = rows
    isManySolutions = False
    if cols - 1 > rows:
        isManySolutions = True
    else :    
        for i in range(rows):
            isZero = isZeroRow(arr, i, cols - 1)
            if isZero:
                if arr[i][cols - 1] != 0:
                    print("Vô nghiệm")
                    return
                else:
                    
                    for k in range(i + 1, rows):
                        if(isZeroRow(arr, k, cols)):
                            isManySolutions = True
                            endNoZeroRow = k - 1
                            pass
                        else:
                            arr[k] += arr[i]
                            arr[i] = arr[k] - arr[i]
                            arr[k] -= arr[i]
                            endNoZeroRow = k
                            i += 1

    if isManySolutions:
        print("\nMa trận vô số nghiệm\n")
        if rows > cols - 1:
            arr = arr[0: endNoZeroRow]
        else:
            temp = arr
            gaussJordan(temp)
            temp = temp.round(2)
            count = 0
            considerCol = 0
            freeVar = ['0']*(cols - 1)
            i = 0
            while i < rows:
                if considerCol >= cols - 1:
                    break
                if temp[i, considerCol] == 1:
                    count += 1
                elif considerCol < cols and arr[i, considerCol] == 0:
                    freeVar[considerCol] = "x{}".format(considerCol + 1)
                    i = i
                    considerCol = considerCol + 1
                    count += 1
                    continue
                i += 1
                considerCol += 1

            numOfFreeVar = cols - 1 - count
            num = cols - 1
            variable = ['0']*(cols - 1)
            for i in range(numOfFreeVar - 1, -1, -1):
                freeVar[num - 1] = "x{}".format(num)
                num -= 1

            freeVar = list(filter(lambda el: el != "0", freeVar))


            for i in range(rows):
                if isZeroRow(temp, i, cols):
                    continue

                variable[i] = str(temp[i, cols - 1])
                numOfFreeVar = len(freeVar)
                for j in range(numOfFreeVar):
                    if temp[i, int(freeVar[j][1:]) - 1] > 0:
                        t = " - {}".format(temp[i, int(freeVar[j][1:]) - 1])
                    elif temp[i, int(freeVar[j][1:]) - 1] < 0:
                        t = " + {}".format(abs(temp[i, int(freeVar[j][1:]) - 1]))
                    else:
                        continue
                    variable[i] = variable[i] + "{}*{}".format(t,freeVar[j])
            print ('\nNghiệm tổng quát của hệ: \n')      
            for x in variable:
                if x != '0':
                    print(x)
            
            for x in freeVar:
                print(x)
            return
                
    print('\nMa trận có nghiệm duy nhất: \n')
    variable = np.zeros(cols - 1)
    temp = arr[:, cols - 1]
    variable[cols - 2] = arr[endNoZeroRow - 1, cols - 1] / arr[endNoZeroRow - 1, cols - 2] 

    for i in range(endNoZeroRow - 2, -1, -1):
        for j in range(i + 1, cols - 1):
            temp[i] = temp[i] - arr[i, j]*variable[j] 
        variable[i] = temp[i] / arr[i, i]

    for x in variable:
        print(x, end = " ")

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

# gauss jordan (support for getting many solutions case)
def gaussJordan(arr):
    rows, cols = arr.shape

    considerCol = 0
    i = 0
    while i < rows:
        if considerCol >= cols - 1:
            break
        if (arr[i, considerCol] == 0):
            isAllZero = False
            noneZeroRow = -1
            for t in range(i, rows):
                if arr[t, considerCol] == 0:
                    isAllZero = True
                else:
                    isAllZero = False
                    noneZeroRow = t
                    break

            if not isAllZero:
                arr[noneZeroRow] += arr[i]
                arr[i] = arr[noneZeroRow] - arr[i]
                arr[noneZeroRow] -= arr[i]
            else:
                considerCol = considerCol + 1
                i = i
                continue
        else:
            isAllZero = False

        if arr[i, considerCol] != 1:
            arr[i] = arr[i] / arr[i, considerCol]

        for j in range(rows):
            if j == i:
                continue
            multiplier = arr[j, considerCol]
            arr[j] = arr[j] - multiplier*arr[i]

        considerCol = considerCol + 1
        i += 1

    # change element which is -0 to 0
    for i in range(rows):
        for j in range(cols):
            if arr[i][j] == -0:
                arr[i][j] = 0

# main
arr = readFile("input.txt")
print(arr)

# execute gauss elimination function
gaussElimination(arr)
print('========= GAUSS ELIMINATION ==========')
print(arr)

# execute back substitution
backSubstitution(arr)