if (!matrix.size())
        return false;
    int row = matrix.size();
    int col = matrix[0].size();

    int lo = 0;
    int hi = (row * col) - 1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (matrix[mid / col][mid % col] == target)
            return true;
        if (matrix[mid / col][mid % col] < target)
            lo = mid + 1;
        else
            hi = mid + 1;
    }
    return false;