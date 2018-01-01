sum_a :: Int -> Int
sum_a n = sum [3,6..n] + sum [5,10..n] - sum [15,30..n]


sum_divisible_by :: Int -> Int -> Int
sum_divisible_by n k = k * (p * (p + 1)) `div` 2
                   where p = n `div` k

sum_b :: Int -> Int
sum_b n = sum_divisible_by n 3 + sum_divisible_by n 5 - sum_divisible_by n 15
