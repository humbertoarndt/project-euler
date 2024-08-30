# ==============================================================================
# Even Fibonacci numbers
# ==============================================================================

# Starting by 1 and 2, the program follows the Fibonacci sequence to find the
# sum of the even valued terms not exceeding 4000000.

def check_even(num: int) -> bool:
    """
    Checks if the given number is even.

    Args:
        num (int): Number to be checked.

    Returns:
        bool: True when the number is even, else False.
    """
    return bool(num % 2 == 0)


def main():
    first = 1
    second = 2
    sum = 2
    while True:
        temp = first + second
        if temp > 4000000:
            break
        if check_even(temp):
            sum += temp
        first = second
        second = temp
    print(f'The sum is: |{sum}|.')


if __name__ == '__main__':
    main()