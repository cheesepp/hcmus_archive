import numpy as np

# read the matrix from the input file
def readFile(filename):
    a = np.loadtxt(filename)
    return a

# gauss elimination function
def gaussElimination(arr):
    rows, cols =  arr.shape # get the number of rows and columns of the matrix

    considerCol = 0
    i = 0
    while i < rows:
        if considerCol >= cols - 1: # constraint iterating column
            break
        if (arr[i, considerCol] == 0):
            isAllZero = False
            noneZeroRow = -1
            for t in range(i, rows): # for loop for checking each element in a considered column is euqual to zero or not
                if arr[t, considerCol] == 0:
                    isAllZero = True
                else:
                    isAllZero = False
                    noneZeroRow = t                        
                    break
            if not isAllZero: # swap two rows if the beneath row was not all zero
                arr[noneZeroRow] += arr[i]
                arr[i] = arr[noneZeroRow] - arr[i]
                arr[noneZeroRow] -= arr[i]   
            else: # go to the next column
                considerCol = considerCol + 1
                i = i
                continue
        else:
            isAllZero = False
        for j in range(i + 1, rows): # for loop for simplifying the matrix
            multiplier = arr[j, considerCol] / arr[i, considerCol]  
            arr[j] = arr[j] - multiplier*arr[i]
        considerCol = considerCol + 1
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
    if cols - 1 > rows: # check if number of variables is greater than number of expressions
        isManySolutions = True # go to the many solutions case if it fit the condition
    else :    
        for i in range(rows):
            isZero = isZeroRow(arr, i, cols - 1) # check the present row is all zero or not (0 -> cols - 1)
            if isZero:
                if arr[i][cols - 1] != 0: # check the last element in the row is 0
                    print("Ma trận vô nghiệm")
                    return
                else:
                    
                    for k in range(rows - 1, i - 1, -1): # for loop for finding the none-zero row
                        if(isZeroRow(arr, k, cols)):
                            isManySolutions = True
                            endNoZeroRow = k - 1 # assign the belowest none zero row to endNoZeroRow 
                            pass
                        else: # swap two rows if it find the none zero row
                            arr[k] += arr[i]
                            arr[i] = arr[k] - arr[i]
                            arr[k] -= arr[i]
                            endNoZeroRow = k # update the belowest none zero row to endNoZeroRow

    # go to many solutions case
    if isManySolutions:
        print("\nMa trận vô số nghiệm\n")
        if rows > cols - 1: 
            arr = arr[0: endNoZeroRow] # slicing the matrix if the number of expressions is greater than number of variables
        else:
            temp = arr # create a temporary matrix
            gaussJordan(temp) # use gauss jordan normalize the matrix
            temp = temp.round(2) # round the matrix
            count = 0 # count the considered variables
            considerCol = 0
            freeVar = ['0']*(cols - 1) # create an array for containing free variables
            i = 0
            while i < rows:
                if considerCol >= cols - 1:
                    break
                if temp[i, considerCol] == 1: # check the considering element is one
                    count += 1 # update the value of considered column
                elif considerCol < cols and arr[i, considerCol] == 0: # if the considering element is zero
                    freeVar[considerCol] = "x{}".format(considerCol + 1) # update the free variable array
                    i = i
                    considerCol = considerCol + 1 # go to the next column
                    count += 1 # update the considered column
                    continue
                i += 1
                considerCol += 1

            numOfFreeVar = cols - 1 - count # get number of rest variable in the matrix
            num = cols - 1
            variable = ['0']*(cols - 1) # array for containing roots
            for i in range(numOfFreeVar - 1, -1, -1): # find rest of variables
                freeVar[num - 1] = "x{}".format(num)
                num -= 1

            freeVar = list(filter(lambda el: el != "0", freeVar)) # filter the array to delete redundant elements


            for i in range(rows):
                if isZeroRow(temp, i, cols):
                    continue

                variable[i] = str(temp[i, cols - 1]) # convert each element in array to string
                numOfFreeVar = len(freeVar) # get the number of free variables
                for j in range(numOfFreeVar): # iterate for Incrementing free variables to the dependent variables
                    if temp[i, int(freeVar[j][1:]) - 1] > 0: # change the sign of element
                        t = " - {}".format(temp[i, int(freeVar[j][1:]) - 1])
                    elif temp[i, int(freeVar[j][1:]) - 1] < 0:
                        t = " + {}".format(abs(temp[i, int(freeVar[j][1:]) - 1]))
                    else:
                        continue
                    variable[i] = variable[i] + "{}*{}".format(t,freeVar[j]) # increment the free variables to the dependent variables
            print ('\nNghiệm tổng quát của hệ: \n')      
            for x in variable: # print the result
                if x != '0':
                    print(x)
            
            for x in freeVar:
                print(x)
            return
                
    print('\nMa trận có nghiệm duy nhất: \n') # go to the unique root case if no conditions are matched
    print('Nghiệm của phương trình là: ')
    variable = np.zeros(cols - 1)  # create an root array
    temp = arr[:, cols - 1] # get the last column elements

    #devide the last none zero rows and column with the last rows and penultimate column 
    variable[cols - 2] = arr[endNoZeroRow - 1, cols - 1] / arr[endNoZeroRow - 1, cols - 2]

    for i in range(endNoZeroRow - 2, -1, -1): # iterate each rows from the belowest none zero row to up
        for j in range(i + 1, cols - 1): # iterate each column
            temp[i] = temp[i] - arr[i, j]*variable[j]  # calcute the value of each column
        variable[i] = temp[i] / arr[i, i] # get the last result

    # print the result
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