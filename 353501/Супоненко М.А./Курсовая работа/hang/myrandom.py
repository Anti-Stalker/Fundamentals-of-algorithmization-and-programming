import numpy as np

class MersenneTwister:
    def __init__(self, seed=None):
        self.index = 624
        self.MT = [0] * 624
        if seed is not None:
            self.seed(seed)
        else:
            self.seed(np.random.randint(0, 2**32 - 1))

    def seed(self, seed):
        self.index = 624
        self.MT[0] = seed
        for i in range(1, 624):
            self.MT[i] = (1812433253 * (self.MT[i-1] ^ (self.MT[i-1] >> 30)) + i) & 0xFFFFFFFF

    def extract_number(self):
        if self.index >= 624:
            self.twist()
        y = self.MT[self.index]
        y = y ^ (y >> 11)
        y = y ^ ((y << 7) & 0x9D2C5680)
        y = y ^ ((y << 15) & 0xEFC60000)
        y = y ^ (y >> 18)

        self.index += 1
        return y

    def twist(self):
        for i in range(624):
            y = (self.MT[i] & 0x80000000) + (self.MT[(i + 1) % 624] & 0x7FFFFFFF)
            self.MT[i] = self.MT[(i + 397) % 624] ^ (y >> 1)
            if y % 2 != 0:
                self.MT[i] = self.MT[i] ^ 0x9908B0DF
        self.index = 0

# # Пример использования
# mt = MersenneTwister(seed=12345)
# random_numbers = [mt.extract_number() for _ in range(10)]
# print("Случайные числа:", random_numbers)
