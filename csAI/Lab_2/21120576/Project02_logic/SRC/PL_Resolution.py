import os
# get directory name of project
dirname = os.path.dirname(os.path.abspath(__file__))

# split CNF clause to list
def split_CNF_clause(cnf_clause):

    literals = cnf_clause.split(' OR ')
    return literals

# sort unique literal in alphabetical order
def sort_clause(literals):
    # get unique literal
    unique = list(set(literals))
    return sorted(unique, key=lambda x: x[-1])

# negate literal
def negate(literal):

    # check if len literal == 1 -> do not have '-'
    if len(literal) == 1:
        return '-' + literal

    return literal[-1]

# check if clause is always true
def is_true(clause):

    for i in range(len(clause) - 1):
        for j in range(i + 1, len(clause)):
            if negate(clause[i]) == clause[j]:
                return True
            
    return False

# pl resolver for resolve clauses
def PL_resolver(clause_1, clause_2):
    
    # save final clause to result
    result = []
    # iterate each literal in both clauses
    for i in range(len(clause_1)):
        for j in range(len(clause_2)):
            # check if two literals is complement
            if negate(clause_1[i]) == clause_2[j]:
                
                # delete the complement literals
                temp_1 = clause_1.copy()
                temp_1.pop(i)
                temp_2 = clause_2.copy()
                temp_2.pop(j)

                # sort literals
                sorted_clause = sort_clause(temp_1 + temp_2)
                # append to result
                result.append(sorted_clause)
    return result

def PL_resolution(KB, alpha):

    # check whether KB ental alpha or not
    is_entail = False
    
    new_KB = []

    # save splitted clause to new kb
    for clause in KB:
        new_KB.append(split_CNF_clause(clause))
    
    # split alpha clause
    al_clause = split_CNF_clause(alpha)
    new_al = []

    # negate each literal in alpha clause
    for literal in al_clause:
        new_al.append(negate(literal))

    # save negated alpha litral to new kb
    for literal in new_al:
        if literal not in new_KB:
            new_KB.append([literal])

    # create step dictionary to store resolved clauses each loop
    steps = dict()

    loop = 0
    print(new_KB)
    while True:
        # increment loop
        loop = loop + 1
        # create empty list each loop
        steps[loop] = []
        print(f'Loop: {loop}')

        # check new clause has been created
        new_clause = False

        # iterate each pair of clauses in new kb
        for i in range(len(new_KB) - 1):
            for j in range(i + 1, len(new_KB)):
                
                # save resolved clauses to resolvents
                resolvents = PL_resolver(new_KB[i], new_KB[j])
                
                # check if resolvents contain empty list -> kb entail alpha
                if [] in resolvents:
                    is_entail = True
                    temp1 = " OR ".join(sort_clause(new_KB[i]))
                    temp2 = " OR ".join(sort_clause(new_KB[j]))
                    print(f'({temp1}) hợp giải với ({temp2})')
                    steps[loop].append([])
                    return is_entail, steps
                
                # iterate clause in resolvents
                for clause in resolvents:
                    
                    # check if clause is always true -> ignore this clause
                    if is_true(clause):
                        continue

                    # check if new_clause is true -> append to steps
                    if clause not in new_KB and clause not in steps[loop]:

                        new_clause = True
                        steps[loop].append(clause)
                        temp1 = " OR ".join(sort_clause(new_KB[i]))
                        temp2 = " OR ".join(sort_clause(new_KB[j]))
                        print(f'({temp1}) hợp giải với ({temp2})')

        # new clauses was created -> append to new kb
        if new_clause:
            
            for clause in steps[loop]:
                new_KB.append(clause)

        else: 
            print('KB KHÔNG entail alpha vì không phát sinh được mệnh đề mới và không tìm thấy mệnh đề rỗng.')
            return False, steps

# CNF clause to write to output directory
def CNF(clause):

    cnf_clause = ''

    if len(clause) == 0:
        cnf_clause = "{}"
        return cnf_clause

    cnf_clause = clause[0]
    for i in range (1, len(clause)):
        cnf_clause = cnf_clause + ' OR ' + clause[i]

    return cnf_clause 

def read_testcases(i):
    print(f'----------- INPUT{i}.txt ------------')
    input_path = os.path.join(dirname, 'INPUT', f'input{i}.txt')

    with open(input_path, 'r+') as f:
        alpha = f.readline().strip()
        n = int(f.readline())
        kb = []
        for i in range(n):
            kb.append(f.readline().strip())     
        return kb, alpha  

def write_solutions(i, is_entail, steps):

    output_path = os.path.join(dirname, 'OUTPUT', f'output{i}.txt')

    with open(output_path, 'w') as f:
        
        for step in steps.values():
            f.write(str(len(step)) + '\n')
            for clause in step:
                f.write(CNF(clause) + '\n')

        if is_entail: f.write("YES")
        else: f.write("NO")
    print(f'-----------------------------------\n')




if __name__ == "__main__":

    for i in range(7,8):
        kb, alpha = read_testcases(i)
        is_entail, steps = PL_resolution(kb, alpha)
        write_solutions(i, is_entail, steps)
 
    


