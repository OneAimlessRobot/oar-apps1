{-

Brincadeiras em Haskell

-}
fun x = 1

h = fun 5

factorial 0 =1
factorial n = n* factorial (n-1)

isPrimeAux n d
  | n < 2 = False
  | d == 1= True
  | n `mod` d  == 0 = False
  |otherwise = isPrimeAux n (d - 1)
    
isPrime n = isPrimeAux n (n - 1)

tenList = [1..10]

listInts=  filter (isPrime) [1..]

listTenPrimes = take 10 (filter (isPrime) listInts)


primes = filter isPrime (take 10 (map (\x-> x) listInts))


sumInts = sum tenList

main =do
 print listTenPrimes
