int mx_sqrt(int x) {
    int start = 1;
    int end = x <= 46340 ? x : 46340;

    while (start <= end) {
        int mid = (start + end) / 2;
        int n = mid * mid - x;

        if (n < 0) {
            start = mid + 1;
        }
        else if (n > 0) {
            end = mid - 1;
        }
        else {
            return mid;
        }
    }
    return 0;
}

