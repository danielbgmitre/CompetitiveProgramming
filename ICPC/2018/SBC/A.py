# A symmetrical pizza
# https://www.urionlinejudge.com.br/judge/pt/problems/view/2903

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def lcm(a, b):
    return (a * b) / gcd(a, b)

def solve(a, b):
    return lcm(a, b) / a

print solve(int(raw_input().replace('.', '')), 36000)
