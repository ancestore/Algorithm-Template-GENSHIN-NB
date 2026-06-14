#include <vector>
using namespace std;

// 合并两个有序区间 [l, m] 和 [m + 1, r]
void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> tmp(r - l + 1);
    int i = l, j = m + 1, k = 0;
    //m是中间的
    while (i <= m && j <= r) 
        tmp[k++] = (arr[i] >= arr[j]) ? arr[i++] : arr[j++];
    //为真就i++假的就是j++
    while (i <= m) tmp[k++] = arr[i++];
    while (j <= r) tmp[k++] = arr[j++];
    //空的直接放，剩下的部分本来就是有序的
    for (int p = 0; p < k; ++p) arr[l + p] = tmp[p];
}

// 递归主函数
void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);//分
    merge(arr, l, m, r);//并
}