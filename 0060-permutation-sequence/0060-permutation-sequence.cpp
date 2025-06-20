class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        int fact = 1;

        for (int i = 1; i <= n; i++) {
            numbers.push_back(i);
            fact *= i;
        }

        k--; // 0-based indexing
        string result;

        for (int i = 0; i < n; i++) {
            fact /= (n - i);
            int index = k / fact;
            result += to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);
            k %= fact;
        }

        return result;
    }
};