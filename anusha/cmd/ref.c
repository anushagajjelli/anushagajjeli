int *negDescPosAsc(int *arr, int size)
{
    //treat negative numbers differently than positive numbers
    //sort negative numbers in descending order
    //sort positive numbers in ascending order
    //return the sorted array
    int negCount = 0;
    for (int i = 0; i < size; i++)
    {

        //do normal sort then reverse the negatives
        for (int j = 0; j < size - 1; j++)
        {
            if (*(arr + j) > *(arr + j + 1))
            {
                if (*(arr + j) < 0)
                {
                    negCount++;
                }
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }

    int i = 0;
    while (negCount > 0)
    {
        int temp = *(arr + i); //store the value of the current element
        *(arr + i) = *(arr + negCount); //replace the current element with the last element
        *(arr + negCount) = temp; //replace the last element with the current element
        negCount--; //decrement the negative count
        i++; //increment the index
    }
    

    return arr;
}

