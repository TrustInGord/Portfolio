##A game where you must look passed the duplicates and find the secret word

import random
import string

def generate_letter_grid(secret_word, rows, cols):
    grid_size = rows * cols
    secret_letters = list(set(secret_word.upper()))
    S = len(secret_letters)

    if (grid_size - S) % 2 != 0:
        raise ValueError("Grid size minus secret letters must be even.")

    W = (grid_size - S) // 2

    if W > 26 - S:
        raise ValueError("Not enough unique wrong letters.")

    all_letters = list(string.ascii_uppercase)
    wrong_choices = [l for l in all_letters if l not in secret_letters]
    wrong_letters = random.sample(wrong_choices, W)

    # Create final letter list
    grid_letters = secret_letters + [l for l in wrong_letters for _ in range(2)]
    random.shuffle(grid_letters)

    # Convert to 2D grid
    grid = [grid_letters[i * cols:(i + 1) * cols] for i in range(rows)]
    return grid

def print_grid(grid):
    for row in grid:
        print(" ".join(row))

def main():
    word_list = [
        "BLUE", "COLD", "FIRM", "GLAD", "HELP", "JUMP", "KIND", "LOVE", "MAKE", "NOTE",
        "OPEN", "PART", "QUIT", "READ", "STOP", "TIME", "USED", "VERY", "WIDE", "ZERO"
    ]

    secret_word = random.choice(word_list).upper()
    rows, cols = 6, 7  # 42 cells = 4 (secret) + 38 = 19 wrong letters x2

    try:
        grid = generate_letter_grid(secret_word, rows, cols)
    except ValueError as e:
        print("Error:", e)
        return
    print(secret_word)


    print("\n\nLook passed the duplicates and find the secret word")
    print("\nGuess the secret 4-letter word hidden in this grid:")
    print_grid(grid)

    guess = input("\nYour guess: ").strip().upper()

    if guess == secret_word:
        print("✅ Correct! The secret word was:", secret_word)
    else:
        print("❌ Incorrect. The secret word was:", secret_word)

if __name__ == "__main__":
    main()
