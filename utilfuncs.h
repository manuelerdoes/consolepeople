#ifndef UTILFUNCS_H
#define UTILFUNCS_H

int randomNumber(int from, int to) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(from,to); // distribution in range [1, 6]

    return dist6(rng);
}

#endif