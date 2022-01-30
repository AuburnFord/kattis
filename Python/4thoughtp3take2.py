OPS = ["*", "//", "+", "-"]
valid = dict()

def calc_valid():
    for op1 in OPS:
        for op2 in OPS:
            for op3 in OPS:
                valid[eval(f'4 {op1} 4 {op2} 4 {op3} 4')] = f'4 {op1} 4 {op2} 4 {op3} 4'

def main():
    calc_valid()
    cases = int(input())
    for i in range(cases):
        desired = int(input())
        if desired in valid:
            out = valid[desired].replace('//', '/')
            print(f'{out} = {desired}')
        else:
            print('no solution')

if __name__ == "__main__":
    main()
