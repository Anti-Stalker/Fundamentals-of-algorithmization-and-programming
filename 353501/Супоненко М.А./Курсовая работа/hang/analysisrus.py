from collections import defaultdict
from .models import Word
from .CountingSort import russian_alphabet_counting_sort

def russian_alphabet_frequency_analysis():
    words = Word.objects.all()

    # Создаем словарь для подсчета частоты встречаемости букв русского алфавита
    frequency = defaultdict(int)
    russian_alphabet = 'абвгдеёжзийклмнопрстуфхцчшщъыьэюя'
    total_letters_count = 0 

    for word in words:
        for char in word.text.lower(): 
            if char in russian_alphabet: 
                frequency[char] += 1
                total_letters_count += 1

    percentage_frequency = {}

    for char, count in frequency.items():
        percentage = (count / total_letters_count) * 100
        percentage_frequency[char] = round(percentage, 1)

    # Преобразуем результат частотного анализа в строку, чтобы передать в сортировку
    input_string = ''.join(char for char, _ in percentage_frequency.items())

    # Используем сортировку подсчетом для получения отсортированной строки
    sorted_string = russian_alphabet_counting_sort(input_string, russian_alphabet)

    # Преобразуем отсортированную строку обратно в список кортежей
    sorted_percentage_frequency = [
        (char, percentage_frequency[char]) 
        for char in sorted_string
        if char in percentage_frequency
    ]

    return sorted_percentage_frequency
