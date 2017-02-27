from itertools import chain
from itertools import combinations

#DATA KHAKI;
#INPUT control_number 0 1 2 3;

a = '''11111 1 1 1 1
12222 1 2 2 2 
13333 2 1 3 3
14444 2 2 1 4
15555 3 1 2 1
16666 3 2 3 2
17777 1 3 1 3
18888 2 3 2 4
19999 3 3 3 1
20000 1 1 1 2
21111 2 2 2 3
22222 3 3 3 4
22223 4 1 1 1
22224 4 2 2 2
22225 4 3 3 3
22226 4 4 4 4'''

a = a.split('\n')
a =[i.split() for i in a]

code = {1:'a',2:'b',3:'c',4:'d'}

def powerset(iterable):
    "powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(1, len(s)+1))

def unicity_calculator(a):
    
    power_set = list(powerset([1,2,3,4]))
    
    
    final_ans = {}
    for i in power_set:
        alphabet = [code[j] for j in i]
        freq_tracker = {}
        for values in a:
            key_val = ''
            for indexes in i:
                key_val += values[indexes]
            if key_val not in freq_tracker:
                freq_tracker[key_val] = 1
            else:
                freq_tracker[key_val] += 1
#         print freq_tracker
        
        for k in freq_tracker:
            if freq_tracker[k] == 1:
                index_key = ''.join(alphabet)
                if index_key not in final_ans:
                    final_ans[index_key] = [k]
                else:
                    final_ans[index_key].append(k)

    for j in final_ans:
        print j
        for val in final_ans[j]:
            print val
            
        print "---------------"
        
                
        
        
unicity_calculator(a)  

# for j in ans:
#     if ans[j] == 1:
#         print j, ans[j]


