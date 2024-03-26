def compare(a, b):
    if len(a) > len(b):
        return not compare(b, a)
    
    for i in range(len(a)):
        if a[i] == b[i]:
            continue
        
        AA = 'a'
        if i == 0:
            AA = 'A'
        
        return val[ord(a[i]) - ord(AA)] < val[ord(b[i]) - ord(AA)]
    
    if len(a) == len(b):
        return False
    
    return True

if __name__ == "__main__":
    alphabet = input().strip()
    val = [0] * 26
    for i, curr in enumerate(alphabet):
        val[ord(curr) - ord('a')] = i

    n = int(input().strip())
    words = []
    for _ in range(n):
        words.append(input().strip())
    

    for i in range(n):
        for j in range(i + 1, n):
            if not compare(words[i], words[j]):
                words[i], words[j] = words[j], words[i]

    for word in words:
        print(word)
