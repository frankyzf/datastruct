import Test.HUnit

import Sort.BubbleSort
import Sort.InsertionSort
import Sort.MergeSort
import Sort.QuickSort

testorder :: Ord a => [a] -> Bool
testorder (x1:x2:xs)
				| x1 > x2 = False
				| otherwise = testorder xs
testorder xs = True

l = [2, 7, 100, 3, 49, 40, 3, 32]
testbubble = TestCase $ assertBool "bubble failed" (testorder $ bubblesort l)
testinsort = TestCase $ assertBool "insort failed" (testorder $ insort l)
testmergesort = TestCase $ assertBool "mergesort failed" (testorder $ mergesort l)
testquicksort = TestCase $ assertBool "quicksort failed" (testorder $ quicksort l)

alltests = TestList [testbubble, testinsort, testmergesort, testquicksort]

main = runTestTT $ alltests
