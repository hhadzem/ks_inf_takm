import sys

RULE_1_LENGTH = 11

SPECIAL_RULE4 = set("!@#$%&*?_")
SPECIAL_RULE5 = set("!@#")


def rule1(s: str) -> bool:
    return len(s) >= RULE_1_LENGTH


def rule2(s: str) -> bool:
    return len(s) > 0 and ("a" <= s[0] <= "z")


def rule3(s: str) -> bool:
    return len(s) > 0 and ("0" <= s[-1] <= "9")


def rule4(s: str) -> bool:
    if len(s) < 2:
        return False
    return (s[1] in SPECIAL_RULE4) or (s[-2] in SPECIAL_RULE4)


def rule5(s: str) -> bool:
    has_lower = has_upper = has_digit = has_special = False

    for c in s:
        if "a" <= c <= "e":
            has_lower = True
        elif "A" <= c <= "E":
            has_upper = True
        elif "0" <= c <= "4":
            has_digit = True
        elif c in SPECIAL_RULE5:
            has_special = True

    count = has_lower + has_upper + has_digit + has_special
    return count >= 3


def rule6(s: str) -> bool:
    freq = {}
    for c in s:
        freq[c] = freq.get(c, 0) + 1
        if freq[c] >= 4:
            return True
    return False


def rule7(s: str) -> bool:
    # Non-overlapping repeated bigram:
    # exists i < j such that s[i:i+2] == s[j:j+2] and j - i >= 2
    if len(s) < 4:
        return False

    first_pos = {}  # bigram -> earliest start index
    for j in range(len(s) - 1):
        bg = s[j : j + 2]
        if bg in first_pos:
            if j - first_pos[bg] >= 2:
                return True
            # keep earliest index; it gives the best chance to reach >=2 later
        else:
            first_pos[bg] = j

    return False


def calculate_password_strength(password: str) -> int:
    checks = [
        rule1(password),
        rule2(password),
        rule3(password),
        rule4(password),
        rule5(password),
        rule6(password),
        rule7(password),
    ]
    return sum(checks)


def main() -> None:
    lines = sys.stdin.read().splitlines()
    if not lines:
        return
    t = int(lines[0].strip())
    out = []
    for i in range(1, 1 + t):
        pw = lines[i].strip()
        out.append(str(calculate_password_strength(pw)))
    sys.stdout.write("\n".join(out))


if __name__ == "__main__":
    main()
