#python read a series number
import sys
if __name__ == '__main__':
    loop = input()
    child = map(int,sys.stdin.readline().split())
    min_size, max_size = map(int, sys.stdin.readline().split())
    childen_num = sum(child)
    div_one = 0
    div_two = 0
    for i in range(loop):
        if div_one < min_size:
            div_one = div_one + child[i]
        elif div_one > max_size:
            print 0,
            break
        else:
            div_two = childen_num - div_one
            if div_two < min_size:
                print 0,
                break
            elif div_two > max_size:
                div_one = div_one + child[i]
                continue
            else:
                print i+1,
                break
