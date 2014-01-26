module Sort.QuickSort (quicksort) where

quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (p:xs) = (quicksort [x | x <- xs, x <= p]) ++ [p] ++ (quicksort [x | x<-xs, x > p])
