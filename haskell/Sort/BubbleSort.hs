module Sort.BubbleSort (bubblesort) where

bsort :: (Ord a) => [a] -> [a]
bsort (x1:x2:xs) 
    | x1 > x2 = x2:(bsort (x1:xs))
    | otherwise = x1:(bsort (x2:xs))
bsort x = x

bubblesort :: (Ord a) => [a] -> [a]
bubblesort x = case (bsort x) of 
    t | t == x -> t
      | otherwise -> bubblesort t
