
def is_valid(s: str) -> bool:
    stack = ['']

    for c in s:
        if stack[-1] + c in ('()', '[]', '{}'):
            stack.pop()
            continue
        stack.append(c)
    
    return len(stack) == 1