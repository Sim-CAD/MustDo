	bool check_elements(int arr[], int n, int A, int B)
	{
		int rangelength = (B - A) < n ? B - A : -1;
		
		if(rangelength == -1)
		    return false;
		
		for(int i = 0; i < n; i++){
		    if(abs(arr[i]) >= A && abs(arr[i]) <= B){
		        int index = abs(arr[i]) - A;
		        if(index < n && arr[index] > 0){
		            arr[index] *= -1;
		        }
		    }
		}
		int count = 0;
		for(int i = 0; i <= rangelength && i < n; i++){
		    if(arr[i] > 0)
		        return false;
		    else
		        count++;
		}
		
		if(count == rangelength + 1)
		    return true;
		
		return false;
    }
