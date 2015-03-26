int linear_search(int * arr, int key, int n) {

int i=0;

for(i=0; i< n; i++){

if(arr[i] == key)
return i;

}

return -1;

}
