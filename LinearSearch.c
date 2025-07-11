void Linearsearch(){
    
    int arr[]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int target = 5;
        int i = 0;
        
        while(i<sizeof(arr)){
            if(arr[i]==target){
                return i;
            }else{
                i++;

            }

        }
        return -1;

}