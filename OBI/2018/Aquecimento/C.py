
real_char = set('abcdefghijklmnopqrstuvwxyz')
vogais =

key = raw_input()

N = int(raw_input())

for i in range(N):
    word = raw_input()
    res = ''
    curr_i = 0
    waiting_word = True
    consoante = False
    for ch in word:
        if ch not in real_char:
            res += ch
            waiting_word = True
            continue
        else:
            if waiting_word:
                if not (ch in 'aeiou'):
                    consoante = True
                else:
                    consoante = False
            waiting_word = False

        waiting_word = False
        if consoante:
            res += chr(ord('a') + (ord(ch)-ord('a') + ord(key[curr_i])-ord('a')) % 26)
            curr_i += 1
            curr_i = curr_i % len(key)
        else:
            res += ch
    print res
