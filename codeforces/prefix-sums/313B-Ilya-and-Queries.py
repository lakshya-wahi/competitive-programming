# RATING: 1100

def solve():
    s = input().strip()
    q = int(input())

    prefix = [0]
    running_sum = 0

    for i in range(1, len(s)):
        if s[i] == s[i - 1]:
            running_sum += 1

        prefix.append(running_sum)

    answers = []

    for _ in range(q):
        left, right = map(int, input().split())

        # Queries are 1-indexed.
        answers.append(prefix[right - 1] - prefix[left - 1])

    print("\n".join(map(str, answers)))


if __name__ == "__main__":
    solve()
