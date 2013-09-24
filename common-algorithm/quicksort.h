/*from K&R 's C bible*/
void swap(int *intArr, int i, int j){
    int tmp;
    tmp = intArr[i];
    intArr[i] = intArr[j];
    intArr[j] = tmp;
}
void quickSort(int *intArr, int left, int right){
    int i, last;
    if(left >= right)     
        return;
    swap(intArr, left, (left + right) / 2);
    last = left;
    for(i = left + 1; i <= right; ++i)
        if(intArr[i] < intArr[left])
            swap(intArr, ++last, i);
    swap(intArr, left, last);
    quickSort(intArr, left, last - 1);
    quickSort(intArr, last + 1, right);
}
