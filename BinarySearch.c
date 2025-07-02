void BinarySearch(int arr,int target,int low,int high){
    while ((low<=high))
    {
        int mid = (low + high) / 2;  
        if(arr[mid]==target){
            return mid;
        }
    }
    
    BinarySearch(arr,target,low,high);

}