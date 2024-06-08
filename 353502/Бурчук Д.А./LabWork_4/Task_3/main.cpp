#include "vector"
#include "iostream"
#include "algorithm"



std::vector<int> findMedian(std::vector<int> sequence) {
    std::vector<int> temp_for_return;
    std::vector<int> tmp;
    int i = 0;
    for (; i < sequence.size() - 2; i += 3) {
        tmp.clear();
        tmp.push_back(sequence[i]);
        tmp.push_back(sequence[i + 1]);
        tmp.push_back(sequence[i + 2]);
        for (int i : tmp) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        std::sort(tmp.data(), tmp.data() + 2);
        temp_for_return.emplace_back(tmp[1]);
    }
    if ( i < sequence.size()) {
        int data = 0;
        int c = 0;
        for (; i < sequence.size(); ++i, ++c) {
            data += sequence[i];
        }
        data /= c;
        temp_for_return.emplace_back(data);
    }
    return temp_for_return;
}

int main(int argc, char *argv[]) {
    std::vector<int> sequence;
    std::vector<int> medianSequence;

    int temp = 0;
    int digit = 0;

    while ((temp = std::cin.get()) != '\n') {
        if (temp != ' ') {
            digit += temp - '0';
            digit *= 10;
        } else if (temp == 32 && std::cin.peek() == ' ') {
            continue;
        } else {
            if (temp == 32 && std::cin.peek() != '\n') {
                sequence.emplace_back(digit / 10);
            }
            digit = 0;
        }
    }
    sequence.emplace_back(digit / 10);
    /*for (int i: sequence) {
        std::cout << i << ' ';
    }*/
    //std::cout << '\n' << sequence.size() << '\n';
    medianSequence = findMedian(sequence);
    for (int i: medianSequence) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}
