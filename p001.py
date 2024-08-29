# ==============================================================================
# Multiples of 3 or 5
# ==============================================================================

# Find the sum of all the multiples pf 3 or 5 bellow 1000.

def check_multiple(num: int) -> bool:
    """
    Checks if a number is multiple of 3 or 5.

    Args:
        num (int): The number to be checked.

    Returns:
        bool: True when the number is a multiple of 3 or 5, else False.
    """
    return bool(num % 3 == 0 or num % 5 == 0)


def main():
    sum = 0
    for i in range(1000):
        if check_multiple(i):
            sum += i
    print(f'The sum is |{sum}|.')


if __name__ == '__main__':
    main()