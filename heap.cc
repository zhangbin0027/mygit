#include <iostream>

using namespace std;

void Swap(int & left_data, int & right_data)
{
    int auxiliary = left_data;
    left_data = right_data;
    right_data = auxiliary;
}
// 小顶堆

// 从i开始，到其父节点，父节点的父节点...，依次检查、调整以符合“小顶堆”的性质
void MinHeapAdjustUp(int data[], int i)
{
    if (i <= 0)
        return;

    int j, auxiliary;

    auxiliary = data[i];
    j = (i - 1) / 2; // 父结点

    while (j >= 0 && i != 0)
    {
        if (data[j] <= auxiliary)
            break;

        data[i] = data[j]; // 较大结点下移,替换它的子结点  
        i = j;
        j = (i - 1) / 2;
    }  

    data[i] = auxiliary;
}

// 向“小顶堆”中添加新的数据
// 每次插入都是将新数据放在数组最后，然后从新插入数据开始，
// 到其父节点，父节点的父节点...，依次检查、调整以符合“小顶堆”的性质
void MinHeapAddData(int data[], int count, int new_data)
{  
    data[count] = new_data;
    MinHeapAdjustUp(data, count);
}

// 从i节点开始，进行一次从上向下的“小顶堆”调整
// count为节点总数，i节点的左右孩子节点依次为 2*i+1， 2*i+2  
void MinHeapAdjustDown(int data[], int i, int count)
{
    int j, auxiliary;

    auxiliary = data[i];
    j = 2 * i + 1; // 左孩子结点

    while (j < count)
    {
        if (j + 1 < count && data[j + 1] < data[j]) // 在左右孩子中找最小的
            j++;

        if (data[j] >= auxiliary)
            break;

        data[i] = data[j]; // 把较小的子结点往上移动,替换它的父结点
        i = j;
        j = 2 * i + 1;
    }

    data[i] = auxiliary;
}

// 从“小顶堆”中删除数据
// 堆中每次都只能删除第0个数据。为便于重建堆，将最后一个数据的值赋给根结点
// 然后再从根结点开始进行一次从上向下的调整
void MinHeapDeleteData(int data[], int count)
{
    Swap(data[0], data[count - 1]);
    MinHeapAdjustDown(data, 0, count - 1);
}

// 建立“小顶堆”
// 因为对叶子结点来说，它已经是一个合法的“小顶堆”
// 所以这里只需要，从下往上，从右到左，将每个“非叶结点”当作根结点，将其与其子树调整成“小顶堆”
void MakeMinHeap(int data[], int count)
{
    for (int i = count / 2 - 1; i >= 0; i--)
        MinHeapAdjustDown(data, i, count);
}

// 堆排序（利用小顶堆，进行降序排序）
void MinHeapSortDesc(int data[], int count)
{
    for (int i = count - 1; i >= 1; i--)
    {
        Swap(data[i], data[0]);
        MinHeapAdjustDown(data, 0, i);
    }
}

// 大顶堆

// 从i开始，到其父节点，父节点的父节点...，依次检查、调整以符合“大顶堆”的性质
void MaxHeapAdjustUp(int data[], int i)
{
    if (i <= 0)
        return;

    int j, auxiliary;

    auxiliary = data[i];
    j = (i - 1) / 2; // 父结点

    while (j >= 0 && i != 0)
    {
        if (data[j] >= auxiliary)
            break;

        data[i] = data[j]; // 较小结点下移,替换它的子结点  
        i = j;
        j = (i - 1) / 2;
    }  

    data[i] = auxiliary;
}

// 向“大顶堆”中添加新的数据
// 每次插入都是将新数据放在数组最后，然后从新插入数据开始，
// 到其父节点，父节点的父节点...，依次检查、调整以符合“大顶堆”的性质
void MaxHeapAddData(int data[], int count, int new_data)
{  
    data[count] = new_data;
    MaxHeapAdjustUp(data, count);
}

// 从i节点开始，进行一次从上向下的“大顶堆”调整
// count为节点总数，i节点的左右孩子节点依次为 2*i+1， 2*i+2  
void MaxHeapAdjustDown(int data[], int i, int count)
{
    int j, auxiliary;

    auxiliary = data[i];
    j = 2 * i + 1; // 左孩子结点

    while (j < count)
    {
        if (j + 1 < count && data[j + 1] > data[j]) // 在左右孩子中找最大的
            j++;

        if (data[j] <= auxiliary)
            break;

        data[i] = data[j]; // 把较大的子结点往上移动,替换它的父结点
        i = j;
        j = 2 * i + 1;
    }

    data[i] = auxiliary;
}

// 从“大顶堆”中删除数据
// 堆中每次都只能删除第0个数据。为便于重建堆，将最后一个数据的值赋给根结点
// 然后再从根结点开始进行一次从上向下的调整
void MaxHeapDeleteData(int data[], int count)
{
    Swap(data[0], data[count - 1]);
    MaxHeapAdjustDown(data, 0, count - 1);
}

// 建立“大顶堆”
// 因为对叶子结点来说，它已经是一个合法的“大顶堆”
// 所以这里只需要，从下往上，从右到左，将每个“非叶结点”当作根结点，将其与其子树调整成“大顶堆”
void MakeMaxHeap(int data[], int count)
{
    for (int i = count / 2 - 1; i >= 0; i--)
        MaxHeapAdjustDown(data, i, count);
}

// 堆排序（利用小顶堆，进行降序排序）
void MaxHeapSortAsc(int data[], int count)
{
    for (int i = count - 1; i >= 1; i--)
    {
        Swap(data[i], data[0]);
        MaxHeapAdjustDown(data, 0, i);
    }
}

int main()
{
    int array[] = {9, 6, 3, 8, 7, 1, 5, 2, 4};

    MakeMinHeap(array, 9);
    MinHeapSortDesc(array, 9);

    for(int i = 0; i < 9; ++i)
        cout << array[i] << " ";

    cout << endl;

    MakeMaxHeap(array, 9);
    MaxHeapSortAsc(array, 9);

    for(int i = 0; i < 9; ++i)
        cout << array[i] << " ";

    cout << endl;

    return 0;
}
