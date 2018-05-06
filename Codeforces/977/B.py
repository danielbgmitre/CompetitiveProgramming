#coding: utf-8

N = int(raw_input())
word = raw_input()

grams = {}

for i in range(N-1):
    if word[i:i+2] in grams:
        grams[word[i:i+2]] += 1
    else:
        grams[word[i:i+2]] = 1

best = ''
maior = 0

for key in grams:
    if grams[key] > maior:
        best = key
        maior = grams[key]

print best
