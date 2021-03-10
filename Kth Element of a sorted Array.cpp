int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        priority_queue<int> heap;
        for(int i=0;i<n;i++)
        {
            heap.push(arr1[i]);
            if(heap.size()>k)
            heap.pop();
        }
        for(int i=0;i<m;i++)
        {
            heap.push(arr2[i]);
            if(heap.size()>k)
            heap.pop();
        }
        return heap.top();
    }
//SPACE COMP: O(K), TC : O(nlog(k))
