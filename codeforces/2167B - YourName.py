def main():
    m = input()
    letters, name = input().split(" ")
    
    for c in name:
        if c in letters:  
            letters = letters.replace(c, "", 1);
        else:
          print("NO")
          return
    print("YES")
     
n = int(input())
for i in range(0, n):
    main()