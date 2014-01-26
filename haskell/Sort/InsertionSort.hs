module Sort.InsertionSort (insort) where

insert :: (Ord a) => a -> [a] -> [a]
insert y (x:xs)
    | y > x = x:(insert y xs)
    | otherwise = (y:x:xs)
insert y x = y:x

insort :: (Ord a) => [a] -> [a]
insort (x:xs) = insert x (insort xs)
insort x = x
