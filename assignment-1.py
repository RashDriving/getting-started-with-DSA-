
stack = []


def push(stack, value):
    stack.append(value)


def pop(stack):
    if empty(stack):
        print("Cannot pop.")
        return None
    else:
        return stack.pop()


def peek(stack):
    if empty(stack):
        return "Stack is empty."
    return stack[-1]


def empty(stack):
    return len(stack) == 0


def main():
    
    push(stack, "Answer1")
    push(stack, "Answer2")
    push(stack, "Answer3")
    
    
    pop(stack)
    
    
    print("Peeked Answer:", peek(stack))
    
    
    push(stack, "Answer4")
    
    
    if empty(stack):
        print("The stack is empty.")
    else:
        print("The stack is not empty.")
    

    print("Status:", stack)


if __name__ == "__main__":
    main()
