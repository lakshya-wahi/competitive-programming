# RATING: 1500

import sys
 
input = sys.stdin.buffer.readline
 
 
def solve():
    n, d = map(int, input().split())
    
    money = set()
    dic = {}
    
    for i in range(n):
        x, y = map(int, input().split())
        money.add(x)
        if dic.get(x):
            dic[x] += y
        else:
            dic[x] = y
    
    money2 = list(money)
    money2.sort()
    
    left = 0
    r = 0
    
    csum = 0
    answer = csum
    while r < len(money2):
        csum += dic[money2[r]]
        while money2[r]- money2[left] >= d:
            csum -= dic[money2[left]]
            left += 1
        answer = max(csum, answer)
        r += 1
    
    print(answer)
        
        
        
            
    
 
 
if __name__ == "__main__":
    solve()
