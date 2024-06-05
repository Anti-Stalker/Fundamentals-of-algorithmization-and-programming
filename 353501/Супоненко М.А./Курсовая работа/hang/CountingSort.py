def russian_alphabet_counting_sort(input_string, russian_alphabet):
    min_char = 'а'
    max_char = 'я'
    count = {}

    for char in input_string:
        if min_char <= char <= max_char:
            if char in count:
                count[char] += 1
            else:
                count[char] = 1

    sorted_string = []
    
    for char in russian_alphabet:
        if char in count:
            sorted_string.append(char * count[char])

    return ''.join(sorted_string)
