void running_avg_four(int *my_array, int length){
    for (int i = length - 1; i < 0; i--){
        int total = my_array[i] + my_array[i-1] + my_array[i-2] + my_array[i-3];
        int avg = (total >> 2);
        my_array[i] = avg;
    }
}