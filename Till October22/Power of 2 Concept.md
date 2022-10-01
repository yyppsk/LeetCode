# Power of 2 Concept

## Key Idea

the binary form of every power of two likes 0b100...0, because pow(2, n) == 1 << n
1 = 0b1
2 = 0b10
4 = 0b100
8 = 0b1000

...
the binary form of everypow(2, n) - 1 likes0b11..1
1 - 1 = 0 = 0b0 => 1 & 0 = 0b1 & 0b0 = 0
2 - 1 = 1 = 0b1 => 2 & 1 = 0b10 & 0b1 = 0
4 - 1 = 3 = 0b11 => 4 & 3 = 0b100 & 0b11 = 0
8 - 1 = 7 = 0b111 => 8 & 7 = 0b1000 & 0b111 = 0
...
so we can find pow(2, n) & (pow(2, n) - 1) == 0

for example, num = 4 = 0b100
4 - 1 = 3 = 0b11
4 & 3 = 0b100 & 0b11 = 0

Amazing, right?
But that's not enough! We need to expain that if n is not a power of two then n & n - 1 != 0
If m is not a power of two, then the binary form of m contains more than one 1, that is 0b1x..x10..0, x represents 0 or 1
som - 1 = 0b1x..x10..0 - 1 = 0b1x..x01..1, that is the first 1 in m is still in the binary form of m - 1, so that m & (m - 1) = 0b1x..x0..0 > 0

for example, m = 6 = **0b110**
6 - 1 = 5 =**0b101**
6 & 5 = 4 =**0b100** > 0
Did you find it? The bold 1 is still there!!!

More generally, for any number n > 0
n & n - 1 removes the last 1 in the binary form of n
if and only if n is a power of two, there is only one 1 in the binary form of n
If you have any question, feel free to ask. If you like the solution or the explanation, Please UPVOTE!
