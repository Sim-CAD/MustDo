 //Problem Name: Second Largest
 //Source : GeeksForGeeks
 /****************************************/
    int print2largest(int arr[], int n) {
	    int max = arr[0];
	    int secondmax = -1;
	    for(int i = 0; i < n ; i++){
	        if(arr[i] > max)
	        {   
	            secondmax = max;
	            max = arr[i];
	           
	        }
	        if(arr[i] < max && arr[i] > secondmax)
	            secondmax = arr[i];
	            
	    }
	    return secondmax;
	}