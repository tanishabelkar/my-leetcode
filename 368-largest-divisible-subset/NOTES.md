Algo -
dp is a vector of vectors
for each index store the max size of subset that ends with that index.
then for each index, traverse backwards. if the element is divisible by current index, then the vector at current index will be vector of that element +  current element.