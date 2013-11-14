#! /usr/bin/env python
#coding=utf-8
import sys
def main(max_stair,dirty_num,dirty_stair):
    i=0
    if dirty_stair[0] is 1 or dirty_stair[-1] is max_stair:
        print 'NO'
        return
    while i+2<dirty_num:
        if dirty_stair[i]+2==dirty_stair[i+2]:
            print 'NO'
            return
        i=i+1
    print 'YES'
    return
if __name__=='__main__':
    max_stair,dirty_num=map(int,sys.stdin.readline().split())
    if dirty_num is 0:
        print 'YES'
    else:
        dirty_stair=map(int,sys.stdin.readline().split())
        dirty_stair.sort()
        main(max_stair,dirty_num,dirty_stair)