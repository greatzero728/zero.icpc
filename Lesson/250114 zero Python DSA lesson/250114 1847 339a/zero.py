input_word = input()
odd_index_chars = input_word[0::2]
sorted_chars = '+'.join(sorted(odd_index_chars))
print(sorted_chars)
