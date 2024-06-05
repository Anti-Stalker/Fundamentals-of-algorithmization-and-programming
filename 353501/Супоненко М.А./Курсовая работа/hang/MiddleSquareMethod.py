class MiddleSquareMethod:
    def __init__(self, seed):
        self.seed = seed

    def generate(self, n):
        result = []
        for _ in range(n):
            self.seed = self.square(self.seed)
            result.append(self.extract_middle(self.seed))
        return result

    def square(self, num):
        return num * num

    def extract_middle(self, num):
        num_str = str(num)
        middle_index = len(num_str) // 2
        middle_digits = num_str[middle_index - 1:middle_index + 1]
        return int(middle_digits)