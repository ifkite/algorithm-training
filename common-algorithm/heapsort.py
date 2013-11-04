import random
def max_heapify(heap,i,heap_len):
    left=(i<<1)+1
    right=(i<<1)+2
    if left<=heap_len and heap[i]<heap[left]:
        largest=left
    else:
        largest=i
    if right<=heap_len and heap[largest]<heap[right]:
        largest=right
    if largest is not i:
        heap[i],heap[largest]=heap[largest],heap[i]
        max_heapify(heap,largest,heap_len)

if __name__=='__main__':
    heap=[random.randint(1,10) for x in range(1,10)]
    #build heap
    i=(len(heap)-1)>>1
    while i>=0:
        max_heapify(heap,i,len(heap)-1)
        i=i-1
    
    while i>0:
        heap[0],heap[i]=heap[i],heap[0]
        max_heapify(heap,0,i-1)
        i=i-1
    print heap
