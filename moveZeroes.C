void moveZeroes(int* nums, int numsSize) {
// Defining 2 varibles i,j for the for loop
    int i,j=0;
    for (i=0;i<numsSize;i++)
    {
        //if nums[i] is a non-zero element, move it to the start of an array.
        if (nums[i]!=0)
        {
            nums[j]=nums[i];
            j++;
        }
    }
    //assigning 0 to the remaining indexes
    for (i=j;i<numsSize;i++)
    {
        nums[i]=0;
    }
}
