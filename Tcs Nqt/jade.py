# # Take input
# N = int(input())
# C = int(input())
# likes = []
# for i in range(C):
#     t = list(map(int, input().split()))
#     likes.append(set(t[1:]))

# # Find intersection of all customer likes
# intersection = set.intersection(*likes)

# # Output minimum number of cocktails needed
# print(len(intersection))
def solution(n,c,t):
    cocktail_counts = {}
    for l in likes:
        for c in l:
            if c in cocktail_counts:
                cocktail_counts[c] += 1
            else:
                cocktail_counts[c] = 1

    # find the minimum number of cocktails to prepare
    min_cocktails = min(cocktail_counts.values())

    print(min_cocktails)

n = int(input()) 
c = int(input()) 
likes = [] # list to store the cocktails each customer likes

for i in range(c):
    t = list(map(int, input().split()))[1:] # extract the list of liked cocktails
    likes.append(t)
solution(n,c,t)
# create a dictionary to count how many customers like each cocktail

