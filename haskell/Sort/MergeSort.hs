module Sort.MergeSort (mergesort) where

merge :: (Ord a) => [a] -> [a] -> [a]
merge l [] = l
merge [] l = l
merge (x1:l1) (x2:l2)
    | x1 <= x2  = x1: merge l1 (x2:l2)
    | otherwise = x2: merge (x1:l1) l2

-- http://en.literateprograms.org/Merge_sort_%28Haskell%29
split :: [a] -> ([a],[a])
split xs = go xs xs where
    go (x:xs) (_:_:zs) = (x:us,vs) where (us,vs)=go xs zs
    go    xs   _       = ([],xs)

mergesort :: (Ord a) => [a] -> [a]
mergesort (x:[]) = [x]
mergesort xs = merge  (mergesort f) (mergesort s)
    where (f, s) = split xs
