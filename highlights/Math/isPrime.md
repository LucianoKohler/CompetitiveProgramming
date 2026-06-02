# Is Prime

Complexity: 
- Processing: **O(sqrt(n))**
- Memory: **O(1)**

---

To find a prime efficiently, we can use the base prime finding function (for from 2 to n-1), but shaving some cases that make the code slow, for example:
- We verify starting values to start the for with a higher value
- If we check if `n%2 == 0` or `n%3 == 0`, we can run make the for run with **step 6** 
- We don't need to loop until n, but **sqrt(n)**

*Note: To calculate multiple small values, it is best to use the **Sieve of Eratosthenes (DP)**, but this algorithm works for most of the cases*

```cpp
bool isPrime(int num) {
      // Corner cases
      if(num <= 1) return false;
      if (num <= 3)  return true;

      // Testing to make the for jump 6 values at a time
      if (num % 2 == 0 || num % 3 == 0)
          return false;

      // Other small optimizations
      for (int i = 5; i <= sqrt(num); i += 6)
          if (num % i == 0 || num % (i + 2) == 0)
              return false;

      return true;
  }
  ```