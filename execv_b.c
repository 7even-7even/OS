#include<stdio.h>
#include<stdlib.h>

int binary(int arr[],int l,int h,int search){
	
	
    	while(l<=h){
    	int mid=l+(h-l)/2;//2
    		if(arr[mid]==search){
			return mid;
      		}
    		else if(search>arr[mid]){
       			l=mid+1;
      		}
        	else {
     			h=mid-1;
      		}
	}
	return -1;
}

void main(int argc, char * argv[]){
	int arr[argc-1],key;
	
	for(int i=1;i<argc;i++){
		arr[i-1]=atoi(argv[i]);
	}
	
	printf("Size Of Array:%d\n",argc-1);
	
	printf("Elements are: \n");
	
	for(int i=0;i<argc-1;i++)
	{
		printf("%d\t",arr[i]);
	}
	
	printf("\nEnter the Search Element: ");
	
	scanf("%d",&key);
	
	int result=binary(arr,0,argc-1,key);
		
	if(result==-1){
		printf("\nElement not found\n");
	}
	else{
		printf("\nElement found at index: %d", result);
	}

}
